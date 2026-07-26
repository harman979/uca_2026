#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a = 1, b = 1;
    int sum = 0;

    while (a <= n) {
        if (a % 2 == 0)
            sum += a;

        int c = a + b;
        a = b;
        b = c;
    }

    printf("%d\n", sum);

    return 0;
}
