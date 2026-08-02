#include <stdio.h>

int bitXor(int x, int y) {
    return (~(~x & ~y)) & (~(x & y));
}

int main() {
    printf("%d\n", bitXor(4, 5));  // Output: 1
    return 0;
}