CC=gcc
#CFLAGS= -Wall -Wextra -Werror
LIB_PATH=libft
INC=includes
INC_PATH= ./$(LIB_PATH)/$(INC)
NAME= ft_select
LIB_PATH= libft
BIN_PATH= bin

SRC_M_SELECT_PATH=m_select

SRC_PATH=srcs
OBJ_PATH=srcs

#################################################
### COLOR
##################################################
COL_BLACK	= \033[1;30m
COL_RED		= \033[1;31m
COL_GREEN	= \033[1;32m
COL_YELLOW	= \033[1;33m
COL_BLUE	= \033[1;34m
COL_PURPLE	= \033[1;35m
COL_WHITE	= \033[1;37m

######
## SOURCES
######

SRC_M_SELECT = ft_parse_argv_to_tlist.c ft_tlist_parse_select_str.c\
		ft_tlist_del.c ft_tlist_del_elem.c ft_init_term.c ft_tlist_display.c\
		ft_applied_basic_capa_str.c\
		ft_term_begin_soulign.c ft_term_end_soulign.c ft_term_invisible_cursor.c\
		ft_term_get_weight.c ft_term_get_height.c\
		ft_tlist_s_display.c ft_term_clear.c\
		ft_found_code_key.c ft_manage_keyboard_event.c\
		ft_one_line_display_is_valid.c\
		ft_catch_sg.c ft_init_sg.c\
		ft_reset_term.c


SRC_M_S=$(addprefix ./$(SRC_M_SELECT_PATH)/, $(SRC_M_SELECT))

#####
## OBJ
#####

OBJ_M_SELECT= $(patsubst %.c, %.o, $(SRC_M_SELECT))
OBJ_M_S= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_SELECT))

######
## RULES
#####

all: $(NAME)

$(NAME): lib $(OBJ_M_S)
	gcc -c main.c -I $(INC) -I $(INC_PATH)
	$(CC) $(CFLAGS) main.o $(OBJ_M_S) -ltermcap -I $(INC) -I $(INC_PATH) -L $(LIB_PATH) -lft -o $(NAME)

$(OBJ_M_S): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_SELECT_PATH)%.c
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

lib:
	@cd $(LIB_PATH) && make

clean: cleanlib
	@rm -rf $(OBJ_ALL) main.o

cleanlib:
	@cd $(LIB_PATH) && make clean
	@echo "$(COL_WHITE)[ CLEAN LIBFT ]\n"

fclean: fcleanlib clean
	@rm -rf $(NAME)

fcleanlib: cleanlib
	@cd $(LIB_PATH) && make fclean
	@echo "$(COL_WHITE)[ FCLEAN LIBFT ]\n"

re: fclean all
