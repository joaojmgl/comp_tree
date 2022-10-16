#include "all_trees.hpp"
ofstream arq("Remoção AVL");





void insertTree_avl(Tree **t, Record r){

  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->left   = NULL; 
    (*t)->right  = NULL; 
    (*t)->weight = 0;
    (*t)->reg    = r; 

  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree_avl(&(*t)->left, r);
      if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2){
      	if(r.key < (*t)->left->reg.key)
      		rotacaoSimplesDireita_avl(t);
      	else
      		rotacaoDuplaDireita(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      insertTree_avl(&(*t)->right, r);
      if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2){
      	if(r.key > (*t)->right->reg.key)
      		rotacaoSimplesEsquerda_avl(t);
      	else
      		rotacaoDuplaEsquerda(t);
      }
    }
  
  }

  (*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}

int isInTree(Tree *t, Record r){ // diferente 
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree(t->left, r) || isInTree(t->right, r);
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->right != NULL){ 
		antecessor(&(*t)->right, aux);
		return;
  	}
  	
  	aux->reg = (*t)->reg;
  	aux = *t; 
  	*t = (*t)->left;
  	free(aux);
} 

void rebalanceTree(Tree **t){
	int balance;
  	int left = 0;
  	int right = 0;

	balance = getWeight(&(*t)->left) - getWeight(&(*t)->right);
	if((*t)->left)
		left = getWeight(&(*t)->left->left) - getWeight(&(*t)->left->right);
	if((*t)->right)
		right = getWeight(&(*t)->right->left) - getWeight(&(*t)->right->right);

	if(balance == 2 && left >= 0)
		rotacaoSimplesDireita_avl(t);
	if(balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if(balance == -2 && right <= 0)
		rotacaoSimplesEsquerda_avl(t);
	if(balance == -2 && right > 0)
		rotacaoDuplaEsquerda(t); 	

}

void remove_search_avl(Tree **t, Tree **f ,Record r){
	Tree *aux1;
	if (*t == NULL){ 
  		arq<<"Numero não encontrado: "<<r.key<<"\n";
    	return;
	}	
  	if (r.key < (*t)->reg.key){ 
		remove_search_avl(&(*t)->left, t, r);
		// arq<<"O numero """<<r.key<<""" foi removido."; 
		return;
		}
  	if (r.key > (*t)->reg.key){ 
		remove_search_avl(&(*t)->right, t, r);
		// arq<<"O numero """<<r.key<<""" foi removido."; 
		return;
	}

  	if ((*t)->right == NULL){ 
		arq<<"O numero """<<r.key<<""" foi removido.\n"; 
  		aux1 = *t;  
  		*t = (*t)->left;
    	free(aux1);
    	rebalanceTree(f);
    	return;
  	}

  	if ((*t)->left != NULL){ 
		arq<<"O numero """<<r.key<<""" foi removido.\n"; 
  		antecessor(&(*t)->left, *t);
  		rebalanceTree(t);
  		rebalanceTree(f);
  		return;
  	}

  	aux1 = *t;  
  	*t = (*t)->right;
  	free(aux1);
  	rebalanceTree(t);
  	rebalanceTree(f); 	
  	
}
void pesquisa_avl(Tree **avl, Tree **aux, Record r){
//   cout<<r.key<<endl;
	if(*avl == NULL){
    // cout<<r.key<<endl;
		// printf("[ERROR]: Node not found!");
		return;
	}
  if((*avl)->reg.key > r.key){ 
    pesquisa_avl(&(*avl)->left, aux, r);
	// cout<<r.key<<endl; 
	// removeTree_avl(avl,avl);
    return;
  }
	if((*avl)->reg.key < r.key){
		pesquisa_avl(&(*avl)->right, aux, r);
		// cout<<r.key<<endl;
		// removeTree_avl(avl,avl);
		// cout<<r.key<<endl; 
		return;
	}
	*aux = *avl;
}




int getWeight(Tree **t){
	if(*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int left, int right){
	if(left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita_avl(Tree **t){
	Tree *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda_avl(Tree **t){
	Tree *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(Tree **t){
	rotacaoSimplesEsquerda_avl(&(*t)->left);
	rotacaoSimplesDireita_avl(t);
}

void rotacaoDuplaEsquerda(Tree **t){
	rotacaoSimplesDireita_avl(&(*t)->right);
	rotacaoSimplesEsquerda_avl(t);
}

