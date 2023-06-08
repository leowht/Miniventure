##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile my_runner
##

ECHO = /bin/echo -e
DEFAULT = "\033[00m"
BOLD = "\e[1m"
RED = "\e[31m"
GREEN = "\e[32m"
LIGHT_BLUE = "\e[94m"
WHITE = "\e[1;37m"

SRC	=	lib/my/base/load_file_in_mem.c \
		lib/my/base/my_getnbr.c	\
		lib/my/base/my_int_to_str.c	\
		lib/my/base/my_strcpy.c	\
		lib/my/base/my_strdup.c	\
		lib/my/base/my_strlen.c	\
		lib/my/base/my_strncmp.c	\
		lib/my/base/my_str_to_word_array.c	\
		\
		lib/my/create/create_all_mobs.c \
		lib/my/create/create_all.c	\
		lib/my/create/create_combat.c	\
		lib/my/create/create_inventory.c	\
		lib/my/create/create_mob.c	\
		lib/my/create/create_npc.c	\
		lib/my/create/create_player.c	\
		lib/my/create/create_scene.c	\
		lib/my/create/create_score.c \
		lib/my/create/get_stat_player.c	\
		lib/my/create/create_text.c \
		lib/my/create/create_menu.c \
		lib/my/create/create_settings.c \
		lib/my/create/creates_control_pannel.c	\
		\
		lib/my/destroy/destroy.c	\
		lib/my/destroy/save_stat.c	\
		lib/my/destroy/get_pos_player.c	\
		lib/my/destroy/destroy_controls_text.c	\
		\
		lib/my/display/display_stat.c	\
		lib/my/display/display.c	\
		lib/my/display/display_score.c \
		lib/my/display/show_inventory_obj.c	\
		lib/my/display/show_stat.c	\
		lib/my/display/display_menu.c \
		lib/my/display/display_controls.c	\
		lib/my/display/display_each_controls.c	\
		lib/my/display/last_part_display_controls.c	\
		lib/my/display/reload_map.c	\
		\
		lib/my/event/analyse_events.c	\
		lib/my/event/close_window.c	\
		lib/my/event/combat_events.c	\
		lib/my/event/is_npc_clicked.c	\
		lib/my/event/menu_events.c \
		lib/my/event/settings_event.c \
		\
		lib/my/fight/combat_actions.c \
		lib/my/fight/combat_scene.c	\
		lib/my/fight/idle.c	\
		lib/my/fight/set_combat.c \
		lib/my/fight/update_stat.c	\
		\
		lib/my/list/list_add.c	\
		lib/my/list/list_create.c	\
		lib/my/list/list_get.c	\
		lib/my/list/list_remove.c	\
		\
		lib/my/loop/combat_loop.c	\
		lib/my/loop/game_loop.c	\
		lib/my/loop/inventory_loop.c	\
		\
		lib/my/mobs/create_mob_list.c \
		lib/my/mobs/list_mob_remove.c \
		\
		lib/my/on_map/animate_player.c	\
		lib/my/on_map/camera.c	\
		lib/my/on_map/collision_detector.c	\
		lib/my/on_map/is_moving.c	\
		lib/my/on_map/move.c	\
		\
		lib/my/start/end.c \
		lib/my/start/flag_h.c	\
		lib/my/start/main.c	\
		lib/my/start/file_checker.c	\
		lib/my/start/settings_menu.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	miniventure

CFLAGS	=	-Wall -Wextra -I include/

CSFMLF	=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFMLF) -lm

	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

debug:	CFLAGS += -g
debug:	re

re:	fclean all

tests_run:
		gcc -o unit_test $(SRC) -L . -lmy -lcriterion --coverage
		./unit_test

%.o:	%.c
	@$(CC) -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)" [OK] " \
	$(WHITE) || $(ECHO) -n $(BOLD) $(RED)" [KO] "$(WHITE) && $(ECHO) \
	$(BOLD) $< | rev | cut -d/ -f 1 | rev && $(ECHO) -n $(DEFAULT)
