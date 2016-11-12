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
OBJS = obj/main.o obj/graphics.o obj/window.o obj/input.o
OBJS += obj/toriaezu_matrix.o obj/data_type.o obj/debug.o

$(NAME):$(OBJS)
	$(CC) -o $@ $^ $(LIBS) -Lobj
	@echo compilation successful af

obj/main.o:base/main.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/graphics.o:base/graphics.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/window.o:base/window.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/input.o:base/input.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

obj/toriaezu_matrix.o:toriaezu_matrix/toriaezu_matrix.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/data_type.o:toriaezu_matrix/data_type.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

obj/debug.o:toriaezu_matrix/debug.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lobj

.PHONY: clean
clean:
	$(RM) $(NAME) *.o *.s obj/*.o

#asm.s:main.c
#	$(CC) -S -fverbose-asm -o $@ $(FLAGS) $<

