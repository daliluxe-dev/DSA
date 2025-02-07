#include <stdio.h>
int main() {
    int i;
    int index=4;
    int marks[] = {1, 2, 3, 4, 5};
    int SIZE = sizeof(marks) / sizeof(marks[0]);

    printf("Traversing the elemnts in the array: \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d \n", marks[i]);
    }

    printf("Inserting the elements in the array: \n");
    for (i = SIZE; i > index; i--) //this is for shifting the elements to the right
    {
        marks[i]=marks[i-1];
    }


    marks[index]= 5; //inserting the new element at index 4
    SIZE++; //making space in the array since we're adding an element
    

    //printing or traversing the array after insertion
    for (i = 0; i < SIZE; i++)
    {
        printf("%d \n", marks[i]);
    }

    return 0;
}
