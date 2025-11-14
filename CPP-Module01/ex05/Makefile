NAME		=	harl

# commands
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror
VFLAGS		=	-std=c++98 -pedantic
RM			=	rm -rf
MAKEFLAGS	+=	--no-print-directory

# Files
SRCS		=	Harl.cpp \
				main.cpp
OBJS		=	${SRCS:.cpp=.o}

# Colors
RESET		=	\033[0m
BOLD		=	\033[1m
LIGHT_BLUE	=	\033[94m
YELLOW		=	\033[93m

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	@printf "\033[K$(BOLD)$(LIGHT_BLUE)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(VFLAGS) $(OBJS) -o $(NAME)
	@printf "\r\033[K$(BOLD)$(LIGHT_BLUE)$(NAME) created successfully!$(RESET)\n"

clean:
	@printf "\033[K$(BOLD)$(LIGHT_BLUE)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@printf "\r\033[K$(BOLD)$(LIGHT_BLUE)Objects cleaned!$(RESET)\n"

fclean:
	@printf "\033[K$(BOLD)$(LIGHT_BLUE)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME) $(OBJS)
	@printf "\r\033[K$(BOLD)$(LIGHT_BLUE)Full clean complete!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re