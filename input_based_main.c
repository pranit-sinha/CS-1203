#include <stdio.h> 
#include <stdlib.h> 
 
int main (int argc, char** argv) { 
  int num_nodes;
  int num_patterns;
  int * eclass_id; 
  ENode **node;
  ENode **pattern;
  EMatchingResult **result;

  printf("Enter number of nodes.");
  scanf("%d", &num_nodes);
  
  EGraph* egraph = buildEGraph(num_nodes);

  for (int i = 0; i < num_nodes; i++) {

      node[i] = malloc(sizeof(ENode));
      printf("Enter function symbol of node %d", i);
      scanf("%s", &node[i].function_symbol);
      printf("Enter number of eclass_ids.");
      scanf("%d", &node[i].size);
      node[j].eclass_ids = malloc(sizeof(int) * node[i].size);

      for (int j = 0; j < node[i].size; j++) {
          printf("Enter eclass id number %d", j);
          scanf("%d", &node[i].eclass_ids[j]);
      }

      int eclass_id[i] = add(egraph, &node[i]);
  }
      
  printf("Enter the number of patterns.");
  scanf("%d", &num_patterns);

  for (int i = 0; i < num_patterns; i++) {

      pattern[i] = malloc(sizeof(ENode));
      printf("Enter function symbol of pattern %d", i);
      scanf("%s", &pattern[i].function_symbol);
      printf("Enter number of eclass_ids.");
      scanf("%d", &pattern[i].size);
      pattern[j].eclass_ids = malloc(sizeof(int) * pattern[i].size);

      for (int j = 0; j < pattern[i].size; j++) {
          printf("Enter eclass id number %d", j);
          scanf("%d", &pattern[i].eclass_ids[j]);
      }
      
      result[i] = eMatch(egraph, &pattern[i]);
      printf("E-class ID: %d\n", result[i].eclass_id);
      for (int j = 0; j < pattern[i].size; j++) {
          printf("Substitution: %d", result[i].substitutions[j]);
      }
      printf("\n");
  }

	return 0; 
}

