#include <iostream>
#include <windows.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

int resource = 0;
int mutex = 1; // semaphore for mutual exclusion
int read_count = 0; // counter for readers

// Semaphore wait operation
void wait(int &sem) {
    while (sem <= 0);
    --sem;
}

// Semaphore signal operation
void signal(int &sem) {
    ++sem;
}

// Reader function
void reader(int id) {
    while (true) {
        wait(mutex); // Enter critical section
        ++read_count;
        if (read_count == 1) {
            // If first reader, lock writers
            wait(mutex);
        }
        signal(mutex); // Exit critical section

        // Read from resource
        std::cout << "Reader " << id << " is reading." << std::endl;

        wait(mutex); // Enter critical section
        --read_count;
        if (read_count == 0) {
            // If last reader, unlock writers
            signal(mutex);
        }
        signal(mutex); // Exit critical section

        // Sleep to simulate reading process
        Sleep(rand() % 1000); // Sleep for up to 1 second
    }
}

// Writer function
void writer(int id) {
    while (true) {
        wait(mutex); // Enter critical section
        // Lock resource for writers
        if (resource == 0) {
            resource = 1;
            std::cout << "Writer " << id << " is writing." << std::endl;
        }
        signal(mutex); // Exit critical section

        // Sleep to simulate writing process
        Sleep(rand() % 1000); // Sleep for up to 1 second

        // Reset resource for next writer
        wait(mutex); // Enter critical section
        resource = 0;
        signal(mutex); // Exit critical section

        // Sleep to introduce delay before next writer operation
        Sleep(2000); // Sleep for 2 seconds
    }
}

int main() {
    srand(GetTickCount()); // Seed the random number generator with system time

    int choice;
    bool hasWriter = false;
    bool hasReaders[NUM_READERS] = {false};

    do {
        std::cout << "Enter 1 to read, 2 to write, 3 to free writer, or 0 to exit: ";
        std::cin >> choice;

        if (choice == 1) {
            bool isReaderAvailable = false;
            for (int i = 0; i < NUM_READERS; ++i) {
                if (!hasReaders[i]) {
                    hasReaders[i] = true;
                    isReaderAvailable = true;
                    std::cout << "Reader " << i << " is reading." << std::endl;
                    break;
                }
            }
            if (!isReaderAvailable) {
                std::cout << "No more readers available." << std::endl;
            }
        } else if (choice == 2) {
            if (hasWriter) {
                std::cout << "Writer is writing. Wait until it finishes." << std::endl;
            } else {
                hasWriter = true;
                std::cout << "Writer is writing." << std::endl;
            }
        } else if (choice == 3) {
            if (hasWriter) {
                std::cout << "Writer has been freed. New writer can start writing." << std::endl;
                hasWriter = false;
            } else {
                std::cout << "No writer is currently writing." << std::endl;
            }
        } else if (choice != 0) {
            std::cout << "Invalid choice!" << std::endl;
        }

    } while (choice != 0);

    return 0;
}

