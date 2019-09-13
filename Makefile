FILES =

OBJS = lada86.c $(FILES)

CC = gcc

COMPILER_FLAGS = -Wall -Wextra -pedantic

LINKER_FLAGS = -lm

OBJ_NAME = lada86

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	
debug : $(OBJS)
	$(CC) $(OBJS) -g -O0 $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)