#include <stdio.h>
struct person {
    int age;
    float weight;
};
int main() {
    struct person *personPtr, person1;
    personPtr = &person1;
    printf("Enter age: ");
    scanf("%d", &personPtr->age);
    printf("Enter weight: ");
    scanf("%f", &personPtr->weight);
    printf("Displaying:\n");
    printf("Age: %d\n", personPtr->age);
    printf("Weight: %.2f", personPtr->weight);
    return 0;
}
