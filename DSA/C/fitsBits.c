#include <stdio.h>

int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);   // 32 - n
    return !(((x << shift) >> shift) ^ x);
}

int main() {
    printf("%d\n", fitsBits(5, 3));   // 0
    printf("%d\n", fitsBits(-4, 3));  // 1
    return 0;
}