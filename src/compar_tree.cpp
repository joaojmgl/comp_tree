#include "compar_tree.hpp"

void insert_500(Tree **avl,Tree **b, Tree **rb, Record r,vector<float>vc){
    float z=0;
    float time_taken_avl=0, time_taken_rb=0,time_taken_b=0;
    ifstream arq;
    string n;
    clock_t start;
    // int cont=0;
    string::size_type sz;
    new_arq_500(z);
    arq.open("500_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof())
            {
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_avl(avl,r);
                
            }
            start = clock() - start;
            time_taken_avl =  (float) start/CLOCKS_PER_SEC;
            }
        cout<<"Tempo gasto na inserção de 500 numeros na arvore AVL: ";
        cout<<time_taken_avl<<endl;
        
        arq.close();
        arq.open("500_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_rb(rb,rb,rb,r);
            
            }
            start = clock() - start;
            time_taken_rb = (float) start/CLOCKS_PER_SEC;
        }
        cout<<"Tempo gasto na inserção de 500 numeros na arvore Red Black: ";
        cout<<time_taken_rb<<endl;
        arq.close();
        arq.open("500_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_binari(b,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
        cout<<"Tempo gasto na inserção de 500 numeros na arvore binaria: ";
        cout<<time_taken_b<<endl;
        arq.close();
        arq.open("500_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof())
            {
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                vc.push_back(r.key);
                
            }
            int size=vc.size();
            QuickSort(vc,0,size-1,0,0);

            start = clock() - start;
            time_taken_avl =  (float) start/CLOCKS_PER_SEC;
            }
        cout<<"Tempo gasto na inserção de 500000 numeros na arvore AVL: ";
        cout<<time_taken_avl<<endl;

}

void insert_5000(Tree **avl,Tree **b, Tree **rb, Record r,vector<float>vc){
    float z=0;
    float time_taken_avl=0, time_taken_rb=0,time_taken_b=0;
    ifstream arq;
    string n;
    clock_t start;
    // int cont=0;
    string::size_type sz;
    new_arq_5000(z);
    arq.open("5000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof())
            {
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_avl(avl,r);
                
            }
            start = clock() - start;
            time_taken_avl =  (float) start/CLOCKS_PER_SEC;
            }
        cout<<"Tempo gasto na inserção de 5000 numeros na arvore AVL: ";
        cout<<time_taken_avl<<endl;
        
        arq.close();
        arq.open("5000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_rb(rb,rb,rb,r);
            
            }
            start = clock() - start;
            time_taken_rb = (float) start/CLOCKS_PER_SEC;
        }
        cout<<"Tempo gasto na inserção de 5000 numeros na arvore Red Black: ";
        cout<<time_taken_rb<<endl;
        arq.close();
        arq.open("5000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_binari(b,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
        cout<<"Tempo gasto na inserção de 5000 numeros na arvore binaria: ";
        cout<<time_taken_b<<endl;
        arq.close();
        arq.open("5000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof())
            {
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                vc.push_back(r.key);
                
            }
            int size=vc.size();
            QuickSort(vc,0,size-1,0,0);

            start = clock() - start;
            time_taken_avl =  (float) start/CLOCKS_PER_SEC;
            }
        cout<<"Tempo gasto na inserção de 500000 numeros na arvore AVL: ";
        cout<<time_taken_avl<<endl;



}


void insert_50000(Tree **avl,Tree **b, Tree **rb, Record r,vector<float>vc){
    float z=0;
    float time_taken_avl=0, time_taken_rb=0,time_taken_b=0;
    ifstream arq;
    string n;
    clock_t start;
    // int cont=0;
    string::size_type sz;
    new_arq_50000(z);
    arq.open("50000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof())
            {
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_avl(avl,r);
                
            }
            start = clock() - start;
            time_taken_avl =  (float) start/CLOCKS_PER_SEC;
            }
        cout<<"Tempo gasto na inserção de 50000 numeros na arvore AVL: ";
        cout<<time_taken_avl<<endl;
        
        arq.close();
        arq.open("50000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_rb(rb,rb,rb,r);
            
            }
            start = clock() - start;
            time_taken_rb = (float) start/CLOCKS_PER_SEC;
        }
        cout<<"Tempo gasto na inserção de 50000 numeros na arvore Red Black: ";
        cout<<time_taken_rb<<endl;
        arq.close();
        arq.open("50000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_binari(b,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
        cout<<"Tempo gasto na inserção de 50000 numeros na arvore binaria: ";
        cout<<time_taken_b<<endl;
        arq.close();
        arq.open("50000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof())
            {
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                vc.push_back(r.key);
                
            }
            int size=vc.size();
            QuickSort(vc,0,size-1,0,0);

            start = clock() - start;
            time_taken_avl =  (float) start/CLOCKS_PER_SEC;
            }
        cout<<"Tempo gasto na inserção de 500000 numeros na arvore AVL: ";
        cout<<time_taken_avl<<endl;



}

