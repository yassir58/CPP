SRC=main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS=$(SRC:.cpp=.o)
CP_FLAGS= -Wall -Wextra -Werror -std=c++98
CPP=c++
NAME=./exec
HEADERS=HumanA.hpp HumanB.hpp Weapon.hpp

%.o:%.cpp
	$(CPP) $(CP_FLAGS) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJS)  $(HEADERS)
	$(CPP) $(CP_FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
fclean:clean
	rm -rf $(NAME)
re:fclean all