.PHONY:clean
CC = gcc
RM = rm
OBJ = phone
OBJS = main.o func.o

$(OBJ):$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c $< -o $@
clean:
	$(RM) $(OBJ) $(OBJS)