#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#define numPhilosophers 5

void displayStatus(bool *eating) {
    printf("Current status:\n");
    for (int i = 0; i < numPhilosophers; i++) {
        if (eating[i]) {
            printf("Philosopher %d is eating.\n", i + 1);
        } else {
            printf("Philosopher %d is thinking.\n", i + 1);
        }
    }
}

int main() {
    printf("Naman Shah\n0827CS221174\nDining Philosophers Problem\n\n");

    bool eating[numPhilosophers];

    int philosopher;
    char choice;
    while (true) {
        for (int i = 0; i < numPhilosophers; i++) {
            eating[i] = false;
        }

        printf("Enter the philosopher number who wants to eat (1-5), or 'q' to quit: ");
        scanf(" %c", &choice);
        if (choice == 'q') {
            break;
        }

        philosopher = choice - '0';
        if (philosopher < 1 || philosopher > numPhilosophers) {
            printf("Invalid philosopher number. Please try again.\n");
            continue;
        }

        philosopher--;  
        int left = (philosopher + numPhilosophers - 1) % numPhilosophers;
        int right = (philosopher + 1) % numPhilosophers;

        if (!eating[left] && !eating[right]) {
            eating[philosopher] = true; 
            printf("Philosopher %d can now eat.\n", philosopher + 1);
            for (int i = 0; i < numPhilosophers; i++) {
                if (i != philosopher) {
                    int leftOfI = (i + numPhilosophers - 1) % numPhilosophers;
                    int rightOfI = (i + 1) % numPhilosophers;
                    if (!eating[leftOfI] && !eating[rightOfI]) {
                        eating[i] = true;
                        printf("Philosopher %d can now eat.\n", i + 1);
                    }
                }
            }
        } else {
            printf("Philosopher %d cannot eat right now.\n", philosopher + 1);
        }

        displayStatus(eating);
    }

    printf("Exit.\n");
    return 0;
}