cc      = gcc
gdb     = gdb
target  = aa

#----------------------------------------------------------

root    = $(shell pwd)
srcdir  = src
dsdir   = $(srcdir)/data_structure
geodir  = $(srcdir)/geometry
mathdir = $(srcdir)/vecmath

incdir  = inc
depdir  = deps
objdir  = objs
testdir = test

#----------------------------------------------------------

vpath %.c src/ $(mathdir) $(geodir) $(dsdir)
.PHONY: clean

depopts   = -MMD -MF $(depdir)/$(*F).d
cppflags := -std=gnu99 -Wl,--build-id=sha1

warnings = -Wall -Werror -Wshadow -Wextra \
           -Wundef -Wpointer-arith \
           -Wcast-align -Wwrite-strings \
           -Wconversion -Wunreachable-code

inc  = -I $(incdir) \
       -I $(incdir)/vecmath \
       -I $(incdir)/data_structure

libs = -lGL -lGLEW -lglfw \
       -lSOIL -lglut -lGLU \
       -lm

src_cfiles  := main.c loop.c             backend.c \
               BufferData.c               camera.c \
               Render.c RenderList.c       Scene.c \
               SceneObject.c Shader.c shaderdata.c \
               texture.c utils.c           World.c
ds_cfiles   := array.c
geo_cfiles  := meshdata.c     meshdata_wavefront.c \
               meshdata_quad.c  meshdata_pyramid.c \
               meshdata_sphere.c   meshdata_cube.c
math_cfiles := Frustum.c Mat4.c Quat.c Vec3.c \
               vecrot.c

srcs := src_cfiles sfiles
objs := $(addprefix $(objdir)/,$(src_cfiles:.c=.c.o)) \
        $(addprefix $(objdir)/,$(math_cfiles:.c=.c.o)) \
        $(addprefix $(objdir)/,$(geo_cfiles:.c=.c.o)) \
        $(addprefix $(objdir)/,$(ds_cfiles:.c=.c.o))
deps := $(addprefix $(depdir)/,$(srcs:.c=.d)) \
        $(addprefix $(depdir)/,$(srcs:.s=.d))


#----------------------------------------------------------

-include $(deps)

ifdef DEBUG
    cppflags += -g -ggdb
endif


#----------------------------------------------------------
#                       Recipes
#----------------------------------------------------------

all: $(target)

dirs:
	mkdir -p $(objdir) $(depdir)
	touch $(objdir) $(depdir)
	@echo $(objs)

showobjs:
	@echo $(objs)
showsrcs:
	@echo $(srcs)

$(target): $(objs)
	$(cc) $(cppflags) $^ -o $@ $(depopts) $(libs)

$(objdir)/%.c.o: %.c dirs
	@echo Building object files from C sources.
	$(cc) $(cppflags) $(warnings) -c $< -o $@ $(depopts) $(inc)

Mat4.s: Mat4.c
	$(cc) -O3 $(cppflags) $(warnings) -S -masm=intel -o $@ $(inc) $<

clean:
	rm -rf $(objdir) $(depdir)
	rm -f $(target) *.o *.log
