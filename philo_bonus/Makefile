FLAGS					= -Wall -Wextra -Werror 
CC						= cc
RM						= rm -rf
NAME					= philo_bonus
HEAD					= philo_bonus.h


SRC						= philo_bonus.c tools/utilis_bonus.c tools/error_msg_bonus.c tools/routine_bonus.c tools/cleanup_bonus.c tools/create_philo_bonus.c tools/exec_philo_bonus.c tools/monitoring_bonus.c tools/parsing_bonus.c
S_OBJ					= ${SRC:.c=.o} 

all:					${NAME}

#-g -fsanitize=address
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