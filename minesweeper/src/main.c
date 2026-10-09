#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>


#define WIDTH 20
#define HEIGHT 10


typedef struct {
    int x;
    int y;
} Cursor;

enum {
    BOMB = -1,
    EMPTY = 0,
    BOMB_COUNT = 10,
};

enum {
    NO_FLAG = 0,
    FLAGGED = 1,
    UNCOVERED = 2,
};


static struct termios original_state;

void reset_color() {
    fputs("\x1b[0m", stdout);
}

void clear_screen() {
    reset_color();
    fputs("\x1b[2J", stdout);
    fflush(stdout);
}

void hide_cursor() {
    fputs("\x1b[?25l", stdout);
    fflush(stdout);
}

void show_cursor() {
    fputs("\x1b[?25h", stdout);
    fflush(stdout);
}

void set_border_color() {
    fputs("\x1b[0;38;5;196;48;5;227m", stdout);
}

void move_to(int x, int y) {
    printf("\x1b[%d;%dH", y+1, x+1);
}

void draw_flag(int x, int y) {
    fputs("\x1b[0;38;5;196;48;5;159m", stdout);
    move_to(x, y);
    putchar('?');
}

void draw_bomb(int x, int y) {
    fputs("\x1b[0;38;5;16;48;5;196m", stdout);
    move_to(x, y);
    putchar('*');
}

void draw_empty(int x, int y) {
    fputs("\x1b[0;38;5;159;48;5;159m", stdout);
    move_to(x, y);
    putchar(' ');
}

void draw_unknown(int x, int y) {
    fputs("\x1b[0;38;5;252;48;5;252m", stdout);
    move_to(x, y);
    putchar(' ');
}

void draw_count(int x, int y, int count) {
    const char* colors[] = {
        "\x1b[0;38;5;159;48;5;159m",
        "\x1b[0;38;5;27;48;5;159m",
        "\x1b[0;38;5;57;48;5;159m",
        "\x1b[0;38;5;129;48;5;159m",
        "\x1b[0;38;5;165;48;5;159m",
        "\x1b[0;38;5;164;48;5;159m",
        "\x1b[0;38;5;163;48;5;159m",
        "\x1b[0;38;5;161;48;5;159m",
        "\x1b[0;38;5;160;48;5;159m"
    };

    fputs(colors[count], stdout);
    move_to(x, y);
    putchar(count + '0');
}

void draw_cursor_cell(int x, int y, char c) {
    fputs("\x1b[0;38;5;16;48;5;214m", stdout);
    move_to(x, y);
    putchar(c);
}

void draw_pixel(int x, int y) {
    move_to(x, y);
    putchar(' ');
    fflush(stdout);
}


struct termios get_termios_state() {
    struct termios state;
    tcgetattr(STDIN_FILENO, &state);

    return state;
}

void set_termios_state(struct termios* state) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, state);
}

void reset_termios_state() {
    set_termios_state(&original_state);
    show_cursor();
    // clear_screen();
}

void enable_raw_mode() {
    struct termios state = original_state;
    state.c_oflag &= ~((tcflag_t)OPOST);
    state.c_lflag &= ~((tcflag_t)ECHO | (tcflag_t)ICANON);
    set_termios_state(&state);

    hide_cursor();
}

void termios_setup() {
    original_state = get_termios_state();
    enable_raw_mode();
    atexit(&reset_termios_state);
}


void setup() {
    srand((unsigned int)time(NULL));
    termios_setup();
}


void generate_bombs(int field[]) {
    int bombs = BOMB_COUNT;

    while (bombs > 0) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        if (field[y*WIDTH + x] != BOMB) {
            field[y*WIDTH + x] = BOMB;
            --bombs;
        }
    }
}


int has_bomb(int field[], int x, int y) {
    if (x < 0 || x >= WIDTH) {
        return 0;
    }
    if (y < 0 || y >= HEIGHT) {
        return 0;
    }
    return field[y*WIDTH + x] == BOMB;
}


int count_surrounding_bombs(int field[], int x, int y) {
    int count = 0;

    for (int dy = -1; dy < 2; ++dy) {
        for (int dx = -1; dx < 2; ++dx) {
            if (dy == 0 && dx == 0) {
                continue;
            }
            count += has_bomb(field, x+dx, y+dy);
        }
    }

    return count;
}


void count_bombs_in_field(int field[]) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (field[y*WIDTH + x] != BOMB) {
                field[y*WIDTH + x] = count_surrounding_bombs(field, x, y);
            }
        }
    }
}


void generate_playing_field(int field[]) {
    generate_bombs(field);
    count_bombs_in_field(field);
}


void draw_vline(int x, int y, int length) {
    for (int dy = 0; dy < length; ++dy) {
        draw_pixel(x, y+dy);
    }
}

void draw_hline(int x, int y, int length) {
    for (int dx = 0; dx < length; ++dx) {
        draw_pixel(x+dx, y);
    }
}


void draw_border() {
    set_border_color();
    draw_hline(0, 0, WIDTH + 2);
    draw_hline(0, HEIGHT+1, WIDTH + 2);
    draw_vline(0, 0, HEIGHT + 2);
    draw_vline(WIDTH+1, 0, HEIGHT + 2);
}

