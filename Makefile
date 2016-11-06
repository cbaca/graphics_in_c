#SRC = $(wildcard *.c)
#OBJ = $(SRC:%.cpp=%.o)
NAME = aa
CC = gcc
FLAGS = -std=gnu99 -g -pedantic
PPFLAGS = -Wl,--build-id=sha1
WARNINGS := -Wall -Wshadow -Wextra -Werror -Wundef -Wpointer-arith\
-Wcast-align -Wwrite-strings -Wconversion -Wunreachable-code
LIBS = -lGL -lGLEW -lglfw
#LIBS = -lglut -lGL -lGLU -lfl -lGLEW \
#-lX11 -lxcb -lXrandr -lXi \
#-lpthread

$(NAME):main.c
	$(CC) -o $@ $(FLAGS) $(WARNINGS) $< $(LIBS)

#%.o : %.cpp
#	$(CC) $(FLAGS) $(WARNINGS) -c $< -o $@

#asm.s:main.c
#	$(CC) -S -fverbose-asm -o $@ $(FLAGS) $<

.PHONY: clean
clean:
	$(RM) $(NAME) *.o *.s
