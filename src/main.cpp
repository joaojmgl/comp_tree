#include "prep_doc.hpp"
#include "all_trees.hpp"
#include "compar_tree.hpp"
Record numeros;
Tree *raiz_avl =  CreateTree();
Tree *raiz_rb = CreateTree();
Tree *raiz_b =CreateTree();
Tree *aux =  CreateTree();
int main(){

insert_500000(&raiz_avl,&raiz_b,&raiz_rb, numeros);
// central(raiz_avl);
search(&raiz_avl,&raiz_rb,&raiz_b,&aux,numeros);
}