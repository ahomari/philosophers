FLAGS					= -Wall -Wextra -Werror 
CC						= cc
RM						= rm -rf
NAME					= philo
HEAD					= philo.h


SRC						= philo.c utilis1.c utilis2.c error_msg.c routine.c cleanup.c
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