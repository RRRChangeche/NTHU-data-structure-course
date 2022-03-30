// #include <cstdio>
#include <stdio.h>

int main(){
    int* x = (int*) malloc (sizeof(int));
    free(x);

    return 0;
}