#
#
CC			= 	cc -g
CFLAGS		= 	 -Wall -Wextra -Werror -fsanitize=address
RM			= 	/bin/rm -f
NAME		= 	push_swap
INCLUDES	= 	-I include/

#COLORS                                                                         
GREEN = \033[1;32m
RED = \033[1;31m
ORANGE = \033[38;5;208m
DEFAULT = \033[0m
YELLOW = \033[1;33m

SRCS = $(wildcard source/*.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@echo
	@make -s -C ./libft/
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "$(GREEN) Your $(ORANGE)$(NAME)(GREEN)is done!$(DEFAULT)"

clean:
	@make clean -s -C ./libft/
	@$(RM) $(OBJS)
	@echo "\$(RED)Object Files are gone$(DEFAULT)"

fclean: clean
	@make fclean -s -C ./libft/
	@$(RM) $(NAME)
	@echo "$(RED)Push_swap executable no longer existes$(DEFAULT)"

re: fclean all

watch:
	@printf "Watching files..\n"
	@while true; do $(MAKE) -q --no-print-directory || $(MAKE) --no-print-directory; sleep 2; done;

.PHONY: all re clean fclean