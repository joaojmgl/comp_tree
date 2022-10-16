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
    <p aling="center"> <img scr=img/redblack.gif/></p>
- O balenciamento da arvore avl se da por meio de rotações.
    - Rotação simples para direita:
        <p aling="center"> <img scr=img/direita.gif/></p>
    - Rotação simples para esquerda: 
        <p aling="center"> <img scr=img/esquerda.gif/></p>
    - Rotação dupla para direita:
        <p aling="center"> <img scr=img/dupla_direita.gif/></p>
    - Rotação dupla para esquerda:
        <p aling="center"> <img scr=img/dupla_esquerda.gif/></p>


### Arvore Red Black:
A estrutura de arvore conhecida como "red black" esta dentro do grupo de estruturas de arvores balanciadas.
Esta estrutura usa um metodo de restrição de suas inserções pela coloração de seus nós, esta estrutura garante que nem um de seus caminhos tera comprimento maior que duas vezes o comprimento de qualquer outro caminho.

- Os nós adquirem a cor vermelho ou preto.
- A raiz sempre sera preta.
- Os filhos dos nós folhas(null) são pretos.
- Um nó é vermelho seus vizinho são pretos. 
- O caminho para qualquer nó apresenta o mesmo numero de nos pretos. 
- Todo novo nó inserido começa vermelho.

- O balanciamento das subarvore de uma arvore redblack se é dado na hora da inserção e pode varias em 3 casos:
    - Caso 1: A inserção de um nó vermelho deve GARANTIR que seu pai e tio sejam pretos.
        - Correção: Faça o pai e o tio se tornarem pretos, o novo item na recursão (i.e., pai do pai) se torna vermelho. Reorganize os ponteiros um nível acima.
    - Caso 2: O tio de um item é preto, o item e seu pai são vermelhos e o item é o filho da direita.
        - Correção: Rotação para a esquerda a partir da posição do pai e do item.
    - Caso 3: O tio do item é preto, o item e seu pai são vermelhos e o item é o filho da esquerda.
        - Correção: Modifique a cor do item do nível acima (11) e gere uma rotação a direita.

 <p aling="center"> <img scr=img/redblack.gif/></p>
  > Imagem ilustrando todos os casos de balanciamento

- A remoção de um item pode gerar o um total de 5 casos sendo sendo que o caso 4 se divide em mais 4 casos:
- Caso 1: O nó a ser removido é vermelho e possui apenas um único filho ou não possui filhos.
    - Correção: Remoção análoga ao de uma árvore binária comum.
- Caso 2: O nó a ser removido é vermelho e seu sucessor também é vermelho
    - Correção: Remoção análoga ao de uma árvore binária comum.
- Caso 3: O nó a ser removido é preto e seu sucessor é vermelho
    - Correção: Remova o nó, substitua pelo sucessor e pinte o sucessor de preto.
- Caso 4: O nó a ser removido e seu sucessor são pretos(doble black):
    - Considere:
    - z: O nó a ser removido.
    - y: o sucessor de z.
    - x: O filho do sucessor antes de qualquer modificação.
    - w: O irmão de x antes da remoção de z.
    - Caso 4.1: O irmão w de x é vermelho.
        - Correção: rocar as cores de w e x.pai e realizar rotação à esquerda tendo como ponto de observação x.pai.
    - Caso 4.2: O irmão w de x é preto e ambos os filhos de w são pretos.
        - Correção: Atualizamos w para vermelho, atualizamos x levando-o para o se pai e repetimos o processo a partir do novo x.
    - Caso 4.3:  O irmão w de x é preto, o filho esquerdo de w é vermelho e o da direita preto.
        - Correção: Troca-se a cor de w e de seu filho esquerdo, rotaciona a árvore para a direita usando como pivô w e neste ponto, o novo irmão wde x é preto com o filho da direita na cor vermelha, o que nos leva ao caso 4.4.
    - Caso 4.4: O irmão w de x é preto e o filho direito de w é vermelho.
        - Correção: Rotaciona a árvore para a esquerda usando como pivô x.pai, w é pintado com a cor de x.pai, x.pai é pintado de preto e pintar o filho direito de w de preto.



## Inserção 