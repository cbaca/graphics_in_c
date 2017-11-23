#vpath %.c src
CC       = gcc
GDB      = gdb
TARGET   =
OBJDIR   = objs

CPPFLAGS = -std=gnu99 -Wl,--build-id=sha1
WARNINGS = -Wall -Wshadow -Wextra -Werror \
           -Wundef -Wpointer-arith \
           -Wcast-align -Wwrite-strings \
           -Wconversion -Wunreachable-code \
           -Wsuggested-attribute=const

LDFLAGS  =
LIBS     =
#INC = -I ./inc


SRCS =
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

all: aa

aa: main.c
	$(CC) -o $@ $<

dirs:
	mkdir -p $(OBJDIR)
	touch $(OBJDIR)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o: %.c dirs
	$(CC) $(CPPFLAGS) $(WARNINGS) -c $< -o $@ $(INC)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)
	$(RM) $(TARGET) *.o

#main.s: main.c
#	$(CC) $(CPPFLAGS) $(WARNINGS) -S -fverbose-asm -o $@ $(INC) $<
