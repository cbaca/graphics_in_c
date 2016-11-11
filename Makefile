NAME = aa
CC = gcc
FLAGS = -std=gnu99 -g -pedantic
PPFLAGS = -Wl,--build-id=sha1
WARNINGS := -Wall -Wshadow -Wextra -Werror -Wundef -Wpointer-arith\
-Wcast-align -Wwrite-strings -Wconversion -Wunreachable-code
LIBS = -lGL -lGLEW -lglfw -lm -lSOIL -Lmatrix_maths
#LIBS = -lglut -lGL -lGLU -lfl -lGLEW \
#-lX11 -lxcb -lXrandr -lXi \
#-lpthread

$(NAME):main.o graphics.o window.o toriaezu_matrix.o
	$(CC) -o $@ $^ $(LIBS)
	@echo compilation successful af

main.o:main.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

graphics.o:graphics.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

window.o:window.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

toriaezu_matrix.o:matrix_maths/toriaezu_matrix.c
	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

debug:main.o graphics.o window.o toriaezu_matrix.o
	$(CC) -o aa_debug $^ $(DEFINE) $(LIBS)
	@echo debug compile

#asm.s:main.c
#	$(CC) -S -fverbose-asm -o $@ $(FLAGS) $<

.PHONY: clean
clean:
	$(RM) $(NAME) *.o *.s aa_debug
