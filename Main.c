#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *ptr;              // Pointer
    int NumOfElements = 5; // Num of elements in array
    printf("Number of elements: %d\n", NumOfElements);

    // Dynamically allocate memory
    ptr = (int *)calloc(NumOfElements, sizeof(int));
    // ^^^ sets size = (4 bytes) * times (number of elements)
    // ^^^ in this case -> 5 * 4 = 20 bytes allocated

    // Checks memory //
    if (ptr == NULL)
    { // exit if not done properly
        printf("Memory was not allocated!\n");
        exit(0);
    }

    else
    {
        printf("Memory has been allocated!\n");
        // numbers each element in array
        for (int index = 0; index < NumOfElements; ++index)
        {
            ptr[index] = index + 1;
        }

        // Print whole array
        printf("The elements of the array are: ");
        for (int index = 0; index < NumOfElements; ++index)
        {
            printf("%d ", ptr[index]);
        }

        // Get the new Num of elements to re-size the array
        NumOfElements = 10;
        printf("\n\nNew number of the array: %d\n", NumOfElements);
        // Dynamically re-allocate memory using realloc()
        ptr = realloc(ptr, NumOfElements * sizeof(int));
        // ^^^ sets size = (4 bytes) * times (number of elements)
        // ^^^ in this case -> 10 * 4 = 40 bytes reallocated

        printf("Memory re-allocated!\n");

        // number the new elements in the array
        for (int index = 5; index < NumOfElements; ++index)
        {
            ptr[index] = index + 1;
        }

        // Print whole array
        printf("The elements in the array: ");
        for (int index = 0; index < NumOfElements; ++index)
        {
            printf("%d ", ptr[index]);
        }

        printf("\n\nElement at index 10: %d ", ptr[10]);

        printf("\n\nElement at index 1: %d ", ptr[1]);
        free(ptr); // deallocates to free memory
        printf("\nptr has been freed!");
        printf("\nElement at index 1: %d ", ptr[1]);
    }
}