 /**
  * Basic (and not-so-basic) functions for tree operations
  *
  * Here's a translation of that language 
  * from an underdeveloped country to help you
  *
  * Functions:
  * alocarNoh                   = alloc a new node
  * alturaNoh                   = counts the height of the tree
  * buscarNoh                   = search for a value
  * imprimirArvoreEmOrdem       = print inorder
  * imprimirArvorePosOrdem      = print postorder
  * imprimirArvorePreOrdem      = print preorder
  * imprimirArvoreFormatada     = embellished print
  * imprimirArvoreNivelada      = print by levels
  * imprimirArvoreComParenteses = print with parenthesis
  * inserirNoh                  = insert a new node
  * inserirNohArvoreBalanceada  = insert a new balanced node
  * profundidadeNoh             = depth of the node
  * quantidadeNohs              = count nodes
  * quickSort                   = sorting algorithm. the best in my humble opinion
  * removerArvore               = delete entire tree
  * removerNoh                  = delete a single node
  * somaFolhas                  = sum the leaf nodes
  * somaInterna                 = sum the branch nodes
  *
  * Words:
  * esquerda = left
  * direita  = right
  * arvore   = tree
  * raiz     = root
  * valor    = value
  * inicio   = start
  * fim      = end
  * 
  * mersonfufu@gmail.com
  *
  */

// .h
typedef struct no stNo;
stNo * alocarNoh(int);
int alturaNoh(stNo *);
void buscarNoh(stNo *, int);
void imprimirArvoreEmOrdem(stNo *);
void imprimirArvorePosOrdem(stNo *);
void imprimirArvorePreOrdem(stNo *);
void imprimirArvoreFormatada(stNo *, int);
void imprimirArvoreNivelada(stNo *, int);
void imprimirArvoreComParenteses(stNo *);
stNo * inserirNoh(stNo *, stNo *);
stNo * inserirNohArvoreBalanceada(stNo *, int *, int, int);
int profundidadeNoh(stNo *, int, int);
int quantidadeNohs(stNo *);
void quickSort(int *, int, int);
stNo * removerArvore(stNo *);
stNo * removerNoh(stNo *, int);
int somaFolhas(stNo *);
int somaInterna(stNo *);