# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 18:01:10 by ahomari           #+#    #+#              #
#    Updated: 2024/06/10 16:21:45 by ahomari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS					= -Wall -Wextra -Werror 
CC						= cc 
RM						= rm -rf
NAME					= philo
HEAD					= philo.h


SRC						= philo.c tools/utilis.c tools/error_msg.c tools/routine.c tools/cleanup.c tools/create_philo.c tools/exec_philo.c tools/monitoring.c tools/parsing.c
S_OBJ					= ${SRC:.c=.o} 

all:					${NAME}

%.o: %.c				${HEAD}
						${CC} ${FLAGS}  -c $< -o $@

${NAME}:				${S_OBJ} ${HEAD}
						@${CC} ${S_OBJ} -o ${NAME}
						@echo "${GREEN}${NAME} Created!${DEFAULT}"

clean:
						@${RM} ${S_OBJ}
						@echo "${YELLOW}Object Files deleted!${DEFAULT}"

fclean:					clean
						@${RM} ${NAME}
						@echo "${RED}All Deleted!${DEFAULT}"

re: 					fclean all

.PHONY: 				fclean all re  clean

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m