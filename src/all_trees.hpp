#ifndef ALL_TREES_HPP
#define ALL_TREES_HPP

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	int key;
    int value; 
};

struct Tree{
	Record reg;
	float val;
	Tree *left, *right;
	Tree *pai; 
	bool cor;  
    int weight; 
 };


// R.B:
void rotacaoSimplesEsquerda_rb(Tree **raiz, Tree *child);
void rotacaoSimplesDireita_rb(Tree **raiz, Tree *child);
void insertFixUp(Tree **raiz, Tree *child);
void insertTree_rb(Tree **t, Tree **pai, Tree **raiz, Record r);
void rb_remove(Tree **raiz, Tree **sucessor, Record r);
void antecessor_rb(Tree **raiz, Tree **aux);
void remove_rb(Tree **rb, Tree *r, Record t);
void Transplante_rb(Tree **rb, Tree *r, Tree *prox);
Tree *TreeMinimun(Tree **aux);
void delete_fixup(Tree **rb, Tree *v);
void central_rb(Tree *t);
// AVL:
void insertTree_avl(Tree **t, Record r);
void avl_remove(Tree **t, Tree **f, Record r);
void rebalanceTree(Tree **t);
int getWeight(Tree **t);
int getMaxWeight(int left, int right);
void rotacaoSimplesDireita_avl(Tree **t);
void rotacaoSimplesEsquerda_avl(Tree **t);
void rotacaoDuplaDireita(Tree **t);
void rotacaoDuplaEsquerda(Tree **t);


// AVL e Binaria:
int isInTree(Tree *t, Record r); 
void antecessor(Tree **t, Tree *aux);
// Arvore bianaria basica:
bool TVazia(Tree **t);
void insertTree_binari(Tree **t, Record r);
void binari_remove(Tree **t, Record r);
void widthPath(Tree *t);
void pesquisa_b(Tree **b, Tree **aux, Record r);




// igual para todas as arvores.
Tree* CreateTree();
void pesquisa(Tree **t, Tree **aux, Record r);
void preordem(Tree *t);
void central(Tree *t);
void posordem(Tree *t);


#endif