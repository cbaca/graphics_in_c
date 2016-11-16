NAME = aa
CC = gcc
FLAGS = -std=gnu99 -g -pedantic
PPFLAGS = -Wl,--build-id=sha1
WARNINGS := -Wall -Wshadow -Wextra -Werror -Wundef -Wpointer-arith\
-Wcast-align -Wwrite-strings -Wconversion -Wunreachable-code
LIBS = -lGL -lGLEW -lglfw -lm -lSOIL
#LIBS = -lglut -lGL -lGLU -lfl -lGLEW \
#-lX11 -lxcb -lXrandr -lXi \
#-lpthread

MAT_DIR = util/mat4
VEC_DIR = util/vec3
INPUT_DIR = util/input
BASE_DIR = base
#BASE_DIR = test

OBJ = obj/main.o obj/window.o obj/input.o
OBJ += obj/player.o obj/cubes.o
OBJ += obj/vecMat4.o obj/mat4array_copy.o obj/mat4array_frustrum.o
OBJ += obj/mat4array_multiply.o obj/mat4array_perspective.o obj/mat4array_print.o
OBJ += obj/mat4array_rotate.o obj/mat4array_scale.o obj/mat4array_set.o
OBJ += obj/mat4array_translate.o obj/mat4array_transpose.o
OBJ += obj/mat4array_view.o
OBJ += obj/vec3array.o

$(NAME):$(OBJ)
	$(CC) -o $@ $^ $(LIBS) -Lobj
	@echo compilation successful af

obj/main.o:$(BASE_DIR)/main.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/window.o:$(BASE_DIR)/window.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/cubes.o:$(BASE_DIR)/cubes.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/player.o:$(BASE_DIR)/player.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@


obj/input.o:$(INPUT_DIR)/input.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@


obj/vec3array.o:$(VEC_DIR)/vec3array.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj


obj/vecMat4.o:$(MAT_DIR)/vecMat4/vecMat4.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj


obj/mat4array_copy.o:$(MAT_DIR)/mat4array_copy.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_frustrum.o:$(MAT_DIR)/mat4array_frustrum.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_multiply.o:$(MAT_DIR)/mat4array_multiply.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_perspective.o:$(MAT_DIR)/mat4array_perspective.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_print.o:$(MAT_DIR)/mat4array_print.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_rotate.o:$(MAT_DIR)/mat4array_rotate.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_scale.o:$(MAT_DIR)/mat4array_scale.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_set.o:$(MAT_DIR)/mat4array_set.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_translate.o:$(MAT_DIR)/mat4array_translate.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_transpose.o:$(MAT_DIR)/mat4array_transpose.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_view.o:$(MAT_DIR)/mat4array_view.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

.PHONY: clean
clean:
	$(RM) $(NAME) *.o *.s obj/*.o

#asm.s:main.c
#	$(CC) -S -fverbose-asm -o $@ $(FLAGS) $<

