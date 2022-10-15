#include "all_trees.hpp"


void insertFixUp(Tree **raiz, Tree *child){
  Tree *tio;

  while((child != *raiz) && (child->pai->cor == false)){
      
      if(child->pai == child->pai->pai->left){
        
        tio = child->pai->pai->right;

        //caso 1:
        if((tio != NULL) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->right){
            child = child->pai;
            rotacaoSimplesEsquerda_rb(raiz, child);
          }
          
          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesDireita_rb(raiz, child->pai->pai);
        }

      }else{
        
        tio = child->pai->pai->left;
        
        //caso 1
        if((tio != NULL) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->left){
            child = child->pai;
            rotacaoSimplesDireita_rb(raiz, child);
          }

          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesEsquerda_rb(raiz, child->pai->pai);      
        }

      }

  }

  (*raiz)->cor = true;
}


void insertTree_rb(Tree **t, Tree **pai, Tree **raiz, Record r){
  
  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->left= NULL; 
    (*t)->right = NULL; 
    (*t)->pai = pai!=t?*pai:NULL;
    (*t)->cor = false; //false: vermelho  true:preto
    (*t)->reg = r; 
    insertFixUp(raiz, *t);
    
  } else { 

    if(r.key < (*t)->reg.key){
      insertTree_rb(&(*t)->left, t, raiz, r);
      return;
    }
    
    if(r.key > (*t)->reg.key){
      insertTree_rb(&(*t)->right, t, raiz, r);
      return;
    }

  }

}

void rotacaoSimplesEsquerda_rb(Tree **raiz, Tree *child){
  Tree *x, *y;

  x = child;
  y = child->right;
  x->right = y->left;

  if(y->left!= NULL)
    y->left->pai = x;

  y->pai = x->pai;
  
  if(x->pai == NULL)
    *raiz = y;

  else{

    if(x == x->pai->left)
      x->pai->left= y;

    else
      x->pai->right = y;
  
  }

  y->left= x;
  x->pai = y;
}


void rotacaoSimplesDireita_rb(Tree **raiz, Tree *child){
  Tree *x, *y;

  x = child;
  y = child->left;
  x->left = y->right;

  if(y->right != NULL)
    y->right->pai = x;

  y->pai = x->pai;
  
  if(x->pai == NULL){
    *raiz = y;
  }

  else{

    if(x == x->pai->right)
      x->pai->right = y;

    else
      x->pai->left = y;
  
  }

  y->right = x;
  x->pai = y;
  
}

// void remove_search_rb(Tree **raiz,Tree **sucessor,Record r){


  
// }

void remove_rb(Tree **rb, Tree *r){
Tree *aux = r;
Tree *aux1;
bool original_color=aux->cor;
if(aux->left==nullptr){
  aux1 = r->right;//x = aux1 y=aux valor=r

  if (aux1==nullptr)
  {
    aux1= new Tree;
    aux1->reg.key=42;
    aux1->cor=true;
    r->right=aux1;
  }
  Transplante_rb(rb,r,r->right);
  aux1->pai = r->pai;
} else if(r->right == nullptr){
  aux1 = r->left;
  if(aux1 == nullptr){
    aux1 = new Tree;
    aux1->reg.key = 42;
    aux1->cor = true;
    r->left = aux1;
  }
  Transplante_rb(rb,r,r->left);
  aux1->pai=r->pai;
}else{
    aux=TreeMinimun(&r->left);
    original_color=aux->cor;
    aux1=aux->left;
    if (aux1==nullptr){
      aux1=new Tree;
      aux1->pai=aux;
      aux1->item.key=404;
      aux1->cor=true;
      aux->left=aux1;
    }
    if (aux->pai==r){
      aux1->pai=aux;
    }
    else{
      Transplante_rb(rb,aux,aux->left);
      aux->left=r->left;
      aux->left->pai=aux;
    }
    Transplante_rb(rb,r,aux);
    aux->right=r->right;
    aux->right->pai=aux;
    aux->cor=r->cor;
  }
  Tree *aux=aux1;
  if (original_color)
    RBDeleteFixup(rb,aux1);
  if (aux->item.key==404){
    if (aux==aux->pai->left)
      aux->pai->left=nullptr;
    else
      aux->pai->right=nullptr;
    delete aux;
  }
  delete r;
}


