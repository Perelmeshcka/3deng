CC = gcc

CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

TARGET = 3deng
SRCS = draw.c 3deng.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(OBJS): config.h

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
