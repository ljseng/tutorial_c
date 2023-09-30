// TODO: Refactor and rename the code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../dbgprint/debug_print.h"

struct CaloriesNode {
    int calories;
    struct CaloriesNode* next;
};

struct CaloriesNode* create_calories_node(int calories) {
    struct CaloriesNode* new_node = (struct CaloriesNode*)malloc(sizeof(struct CaloriesNode));

    if (new_node == NULL) {
        DEBUG_PRINT("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    new_node->calories = calories;
    new_node->next = NULL;

    return new_node;
}

void append_to_end_calories_list(struct CaloriesNode** head, int calories) {
    struct CaloriesNode* new_node = create_calories_node(calories);

    if (*head == NULL) {
        // Is empty singly list
        *head = new_node;
        return;
    }

    struct CaloriesNode* current = *head;

    while (current->next != NULL) {
        current = current->next; // Ensure at the end of the list
    }

    current->next = new_node;
}

struct ElfNode {
    struct CaloriesNode* calories;
    struct ElfNode* next;
};

struct ElfNode* create_elf_node() {
    struct ElfNode* new_node =  (struct ElfNode*)malloc(sizeof(struct ElfNode));

    if (new_node == NULL) {
        DEBUG_PRINT("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    new_node->calories = NULL;
    new_node->next = NULL;

    return new_node;
}

void append_to_end_elf_list(struct ElfNode** head, struct CaloriesNode* calories) {
    struct ElfNode* new_node = create_elf_node();
    new_node->calories = calories;

    if (*head == NULL) {
        // Is empty singly list
        *head = new_node;
        return;
    }

    struct ElfNode* current = *head;
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

    struct ElfNode* elfHead = NULL;
    struct CaloriesNode* caloriesHead = NULL;

    // Read and print each line until EOF
    while (fgets(line, sizeof(line), fp) != NULL) {
        append_to_end_elf_list(&elfHead, caloriesHead);

        if (line[0] == '\n' || line[0] == '\0') {
            // Done one Elf
            caloriesHead = NULL;
            continue;
        }

        append_to_end_calories_list(&caloriesHead, atoi(line));
    }

    fclose(fp);

    int idx_of_elf       = 0; // Index of elf being processed
    int calories_max     = 0; // Maximum calories sum found
    int elf_calories_sum = 0; // Calories sum for each Elf

    struct ElfNode* current = elfHead;
    while (current != NULL) {
        struct CaloriesNode* currentCalories = current->calories;
        while (currentCalories != NULL) {
            elf_calories_sum += currentCalories->calories;
            currentCalories = currentCalories->next;
        }

        if (elf_calories_sum > calories_max) {
            calories_max = elf_calories_sum;
        }

        elf_calories_sum = 0;
        current = current->next;
    }

    DEBUG_PRINT("===> Maximum calories found: %d <===", calories_max);
    return 0;
}
