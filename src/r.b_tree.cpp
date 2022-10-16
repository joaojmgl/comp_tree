#include "all_trees.hpp"
ofstream arq_rb("Remoção Red Black");


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

void remove_rb(Tree **rb, Tree *r, Record t){
Tree *aux = r;
Tree *aux1;
// cout<<"merda"<<endl;
arq_rb<<"O numero """<<t.key<<""" foi removido.\n";
bool original_color=aux->cor;
if(aux->left==nullptr){
  // arq_rb<<"O numero """<<t.key<<""" foi removido.\n"; 
  aux1 = r->right;

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
  // arq_rb<<"O numero """<<t.key<<""" foi removido.\n"; 
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
      aux1->reg.key=404;
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
  Tree *sec=aux1;
  if (original_color)
    delete_fixup(rb,aux1);
  if (sec->reg.key==404){
    if (sec==sec->pai->left)
      sec->pai->left=nullptr;
    else
      sec->pai->right=nullptr;
    delete sec;
  }
  delete r;
}


void Transplante_rb(Tree **rb, Tree *r, Tree *prox){
  if (r->pai==nullptr)
    (*rb)=prox;
  else if(r==r->pai->left)
    r->pai->left=prox;
  else
    r->pai->right=prox;
  prox->pai=r->pai;
}

void remove_search_rb(Tree **rb,Tree **aux, Record r){
  if (*aux == nullptr){ 
    arq_rb<<"Numero não encontrado: "<<r.key<<"\n";
    return;
  }
    
  if (r.key < (*aux)->reg.key){ 
    remove_search_rb(rb, &(*aux)->left, r);
    return; 
  }
  if (r.key > (*aux)->reg.key){ 
    remove_search_rb(rb, &(*aux)->right, r); 
    return; 
  }

  if ((*rb)->right==nullptr && (*rb)->left==nullptr){
    delete (*rb);
    (*rb)=nullptr;
    return;
  } 
  remove_rb(rb,(*aux),r);
  
} 


Tree *TreeMinimun(Tree **aux){
  if ((*aux)->right != nullptr){
    return TreeMinimun(&(*aux)->right);
  }
  else{
    return (*aux);
  }
  return nullptr;
} 



void delete_fixup(Tree **rb, Tree *v){
  while (v!=(*rb)&&v->cor){
    if (v==v->pai->left){
      Tree* aux=v->pai->right;
      if (aux!=nullptr){
        if (!aux->cor){
          aux->cor=true;
          v->pai->cor=false;
          rotacaoSimplesEsquerda_rb(rb,v->pai);
          aux=v->pai->right;
        }
        if ((aux->right==nullptr||aux->right->cor)&&(aux->left==nullptr||aux->left->cor)){
          aux->cor=false;
          v=v->pai;
        }
        else if(aux->right==nullptr||aux->right->cor){
          aux->left->cor=true;
          aux->cor=false;
          rotacaoSimplesDireita_rb(rb,aux);
          aux=v->pai->right;
        }
        if(aux->right!=nullptr&&!aux->right->cor){
          aux->cor=v->pai->cor;
          v->pai->cor=true;
          aux->right->cor=true;
          rotacaoSimplesEsquerda_rb(rb,v->pai);
          v=(*rb);
        }
      }
      else
        v=v->pai;
    }
    else{
      Tree* aux=v->pai->left;
      if (aux!=nullptr){
        if (!aux->cor){
          aux->cor=true;
          v->pai->cor=false;
          rotacaoSimplesDireita_rb(rb,v->pai);
          aux=v->pai->left;
        }
        if ((aux->right==nullptr||aux->right->cor)&&(aux->left==nullptr||aux->left->cor)){
          if(aux)
            aux->cor=false;
          v=v->pai;
        }
        else if(aux->left==nullptr||aux->left->cor){
          aux->right->cor=true;
          aux->cor=false;
          rotacaoSimplesEsquerda_rb(rb,aux);
          aux=v->pai->left;
        }
        if(aux->left!=nullptr&&!aux->left->cor){
          aux->cor=v->pai->cor;
          v->pai->cor=true;
          aux->left->cor=true;
          rotacaoSimplesDireita_rb(rb,v->pai);
          v=(*rb);
        }
      }
      else
        v=v->pai;
    }
  }
  v->cor=true;  
}