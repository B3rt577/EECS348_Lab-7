#include "football.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Check if the user has provided the points as a command-line argument
        printf("Usage: %s <points>\n", argv[0]);
        return 1;
    }

    int points = atoi(argv[1]); // Convert the command-line argument to an integer

    if (points <= 0) {
        printf("Please provide a valid positive integer for points.\n");
        return 1;
    }

    // Print the number of combinations
    printf("Number of combinations: %d\n", count_combinations(points));

    // Print all possible combinations
    print_combinations(points);
    return 0;
}
