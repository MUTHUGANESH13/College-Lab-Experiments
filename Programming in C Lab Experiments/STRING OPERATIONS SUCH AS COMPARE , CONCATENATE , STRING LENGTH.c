#include<string.h>
#include<stdlib.h>
#include<stdio.h>
void com2str(char str1[100], char str2[100]);
void concat2str(char str1[100], char str2[100]);
void length(char str[100]);
int main() {
    int ch;
    char s1[100], s2[100];
    printf("Enter a first string: ");
    scanf("%s", s1);
    printf("Enter a second string: ");
    scanf("%s", s2);
    printf("The length of first string: ");
    length(s1);
    printf("\nThe length of second string: ");
    length(s2);
    printf("\nResults of two strings compare: ");
    com2str(s1, s2);
    printf("Results After concatenation of two strings: ");
    concat2str(s1, s2);
    getchar();
}
void com2str(char str1[100], char str2[100]) {
    if (strcmp(str1, str2) == 0)
        printf("Both the strings are equal\n");
    else
        printf("Both the strings are not equal\n");
}
void concat2str(char str1[100], char str2[100]) {
    strcat(str1, str2);
    printf("%s\n", str1);
}
void length(char str1[100]) {
    int x;
    x = strlen(str1);
    printf("%s = %d", str1, x);
}
