#include "all_trees.hpp"
#include "fila.hpp"
ofstream arq_b("Remoção binario");

bool TVazia(Tree **t){
  return *t == NULL;
}

void insertTree_binari(Tree **t, Record r){

  if(TVazia(t)){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->left = NULL; 
    (*t)->right = NULL; 
    (*t)->reg = r; 
  
  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree_binari(&(*t)->left, r);
      
    }
    
    if(r.key > (*t)->reg.key){
      insertTree_binari(&(*t)->right, r);
    }
  
  }

}
 
void binari_remove(Tree **t, Record r){
	Tree *aux;
  	if (*t == NULL){ 
  		arq_b<<"Numero não encontrado: "<<r.key<<endl;
    	return;
  	}

  	if (r.key < (*t)->reg.key){ 
      binari_remove(&(*t)->left, r);
      return; 
    }
  	if (r.key > (*t)->reg.key){ 
      binari_remove(&(*t)->right, r); 
      return;
    }

  	if ((*t)->right == NULL){ 
      arq_b<<"O numero """<<r.key<<""" foi removido.\n"; 
  		aux = *t;  
  		*t = (*t)->left;
    	free(aux);
    	return;
  	}

  	if ((*t)->left != NULL){ 
      arq_b<<"O numero """<<r.key<<""" foi removido.\n"; 
      antecessor(&(*t)->left, *t); 
      return; 
    }

  	aux = *t;  
  	*t = (*t)->right;
  	free(aux);
}

void widthPath(Tree *t){
  Fila q;
  Item no, filho;
  
  FFVazia(&q);
  no.p = t;
  Enfileira(&q, no);

  while (!isVazia(&q)){

    Desenfileira(&q, &no);
    printf("%d ", no.p->reg.key);

    if(no.p->left != NULL){
      filho.p = no.p->left;
      Enfileira(&q, filho);
    }

    if(no.p->right != NULL){
      filho.p = no.p->right;
      Enfileira(&q, filho);
     
    }

  }


}