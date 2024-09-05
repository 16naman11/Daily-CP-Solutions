#include <iostream>
#include <queue>

using namespace std;

// Function to simulate FIFO page replacement algorithm
int FIFO(char pages[], int num_pages, int num_frames, int& page_replacements) {
    int page_faults = 0;
    page_replacements = 0;
    queue<char> frame_queue;
    bool in_frames[26] = {false}; // Assuming page reference string consists of characters from 'a' to 'z'

    for (int i = 0; i < num_pages; ++i) {
        char page = pages[i] - 'a'; // Convert character to index (0-25)
        if (!in_frames[page]) {
            page_faults++;
            if (frame_queue.size() == num_frames) {
                char replaced_page = frame_queue.front();
                frame_queue.pop();
                in_frames[replaced_page] = false;
                page_replacements++;
            }
            frame_queue.push(page);
            in_frames[page] = true;
        }
    }

    return page_faults;
}

// Function to simulate LRU page replacement algorithm
int LRU(char pages[], int num_pages, int num_frames, int& page_replacements) {
    int page_faults = 0;
    page_replacements = 0;
    int frame_index = 0;
    char frames[num_frames];
    int last_used[26] = {0}; // Array to store last used index for each page (0-25)

    for (int i = 0; i < num_pages; ++i) {
        char page = pages[i] - 'a'; // Convert character to index (0-25)
        bool found = false;
        for (int j = 0; j < frame_index; ++j) {
            if (frames[j] == page) {
                found = true;
                last_used[page] = i;
                break;
            }
        }
        if (!found) {
            page_faults++;
            if (frame_index == num_frames) {
                int replace_page = 0;
                for (int j = 1; j < num_frames; ++j) {
                    if (last_used[frames[j]] < last_used[frames[replace_page]]) {
                        replace_page = j;
                    }
                }
                frames[replace_page] = page;
                last_used[page] = i;
                page_replacements++;
            } else {
                frames[frame_index++] = page;
                last_used[page] = i;
            }
        }
    }

    return page_faults;
}

// Function to simulate OPTIMAL page replacement algorithm
int OPTIMAL(char pages[], int num_pages, int num_frames, int& page_replacements) {
    int page_faults = 0;
    page_replacements = 0;
    char frames[num_frames];
    int next_use[num_frames]; // Array to store next use index for each frame
    fill_n(next_use, num_frames, num_pages); // Initialize to a value beyond num_pages

    for (int i = 0; i < num_pages; ++i) {
        char page = pages[i] - 'a'; // Convert character to index (0-25)
        bool found = false;
        for (int j = 0; j < num_frames; ++j) {
            if (frames[j] == page) {
                found = true;
                break;
            }
        }
        if (!found) {
            page_faults++;
            if (page_replacements < num_frames) {
                frames[page_replacements] = page;
                next_use[page_replacements] = i;
                page_replacements++;
            } else {
                int replace_page = 0;
                int farthest_use = -1;
                for (int j = 0; j < num_frames; ++j) {
                    if (next_use[j] > farthest_use) {
                        farthest_use = next_use[j];
                        replace_page = j;
                    }
                }
                frames[replace_page] = page;
                next_use[replace_page] = i;
                page_replacements++;
            }
        }
        // Update next use for all frames
        for (int j = 0; j < num_frames; ++j) {
            int k = i + 1;
            while (k < num_pages && pages[k] - 'a' != frames[j]) {
                k++;
            }
            next_use[j] = k;
        }
    }

    return page_faults;
}

// Function to simulate LFU page replacement algorithm
int LFU(char pages[], int num_pages, int num_frames, int& page_replacements) {
    int page_faults = 0;
    page_replacements = 0;
    int page_frequency[26] = {0}; // Array to store frequency of each page (0-25)
    char frames[num_frames];
    bool in_frames[26] = {false}; // Array to check presence of pages in frames

    for (int i = 0; i < num_pages; ++i) {
        char page = pages[i] - 'a'; // Convert character to index (0-25)
        if (!in_frames[page]) {
            page_faults++;
            if (page_replacements < num_frames) {
                frames[page_replacements] = page;
                in_frames[page] = true;
                page_replacements++;
            } else {
                int replace_page = 0;
                for (int j = 1; j < num_frames; ++j) {
                    if (page_frequency[frames[j]] < page_frequency[frames[replace_page]]) {
                        replace_page = j;
                    }
                }
                in_frames[frames[replace_page]] = false;
                frames[replace_page] = page;
                in_frames[page] = true;
            }
            page_replacements++;
        }
        page_frequency[page]++;
    }

    return page_faults;
}

int main() {
    int num_pages, num_frames;
    cout << "Enter the number of pages: ";
    cin >> num_pages;
    char pages[num_pages];
    cout << "Enter the page reference string (characters a-z, separated by spaces): ";
    for (int i = 0; i < num_pages; ++i) {
        cin >> pages[i];
    }
    cout << "Enter the number of free frames: ";
    cin >> num_frames;
    cout<<"\nName : Naman Shah\n";
    cout<<"Results\n";
    int page_replacements = 0;

    int fifo_faults = FIFO(pages, num_pages, num_frames, page_replacements);
    cout << "FIFO:\t" << fifo_faults << " page faults,\t" << page_replacements << " page replacements\n";

    int lru_faults = LRU(pages, num_pages, num_frames, page_replacements);
    cout << "LRU:\t" << lru_faults << " page faults,\t" << page_replacements << " page replacements\n";

    int lfu_faults = LFU(pages, num_pages, num_frames, page_replacements);
    cout << "LFU:\t" << lfu_faults << " page faults,\t" << page_replacements << " page replacements\n";
    
    int optimal_faults = OPTIMAL(pages, num_pages, num_frames, page_replacements);
    cout << "OPTIMAL:\t" << optimal_faults << " page faults,\t" << page_replacements << " page replacements\n";
    cout<<"Enrollment no.: 0827CS221174\n";
    return 0;
}