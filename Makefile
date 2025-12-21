TARGET = myshell

CC = gcc

# considering warning as error
CFLAGS = -Wall -Wextra -g

# all the files of the project
SRCS = main.c \
	   question_1.c \
	   question_2.c \
	   question_3.c \
	   question_4.c \
	   question_5.c \
	   question_6.c \
	   question_7.c \
	   question_8.c

OBJS = $(SRCS:.c=.o)


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# cleaning the repertory after execution 

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean