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
    int value; // Valume utilizado na arvore binaria basica 
};

struct Tree{
	Record reg;
	float val;
	Tree *left, *right;
	Tree *pai; //específico para rubro negra
	bool cor;  //específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
    int weight; // Pronfudidade para arvore avl 
 };


// R.B:
void rotacaoSimplesEsquerda_rb(Tree **raiz, Tree *child);//ok
void rotacaoSimplesDireita_rb(Tree **raiz, Tree *child);//ok
void insertFixUp(Tree **raiz, Tree *child);//ok
void insertTree_rb(Tree **t, Tree **pai, Tree **raiz, Record r);//ok
void remove_search_rb(Tree **raiz, Tree **sucessor, Record r);
void antecessor_rb(Tree **raiz, Tree **aux);
void remove_rb(Tree **rb, Tree *r, Record t);
void Transplante_rb(Tree **rb, Tree *r, Tree *prox);
Tree *TreeMinimun(Tree **aux);
void delete_fixup(Tree **rb, Tree *v);
// AVL:
void insertTree_avl(Tree **t, Record r);//ok
void remove_search_avl(Tree **t, Tree **f, Record r);//ok
void rebalanceTree(Tree **t);//ok
int getWeight(Tree **t);//ok
int getMaxWeight(int left, int right);//ok
void rotacaoSimplesDireita_avl(Tree **t);//ok
void rotacaoSimplesEsquerda_avl(Tree **t);//ok
void rotacaoDuplaDireita(Tree **t);//ok
void rotacaoDuplaEsquerda(Tree **t);//ok
// void pesquisa_avl(Tree **t, Tree **aux, Record r);

// AVL e Binaria:
int isInTree(Tree *t, Record r); //ok
void antecessor(Tree **t, Tree *aux);//ok
// Arvore bianaria basica:
bool TVazia(Tree **t);//ok
void insertTree_binari(Tree **t, Record r);//ok
void remove_search_binari(Tree **t, Record r);//ok
void widthPath(Tree *t);//ok
void pesquisa_b(Tree **b, Tree **aux, Record r);




// igual para todas as arvores.
Tree* CreateTree();//ok
void pesquisa(Tree **t, Tree **aux, Record r);//ok
void preordem(Tree *t);//ok
void central(Tree *t);//ok
void posordem(Tree *t);//ok


#endif