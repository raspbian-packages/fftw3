#include <stdio.h>

int main(){
        int size_long_double = sizeof(long double);
        int size_double = sizeof(double);
        printf("size of long double is %d\n", size_long_double);
        printf("size of double is %d\n", size_double);
        if (size_long_double != size_double)
                return 1;
        return 0;
}
