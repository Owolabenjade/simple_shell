CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
OBJS = main.o shell.o
TARGET = simple_shell

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
		rm -f $(OBJS) $(TARGET)
