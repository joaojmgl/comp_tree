#include "all_trees.hpp"
#include "prep_doc.hpp"
#include <map>
#include<unordered_map>
using namespace std;

void insert(Tree **avl,Tree **rb, Tree **b, Record r, string arquivo);
void insertmap(map<float,float>cmap,Record r, string arquivo);
void search(Tree **avl,Tree **rb, Tree **b, Tree **aux, Record r);
void remove(Tree **avl,Tree **rb, Tree **b, Record r);
void Swap(float *a, float *b);
void Partition(vector<float>vc, int p, int r, int *i, int *j);
void QuickSort(vector<float>vc, int p, int r, int i, int j);
float recursive_binary_search(vector<float>vc, int begin, int end, float item);
void cont_remove();
int cont_rotacao(int rotacao_sdireita,int rotacao_sesquerda,int rotacao_ddireita, int rotacao_desquerda);
void insert_vector(vector<float>vc, Record r, string arquivo);
void search_vector(vector<float>vc, Record r);
void search_map(map<float,float>cmap, Record r, string arquivo);
void insertmap(map<float,float>cmap,Record r, string arquivo);
void removemap(map<float,float>cmap,Record r, string arquivo);
void searchu_map(unordered_map<float,float>cmap, Record r, string arquivo);
void insertu_map(unordered_map<float,float>cmap,Record r, string arquivo);
void removeu_map(unordered_map<float,float>cmap,Record r, string arquivo);


// void vector_caomp(vector<float>vc);