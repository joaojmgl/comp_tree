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
 
void remove_search_binari(Tree **t, Record r){
	Tree *aux;
  	if (*t == NULL){ 
  		arq_b<<"Numero não encontrado: "<<r.key<<endl;
    	return;
  	}

  	if (r.key < (*t)->reg.key){ 
      remove_search_binari(&(*t)->left, r); 
      // arq_b<<"O numero """<<r.key<<""" foi removido.\n"; 
      return; 
    }
  	if (r.key > (*t)->reg.key){ 
      remove_search_binari(&(*t)->right, r); 
      // arq_b<<"O numero """<<r.key<<""" foi removido.\n"; 
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
// void pesquisa_b(Tree **b, Tree **aux, Record r){
//   // cout<<r.key<<endl;
// 	if(*b == NULL){
//     // cout<<r.key<<endl;
// 		// printf("[ERROR]: Node not found!");
// 		return;
// 	}
//   if((*b)->reg.key > r.key){ 
//     pesquisa_b(&(*b)->left, aux, r); 
//     removeTree_binari( b,r);
//     // cout<<r.key<<endl;
//     return;
//   }
// 	if((*b)->reg.key < r.key){ 
//     pesquisa_b(&(*b)->right, aux, r);
//     removeTree_binari(b, r);
//     // cout<<r.key<<endl;
//     return;
//   }
// 	*aux = *b;
// }



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
      //printf(" Entrei leftuerda! ");
    }

    if(no.p->right != NULL){
      filho.p = no.p->right;
      Enfileira(&q, filho);
      //printf(" Entrei direita! ");
    }

  }


}