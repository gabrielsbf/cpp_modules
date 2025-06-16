EXEC_FD = ./run/
NAME = $(EXEC_FD)ex05

RM = rm -rf

DIR_OBJS = builds/
DIR_SRCS = ./
DIR_INCLUDES = includes/
COMPILER = c++ -Wall -Wextra -Werror --std=c++98 -I $(DIR_INCLUDES)

GET_SRCS = $(shell find $(DIR_SRCS))

PRE-FILTER_SRCS = $(filter %.cpp, $(GET_SRCS))

FILTER_SRCS = $(filter-out %testing.cpp, $(PRE-FILTER_SRCS))

OBJS = $(FILTER_SRCS:%.cpp=$(DIR_OBJS)%.o)

all: $(NAME)

$(NAME): $(OBJS) $(DIR_OBJS) $(EXEC_FD)
	$(COMPILER) $(OBJS) -o $(NAME)

$(DIR_OBJS):
	mkdir $(DIR_OBJS)

$(EXEC_FD):
	mkdir $(EXEC_FD)

$(DIR_OBJS)%.o : %.cpp
	mkdir -p $(dir $@)
	$(COMPILER) -c $< -o $@

val: all
	valgrind --leak-check=full ./$(NAME)

clean:
	$(RM) $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME) $(DIR_OBJS) $(EXEC_FD)

re: fclean all

