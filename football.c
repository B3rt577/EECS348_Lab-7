#include "football.h"
#include <stdio.h>
#include <stdlib.h>

// Compare function for ascending order
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

// Function to find all combinations of scoring plays
void find_combinations(int score) {
    int td = 6, fg = 3, safety = 2, td2pt = 8, tdfg = 7;
    ScoreCombination combinations[100];
    int combination_count = 0;

    // Loop through all combinations of scoring plays
    for (int td2pt_count = 0; td2pt_count * td2pt <= score; td2pt_count++) {
        for (int tdfg_count = 0; tdfg_count * tdfg <= score; tdfg_count++) {
            for (int td_count = 0; td_count * td <= score; td_count++) {
                for (int fg_count = 0; fg_count * fg <= score; fg_count++) {
                    for (int safety_count = 0; safety_count * safety <= score; safety_count++) {
                        // Calculate the total score for the combination of counts
                        int total_score = td2pt_count * td2pt + tdfg_count * tdfg + td_count * td + fg_count * fg + safety_count * safety;
                        
                        // If the total score matches the desired score, store the combination
                        if (total_score == score) {
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

    // Sort combinations in ascending order based on scoring plays
    qsort(combinations, combination_count, sizeof(ScoreCombination), compare);

    // Print the sorted combinations
    for (int i = 0; i < combination_count; i++) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                combinations[i].td2pt_count, combinations[i].tdfg_count, combinations[i].td_count, combinations[i].fg_count, combinations[i].safety_count);
    }
}
