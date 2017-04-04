NAME = aa
CC  = gcc
GDB = gdb

vpath %.c base math/mat4 math/mat4/vecMat4 math/vec3

FLAGS = -std=gnu99

PPFLAGS = -Wl,--build-id=sha1

WARNINGS := -Wall -Wshadow -Wextra -Werror -Wundef -Wpointer-arith\
-Wcast-align -Wwrite-strings -Wconversion -Wunreachable-code

LIBS = -lGL -lGLEW -lglfw -lm -lSOIL
LIBS += -lglut -lGLU

INC = -I ./include -I ./math/include

OBJ_DIR = objs

SRCS = main.c window.c input.c shaders.c
SRCS += player.c
SRCS += vecMat4.c mat4array_copy.c mat4array_frustrum.c
SRCS += mat4array_multiply.c mat4array_perspective.c mat4array_print.c
SRCS += mat4array_rotate.c mat4array_scale.c mat4array_set.c
SRCS += mat4array_translate.c mat4array_transpose.c
SRCS += mat4array_view.c
SRCS += vec3array.c

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $@ $^ $(LIBS)
	@echo compilation successful af

$(OBJ_DIR)/%.o:%.c
	$(CC) $(FLAGS) $(WARNINGS) -c $^ -o $@ $(INC)

.PHONY: clean
clean:
	$(RM) $(NAME) *.o *.s $(OBJ_DIR)/*.o

#asm.s:main.c
#	$(CC) -S -fverbose-asm -o $@ $(FLAGS) $<

