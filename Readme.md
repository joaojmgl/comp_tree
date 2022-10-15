# Relatorio comparação de arvores:

    De acordo com a proposta apresentada pelo professor teriamos que comparar 3 tipos de estruturas de arvores diferentes com 4 entradas diferentes.

## Estrutura de arvores:

### Arvore Binaria:
    Considere uma arvore binaria cujos os nos admitem comparação.
        Supondo que os nos são do tipo inteiro, e as entradas são (5,4,7,9,8), temos essa estrutura:  
        (gif)

- Observe que a comparação ocorre no momento da inserção, numeros menores que a raiz(5) vão para subárvore esquerda e maiores para subárvore direita, usamos o mesmo raciociono para os demais nós.

### Arvore AVL 
    Esta estrutura veio para corrigir um problema encontrado na arvore binaria, onde, seu desempenho pode ser afetado pela forma com que o conjunto é apresentado para o metodo de inserção da arvore.
    Para solucionar esse problema gereamos oque chamamos de balanciado da arvore.

- O balenciamento se consiste em manter as subarvores esquerda e direita com uma altura aproximada.
- O algoritmo identifica subarvores desbalanciadas quando as alturas de suas subarvores diferencia em uma unidade.
    - (img)
- O balenciamento da arvore avl se da por meio de rotações.
    - Rotação simples para direita:
        (gif)
    - Rotação simples para esquerda: 
        (gif)
    - Rotação dupla para direita:
        (gif)
    - Rotação dupla para esquerda:
        (gif)


### Arvore Red Black:
A estrutura de arvore conhecida como "red black" esta dentro do grupo de estruturas de arvores balanciadas.
Esta estrutura usa um metodo de restrição de suas inserções pela coloração de seus nós, esta estrutura garante que nem um de seus caminhos tera comprimento maior que duas vezes o comprimento de qualquer outro caminho.

- Os nós adquirem a cor vermelho ou preto.
- A raiz sempre sera preta.
- Os filhos dos nós folhas(null) são pretos.
- Um nó é vermelho seus vizinho são pretos. 
- O caminho para qualquer nó apresenta o mesmo numero de nos pretos. 
- Todo novo nó inserido começa vermelho.

- O balanciamento das subarvore de uma arvore redblack se é dado na hr da inserção e pode varias em 3 casos:
 - Caso 1: 
        
    




## Inserção 