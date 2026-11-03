//202610302223
//ÍõÊ«Ó÷

#include <stdio.h>

struct Player {
    char name[16];
    int score;
};

void sort_players(struct Player arr[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j].score < arr[j + 1].score) {
                struct Player temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    struct Player players[10];
    int n, i;

    if (scanf("%d", &n) != 1 || n < 1 || n > 10) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        if (scanf("%15s%d", players[i].name, &players[i].score) != 2) {
            return 0;
        }
    }

    sort_players(players, n);

    for (i = 0; i < n; i++) {
        printf("%d %s %d\n", i + 1, players[i].name, players[i].score);
    }

    return 0;
}
