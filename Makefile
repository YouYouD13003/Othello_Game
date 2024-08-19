CC = gcc
CFLAGS = -Wall -Wextra -Wno-missing-field-initializers
LIBS = -lSDL -lSDL_image -lSDL_ttf

SRCS = main.c
OBJS = $(SRCS:.c=.o)

TARGET = myprogram

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

