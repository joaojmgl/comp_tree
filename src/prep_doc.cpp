#include "prep_doc.hpp"



void new_arq_500(float numeros, string *arquivo,int range){
    ofstream arq("500_num.txt");
    string arquivo_500="500_num.txt";
    *arquivo = arquivo_500;
    for (int i = 0; i <= 499; i++)
    {
     numeros = rand()%range;
     if(i<499){
    arq << numeros << "\n";
    }else{
        arq<<numeros;
    }
    }
}    
void new_arq_5000(float numeros, string *arquivo,int range){
    ofstream arq("5000_num.txt");
    string arquivo_5000="5000_num.txt";
    *arquivo = arquivo_5000;
    for (int i = 0; i <= 4999; i++)
    {
     numeros = rand()%range;
     if(i<4999){
    arq << numeros << "\n";
    }else{
        arq<<numeros;
    }
    }
}
void new_arq_50000(float numeros, string *arquivo,int range){
    ofstream arq("50000_num.txt");
    string arquivo_5000="50000_num.txt";
    *arquivo = arquivo_5000;
    for (int i = 0; i <= 49999; i++)
    {
     numeros = rand()%range;
    if(i<49999){
    arq << numeros << "\n";
    }else{
        arq<<numeros;
    }
    }
}
void new_arq_500000(float numeros, string *arquivo,int range){
    ofstream arq("500000_num.txt");
    string arquivo_50000="500000_num.txt";
    *arquivo = arquivo_50000;
    for (int i = 0; i <= 499999; i++)
    {numeros = rand()%range;
    if(i<499999){
    arq << numeros << "\n";
    }else{
        arq<<numeros;
    }
    }

}

void arq_search(float numeros){
ofstream arq("search.txt");
    for (int i = 0; i <= 9999; i++)
    {
    numeros = rand()%5000;
    if(i<9999){
    arq << numeros << "\n";
    }else{
        arq<<numeros;
    }
    }

}