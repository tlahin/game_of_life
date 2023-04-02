NAME = game

SRCS_DIR = srcs/
SRCS = main utilities gol

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS)))

FLAGS = -Wall -Wextra -Werror
INCLUDES = includes/
LIBFT = libft/libft.a

#COLORS:
GREEN := '\033[1;3;32m'
CYAN := '\033[2;3;36m'
RED := '\033[2;3;31m'
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo ${CYAN}"Compiling $(@)${RESET}"
	@gcc $(OBJS) $(LIBFT) -I $(INCLUDES) $(FLAGS) -o $@
	@echo ${GREEN}"Executable ($(NAME)) compiled successfully.${RESET}"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)gol.h $(LIBFT)
	@mkdir -p $(OBJS_DIR)
	@gcc -c $(FLAGS) -I $(INCLUDES) $< -o $@

$(LIBFT):

	@make -C libft/
	@echo ${GREEN}"Libft compiled successfully.${RESET}"

clean:
	@echo ${RED}"Removing object directory & files...${RESET}"
	@make clean -C libft/
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo ${RED}"Removing executables...${RESET}"
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@/bin/rm -f a.out

re: fclean all

.PHONY: all clean fclean re