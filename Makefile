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

GEO_DIR = utils/geometry
INPUT_DIR = utils/input

OBJS = obj/main.o obj/graphics.o obj/window.o obj/input.o

OBJS += obj/vecMat4.o obj/mat4array_transpose.o
OBJS += obj/mat4array_translate.o obj/mat4array_rotate.o obj/mat4array_print.o
OBJS += obj/mat4array_multiply.o obj/mat4array_set.o obj/mat4array_copy.o
OBJS += obj/mat4array_scale.o obj/mat4array_perspective.o

$(NAME):$(OBJS)
	$(CC) -o $@ $^ $(LIBS) -Lobj
	@echo compilation successful af

obj/main.o:base/main.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/graphics.o:base/graphics.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/window.o:base/window.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/input.o:$(INPUT_DIR)/input.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/vecMat4.o:$(GEO_DIR)/vecMat4/vecMat4.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_transpose.o:$(GEO_DIR)/mat4array_transpose.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_translate.o:$(GEO_DIR)/mat4array_translate.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_rotate.o:$(GEO_DIR)/mat4array_rotate.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_print.o:$(GEO_DIR)/mat4array_print.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_multiply.o:$(GEO_DIR)/mat4array_multiply.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_set.o:$(GEO_DIR)/mat4array_set.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_copy.o:$(GEO_DIR)/mat4array_copy.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_scale.o:$(GEO_DIR)/mat4array_scale.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/mat4array_perspective.o:$(GEO_DIR)/mat4array_perspective.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

.PHONY: clean
clean:
	$(RM) $(NAME) *.o *.s obj/*.o

#asm.s:main.c
#	$(CC) -S -fverbose-asm -o $@ $(FLAGS) $<

