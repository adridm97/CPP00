# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrian <adrian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 20:24:01 by aduenas-          #+#    #+#              #
#    Updated: 2024/09/12 23:02:23 by adrian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= phonebook
CPP		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address
SOURCES	= main.cpp PhoneBook.cpp Contact.cpp
OBJS	= ${SOURCES:.cpp=.o}

all: $(NAME)


$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
