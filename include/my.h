/*
** EPITECH PROJECT, 2022
** my
** File description:
** header
*/

#ifndef MY
    #define MY
    #include <stdarg.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    #define EVENT(the_button, texture) {\
        sfSprite_setTexture(the_button.button, texture, sfTrue);\
    }
    #define KP(key) sfKeyboard_isKeyPressed(key)

    int my_strncmp(char *str, char *cmp, int lim);
    char **my_str_to_word_array(char *str, char limiter);
    int my_strlen(char *str);
    char *my_str_dup(char *str);
    size_t my_getnbr(char *str);
    char *my_int_to_str(size_t num);
    char *load_file_in_mem(char const *filepath);

    typedef struct list_node_s {
        sfSprite *object;
        int luck_st;
        int atk_st;
        int def_st;
        int life_st;
        sfTexture *object_tex;
        struct list_node_s *next;
        struct list_node_s *prev;
    } list_node_t;

    typedef struct list_npc_s {
        sfSprite *npc;
        sfVector2f coords;
        char *npc_text;
        sfIntRect rect;
        struct list_npc_s *next;
        struct list_npc_s *prev;
    } list_npc_t;

    typedef struct list_s {
            list_node_t *head;
            list_node_t *tail;
            unsigned int size;
    } list_t;

    typedef struct nlist_s {
            list_npc_t *head;
            list_npc_t *tail;
            unsigned int size;
    } nlist_t;

    list_t *list_create(void);

    nlist_t *nlist_create(void);

    unsigned int list_add(list_t *list, void *value);

    unsigned int list_add_npc(nlist_t *list, sfSprite *sprite,
    sfVector2f coords, char *text);

    sfSprite *list_get(list_t *list, unsigned int index);

    list_node_t *list_get_node(list_t *list, unsigned int index);

    void list_remove(list_t *list, unsigned int index);

    void create_objects(list_t *object_list);
    void show_objects(sfRenderWindow *window,
    sfSprite* inventory, list_t* object_list);

    enum mob_db {
        GOBLIN = 0,
        GOLEM,
        HOBGOBLIN,
        SLIMEBALL,
        SLIME,
        DEMON,
        DEVIL,
        ORC,
        GHOST,
        GOBLINKING,
        NECROMANCER,
        SKELETON,
        WARLOCK,
        FUNGUS,
        GNOME,
        TROLL
    };

    typedef struct mob_s {
        sfSprite *mob;
        sfTexture *mob_text;
        sfIntRect rect;
        sfVector2f coords;
        int offset;
        int val_max;
        char *sheet;
        int hp;
        int atk;
        int def;
        int lck;
    } mob_t;

    typedef struct node_mob_s {
        struct mob_s c_mob;
        struct node_mob_s *next;
        struct node_mob_s *prev;
    } node_mob_t;

    typedef struct list_mob_s {
            node_mob_t *head;
            node_mob_t *tail;
            unsigned int size;
    } list_mob_t;

    typedef struct npc_s {
        sfSprite *npc;
        sfTexture *npc_text;
        sfIntRect rect;
        int offset;
        int val_max;
        char *sheet;
        sfVector2f coords;
    } npc_t;

    typedef struct object_s {
        sfSprite *object;
        int luck_st;
        int atk_st;
        int def_st;
        int life_st;
        sfTexture *object_tex;
    } object_t;

    typedef struct player_stat_s {
        size_t pv;
        sfText *pv_t;
        size_t att;
        sfText *att_t;
        size_t def;
        sfText *def_t;
        size_t lck;
        sfText *lck_t;
        size_t xp;
        sfText *xp_t;
        size_t lvl;
        sfText *lvl_t;
        size_t max_pv;
        char *file_path;
        int status;
    } player_stat_t;

    typedef struct player_s {
        sfSprite *player;
        sfImage *map_colliosions;
        sfTexture *player_text;
        sfIntRect rect;
        sfView *view;
        bool is_near;
        sfVector2f pos;
        int offset;
        int val_max;
        char *sheet;
        int health;
    } player_t;

    typedef struct inventory_s {
        sfSprite *inv;
        sfTexture *inv_text;
        bool is_open;
    } inventory_t;

    enum e_giu_state {
        NONE = 0,
        HOVER,
        PRESSED,
        RELEASED
    };

    typedef struct button_s {
        sfSprite *button;
        sfRectangleShape *rect;
        sfSprite *text;
        sfTexture *text_t;
        sfVector2f pos;
        sfVector2f size;
        sfBool (*is_clicked)(struct button_s, sfMouseButtonEvent*);
        sfBool (*is_hover)(struct button_s, sfMouseMoveEvent*);
        enum e_giu_state state;
    } button_t;

    enum action {
        ATK = 0,
        DEF,
        NOTHING
    };

    typedef struct combat_s {
        sfSprite *back;
        sfTexture *back_tex;
        sfTexture *coll_tex;
        sfTexture *b_none;
        sfTexture *b_hover;
        sfTexture *b_pressed;
        mob_t *mob;
        button_t fight;
        button_t shield;
        bool is_combat;
        bool player_turn;
        enum action player_a;
        enum action mob_a;
    } combat_t;

    typedef struct npc_text_s {
        sfRectangleShape *bulle;
        sfFont *font;
        sfText *text;
    } npc_text_t;

    typedef struct page_s {
        sfRenderWindow *window;
        sfSprite *back;
        sfTexture *back_tex;
        sfTexture *coll_tex;
        sfTexture *end;
        sfTexture *game_over;
        sfSprite *name;
        sfTexture *name_t;
        sfEvent event;
        sfClock *clock;
        sfTime time;
        float seconds;
        sfVector2i cursor_coords;
        sfVector2f save_pos;
        sfVector2u win_size;
        bool is_won;
        bool is_lost;
    } page_t;

    typedef struct settings_s {
        sfTexture *b_none;
        sfTexture *b_hover;
        sfTexture *b_pressed;
        sfTexture *b_none_rect;
        sfTexture *b_hover_rect;
        sfTexture *b_pressed_rect;
        button_t b_plus;
        button_t b_minus;
        button_t b_return;
        bool is_open;
        int is_return;
    } settings_t;

    typedef struct menu_s {
        sfSprite *back;
        sfTexture *back_tex;
        sfTexture *b_none;
        sfTexture *b_hover;
        sfTexture *b_pressed;
        button_t b_start;
        button_t b_resume;
        button_t b_settings;
        button_t b_exit;
        bool is_open;
        int current_pos;
        settings_t settings;
    } menu_t;

    typedef struct controls_pan_s {
        sfSprite *pannel;
        sfTexture *pannel_tex;
        sfTexture *b_none;
        sfTexture *b_hover;
        sfTexture *b_pressed;
        button_t b_exit;
        sfText *left_key;
        sfText *up_key;
        sfText *right_key;
        sfText *down_key;
        sfText *title;
        sfText *exit_key;
        sfText *control_key;
        sfText *spacebar_key;
        sfText *inv_key;
        bool is_open;
    } controls_pan_t;

    typedef struct score_s {
        sfText *t_score;
        sfFont *font;
        int i_score;
    } score_t;

    typedef struct all_s {
        page_t scene;
        player_t play;
        inventory_t inv;
        player_stat_t player_stat;
        list_t *object_list;
        nlist_t *npc_list;
        list_npc_t *npc_all;
        combat_t combat;
        list_mob_t *mobs;
        npc_text_t npc_text;
        controls_pan_t controls;
        menu_t menu;
        score_t score;
        int status;
        bool new_game;
    } all_t;

    void flag_h(void);

    all_t create_all(all_t all);
    int checker_assets(all_t *all);
    page_t create_scene(void);
    player_t create_player(page_t page);
    inventory_t create_inventory(inventory_t inv);
    player_stat_t get_stat(player_stat_t play_stat, char *path);
    controls_pan_t create_controls_pannel(controls_pan_t pannel);
    void create_view(player_t *player, sfRenderWindow *window);
    combat_t create_combat(combat_t combat);
    mob_t create_mob(sfVector2f pos, char *text, int max);
    npc_t create_npc(npc_t npc, sfVector2f coords, char *sheet);
    list_mob_t *create_all_mobs(void);

    sfIntRect create_rect(sfIntRect rect, int offset);

    all_t game_loop(all_t all);
    all_t inventory_loop(all_t all);

    all_t do_events(all_t all);
    void close_window(sfRenderWindow *window);

    void animate_player(all_t *all, player_t *player);
    void animate_mob(list_mob_t *mobs);
    void animate_npc(list_npc_t *npc);

    bool is_moving(sfEvent event);

    void idle_animation(player_t *player);
    void move(player_t *player);

    all_t display(all_t all);
    void reload_map(all_t all);
    void display_mobs(all_t all, list_mob_t *mobs);
    void destroy(all_t all);

    int obs_left(player_t *player);
    int obs_right(player_t *player);
    int obs_up(player_t *player);
    int obs_down(player_t *player);

    void set_view(player_t *player, sfRenderWindow *window);

    score_t create_score(void);
    void display_score(all_t *all);

    all_t is_npc_clicked(all_t all, nlist_t* npc_list);

    list_mob_t *create_mob_list(void);
    unsigned int add_mob(list_mob_t *list, mob_t value);
    mob_t list_get_mob(list_mob_t *list, unsigned int index);
    node_mob_t *list_get_the_mob_node(list_mob_t *list, unsigned int index);
    void list_mob_remove(list_mob_t *list, unsigned int index);

    all_t combat_loop(all_t all);

    all_t combat_events(all_t all);
    void fight_button_hover(all_t *all);
    void shield_button_hover(all_t *all);

    void exit_combat_scene (all_t *all);
    void set_combat_scene(all_t *all, mob_t *mob);

    void fight(all_t *all);
    void shield(all_t *all);

    void atk_atk(all_t *all);
    void atk_def(all_t *all);
    void def_atk(all_t *all);
    void def_def(all_t *all);

    void show_stat_inv(player_stat_t *stat, sfRenderWindow *window,
sfSprite *inventory);
    void display_att(sfText *att_t, sfRenderWindow *window,
sfSprite *inventory, sfFont *font);
    void display_def(sfText *def_t, sfRenderWindow *window,
sfSprite *inventory, sfFont *font);
    void display_lck(sfText *def_t, sfRenderWindow *window,
sfSprite *inventory, sfFont *font);

    void display_controls(sfRenderWindow *window, controls_pan_t controls);
    void display_left_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font);
    void display_inv_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font);
    void display_spacebar_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font);
    void display_down_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font);
    void display_up_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font);
    void display_title_control(controls_pan_t controls, sfRenderWindow *window,
sfFont *font);
    void display_c_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font);
    void display_exit_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font);

    void update_stat(player_stat_t *player_stat);
    void save_stat(player_stat_t *play_stat);

    all_t create_npc_texte(all_t all, sfSprite *npc, char* dialogue);
    all_t destroy_npc_texte(all_t all);
    all_t get_pos_player(all_t all);
    void destroy_stat_txt(player_stat_t *player_stat);
    void destroy_controls_text(controls_pan_t controls);

    button_t create_button(sfVector2f position, sfVector2f size, char *text);
    menu_t create_menu(menu_t menu);
    void display_the_menu(sfRenderWindow *window, menu_t menu);

    all_t menu_events(all_t all);
    sfVector2f get_player_pos(void);

    void display_the_settings(sfRenderWindow *window, menu_t menu);
    menu_t create_settings(menu_t menu);
    all_t settings_loop(all_t all);
    all_t settings_events(all_t all);

    void end_game(all_t *all);
    void game_over(all_t *all);

#endif
