/*
    --> Program to sort the elements of an array using Bubble sort.
*/

/* Header Files */

#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */

void BubbleSort(int *, int); // Function to perform Bubble Sort
void PrintArray(int *, int); // Function to print array
void ScanArray(int *, int);  // Function to input array

/* Start of main() */

int main()
{
    system("cls");

    int size; // Variable to store size of array

    printf("Input size of array --> ");
    scanf("%d", &size);

    int *Array = (int *)calloc(size, sizeof(int)); // Memory allocation for array
    printf("\n");

    if (!Array) // Condition to check if memory is allocated or not
    {
        printf("Error in memory allocation... Returning...");
        printf("\n");

        return 0; // If memory is not allocated, terminate the program
    }

    printf("Input %d elements:\n", size);
    printf("\n");

    ScanArray(Array, size); // Function call to input elements of array
    printf("\n");

    printf("Sorting array in ascending order...");
    system("pause");

    printf("\n");
    BubbleSort(Array, size); // Function call to sort array elements using bubble sort

    printf("\n");
    printf("The sorted array is as shown below:\n");

    PrintArray(Array, size); // Function call to print final sorted array

    printf("\n");
    return 0;

    /* End of program */
}

/* Function definitions */

void BubbleSort(int *Array, int size) // Function to perform bubble sort
{
    int swap;

    // Outer loop to iterate all elements of array
    for (int i = 0; i < size; i++)
    {
        // Inner loop iterate and compare each element with next element
        for (int j = 0; j < ((size - 1) - i); j++)
        {
            // If current element is greater than the next element, settle current elememt downwards
            if (Array[j] > Array[j + 1])
            {
                // Settle greater element downwards by swapping the values
                swap = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = swap;
            }
        }

        /* Printing array after each iteration of comparision */

        printf("After iteration %d, array is\t--> ", (i + 1));
        PrintArray(Array, size); // Function call to print array

        fflush(stdin);
        getchar();
    }

    return;
}

void PrintArray(int *Array, int size) // Function to print array
{
    printf("%d", Array[0]);

    //Loop to print elements of array
    for (int i = 1; i < size; i++)
    {
        printf(",  %d", Array[i]);
    }

    return;
}

void ScanArray(int *Array, int size) // Function to input array
{
    //Loop to input elements of array
    for (int i = 0; i < size; i++)
    {
        printf("Element %d\t--> ", (i + 1));
        scanf("%d", (Array + i));
    }

    printf("\n");
    return;
}