 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // Fork a new process
    pid_t pid = fork();

    if (pid < 0) {
        // Forking failed, print an error message
        fprintf(stderr, "Fork failed.\n");
        return 1; // Exit the program with an error code
    } else if (pid == 0) {
        // This code block is executed by the child process

        // Check if the number is even or odd
        if (number % 2 == 0) {
            printf("%d is even (Child Process).\n", number);
        } else {
            printf("%d is odd (Child Process).\n", number);
        }
    } else {
        // This code block is executed by the parent process

        // Wait for the child process to finish
        wait(NULL);

        // Print a message indicating that the parent process has completed
        printf("Parent process has completed.\n");
    }

    return 0; // Exit the program
}
