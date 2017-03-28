NAME = computorV1

SRC = computorV1.cpp \
		equation0.cpp \
		equation1.cpp \
		equation2.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		g++ -std=c++11 -c $(SRC)
		g++ -std=c++11 $(OBJ)  -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re : fclean all
