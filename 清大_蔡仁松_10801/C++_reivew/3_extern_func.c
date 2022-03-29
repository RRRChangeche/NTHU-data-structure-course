// file: func.c
#include<stdio.h>

// auto global defined in other file 
extern int x;


void func(){
    printf("x = %d\n", x);
}