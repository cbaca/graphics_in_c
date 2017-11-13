CC      = gcc
GDB     = gdb
TARGET  = aa
SRCDIR  = src
INCDIR  = inc
TSTDIR  = test
OBJDIR  = objs
DEPDIR  = deps

vpath %.c src src/Math src/local

CPPFLAGS = -std=gnu11 -Wl,--build-id=sha1 -g -v
DEPOPTS  = -MMD -MF $(DEPDIR)/$(*F).d

WARNINGS = -Wall -Werror -Wshadow -Wextra \
           -Wundef -Wpointer-arith \
           -Wcast-align -Wwrite-strings \
           -Wconversion -Wunreachable-code

LIBS = -lGL -lGLEW -lglfw \
       -lSOIL -lglut -lGLU \
       -lm


INC  = -I ./inc -I ./inc/Math

SRCS = main.c loop.c backend.c Shader.c \
       Render.c BufferData.c World.c \
       Camera.c Frustum.c Vec3.c Mat4.c \
       SceneObject.c RenderList.c Scene.c \
       shaderdata.c utils.c meshdata.c \
       texture.c Array.c

OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
DEPS = $(addprefix $(DEPDIR)/,$(SRCS:.c=.d))

all: proj

-include $(DEPS)

proj: $(TARGET)

dirs:
	mkdir -p $(OBJDIR) $(DEPDIR)
	touch $(OBJDIR) $(DEPDIR)

$(TARGET):  $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LIBS)
	@echo compilation successful af

$(OBJDIR)/%.o: %.c dirs
	$(CC) $(CPPFLAGS) $(WARNINGS) -c $< -o $@ $(DEPOPTS) $(INC)

Mat4.s: Mat4.c
	$(CC) -O $(CPPFLAGS) $(WARNINGS) -S -fverbose-asm -masm=intel -o $@ $(INC) $<

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(DEPDIR)
	$(RM) $(TARGET) *.o
