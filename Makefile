NAME		:=	philosophers
CC			:=	cc
FLAGS		:=	-Wall -Wextra -Werror -g -fsanitize=address

SOURCES_DIR	:=	sources/
SOURCES		:=	cleanup.c\
				errors.c\
				forks.c\
				main.c\
				parsing.c\
				printing.c\
				routine.c\
				setup_data.c\
				setup_input.c\
				setup_philo.c\
				time.c\
				utils.c\
				wip_todo_functions.c\

OBJECTS_DIR	:=	objects/
OBJECTS		:=	$(addprefix $(OBJECTS_DIR), $(SOURCES:.c=.o))
HEADER_DIR	:=	headers/
HEADERS		:=	-I $(HEADER_DIR)

all:		$(NAME)

$(NAME):	$(OBJECTS)
				$(CC) $(FLAGS) -o $@ $^ $(HEADERS) -lpthread

$(OBJECTS_DIR)%.o:	$(SOURCES_DIR)%.c
					@mkdir -p $(dir $@)
					$(CC) $(FLAGS) $(HEADERS) -c -o $@ $< -O3

clean:
			@rm -rf $(OBJECTS)

fclean:		clean
			@rm -rf $(NAME)
			@if [ -d "$(OBJECTS_DIR)" ]; then rm -drf $(OBJECTS_DIR); fi
			@echo Cleaned up all created files.

re:	fclean all

.PHONY:		all, clean, fclean, re
