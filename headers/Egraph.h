#ifndef EGRAPH_H_
#define EGRAPH_H_

// Struct for an e-node
typedef struct {
  int size;
  char* function_symbol;
  int* eclass_ids;
} ENode;

// Struct for an e-class
typedef struct {
  ENode* nodes;
  int size;
} EClass;

// Union-find structure for e-class IDs
typedef struct {
  int* parent;
  int* rank;
} UnionFind;

// Hash table for mapping canonical e-nodes to e-class IDs
typedef struct {
  ENode** nodes;
  int* eclass_ids;
  int size;
} HashCons;

// E-graph struct
typedef struct {
  UnionFind uf;
  HashCons hashcons;
  EClass* eclass_map;
} EGraph;

typedef struct {
  int* substitutions;
  int eclass_id;
} EMatchingResult;

//functions 
EGraph* buildEGraph(int num_nodes)
int add(EGraph* egraph, ENode* node)
int find(EGraph* egraph, int x)
void merge(EGraph* egraph, int x, int y)
EMatchingResult eMatch(EGraph* egraph, ENode* pattern)
