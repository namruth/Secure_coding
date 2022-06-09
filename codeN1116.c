// Use C-Lang Static Analyzer to analyze and fix the bugs
// Also review the output generated to find any bugs that the static analyzer misses.
// Hint this code has 5-6 bugs that can be identified using static analyzer, 3 Tasks will also have to be completed
//1.. add null pointer check condition for ptr1 and ptr2 in the even_number method
//2.. add null pointer check condition for ptr3 in the array_print method
//3.. Complete even Logic using given pointer.

//MACROS (Hint: 1 macro definition for a library function is missing (look at warnings maybe?))
#include<stdio.h>
#include<stdlib.h>

// custom method to check for even or odd number
void even_number(int *ptr1, char *ptr2) {
    if (!ptr1 || !ptr2){
      printf("One of the pointers passed is NULL\n");
      return;
    }

    printf("Original First Number is : %d \n ", (*ptr1));
    printf("Choice is : %c \n ", (*ptr2));

    if (*ptr1 % 2 == 0)//add logic for checking even number inside if condition ()
    {
        printf("Numbner %d is Even : \n", (*ptr1));
        printf("Confirmed choice is : %c \n", (*ptr2));
    } else {
        printf("Odd Number\n");
    }

}

//another custom array printing an array
void array_print(int *ptr3, int n) {
    if (!ptr3){
      printf("One of the pointers passed is NULL\n");
      return;
    }
    for (int i = 0; i < n + 1; i++) {
        ptr3[i] = i;
        printf("Array is:%d\n ", ptr3[i]);
    }
}

int main() {
    // variable initializations (Hint: Missing values?????)
    int first_number = 17;
    char choice = 'Y';
    int *ptr_to_arr;
    int size_array = 10;

    int *ptr_to_first_number = &first_number;
    char *ptr_to_char = &choice;
    ptr_to_arr = (int *) malloc(size_array * sizeof(int));
    even_number(ptr_to_first_number, ptr_to_char);
    array_print(ptr_to_arr, size_array);

    free(ptr_to_arr);
    return 0;
}
