#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk mengecek apakah suatu posisi valid di dalam papan catur //
int isValidPosition(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

// Fungsi untuk memberi nilai 1 pada posisi yang dapat dicapai oleh bidak kuda //
void markPosition(int i, int j, int *chessBoard) {
    if (isValidPosition(i, j)) {
        chessBoard[i * 8 + j] = 1;
    }
}

// Fungsi untuk mensimulasikan pergerakan bidak kuda dalam sekali jalan //
void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Posisi yang mungkin dicapai oleh bidak kuda dalam sekali jalan //
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    // Menandai setiap posisi yang mungkin dicapai oleh bidak kuda //
    for (int k = 0; k < 8; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        markPosition(ni, nj, chessBoard);
    }
}

int main() {
    // Mendefinisikan array untuk papan catur berukuran 8x8 //
    int chessBoard[64] = {0};

    // Menerima input posisi bidak kuda
    int i, j;
    scanf("%d %d", &i, &j);

    // Mensimulasikan pergerakan bidak kuda //
    koboImaginaryChess(i, j, 8, chessBoard);

    // Mencetak papan catur setelah simulasi //
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            printf("%d", chessBoard[row * 8 + col]);
        }
        printf("\n");
    }

    return 0;
}