SRC=main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJS=$(SRC:.cpp=.o)
CP_FLAGS= -Wall -Wextra -Werror -std=c++98
CPP=c++
NAME=./exec
HEADER=Base.hpp A.hpp B.hpp C.hpp
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