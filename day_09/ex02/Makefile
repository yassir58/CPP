SRCS=main.cpp PmergeMe.cpp 
OBJS=$(SRCS:.cpp=.o)
EXEC=PmergeMe
CC=c++
HEADERS=PmergeMe.hpp
CFLAGS= -Wall -Wextra -Werror -std=c++98 -fsanitize=leak

all: $(EXEC)


%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC):$(OBJS)
	$(CC) $(CFLGS) $(OBJS) -o $(EXEC)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(EXEC)
re: fclean all

.PHONY: re fclean clean all