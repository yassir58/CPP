SRCS=main.cpp RPN.cpp 
OBJS=$(SRCS:.cpp=.o)
EXEC=RPN
CC=c++
HEADERS=RPN.hpp
CFLAGS=-Wall -Wextra -Wextra -std=c++98

all: $(EXEC)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(EXEC)
re: fclean all

.PHONY: re fclean clean all