NAME = megaphone

RM = rm -rf
COMPILER = g++

DIR_OBJS = builds/
DIR_SRCS = ./
DIR_INCLUDES = includes/

GET_SRCS = $(shell find $(DIR_SRCS))

PRE-FILTER_SRCS = $(filter %.cpp, $(GET_SRCS))

FILTER_SRCS = $(filter-out %testing.cpp, $(PRE-FILTER_SRCS))

OBJS = $(FILTER_SRCS:%.c=$(DIR_OBJS)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(DIR_OBJS)
	$(COMPILER) $(OBJS) -o $(NAME)

$(DIR_OBJS):
	mkdir builds

$(DIR_OBJS)/%.o : %.c
	mkdir -p $(dir $@)
	$(COMPILER) -c $< -o $@

val: all
	valgrind --read-inline-info=yes --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=$(SUPP_FILE) ./$(NAME)
clean:
	$(RM) $(DIR_OBJS)
	cd includes/libft && make clean && cd ../..

fclean: clean
	$(RM) $(NAME) $(DIR_OBJS)

re: fclean all

