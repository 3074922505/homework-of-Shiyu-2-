//202610302223
//王诗喻

#include <stdio.h>

struct Window {
    int buffer[3];
    int count;
};

struct Window push_data(struct Window win, int val) {
    win.buffer[win.count % 3] = val;
    win.count++;
    return win;
}

int get_average(struct Window win) {
    int i;
    int sum = 0;
    int number;

    if (win.count < 3) {
        number = win.count;
    } else {
        number = 3;
    }

    for (i = 0; i < number; i++) {
        sum += win.buffer[i];
    }

    return sum / number;
}

int main(void) {
    struct Window win = {{0, 0, 0}, 0};
    int m, i, value;

    if (scanf("%d", &m) != 1 || m < 1 || m > 6) {
        return 0;
    }

    for (i = 0; i < m; i++) {
        if (scanf("%d", &value) != 1) {
            return 0;
        }

        win = push_data(win, value);

        if (i > 0) {
            printf(" ");
        }
        printf("%d", get_average(win));
    }

    printf("\n");
    return 0;
}
