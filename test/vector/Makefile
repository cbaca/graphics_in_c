CC       = gcc
GDB      = gdb
TARGET   = aa
OBJDIR   = objs

CPPFLAGS = -std=gnu99 -Wl,--build-id=sha1
WARNINGS = -Wall -Wshadow -Wextra -Werror \
           -Wundef -Wpointer-arith \
           -Wcast-align -Wwrite-strings \
           -Wconversion -Wunreachable-code
all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CPPFLAGS) $(WARNINGS) $< -o $@ $(INC) -g

.PHONY: clean
clean:
	$(RM) $(TARGET)
