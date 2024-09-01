#include<stdio.h>
void main() {
    FILE *fp;
    char ch;
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("File opening problem\n");
        return;
    }
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}
