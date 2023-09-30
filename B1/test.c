#include <stdio.h>

int main() {
    int n[5];
    int c[14] = {0}; // Array to count the frequency of each number
    int numbers = 5; // Number of integers to input

    for (;;) {
        fprintf(stderr, "整数を入力してください:");
        for (int i = 0; i < numbers; i++) {
            if (scanf("%d", &n[i]) == EOF) {
                return 0; // Exit program if EOF is reached
            }
            c[n[i]]++;
        }

        int hasFourOfAKind = 0;
        int hasFullHouse = 0;
        int hasThreeOfAKind = 0;
        int hasTwoPair = 0;
        int hasOnePair = 0;

        for (int i = 1; i <= 13; i++) {
            if (c[i] == 4) {
                hasFourOfAKind = 1;
            } else if (c[i] == 3) {
                hasThreeOfAKind = 1;
                for (int j = 1; j <= 13; j++) {
                    if (j != i && c[j] >= 2) {
                        hasFullHouse = 1;
                        break;
                    }
                }
            } else if (c[i] == 2) {
                if (hasOnePair) {
                    hasTwoPair = 1;
                } else {
                    hasOnePair = 1;
                }
            }
        }

        if (hasFourOfAKind) {
            printf("four of a kind\n");
        } else if (hasFullHouse) {
            printf("full house\n");
        } else if (hasThreeOfAKind) {
            printf("three of a kind\n");
        } else if (hasTwoPair) {
            printf("two pair\n");
        } else if (hasOnePair) {
            printf("one pair\n");
        } else {
            printf("no pair\n");
        }

        // Reset counts for the next hand
        for (int i = 1; i <= 13; i++) {
            c[i] = 0;
        }
    }

    return 0;
}
