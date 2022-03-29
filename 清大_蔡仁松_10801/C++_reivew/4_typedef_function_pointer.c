#include<stdio.h>

typedef int(*t_somefunc)(int, int);

int product(int u, int v){
    return u*v;
}

// t_somefunc afunc = &product;
t_somefunc afunc = &product;

int main(){

    printf("result = %d\n", afunc(3,5));
    return 0;
}