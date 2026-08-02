#include <stdio.h>

int sign(int x) {
    return (x >> 31) | (!!x);
}

int main() {
    printf("%d\n", sign(130));  
    printf("%d\n", sign(-23));   
    printf("%d\n", sign(0));     
    return 0;
}