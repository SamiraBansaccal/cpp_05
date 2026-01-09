# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 01:39:34 by sbansacc          #+#    #+#              #
#    Updated: 2025/12/19 00:53:45 by sbansacc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		Intern
CXX =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98
SRCS =		main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			Intern.cpp
OBJDIR =	obj/
OBJS =		$(SRCS:%.cpp=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "🚀 Houston, we have a $(NAME)!"

$(OBJDIR)%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJDIR)
	@echo "🧹 Cleaning up the mess!"

fclean: clean 
	rm -f $(NAME)
	@echo "🧨 Obliterating all traces!"

re: fclean all

.PHONY:  all clean fclean re