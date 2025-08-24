#include <stdio.h>

//Mostrar matriz transposta à A
void transposta(int rowsA, int colsA, int A[rowsA][colsA]){
    int i, j;
    printf("\nMatriz Transposta\n");
    for(i=0; i<colsA; i++){
        for(j=0; j<rowsA; j++){
            printf("%4d", A[j][i]);
        }
        printf("\n");
    }
}

//Realizar adição ou subtração de A e B
void adicao(int rowsA, int colsA, int A[rowsA][colsA]){
    int i, j, B[rowsA][colsA], C[rowsA][colsA], opc;
    char operacao;
   
    //Definir elementos da matriz B
    printf("\nNão é possível escolher dimensões de B nesse modo!\n");
    printf("\nDigite os elementos da matriz B\n");
    for(i=0; i<rowsA; i++){
        for(j=0; j<colsA; j++){
            printf("b%d%d: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }
   
    //Mostrar matriz B para o usuário
    printf("\nMatriz B:\n");
    for(i=0; i<rowsA; i++){
        for(j=0; j<colsA; j++){
            printf("%4d", B[i][j]);
        }
        printf("\n");
    }
   
    //Escolher adição ou subtração
    printf("\nSelecione a opção desejada:\n");
    printf("[1] - Adição\n");
    printf("[2] - Subtração\n");
    scanf("%d", &opc);
   
    //Definir soma ou subtração
    switch(opc){
        case 1:
            for(i=0; i<rowsA; i++){
                for(j=0; j<colsA; j++){
                    C[i][j] = A[i][j] + B[i][j];
                }
            }
            operacao = '+';
            break;
        case 2:
            for(i=0; i<rowsA; i++){
                for(j=0; j<colsA; j++){
                    C[i][j] = A[i][j] - B[i][j];
                }
            }
            operacao = '-';
            break;
        default:
            printf("Opção Inválida!\n");
            return;
    }
   
    //Mostrar matriz C ao usuário
        printf("\nMatriz C (A %c B):\n", operacao);
    for(i=0; i<rowsA; i++){
        for(j=0; j<colsA; j++){
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }
}

//Realizar multiplicação
void multiplicacao(int rowsA, int colsA, int A[rowsA][colsA]){
    int i, j, opc;
   
    printf("\nSelecione a opção desejada:\n");
    printf("[1] - Multiplicação por escalar\n");
    printf("[2] - Multiplicação entre matrizes\n");
    scanf("%d", &opc);
   
    switch(opc){
        case 1: {
            //Escolher escalar
            int escalar, B[rowsA][colsA];
            printf("\nDigite o escalar desejado: ");
            scanf("%d", &escalar);
           
            //Calcular produto
            for(i=0; i<rowsA; i++){
                for(j=0; j<colsA; j++){
                    B[i][j] = escalar * A[i][j];
                }
            }
           
            //Mostrar resultado
            printf("\nMatriz B (A * %d)\n", escalar);
            for(i=0; i<rowsA; i++){
                for(j=0; j<colsA; j++){
                    printf("%4d", B[i][j]);
                }
                printf("\n");
            }
            break;
        }
        case 2: {
            int k, rowsB = colsA, colsB;
            //Definir dimensões da matriz B
            printf("\nDigite as dimensões da matriz B\n");
            printf("Linhas: %d (Não é possível alterar!)\n", rowsB);
            printf("Colunas: ");
            scanf("%d", &colsB);
            int B[rowsB][colsB], C[rowsA][colsB];
            
            //Definir elementos da matriz B
            printf("\nDigite os elementos da matriz B\n");
            for(i=0; i<rowsB; i++){
                for(j=0; j<colsB; j++){
                    printf("b%d%d: ", i+1, j+1);
                    scanf("%d", &B[i][j]);
                }
            }
            
            //Mostrar matriz B
            printf("\nMatriz B: \n");
            for(i=0; i<rowsB; i++){
                for(j=0; j<colsB; j++){
                    printf("%4d", B[i][j]);
                }
                printf("\n");
            }
            
            //Inicializar C com 0
            for(i=0; i<rowsA; i++){
                for(j=0; j<colsB; j++){
                    C[i][j] = 0;
                }
            }
            
            // Realizar multiplicação
            for(i=0; i<rowsA; i++){
                for(j=0; j<colsB; j++){
                    for(k=0; k<colsA; k++){
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            
            //Mostrar matriz C
            printf("\nMatriz C (A * B):\n");
            for(i=0; i<rowsA; i++){
                for(j=0; j<colsB; j++){
                    printf("%4d", C[i][j]);
                }
                printf("\n");
            }
            break;
        }
        default:
            printf("Opção Inválida!\n");
    }
}

int main() {
    int rowsA, colsA;
    int i, j, opc1, opc2;
   
    //Definir dimensões da matriz A
    printf("Digite as dimensões da matriz\n");
    printf("Linhas: ");
    scanf("%d", &rowsA);
    printf("Colunas: ");
    scanf("%d", &colsA);
    if(rowsA < 1 || colsA < 1){
        printf("As dimensões devem ser positivas!\n");
        return 0;
    }
   
    int A[rowsA][colsA];
   
    //Definir elementos da matriz A
    printf("\nDigite os elementos da matriz A\n");
    for(i=0; i<rowsA; i++){
        for(j=0; j<colsA; j++){
            printf("a%d%d: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
   
    //Mostrar matriz A para o usuário
    printf("\nMatriz A:\n");
    for(i=0; i<rowsA; i++){
        for(j=0; j<colsA; j++){
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
   
    printf("\nDigite [1] para mostrar a matriz transposta ou [2] para realizar operações de matrizes: ");
    scanf("%d", &opc1);
   
    switch(opc1){
        case 1:
            transposta(rowsA, colsA, A);
            break;
        case 2:
            printf("Selecione a opção desejada:\n");
            printf("[1] - Adição ou Subtração\n");
            printf("[2] - Multiplicação\n");
            scanf("%d", &opc2);
           
            switch(opc2){
                case 1:
                    adicao(rowsA, colsA, A);
                    break;
                case 2:
                    multiplicacao(rowsA, colsA, A);
                    break;
                default:
                    printf("Opção Inválida!\n");
            }
            break;
        default:
            printf("Opção Inválida!\n");
    }
   
    return 0;
}