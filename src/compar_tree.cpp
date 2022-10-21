#include "compar_tree.hpp"

void insert(Tree **avl,Tree **b, Tree **rb, Record r,string arquivo){
    // float z=0;
    float time_taken_avl=0, time_taken_rb=0,time_taken_b=0;
    ifstream arq;
    string n;
    clock_t start;
    // int cont=0;
    string::size_type sz;
    arq.open(arquivo);
        if(arq.is_open()){
            start = clock();
            while (!arq.eof())
            {
                getline(arq,n);
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_avl(avl,r);
                
            }
            start = clock() - start;
            time_taken_avl =  (float) start/CLOCKS_PER_SEC;
            }
        cout<<"Tempo gasto na inserção na arvore AVL: ";
        cout<<time_taken_avl<<endl;
        
        arq.close();
        arq.open(arquivo);
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_rb(rb,rb,rb,r);
            
            }
            start = clock() - start;
            time_taken_rb = (float) start/CLOCKS_PER_SEC;
        }
        cout<<"Tempo gasto na inserção na arvore Red Black: ";
        cout<<time_taken_rb<<endl;
        arq.close();
        arq.open(arquivo);
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                r.key=stof(n,&sz);
                r.value=1;
                insertTree_binari(b,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
        cout<<"Tempo gasto na inserção na arvore binaria: ";
        cout<<time_taken_b<<endl;
        arq.close();
}

void remove(Tree **avl,Tree **rb, Tree **b,Record r){
    clock_t start;
    float time_taken_b=0;
    string n;
    ifstream arq;
    float num=0;
    string::size_type sz;
    arq_search(num);
    arq.open("search.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                r.key=stof(n,&sz);
                r.value=1;
                binari_remove(b,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
    cout<<"Tempo gasto na remoção arvore binaria: ";
    cout<<time_taken_b<<endl;
    arq.close();
    arq.open("search.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                r.key=stof(n,&sz);
                avl_remove(avl,avl,r);

            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
    cout<<"Tempo gasto na remoção arvore avl: ";
    cout<<time_taken_b<<endl;
    arq.close();
    arq.open("search.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                r.key=stof(n,&sz);
                rb_remove(rb,rb,r);
        
            }
            // cout<<"buguei\n";
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
    cout<<"Tempo gasto na remoção arvore red black: ";
    cout<<time_taken_b<<endl;
    arq.close();
}


void insert_vector(vector<float>vc, Record r, string arquivo){
ifstream arq;
string n;
clock_t start;
float time_taken_avl=0;
string::size_type sz;
arq.open(arquivo);
if(arq.is_open()){
start = clock();
    while (!arq.eof()){
        getline(arq,n);
        r.key=stof(n,&sz);
        vc.push_back(r.key);        
    }
}
    int size =  vc.size();
    QuickSort(vc,0,size-1,0,0);
    start = clock() - start;
    time_taken_avl =  (float) start/CLOCKS_PER_SEC;
    cout<<"Tempo gasto na inserção em um vector: ";
    cout<<time_taken_avl<<endl;
   
}

void search_vector(vector<float>vc, Record r){
    clock_t start;
    float time_taken_b=0;
    string n;
    ifstream arq;
    float num=0;
    string::size_type sz;
    arq_search(num);
    int size=vc.size();
    arq.close();
    arq.open("search.txt");
    if(arq.is_open()){
        start = clock();
        while (!arq.eof()){
            getline(arq,n);
            r.key=stof(n,&sz);
            recursive_binary_search(vc,0, size-1, r.key);
                
        }
        start = clock() - start;
        time_taken_b =  (float) start/CLOCKS_PER_SEC;
    }
    cout<<"Tempo gasto na pesquisa bianria de um vector: ";
    cout<<time_taken_b<<endl;
}

void Partition(vector<float>vc, int p, int r, int *i, int *j){
	int pivo;
	int idx = (p+r)/2; 
	*i = p; 
	*j = r; 
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
			
		}

	}while(*i<=*j);
	
}


void QuickSort(vector<float>vc, int p, int r, int i, int j){
	
	Partition(vc, p, r, &i, &j);
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

    } else {  
        return recursive_binary_search(vc, begin, i - 1, item);
    }
}

void search(Tree **avl,Tree **rb, Tree **b,Tree **aux, Record r){
    clock_t start;
    float time_taken_b=0;
    string n;
    ifstream arq;
    float num=0;
    string::size_type sz;
    arq_search(num);
    arq.open("search.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                r.key=stof(n,&sz);
                r.value=1;
                pesquisa(avl,aux,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
    cout<<"Tempo gasto na pesquisa na arvore binaria: ";
    cout<<time_taken_b<<endl;
    arq.close();
    arq.open("search.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                r.key=stof(n,&sz);
                pesquisa(b,aux,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
    cout<<"Tempo gasto na pesquisa na arvore avl: ";
    cout<<time_taken_b<<endl;
    arq.close();
    arq.open("search.txt");
        if(arq.is_open()){
            start = clock();
            while (!arq.eof()){
                getline(arq,n);
                r.key=stof(n,&sz);
                pesquisa(rb,aux,r);
            
            }
            start = clock() - start;
            time_taken_b =  (float) start/CLOCKS_PER_SEC;
        }
    cout<<"Tempo gasto na pesquisa na arvore red black: ";
    cout<<time_taken_b<<endl;
    arq.close();
}


void removemap(map<float,float>cmap,Record r, string arquivo){
    float time_taken_avl=0;
    ifstream arq;
        string n;
        clock_t start;
        // int cont=0;
        string::size_type sz;
        arq.open(arquivo);
            if(arq.is_open()){
                start = clock();
                while (!arq.eof())
                {
                    getline(arq,n);
                    r.key=stof(n,&sz);
                    cmap.erase(r.key);
                    }
                start = clock() - start;
                time_taken_avl =  (float) start/CLOCKS_PER_SEC;
                }
            cout<<"Tempo gasto na remoção no map: ";
            cout<<time_taken_avl<<endl;

}


void search_map(map<float,float>cmap, Record r, string arquivo){
    float time_taken_avl=0;
    ifstream arq;
        string n;
        clock_t start;
        string::size_type sz;
        arq.open(arquivo);
            if(arq.is_open()){
                start = clock();
                while (!arq.eof())
                {
                    getline(arq,n);
                    r.key=stof(n,&sz);
                    cmap.find(r.key);
                    }
                start = clock() - start;
                time_taken_avl =  (float) start/CLOCKS_PER_SEC;
                }
            cout<<"Tempo gasto na pesquisa no map: ";
            cout<<time_taken_avl<<endl;

}

void insertmap(map<float,float>cmap,Record r, string arquivo){
    float time_taken_avl=0;
    ifstream arq;
        string n;
        clock_t start;
        string::size_type sz;
        arq.open(arquivo);
            if(arq.is_open()){
                start = clock();
                while (!arq.eof())
                {
                    getline(arq,n);
                    r.key=stof(n,&sz);
                    cmap.emplace(r.key,r.key);
                    }
                start = clock() - start;
                time_taken_avl =  (float) start/CLOCKS_PER_SEC;
                }
            cout<<"Tempo gasto na inserção no map: ";
            cout<<time_taken_avl<<endl;

}

void removeu_map(unordered_map<float,float>umap,Record r, string arquivo){
    float time_taken_avl=0;
    ifstream arq;
        string n;
        clock_t start;
        // int cont=0;
        string::size_type sz;
        arq.open(arquivo);
            if(arq.is_open()){
                start = clock();
                while (!arq.eof())
                {
                    getline(arq,n);
                    r.key=stof(n,&sz);
                    umap.erase(r.key);
                    }
                start = clock() - start;
                time_taken_avl =  (float) start/CLOCKS_PER_SEC;
                }
            cout<<"Tempo gasto na remoção no unordered_map: ";
            cout<<time_taken_avl<<endl;

}


void searchu_map(unordered_map<float,float>umap, Record r, string arquivo){
    float time_taken_avl=0;
    ifstream arq;
        string n;
        clock_t start;
        string::size_type sz;
        arq.open(arquivo);
            if(arq.is_open()){
                start = clock();
                while (!arq.eof())
                {
                    getline(arq,n);
                    r.key=stof(n,&sz);
                    umap.find(r.key);
                    }
                start = clock() - start;
                time_taken_avl =  (float) start/CLOCKS_PER_SEC;
                }
            cout<<"Tempo gasto na pesquisa no unordered_map: ";
            cout<<time_taken_avl<<endl;

}

void insertu_map(unordered_map<float,float>umap,Record r, string arquivo){
    float time_taken_avl=0;
    ifstream arq;
        string n;
        clock_t start;
        string::size_type sz;
        arq.open(arquivo);
            if(arq.is_open()){
                start = clock();
                while (!arq.eof())
                {
                    getline(arq,n);
                    r.key=stof(n,&sz);
                    umap.emplace(r.key,r.key);
                    }
                start = clock() - start;
                time_taken_avl =  (float) start/CLOCKS_PER_SEC;
                }
            cout<<"Tempo gasto na inserção no unordered_map: ";
            cout<<time_taken_avl<<endl;

}