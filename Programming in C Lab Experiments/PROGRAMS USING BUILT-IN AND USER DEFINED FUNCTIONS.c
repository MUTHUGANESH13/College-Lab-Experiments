#include<stdio.h>
int sumTwoNum(int, int);
float averageTwoNum(int, int);
int main() {
    int number1, number2;
    int sum;
    float avg;
    printf("Enter the first integer number:\n");
    scanf("%d", &number1);
    printf("Enter the second integer number: ");
    scanf("%d", &number2);
    sum = sumTwoNum(number1, number2);
    avg = averageTwoNum(number1, number2);
    printf("Number1: %d, Number2: %d\n", number1, number2);
    printf("Sum: %d, Average: %f\n", sum, avg);
    return 0;
}
int sumTwoNum(int x, int y) {
    return x + y;
}
float averageTwoNum(int x, int y) {
    return (float)(x + y) / 2;
}
