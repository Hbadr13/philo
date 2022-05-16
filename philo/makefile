NAME = philo
SRC = main.c init_philo.c libft.c philo_util.c

OBJ = ${SRC:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERS = philosophers.h

GREEN  = \033[1;32m
YELLOW = \033[1;33m

all : $(NAME)

%.o:%.c  $(HEADERS)
	@$(CC) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "$(GREEN)---> success!"
clean :
	@rm -f $(OBJ)
	@echo "${YELLOW}---> object files deleted!"

fclean : clean
	@rm -f $(NAME)
	@echo "${YELLOW}---> all deleted!"
re : fclean all