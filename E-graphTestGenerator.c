#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_TEST_CASES 100
#define MAX_NUM_NODES 100
#define MAX_NUM_VARIABLES 10
#define MAX_NAME_LENGTH 10

// Struct for an e-node
typedef struct {
  char* function_symbol;
  int* e_class_ids;
  int size;
} ENode;

// Generate a random e-node
ENode generate_random_e_node() {
  ENode node;
  node.size = rand() % MAX_NUM_VARIABLES + 1;
  node.e_class_ids = malloc(sizeof(int) * node.size);
  for (int i = 0; i < node.size; i++) {
    node.e_class_ids[i] = rand() % MAX_NUM_NODES - MAX_NUM_VARIABLES;
  }
  node.function_symbol = malloc(sizeof(char) * (MAX_NAME_LENGTH + 1));
  for (int i = 0; i < MAX_NAME_LENGTH; i++) {
    node.function_symbol[i] = 'a' + rand() % 26;
  }
  node.function_symbol[MAX_NAME_LENGTH] = '\0';
  return node;
}

int main() {
  srand(time(0));

  for (int t = 0; t < NUM_TEST_CASES; t++) {
    // Generate a random set of e-nodes
    int num_nodes = rand() % MAX_NUM_NODES + 1;
    ENode* nodes = malloc(sizeof(ENode) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
      nodes[i] = generate_random_e_node();
    }

    // Generate a random set of merge operations
    int num_merges = rand() % num_nodes;
    int* merge_pairs = malloc(sizeof(int) * num_merges * 2);
    for (int i = 0; i < num_merges; i++) {
      merge_pairs[i * 2] = rand() % num_nodes;
      merge_pairs[i * 2 + 1] = rand() % num_nodes;
    }

    // Generate a random set of patterns
    int num_patterns = rand() % num_nodes;
    ENode* patterns = malloc(sizeof(ENode) * num_patterns);
    for (int i = 0; i < num_patterns; i++) {
      patterns[i] = generate_random_e_node();
    }
    // Print the test case (continued)
    printf("%d\n", num_patterns);
    for (int i = 0; i < num_patterns; i++) {
      printf("%s ", patterns[i].function_symbol);
      for (int j = 0; j < patterns[i].size; j++) {
        printf("%d ", patterns[i].e_class_ids[j]);
      }
      printf("\n");
    }

    // Clean up memory
    for (int i = 0; i < num_nodes; i++) {
      free(nodes[i].function_symbol);
      free(nodes[i].e_class_ids);
    }
    free(nodes);
    free(merge_pairs);
    for (int i = 0; i < num_patterns; i++) {
      free(patterns[i].function_symbol);
      free(patterns[i].e_class_ids);
    }
    free(patterns);
  }

  return 0;
}