void insert_500000(Tree **avl,Tree **rb, Tree **b, Record r,vector<float>vc){
    float z=0;
    float time_taken_avl=0, time_taken_rb=0,time_taken_b=0;
    ifstream arq;
    string n;
    clock_t start;
    // int cont=0;
    string::size_type sz;
    new_arq_500000(z);
    arq.open("500000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof())
            {
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_avl(avl,r);
            }
            start = clock() - start;
            time_taken_avl =  (float) start/CLOCKS_PER_SEC;
            }
        cout<<"Tempo gasto na inserção de 500000 numeros na arvore AVL: ";
        cout<<time_taken_avl<<endl;
        
        arq.close();
        arq.open("500000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<"buguei1"<<endl;
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_rb(rb,rb,rb,r);
            
            }
            start = clock() - start;
            time_taken_rb = (float) start/CLOCKS_PER_SEC;
        }
        cout<<"Tempo gasto na inserção de 500000 numeros na arvore Red Black: ";
        cout<<time_taken_rb<<endl;
        arq.close();
        arq.open("500000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_binari(b,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
        cout<<"Tempo gasto na inserção de 500000 numeros na arvore binaria: ";
        cout<<time_taken_b<<endl;
        arq.close();
        arq.open("500000_num.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof())
            {
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                vc.push_back(r.key);
                
            }
            int size=vc.size();
            QuickSort(vc,0,size-1,0,0);

            start = clock() - start;
            time_taken_avl =  (float) start/CLOCKS_PER_SEC;
            }
        cout<<"Tempo gasto na inserção de 500000 numeros na arvore AVL: ";
        cout<<time_taken_avl<<endl;


}
void search(Tree **avl,Tree **rb, Tree **b,Record r,vector<float>vc){
    clock_t start;
    float time_taken_b=0;
    string n;
    ifstream arq;
    float num=0;
    // int cont=0;
    string::size_type sz;
    arq_search(num);
    arq.open("search.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                r.value=1;
                remove_search_binari(b,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
    cout<<"Tempo gasto na pesquisa de 100000 numeros na arvore binaria: ";
    cout<<time_taken_b<<endl;
    arq.close();
    arq.open("search.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                remove_search_avl(avl,avl,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
    cout<<"Tempo gasto na pesquisa de 100000 numeros na arvore avl: ";
    cout<<time_taken_b<<endl;
    arq.close();
    arq.open("search.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                remove_search_rb(rb,rb,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
    cout<<"Tempo gasto na pesquisa de 100000 numeros na arvore red black: ";
    cout<<time_taken_b<<endl;
    int size=vc.size();
    arq.close();
    arq.open("search.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                // cout<<n<<endl;
                r.key=stof(n,&sz);
                recursive_binary_search(vc,0, size-1, r.key);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
    cout<<"Tempo gasto na pesquisa de 100000 numeros na pesquisa bianria de um vector: ";
    cout<<time_taken_b<<endl;


}

void Partition(vector<float>vc, int p, int r, int *i, int *j){
	int pivo;
	int idx = (p+r)/2; //4
	*i = p; //0
	*j = r; //9
	pivo = vc[idx];

	do{
    while(vc[*i] < pivo && *i < r)
			*i = *i + 1;
		while(vc[*j] > pivo && *j > p)
			*j = *j - 1;
		if(*i<=*j){
			Swap(&vc[*i], &vc[*j]);
			*i = *i + 1;
			*j = *j - 1;
			// vc->swap++;
		}

	}while(*i<=*j);
	
}


void QuickSort(vector<float>vc, int p, int r, int i, int j){
	
	Partition(vc, p, r, &i, &j);
	// printf("INÍCIO:%d, FIM:%d --> \t",p,r);
	// Imprime(v);
	if(j > p)
		QuickSort(vc, p, j, i, j);
	if(i < r)
		QuickSort(vc, i, r, i, j);
}

void Swap(float *a, float *b){
	float aux = *a;
	*a = *b;
	*b = aux;
}

float recursive_binary_search(vector<float>vc, int begin, int end, float item)
{
    int i = (begin + end) / 2;

    if (begin > end) {
        return -1;
    }

    if (vc[i] == item) {
        return i;
    }

    if (vc[i] < item) {
        return recursive_binary_search(vc, i + 1, end, item);

    } else {  // vector[i] > item
        return recursive_binary_search(vc, begin, i - 1, item);
    }
}
