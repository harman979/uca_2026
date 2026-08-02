#include <stdio.h>

int isPower2(int x) {
    return !(x & (x + ~0)) & !!x & !(x >> 31);
}

int main() {
    printf("%d\n", isPower2(5)); 
    printf("%d\n", isPower2(8));  
    printf("%d\n", isPower2(0));  
    printf("%d\n", isPower2(-8)); 
    return 0;
}