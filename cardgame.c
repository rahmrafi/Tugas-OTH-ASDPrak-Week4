#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk mengimplementasikan nilai kartu yaitu J, Q, K //
int compare(const void *a, const void *b) {
    char cardA = *(char *)a;
    char cardB = *(char *)b;
    char order[] = "123456789JQK";

    int indexA = strchr(order, cardA) - order;
    int indexB = strchr(order, cardB) - order;

    return indexA - indexB;
}

// Selection sort untuk mengurutkan kartu //
int sortCards(int n, char cards[]) {
    int steps = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (compare(&cards[j], &cards[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            char temp = cards[i];
            cards[i] = cards[minIndex];
            cards[minIndex] = temp;
            steps++;
            // Menampilkan setiap pertukaran yang terjadi //
            printf("Pertukaran %d: ", steps);
            for (int k = 0; k < n; k++) {
                printf("%c ", cards[k]);
            }
            printf("\n");
        }
    }
    return steps;
}

int main() {
    int n;
    // Inputan jumlah kartu //
    printf("");
    scanf("%d", &n);

    char cards[n];
    // Memasukkan kartu //
    printf("");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &cards[i]);
    }

    int steps = sortCards(n, cards);

    // Mencetak kartu yang telah diurutkan //
    printf("Jumlah langkah untuk mengurutkan kartu : %d\n", steps);
    printf("Urutan kartu setelah diurutkan : ");
    for (int i = 0; i < n; i++) {
        printf("%c ", cards[i]);
    }
    printf("\n");

    return 0;
}