void draw_cursor(int field[], int flags[], Cursor cursor) {
    int x = cursor.x;
    int y = cursor.y;
    int dx = cursor.x+1;
    int dy = cursor.y+1;

    char c = ' ';

    if (flags[y*WIDTH + x] == UNCOVERED) {
        if (field[y*WIDTH + x] == BOMB) {
            c = '*';
        } else {
            c = (char)field[y*WIDTH + x] + '0';
        }
    } else if (flags[y*WIDTH + x] == FLAGGED) {
        c = '?';
    }

    draw_cursor_cell(dx, dy, c);
}

void draw_cell(int field[], int flags[], Cursor cursor, int x, int y) {

    if (x == cursor.x && y == cursor.y) {
        draw_cursor(field, flags, cursor);
        return;
    }

    int dx = x+1;
    int dy = y+1;


    if (flags[y*WIDTH + x] == FLAGGED) {
        draw_flag(dx, dy);
        return;
    }

    if (flags[y*WIDTH + x] == UNCOVERED) {

        if (field[y*WIDTH + x] == BOMB) {
            draw_bomb(dx, dy);
        } else {
            draw_count(dx, dy, field[y*WIDTH + x]);
        }

        return;
    }

    draw_unknown(dx, dy);
}


void draw_field(int field[], int flags[], Cursor cursor) {
    clear_screen();
    draw_border();

    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            draw_cell(field, flags, cursor, x, y);
        }
    }

    fflush(stdout);
}


void uncover_all(int flags[]) {
    for (int i = 0; i < WIDTH*HEIGHT; ++i) {
        if (flags[i] == NO_FLAG) {
            flags[i] = UNCOVERED;
        }
    }
}


int max(int x, int y) {
    if (x > y) {
        return x;
    }
    return y;
}

int min(int x, int y) {
    if (x < y) {
        return x;
    }
    return y;
}


void uncover(int field[], int flags[], Cursor cursor) {
    int x = cursor.x;
    int y = cursor.y;

    if (x < 0 || x >= WIDTH) {
        return;
    }
    if (y < 0 || y >= HEIGHT) {
        return;
    }

    if (flags[y*WIDTH + x] == FLAGGED || flags[y*WIDTH + x] == UNCOVERED) {
        return;
    }

    flags[y*WIDTH + x] = UNCOVERED;

    if (field[y*WIDTH + x] == EMPTY) {
        uncover(field, flags, (Cursor){ x+1, y });
        uncover(field, flags, (Cursor){ x-1, y });
        uncover(field, flags, (Cursor){ x, y+1 });
        uncover(field, flags, (Cursor){ x, y-1 });
    }
}


void flag(int flags[], Cursor cursor) {
    int x = cursor.x;
    int y = cursor.y;

    if (flags[y*WIDTH + x] == UNCOVERED) {
        return;
    }

    int flag = FLAGGED;

    if (flags[y*WIDTH + x] == FLAGGED) {
        flag = NO_FLAG;
    }

    flags[y*WIDTH + x] = flag;
}

void end_game(int success) {
    const char* text[] = {
        "Defeat\r\n",
        "Victory\r\n"
    };

    const char* color[] = {
        "\x1b[0;38;5;196;48;5;220m",
        "\x1b[0;38;5;16;48;5;123m"
    };

    int len = (int)strlen(text[success]) - 2;

    int x = 0;
    int width = WIDTH + 2;

    if (len < width) {
        x = (width - len) / 2;
    }

    move_to(x, HEIGHT + 2 + 1);
    fputs(color[success], stdout);
    fputs(text[success], stdout);
}

void defeat() {
    end_game(0);
}

void victory() {
    end_game(1);
}


int count_left(int* flags) {
    int count = 0;

    for (int i = 0; i < WIDTH*HEIGHT; ++i) {
        if (flags[i] != UNCOVERED) {
            count += 1;
        }
    }

    return count;
}

int main() {
    setup();

    Cursor cursor = { .x = 0, .y = 0 };

    int field[WIDTH * HEIGHT] = { 0 };
    int flags[WIDTH * HEIGHT] = { 0 };
    generate_playing_field(field);

    draw_field(field, flags, cursor);

    int c = 0;

    while (1) {
        c = getchar();

        if (c == 'q') {
            return 0;
        } else if (c == 'w') {
            cursor.y = max(0, cursor.y - 1);
        } else if (c == 'a') {
            cursor.x = max(0, cursor.x - 1);
        } else if (c == 's') {
            cursor.y = min(HEIGHT-1, cursor.y + 1);
        } else if (c == 'd') {
            cursor.x = min(WIDTH-1, cursor.x + 1);
        } else if (c == '\n') {
            uncover(field, flags, cursor);

            if (field[cursor.y * WIDTH + cursor.x] == BOMB) {
                uncover_all(flags);
                defeat();
                break;
            }

            if (count_left(flags) == BOMB_COUNT) {
                victory();
                break;
            }

        } else if (c == ' ') {
            flag(flags, cursor);
        }

        draw_field(field, flags, cursor);
    }
}
