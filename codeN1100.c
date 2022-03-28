#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


//------ Tasks -------------------------
// use clang static analyser to identify bug(s)
// critical issue related how input is sanitized

void executeSystem(char* executable) {
  system(executable);
}

void bookReader(char **bookName) {
 char reader[] = "cat ";
 size_t executableLength = strlen(reader) + strlen(bookName[1]) + 1;

 char *executable = (char *) malloc(executableLength);
 strncpy(executable, reader, executableLength);
 strncat(executable, bookName[1], (executableLength - strlen(reader)));

 executeSystem(executable);
}

int main(int argc, char **argv) {
 bookReader(argv);
 return (0);
}

