#include<stdio.h>

int size = 5;

void recurse() {
    void (*foo)(void); //fix uninitialized pointer
    foo();

    //recursive call (implement a valid recursive check mechanism to fix null dereference)
    foo();

}

int main() {
    recurse();
    return 0;
}