# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmafrid <asmafrid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 09:58:53 by asmafrid          #+#    #+#              #
#    Updated: 2026/01/29 08:44:18 by asmafrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       Bureaucrat.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m # No Color

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Build successful!$(NC)"

%.o: %.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(NC)"
	@rm -f $(NAME)

re: fclean all

run: $(NAME)
	@echo "$(GREEN)Running $(NAME)...$(NC)"
	@./$(NAME)
