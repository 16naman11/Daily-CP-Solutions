#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10  // Number of items to produce and consume

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int count = 0;  // To track the number of items in the buffer

void produce() {
    int item = rand() % 100;  // Produce a random item

    // Simulate waiting if the buffer is full
    while (count == BUFFER_SIZE) {
        printf("Buffer is full. Producer waiting...\n");
        sleep(1);  // Sleep to simulate waiting
    }

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    count++;
    printf("Produced: %d\n", item);
}

void consume() {
    // Simulate waiting if the buffer is empty
    while (count == 0) {
        printf("Buffer is empty. Consumer waiting...\n");
        sleep(1);  // Sleep to simulate waiting
    }

    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;
    printf("Consumed: %d\n", item);
}

int main() {
    char choice;
    int itemsProduced = 0;
    int itemsConsumed = 0;

    while (itemsProduced < NUM_ITEMS || itemsConsumed < NUM_ITEMS) {
        printf("Enter 'p' to produce, 'c' to consume, or 'q' to quit: ");
        scanf(" %c", &choice);  // Note the space before %c to consume any trailing newline

        if (choice == 'p') {
            if (itemsProduced < NUM_ITEMS) {
                if (count < BUFFER_SIZE) {
                    produce();
                    itemsProduced++;
                } else {
                    printf("Buffer is full. Producer cannot produce now.\n");
                }
            } else {
                printf("All items have been produced.\n");
            }
        } else if (choice == 'c') {
            if (itemsConsumed < NUM_ITEMS) {
                if (count > 0) {
                    consume();
                    itemsConsumed++;
                } else {
                    printf("Buffer is empty. Consumer cannot consume now.\n");
                }
            } else {
                printf("All items have been consumed.\n");
            }
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid choice. Please enter 'p', 'c', or 'q'.\n");
        }
    }

    printf("Production and consumption complete.\n");

    return 0;
}

