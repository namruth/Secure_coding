// Use C-Lang Static Analyzer to analyze and fix the bugs
// Also review the output generated to find any bugs that the static analyzer misses.
// Hint this code has 1-2 bugs that can be identified using static analyzer, 2 Tasks will have to be completed
//1.. add null pointer check condition in the swap method for swapping logic.
//2.. Complete swapping Logic using given pointers.

//MACROS
#include<stdio.h>

// custom method to swap digits (without using third variable/pointer) passed to it as arguments from main()
void swap(int *ptr1, int *ptr2) {

   if (!ptr1 || !ptr2){
     printf("One of the pointers passed is NULL, cant be swapped\n");
     return;
   }

    printf("Original First Number is : %d \n ", (*ptr1));
    printf("Original Second Number is : %d \n ", (*ptr2));

    // logic for swapping
    *ptr1 = *ptr1 + *ptr2;
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 = *ptr1 - *ptr2;

    printf("Swapped First Number is : %d \n", (*ptr1));
    printf("Swapped Second Number is : %d \n", (*ptr2));

}

int main() {
    int first_number = 10;
    int second_number = 20;
    //Note for developers(students): use numbers in method using defined pointers (not directly)

    int *ptr_to_first_number = &first_number;
    int *ptr_to_second_number = &second_number;
    // Hint:: add the assign the references to the pointers here:


    //function call statements
    swap(ptr_to_first_number, ptr_to_second_number);

    return 0;

}
