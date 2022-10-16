#include "prep_doc.hpp"
#include "all_trees.hpp"
#include "compar_tree.hpp"
Record numeros;
Tree *raiz_avl =  CreateTree();
Tree *raiz_rb = CreateTree();
Tree *raiz_b =CreateTree();
Tree *aux =  CreateTree();
vector<float>vc;
int main(){
int select;

cout<<"|_________________Comparação de estruturas___________________|"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|"<<" Para comparar um arquivos com 500 numeros digite 1         |"<<endl;
cout<<"|"<<" Para comparar um arquivos com 5000 numeros digite 2        |"<<endl;
cout<<"|"<<" Para comparar um arquivos com 50000 numeros digite 3       |"<<endl;
cout<<"|"<<" Para comparar um arquivos com 500000 numeros digite 4      |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|                                                            |"<<endl;
cout<<"|____________________________________________________________|"<<endl;
cin>>select;
switch (select)
{
case 1:
insert_500(&raiz_avl,&raiz_rb, &raiz_b,numeros,vc);

    break;
case 2:
insert_5000(&raiz_avl,&raiz_rb, &raiz_b,numeros,vc);
break;
case 3:
insert_50000(&raiz_avl,&raiz_rb, &raiz_b,numeros,vc);
search(&raiz_avl,&raiz_rb,&raiz_b,numeros,vc);
break;

case 4:
insert_500000(&raiz_avl,&raiz_rb, &raiz_b,numeros,vc);
// central(raiz_rb);
search(&raiz_avl,&raiz_rb,&raiz_b,numeros,vc);
break;




default:
    break;
}
}