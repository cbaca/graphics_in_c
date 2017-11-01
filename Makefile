NAME = aa
CC  = gcc
GDB = gdb

vpath %.c src src/Math src/Scene src/local

FLAGS = -std=gnu11

PPFLAGS = -Wl,--build-id=sha1

WARNINGS := -Werror -Wall -Wshadow -Wextra -Wundef -Wpointer-arith\
-Wcast-align -Wwrite-strings -Wconversion -Wunreachable-code

LIBS = -lGL -lGLEW -lglfw -lm -lSOIL
LIBS += -lglut -lGLU

INC = -I ./include -I ./include/Math -I ./include/Scene

OBJ_DIR = objs

SRCS = main.c Shader.c Render.c Backend.c BufferData.c World.c
SRCS += Camera.c Frustum.c
SRCS += Vec3.c Mat4.c
SRCS += SceneObject.c RenderList.c Scene.c
SRCS += utils.c meshdata.c texture.c Array.c

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $@ $^ $(LIBS) -g
	@echo compilation successful af

$(OBJ_DIR)/%.o:%.c
	$(CC) $(FLAGS) $(WARNINGS) -c $^ -o $@ $(INC) -g

.PHONY: clean
clean:
	$(RM) $(NAME) *.o *.s $(OBJ_DIR)/*.o

#asm.s:main.c
#	$(CC) -S -fverbose-asm -o $@ $(FLAGS) $<

