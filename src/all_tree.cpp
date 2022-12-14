#include "all_trees.hpp"

Tree* CreateTree(){
	return NULL;
}
void pesquisa(Tree **t, Tree **aux, Record r){
	if(*t == NULL){
		return;
	}
  if((*t)->reg.key > r.key){ 
    pesquisa(&(*t)->left, aux, r);
    return;
  }
	if((*t)->reg.key < r.key){ pesquisa(&(*t)->right, aux, r); return;}
	*aux = *t;
}

void preordem(Tree *t)
{
  if(!(t == NULL)){
    preordem(t->left); 
    preordem(t->right); 
  }
}


void central(Tree *t)
{
  if(!(t == NULL)){
    central(t->left); 
    printf("%d\t", t->reg.key);
    central(t->right); 
  }
}

void posordem(Tree *t)
{
  if(!(t == NULL)){
    posordem(t->left); 
    posordem(t->right); 
    printf("%d\t", t->reg.key);
  }
}