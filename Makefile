NAME	=	ft_retro

CLANG	=	clang++ -g -Wall -Wextra -Werror

NCURSES	=	-lncurses

SRC		=	main.cpp \
			Enemy.cpp \
			Star.cpp \
			Player.cpp \

OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(NCURSES) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CLANG) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all
