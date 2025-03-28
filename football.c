#include <stdio.h>
#include <stdlib.h>
#include "football.h"

// Structure to store the combination counts
typedef struct {
    int td2pt_count;   // Touchdown + 2-point conversion count
    int tdfg_count;    // Touchdown + field goal count
    int td_count;      // Touchdown count
    int fg_count;      // Field goal count
    int safety_count;  // Safety count
} ScoreCombination;

// Function to compare ScoreCombination structures (used for sorting)
int compare(const void *a, const void *b) {
    ScoreCombination *sc1 = (ScoreCombination *)a;
    ScoreCombination *sc2 = (ScoreCombination *)b;

    // Compare in ascending order
    if (sc1->td2pt_count != sc2->td2pt_count)
        return sc1->td2pt_count - sc2->td2pt_count;
    if (sc1->tdfg_count != sc2->tdfg_count)
        return sc1->tdfg_count - sc2->tdfg_count;
    if (sc1->td_count != sc2->td_count)
        return sc1->td_count - sc2->td_count;
    if (sc1->fg_count != sc2->fg_count)
        return sc1->fg_count - sc2->fg_count;
    return sc1->safety_count - sc2->safety_count;
}

// Function to find all combinations of scoring plays that add up to `points`
int find_combinations(int points, ScoreCombination *combinations) {
    int td = 6, fg = 3, safety = 2, td2pt = 8, tdfg = 7;
    int combination_count = 0;

    // Loop through all combinations of scoring plays
    for (int td2pt_count = 0; td2pt_count * td2pt <= points; td2pt_count++) {
        for (int tdfg_count = 0; tdfg_count * tdfg <= points; tdfg_count++) {
            for (int td_count = 0; td_count * td <= points; td_count++) {
                for (int fg_count = 0; fg_count * fg <= points; fg_count++) {
                    for (int safety_count = 0; safety_count * safety <= points; safety_count++) {
                        // Calculate the total score for the combination of counts
                        int total_score = td2pt_count * td2pt + tdfg_count * tdfg + td_count * td + fg_count * fg + safety_count * safety;
                        
                        // If the total score matches the desired score, store the combination
                        if (total_score == points) {
                            combinations[combination_count].td2pt_count = td2pt_count;
                            combinations[combination_count].tdfg_count = tdfg_count;
                            combinations[combination_count].td_count = td_count;
                            combinations[combination_count].fg_count = fg_count;
                            combinations[combination_count].safety_count = safety_count;
                            combination_count++;
                        }
                    }
                }
            }
        }
    }

    // Return the number of combinations found
    return combination_count;
}

// Function to count the number of possible combinations to add up to `points`
int count_combinations(int points) {
    ScoreCombination combinations[100];
    int combination_count = find_combinations(points, combinations);

    // Return the number of valid combinations
    return combination_count;
}

// Function to print all possible combinations in a formatted table
void print_combinations(int points) {
    ScoreCombination combinations[100];
    int combination_count = find_combinations(points, combinations);

    // Sort the combinations in ascending order
    qsort(combinations, combination_count, sizeof(ScoreCombination), compare);

    // Print the table of combinations
    for (int i = 0; i < combination_count; i++) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                combinations[i].td2pt_count, combinations[i].tdfg_count, combinations[i].td_count, combinations[i].fg_count, combinations[i].safety_count);
    }
}
