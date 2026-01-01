NAME		=	megaphone

# commands
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
CXXFLAGS	+=	-std=c++98 -pedantic
RM			=	rm -rf
MAKEFLAGS	+=	--no-print-directory

# Files
SRCS		=	megaphone.cpp
OBJS		=	${SRCS:.cpp=.o}

# Colors
RESET		=	\033[0m
BOLD		=	\033[1m
LIGHT_BLUE	=	\033[94m
YELLOW		=	\033[93m

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[K$(BOLD)$(LIGHT_BLUE)Compiling $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\r\033[K$(BOLD)$(LIGHT_BLUE)$(NAME) created successfully!$(RESET)\n"

clean:
	@echo "\033[K$(BOLD)$(LIGHT_BLUE)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@echo "\r\033[K$(BOLD)$(LIGHT_BLUE)Objects cleaned!$(RESET)\n"

fclean:
	@echo "\033[K$(BOLD)$(LIGHT_BLUE)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME) $(OBJS)
	@echo "\r\033[K$(BOLD)$(LIGHT_BLUE)Full clean complete!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
