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

$(NAME):src/main.o src/graphics.o src/window.o src/toriaezu_matrix.o src/toriaezu_debug.o src/input.o
	$(CC) -o $@ $^ $(LIBS) -Lsrc
	@echo compilation successful af

src/main.o:base/main.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

src/graphics.o:base/graphics.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

src/window.o:base/window.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

src/input.o:base/input.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

src/toriaezu_matrix.o:toriaezu_matrix/toriaezu_matrix.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lsrc

src/toriaezu_debug.o:toriaezu_matrix/toriaezu_debug.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@ -Lsrc

.PHONY: clean
clean:
	$(RM) $(NAME) *.o *.s src/*.o

#asm.s:main.c
#	$(CC) -S -fverbose-asm -o $@ $(FLAGS) $<

