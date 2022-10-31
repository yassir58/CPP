SRC=ClapTrap.cpp main.cpp
OBJS=$(SRC:.cpp=.o)
CP_FLAGS= -Wall -Wextra -Werror -std=c++98
CPP=c++
NAME=./exec
HEADER=ClapTrap.hpp
%.o:%.cpp $(HEADER)
	$(CPP) $(CP_FLAGS) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJS) $(HEADER)
	$(CPP) $(CP_FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
fclean:clean
	rm -rf $(NAME)
re:fclean all
