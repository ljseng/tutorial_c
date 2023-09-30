#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../dbgprint/debug_print.h"

int main() {
    DEBUG_PRINT("Advent of Code Day 1");

    const char *input_file_path = "input.txt";

    FILE *fp;
    fp = fopen(input_file_path, "r");

    if (fp == NULL) {
        DEBUG_PRINT("Error opening %s", input_file_path);
        return 1;
    }

    DEBUG_PRINT("Successfully opened %s", input_file_path);

    char line[16]; // Buffer to store each line

    int idx_of_elf       = 0; // Index of elf being processed
    int calories_max     = 0; // Maximum calories sum found
    int elf_calories_sum = 0; // Calories sum for each Elf

    // Read and print each line until EOF
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (elf_calories_sum <= 0) {
            DEBUG_PRINT("Summing calories for Elf #%d", ++idx_of_elf);
        }

        if (line[0] == '\n' || line[0] == '\0') {
            // Done one Elf
            DEBUG_PRINT("Sum of calories for Elf #%d: %d", idx_of_elf, elf_calories_sum);

            if (elf_calories_sum > calories_max) {
                calories_max = elf_calories_sum;
                DEBUG_PRINT("Found new maximum calories: %d", calories_max);
            }

            elf_calories_sum = 0;
            continue;
        }

        elf_calories_sum += atoi(line);
        DEBUG_PRINT("Iteration calories sum: %d", elf_calories_sum);
    }

    fclose(fp);

    DEBUG_PRINT("===> Maximum calories found: %d <===", calories_max);

    return 0;
}
