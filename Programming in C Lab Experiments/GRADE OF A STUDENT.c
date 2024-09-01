#include <stdio.h>
#include <conio.h>
void main() {
    int rollno;
    float m1, m2, m3, m4, m5, m6, avg;
    char name[100], grade;
    clrscr();
    printf("Enter your Roll Number: ");
    scanf("%d", &rollno);    
    printf("Enter your Name: ");
    scanf("%s", name);
    printf("Hi %s, Enter the marks in six subjects: ", name);
    scanf("%f %f %f %f %f %f", &m1, &m2, &m3, &m4, &m5, &m6);
    avg = (m1 + m2 + m3 + m4 + m5 + m6) / 6;    
    if (avg == 100.0f)
        grade = 'S';
    else if (avg > 90.0f)
        grade = 'A';
    else if (avg > 75.0f)
        grade = 'B';
    else if (avg > 60.0f)
        grade = 'C';
    else if (avg >= 50.0f)
        grade = 'D';
    else
        grade = 'F';
    printf("RollNo\tName\tM1\tM2\tM3\tM4\tM5\tM6\tAVG\tGrade\n");
    printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%c",rollno, name, m1, m2, m3, m4, m5, m6, avg, grade);
    getch();
}
