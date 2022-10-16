#include "all_trees.hpp"
#include "prep_doc.hpp"
using namespace std;

void insert_500(Tree **avl,Tree **rb, Tree **b, Record r,vector<float>vc);
void insert_5000(Tree **avl,Tree **rb, Tree **b, Record r,vector<float>vc);
void insert_50000(Tree **avl,Tree **rb, Tree **b, Record r,vector<float>vc);
void insert_500000(Tree **avl,Tree **rb, Tree **b, Record r,vector<float>vc);
void search(Tree **avl,Tree **rb, Tree **b, Record r,vector<float>vc);
void Swap(float *a, float *b);
void Partition(vector<float>vc, int p, int r, int *i, int *j);
void QuickSort(vector<float>vc, int p, int r, int i, int j);
float recursive_binary_search(vector<float>vc, int begin, int end, float item);
// void vector_caomp(vector<float>vc);