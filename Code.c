#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateFrequencies(int *frequencies, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        frequencies[i] = rand() % 101;
    }
    printf("\nFrequency Visualization:\n");
    for (int i = 0; i < size; i++) {
        printf("Frequency %d: ", i + 1);
        for (int j = 0; j < frequencies[i]; j += 10) {
            printf("*");
        }
        printf("\n");
    }
}

void inputFrequencies(int *frequencies, int size) {
    printf("\nEnter frequencies for %d channels (0-100):\n", size);
    for (int i = 0; i < size; i++) {
        do {
            printf("Frequency %d: ", i + 1);
            scanf("%d", &frequencies[i]);
            if (frequencies[i] < 0 || frequencies[i] > 100) {
                printf("Invalid input. Please enter a value between 0 and 100.\n");
            }
        } while (frequencies[i] < 0 || frequencies[i] > 100);
    }
}

void visualizeFrequencies(int *frequencies, int size) {
    printf("\nFrequency Visualization:\n");
    for (int i = 0; i < size; i++) {
        printf("Frequency %d: ", i + 1);
        for (int j = 0; j < frequencies[i]; j += 10) {
            printf("*");
        }
        printf("\n");
    }
}

void analyzeFrequencies(int *frequencies, int size) {
    if (frequencies[0] == 0) {
        printf("\nNo frequencies available for analysis. Please generate or input frequencies first.\n");
        return;
    }

    int highest = frequencies[0];
    int lowest = frequencies[0];
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (frequencies[i] > highest) {
            highest = frequencies[i];
        }
        if (frequencies[i] < lowest) {
            lowest = frequencies[i];
        }
        sum += frequencies[i];
    }

    float average = sum / (float)size;

    printf("\nFrequency Analysis:\n");
    printf("Highest Frequency: %d\n", highest);
    printf("Lowest Frequency: %d\n", lowest);
    printf("Average Frequency: %.2f\n", average);
}

int main() {
    int frequencies[10] = {0}; 
    int choice;

    while (choice != 5) {
        printf("\nAudio Frequency Visualizer\n");
        printf("1. Generate Frequencies\n");
        printf("2. Input Frequencies\n");
        printf("3. Visualize Frequencies\n");
        printf("4. Analyze Frequencies\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateFrequencies(frequencies, 10);
                printf("Frequencies generated!\n");
                break;
            case 2:
                inputFrequencies(frequencies, 10);
                break;
            case 3:
                visualizeFrequencies(frequencies, 10);
                break;
            case 4:
                analyzeFrequencies(frequencies, 10);
                break;
            case 5:
                printf("Program End.\n");
                return 0;  
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}