#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mostraMat(int [4][5]);
void preencheMat(int mat[4][5]);

int main(){
    int *ptr;
    int i, j;    // variáveis simples para indice
    int v[5];    // vetor de 5 posicoes
    int v2[] = {1, 2, 3}; // vetor inicializado
    int m[4][5] = {0}; // matriz de 4 linhas, 5 colunas e 20 posicoes no total
    int m2[2][3] = {{1, 2, 3}, 
                   {4, 5, 6}}; // matriz 2x3 inicializada
    preencheMat(m);

    printf("\nImprimindo em modelo de matriz:\n");
    mostraMat(m);

    printf("\nNavegando mat como vetor crescente com ponteiro:\n");
    // navegar na matriz m usando ponteiros, e não abordagem [i][j] tradicional
    // ou seja, usando ponteiro podemos navegar linearmente na matriz bidimensional
    ptr = &m[0][0]; // endereco do primeiro elemento da matriz 4x5
    // ptr = m;  é igual a ptr = &m[0][0]
    for (i=0; i<20; i++){
        printf("%d (%u)  ", *ptr, ptr);
        ptr++;  // pula o ponteiro para direita em 4 bytes, incremente de 1 de ptr
    } 
    printf("\n");

    printf("\nNavegando mat como vetor decrescente com ponteiro:\n");
    ptr = &m[3][4]; // endereco do último elemento da matriz 4x5
    for (i=0; i<20; i++){ 
        printf("%d (%p)   ", *ptr, ptr);
        ptr--;  // pula o ponteiro para direita em 4 bytes, incremente de 1 de ptr
    }
    printf("\n");

    printf("\nNavegando mat como vetor crescente com ponteiro mantendo endereco base:\n");
    ptr = &m[0][0];
    for (i=0; i<20; i++){
        printf("%d (%p)  ", *(ptr+i), ptr+i); // soma um descolamento
    }                        // ao final do loop, ptr continua apontando para o comeco
    printf("\n");

    return 0; // devolve ok para o SO
}

void mostraMat(int mat[4][5]){
    int i, j;
    for (i=0; i<4; i++) { // variando as linhas
        for (j=0; j<5; j++) { // variando as colunas
            printf("%d   ", mat[i][j]);
        }
        printf("\n");
    }
}

// ARRAY sempre é passagem de parâmetros por REFERÊNCIA ou seja, ao manipular o parâmetro mat está alterando a matriz m da main
void preencheMat(int mat[4][5]){
    int i, j;
    srand(time(NULL));
    for (i=0; i<4; i++) { // variando as linhas
        for (j=0; j<5; j++) { // variando as colunas
           mat[i][j] = 10 + rand()%90; // manipular o rand para dar [10..99]
        }
    }
}