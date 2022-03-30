// file: main.c
#include<stdio.h>
#include "3_extern_func.c"

int x = 100;

// static global only within a file 
static int size = 10;

int main(){

    func();
    return 0;
}