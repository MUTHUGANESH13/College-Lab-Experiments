#include<stdio.h>
struct student {
    char name[20];
    int marks[5];
    int tot;
    float avg;
};
void main() {
    struct student s1;
    int total = 0, i;
    printf("Enter the name of the student:\n");
    scanf("%s", s1.name);
    printf("Enter the marks of the student:\n");
    for(i = 0; i < 5; i++) {
        printf("Mark%d: ", i + 1);
        scanf("%d", &s1.marks[i]);
        total += s1.marks[i];
    }
    s1.tot = total;
    s1.avg = (float)total / 5;
    printf("\nStudent Name: %s\n", s1.name);
    printf("English Marks: %d\n", s1.marks[0]);
    printf("Maths Marks: %d\n", s1.marks[1]);
    printf("Physics Marks: %d\n", s1.marks[2]);
    printf("Chemistry Marks: %d\n", s1.marks[3]);
    printf("Biology Marks: %d\n", s1.marks[4]);
    printf("\nTotal marks: %d\n", s1.tot);
    printf("Average: %f\n", s1.avg);
}
