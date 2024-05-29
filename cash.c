#include <stdio.h>
#include <cs50.h>

int main(void) {
    int change;

    do {
        change = get_int("Change owed: ");
    } while (change < 0);

    int coins = 0;

    int coin_values[] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++) {
        coins += change / coin_values[i];

        change %= coin_values[i];
    }
    printf("%d\n", coins);

    return 0;
}
