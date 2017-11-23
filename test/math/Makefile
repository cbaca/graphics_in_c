CC       = gcc
GDB      = gdb
TARGET   = aa
OBJDIR   = objs
SRCDIR   = src
INCDIR   = inc

CPPFLAGS = -std=gnu99 -Wl,--build-id=sha1 -g
WARNINGS = -w #-Wall -Wshadow -Wextra -Werror \
           #-Wundef -Wpointer-arith \
           #-Wcast-align -Wwrite-strings \
           #-Wconversion -Wunreachable-code
LDFLAGS  =
LIBS     = -lm
INC      = -I ./$(INCDIR)

SRCS = $(wildcard $(SRCDIR)/*.c)
TMPSRC = $(subst $(SRCDIR)/,,$(SRCS))
OBJS = $(addprefix $(OBJDIR)/,$(TMPSRC:.c=.o))



all: $(TARGET)

dirs:
	mkdir -p $(OBJDIR)
	touch $(OBJDIR)
	@echo $(SRCS)
	@echo $(OBJS)

$(TARGET): $(OBJS) $(OBJDIR)/vec3.o
	$(CC) $(CPPFLAGS) -o $@ $^ $(LIBS)
	@echo compiled successfully

$(OBJDIR)/%.o: $(SRCDIR)/%.c dirs
	$(CC) -O3 $(CPPFLAGS) $(WARNINGS) -c $< -o $@ $(INC)

$(OBJDIR)/vec3.o: $(SRCDIR)/vec3.s
	$(CC) -O3 $(CPPFLAGS) $(WARNINGS) -c $< -o $@

asm.s: $(SRCDIR)/Vec3.c
	$(CC) -O3 $(CPPFLAGS) $(WARNINGS) -S -masm=intel -o $@ $(INC) $<

.PHONY: clean
clean:
	rm -rf $(OBJDIR)
	$(RM) $(TARGET) *.o
