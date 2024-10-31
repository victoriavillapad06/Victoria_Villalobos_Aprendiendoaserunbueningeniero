//
// Created by victo on 31/10/2024.
//
#include <stdio.h>

#define NUM_TECLAS 10


int movimientos[NUM_TECLAS][4] = {
    {4, 6, -1, -1},   // 0
    {6, 8, -1, -1},   // 1
    {7, 9, -1, -1},   // 2
    {4, 8, -1, -1},   // 3
    {3, 9, 0, -1},    // 4
    {-1, -1, -1, -1}, // 5
    {1, 7, 0, -1},    // 6
    {2, 6, -1, -1},   // 7
    {1, 3, -1, -1},   // 8
    {2, 4, -1, -1}    // 9
};


long long contar_movimientos(int n) {
    long long dp[NUM_TECLAS], nuevo_dp[NUM_TECLAS];


    for (int i = 0; i < NUM_TECLAS; i++) {
        dp[i] = 1;
    }


    for (int m = 0; m < n; m++) {

        for (int i = 0; i < NUM_TECLAS; i++) {
            nuevo_dp[i] = 0;
        }


        for (int i = 0; i < NUM_TECLAS; i++) {
            for (int j = 0; movimientos[i][j] != -1; j++) {
                nuevo_dp[i] += dp[movimientos[i][j]];
            }
        }

        for (int i = 0; i < NUM_TECLAS; i++) {
            dp[i] = nuevo_dp[i];
        }
    }


    long long total = 0;
    for (int i = 0; i < NUM_TECLAS; i++) {
        total += dp[i];
    }

    return total;
}

int main() {
    int n;


    printf("Introduce la cantidad de movimientos: ");
    scanf("%d", &n);

    long long resultado = contar_movimientos(n);


    printf("La cantidad de posibilidades válidas para %d movimientos es: %lld\n", n, resultado);

    return 0;
}