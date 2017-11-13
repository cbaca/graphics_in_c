CC       = gcc
GDB      = gdb
TARGET   = aa

CPPFLAGS = -std=gnu99 -Wl,--build-id=sha1 -g
WARNINGS = -Wall -Wshadow -Wextra -Werror \
           -Wundef -Wpointer-arith \
           -Wcast-align -Wwrite-strings \
           -Wconversion -Wunreachable-code

SRCS = $(wildcard *.c)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LIBS)
	@echo compiled successfully

.PHONY: clean
clean:
	$(RM) $(TARGET)
