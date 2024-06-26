#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "headers/Egraph.h"

/*
 * Functions 
 */

// Init structure
EGraph* buildEGraph(int num_nodes) {

  EGraph* egraph = malloc(sizeof(EGraph));
  egraph->uf.parent = malloc(sizeof(int) * num_nodes);
  egraph->uf.rank = malloc(sizeof(int) * num_nodes);
  egraph->hashcons.nodes = malloc(sizeof(ENode*) * num_nodes);
  egraph->hashcons.eclass_ids = malloc(sizeof(int) * num_nodes);
  egraph->hashcons.size = num_nodes;
  egraph->eclass_map = malloc(sizeof(EClass) * num_nodes);

  return egraph;
}

// Add e-node to graph and corresponding hash table
int add(EGraph* egraph, ENode* node) {
  for (int i = 0; i < egraph->hashcons.size; i++) {

    if (egraph->hashcons.nodes[i]) {
      if (strcmp(egraph->hashcons.nodes[i]->function_symbol, node->function_symbol) == 0) {
        bool same = true;

        for (int j = 0; j < egraph->hashcons.nodes[i]->size; j++) {
          if (egraph->hashcons.nodes[i]->eclass_ids[j] != node->eclass_ids[j]) {
            same = false;
            break;
          }
        }

        if (same) {
          return egraph->hashcons.eclass_ids[i];
        }

      }
    }
  }

  // create e-class for added node
  for (int i = 0; i < egraph->hashcons.size; i++) {

    if (egraph->hashcons.nodes[i] == NULL) {

      egraph->hashcons.nodes[i] = node;
      egraph->hashcons.eclass_ids[i] = i;
      egraph->eclass_map[i].nodes = malloc(sizeof(ENode));
      egraph->eclass_map[i].nodes[0] = *node;
      egraph->eclass_map[i].size = 1;

      return i;
    }

  }
  return -1;
}

int find(EGraph* egraph, int x) {

  if (egraph->uf.parent[x] != x) {
    egraph->uf.parent[x] = find(egraph, egraph->uf.parent[x]);
  }

  return egraph->uf.parent[x];
}

void merge(EGraph* egraph, int x, int y) {

  int xroot = find(egraph, x);
  int yroot = find(egraph, y);

  if (egraph->uf.rank[xroot] < egraph->uf.rank[yroot]) {
    egraph->uf.parent[xroot] = yroot;
  }
  else if (egraph->uf.rank[yroot] < egraph->uf.rank[xroot]) {
    egraph->uf.parent[yroot] = xroot;
  } 
  else {
    egraph->uf.parent[yroot] = xroot;
    egraph->uf.rank[xroot]++;
  }

}

// Perform e-matching on the e-graph
// Returns a tuple of substitutions and e-class IDs for nodes that match the pattern
// The substitution map maps variables in the pattern to e-class IDs in the e-graph

EMatchingResult eMatch(EGraph* egraph, ENode* pattern) {
  EMatchingResult result;
  result.substitutions = malloc(sizeof(int) * pattern->size);

  for (int i = 0; i < egraph->hashcons.size; i++) {

    if (egraph->hashcons.nodes[i] != NULL) {

      if (strcmp(egraph->hashcons.nodes[i]->function_symbol, pattern->function_symbol) == 0) {
        bool same = true;

        for (int j = 0; j < egraph->hashcons.nodes[i]->size; j++) {

          if (pattern->eclass_ids[j] >= 0) {

            if (egraph->hashcons.nodes[i]->eclass_ids[j] != pattern->eclass_ids[j]) {
              same = false;
              break;
            }
          }
          else {
            result.substitutions[j] = egraph->hashcons.nodes[i]->eclass_ids[j];
          }
        }

        if (same) {
          result.eclass_id = egraph->hashcons.eclass_ids[i];
          return result;
        }

      }
    }
  }

  result.eclass_id = -1;
  return result;
}

int main(int argc, char** argv) {
    
  int num_nodes;
  printf("Enter number of nodes.");
  scanf("%d", &num_nodes);
  EGraph *egraph = buildEGraph(num_nodes);

  ENode node1;
  printf("Enter function symbol.");
  node1.function_symbol = "f";
  node1.eclass_ids = malloc(sizeof(int) * 2);
  node1.eclass_ids[0] = 0;
  node1.eclass_ids[1] = 1;
  node1.size = 2;
  int eclass_id1 = add(egraph, &node1);

  ENode node2;
  node2.function_symbol = "f";
  node2.eclass_ids = malloc(sizeof(int) * 2);
  node2.eclass_ids[0] = 2;
  node2.eclass_ids[1] = 1;
  node2.size = 2;
  int eclass_id2 = add(egraph, &node2);

  ENode node3;
  node3.function_symbol = "g";
  node3.eclass_ids = malloc(sizeof(int) * 1);
  node3.eclass_ids[0] = 3;
  node3.size = 1;
  int eclass_id3 = add(egraph, &node3);

  merge(egraph, eclass_id1, eclass_id2);

  ENode pattern1;
  pattern1.function_symbol = "f";
  pattern1.eclass_ids = malloc(sizeof(int) * 2);
  pattern1.eclass_ids[0] = -1; // Variable
  pattern1.eclass_ids[1] = 1;
  pattern1.size = 2;
  EMatchingResult result1 = eMatch(egraph, &pattern1);
  printf("E-class ID: %d\n", result1.eclass_id);
  printf("Substitution: %d %d\n", result1.substitutions[0], result1.substitutions[1]);

  ENode pattern2;
  pattern2.function_symbol = "g";
  pattern2.eclass_ids = malloc(sizeof(int) * 1);
  pattern2.eclass_ids[0] = -1; 
  pattern2.size = 1;
  EMatchingResult result2 = eMatch(egraph, &pattern2);
  printf("E-class ID: %d\n", result2.eclass_id);
  printf("Substitution: %d\n", result2.substitutions[0]);

  return 0;
}
