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

$(NAME):main.o graphics.o window.o toriaezu_matrix.o input.o
	$(CC) -o $@ $^ $(LIBS)
	@echo compilation successful af

main.o:base/main.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

graphics.o:base/graphics.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

window.o:base/window.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

input.o:base/input.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

toriaezu_matrix.o:calc/toriaezu_matrix.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(NAME) *.o *.s

#asm.s:main.c
#	$(CC) -S -fverbose-asm -o $@ $(FLAGS) $<

