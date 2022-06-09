// Use C-Lang Static Analyzer to analyze and fix the bugs
// Also review the output generated to find any bugs that the static analyzer misses.
// Hint this code has 2-3 bugs that can be identified using static analyzer, 2 Tasks will have to be completed
//1.. add null pointer check condition for ptr1 in the reverse method for reversing logic.
//2.. Complete reversing Logic using given pointer.

//MACROS
#include<stdio.h>

// custom method to reverse a number (without using third variable/pointer) passed to it as arguments from main()
void reverse_number(int *ptr1, char* ptr2){
    if (!ptr1 || !ptr2){
      printf("One of the pointers passed is NULL\n");
      return;
    }
    int reverse = 0; //will be used as reversing variable.
    int remainder = 0;
    printf("Original First Number is : %d \n ", (*ptr1));
    printf("Choice is : %c \n ", (*ptr2));

    if(*ptr2 == 'Y')
    {
        while(*ptr1 > 0)
        {
          remainder = *ptr1%10;
          reverse = reverse*10 + remainder;
          *ptr1 /= 10;
        }
        *ptr1=reverse;
        //print statements
        printf("Reversed First Number is : %d \n", (*ptr1));
        printf("Confirmed choice is : %c \n", (*ptr2));
    }
    else{
        printf("Sorry Not allowed\n");
    }

}

int main(){
    // variable initializations
    int first_number = 12345;
    char choice = 'Y';

    int* ptr_to_first_number = &first_number;
    char *ptr_to_char = &choice;
    // Hint:: add and assign the references to the pointers here:


    //function call statements
    reverse_number(ptr_to_first_number, ptr_to_char);

    return 0;

}
