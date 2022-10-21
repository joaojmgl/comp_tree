#include "prep_doc.hpp"
#include "all_trees.hpp"
#include "compar_tree.hpp"
Record numeros;
float test;
string arquivo;
Tree *raiz_avl =  CreateTree();
Tree *raiz_rb = CreateTree();
Tree *raiz_b =CreateTree();
Tree *aux =  CreateTree();
vector<float>vc;
map<float,float>cmap;
unordered_map<float,float>umap;
int main(){
int select;
int range_arq=5100001;

cout<<"|______________________Comparação de estruturas_____________________________|"<<endl;
cout<<"|                                                                           |"<<endl;
cout<<"|                                                                           |"<<endl;
cout<<"| Para comparar um arquivos com 500 numeros digite 1.                       |"<<endl;
cout<<"| Para comparar um arquivos com 5000 numeros digite 2.                      |"<<endl;
cout<<"| Para comparar um arquivos com 50000(Apenas com arvores) numeros digite 3. |"<<endl;
cout<<"| Para comparar um arquivos com 500000(Apenas com arvores) numeros digite 4.|"<<endl;
cout<<"| Para comparar as estruturas de arvore com um vector                       |"<<endl;
cout<<"| com 50000 entradas  digite 5.                                             |"<<endl;
cout<<"| Para comparar as estruturas de arvore com um vector                       |"<<endl;
cout<<"| com 500000 entradas digite 6.                                             |"<<endl;
cout<<"|                                                                           |"<<endl;
cout<<"|                                                                           |"<<endl;
cout<<"|                                                                           |"<<endl;
cout<<"|                                                                           |"<<endl;
cout<<"|                                                                           |"<<endl;
cout<<"|                                                                           |"<<endl;
cout<<"|___________________________________________________________________________|"<<endl;
cin>>select;

switch (select)
{
case 1:
new_arq_500(test,&arquivo,range_arq);
insert_vector(vc,numeros,arquivo);
break;
case 2:
new_arq_5000(test,&arquivo,range_arq);
insert_vector(vc,numeros,arquivo);
search_vector(vc,numeros);
break;
case 3:
new_arq_50000(test,&arquivo,range_arq);
break;
case 4:
new_arq_500000(test,&arquivo,range_arq);
break;
case 5:
new_arq_50000(test,&arquivo,range_arq);
insert_vector(vc,numeros,arquivo);
search_vector(vc,numeros);
break;
case 6 :
new_arq_500000(test,&arquivo,range_arq);
insert_vector(vc,numeros,arquivo);
search_vector(vc,numeros);
break;
default:
    break;
}
insertmap(cmap,numeros,arquivo);
insertu_map(umap,numeros,arquivo);
insert(&raiz_avl,&raiz_rb, &raiz_b,numeros,arquivo);
cout<<"______________________________________"<<endl;
search(&raiz_avl,&raiz_rb,&raiz_b,&aux,numeros);
search_map(cmap, numeros,arquivo);
searchu_map(umap,numeros,arquivo);
cout<<"----------------------------------"<<endl;
removeu_map(umap,numeros,arquivo);
remove(&raiz_avl,&raiz_rb,&raiz_b,numeros);
removemap(cmap,numeros,arquivo);




}