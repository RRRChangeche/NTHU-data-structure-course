#include<stdio.h>

void func(void);

// static int count = 5;
int count = 5;

int main(){
    while(count--){
        func();
    }

    return 0;
}

void func( void ){
    // int i = 5;
    static int i = 5;
    i++;
    printf("i is %d, and count is %d\r\n", i, count);
}