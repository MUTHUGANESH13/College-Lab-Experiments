#include<stdio.h>
#include<conio.h>
int i = 10; // global variable
void fun() {
    static int k = 0;
    int z = 0;
    k++;
    z++;
    printf("k=%d z=%d\n", k, z);
    i = i + 10;
    printf("i=%d\n", i); // global variable accessible here
}
void main() {
    int j = 20; // auto variable
    fun();
    fun();
    fun();
    printf("j=%d\n", j);
    printf("i=%d\n", i);
}
