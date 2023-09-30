#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../dbgprint/debug_print.h"

struct CaloriesSumNode {
    int calories_sum;
    struct CaloriesSumNode* next;
};

struct CaloriesSumNode* create_calories_sum_node(int calories_sum) {
    struct CaloriesSumNode* new_node =  (struct CaloriesSumNode*)malloc(sizeof(struct CaloriesSumNode));

    if (new_node == NULL) {
        DEBUG_PRINT("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    new_node->calories_sum = calories_sum;
    new_node->next = NULL;

    return new_node;
}

void append_to_end_calories_sum_list(struct CaloriesSumNode** head, int calories_sum) {
    struct CaloriesSumNode* new_node = create_calories_sum_node(calories_sum);

    if (*head == NULL) {
        // Is empty singly list
        *head = new_node;
        return;
    }

    struct CaloriesSumNode* current = *head;
    while (current->next != NULL) {
        current = current->next; // Ensure at the end of the list
    }

    current->next = new_node;
}

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

    struct CaloriesSumNode* head = NULL;

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

            append_to_end_calories_sum_list(&head, elf_calories_sum);
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

    struct CaloriesSumNode* current = head;
    int idx = 0;
    int max = 0;
    while (current != NULL) {
        DEBUG_PRINT("***Sum of calories for Elf #%d: %d", ++idx, current->calories_sum);
        if (current->calories_sum > max) {
            max = current->calories_sum;
            DEBUG_PRINT("***Found new maximum calories: %d", max);
        }
        current = current->next;
    }
    DEBUG_PRINT("***> Maximum calories found: %d <***", max);

    return 0;
}
