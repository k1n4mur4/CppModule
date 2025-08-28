NAME		=	megaphone
CC			=	c++
CFLAG		=	-Wall -Wextra -Werror 
VFLAG		=	-std=c++98 -pedantic

RM			=	rm -rf
MAKEFLAG	+=	--no-print-directory

SRCS		=	megaphone.cpp
OBJS		=	$(SRCS:.cpp=.o)

# **************************************************************************** #
# **********************************target************************************ #
# **************************************************************************** #

all: $(NAME)
$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAG) $(VFLAG) $(OBJS) -o $(NAME)
	@echo "$(NAME) successfully!"

clean:
	@echo "Cleaning objects file"
	@$(RM) $(OBJS)
	@echo "successfully!"

fclean:
	@echo "Removing $(NAME)..."
	@$(RM) $(OBJS) $(NAME)
	@echo "successfully!"

re: fclean all

.PHONY: all clean fclean re