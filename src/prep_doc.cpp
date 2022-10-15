#include "prep_doc.hpp"



void new_arq_500(float numeros){
    ofstream arq("500_num.txt");
    for (int i = 0; i <= 500; i++)
    {
     numeros = rand()%500;
     arq << numeros<<"\n";
    }
}    
void new_arq_5000(float numeros){
    ofstream arq("5000_num.txt");
    for (int i = 0; i <= 5000; i++)
    {
     numeros = rand()%5000;
     arq << numeros << "\n";
    }
}
void new_arq_50000(float numeros){
    ofstream arq("50000_num.txt");
    for (int i = 0; i <= 50000; i++)
    {
     numeros = rand()%50000;
    arq << numeros << "\n";
    }
}
void new_arq_500000(float numeros){
    ofstream arq("500000_num.txt");
    for (int i = 0; i <= 499999; i++)
    {numeros = rand()%500000;
    if(i<499999){
    //  numeros = rand()%500000;
    arq << numeros << "\n";
    }else{
        arq<<numeros;
    }
    }

}

void arq_search(float numeros){
ofstream arq("search.txt");
    for (int i = 0; i <= 99999; i++)
    {
    numeros = rand()%500000;
    if(i<99999){
    //  numeros = rand()%500000;
    arq << numeros << "\n";
    }else{
        arq<<numeros;
    }
    }

}