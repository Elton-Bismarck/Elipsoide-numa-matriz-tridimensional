/*Questão 1*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int alt,larg,comp,aux = 0;
    int ***matriz;
    float rx,ry,rz,xc,yc,zc,a,b,c;

    /*Recebe os Valores Dados pelo Usuário*/
    printf("Digite a Altura da matriz\n");
    scanf("%d", &alt);
    
    printf("Digite a Largura da Matriz\n");
    scanf("%d", &larg);

    printf("Digite o Comprimento da Matriz\n");
    scanf("%d", &comp);    
    
    printf("Sua Matriz Tridimencional Tera \n\n%d de Altura \n\nCom %d de Largura \n\nE %d de Comprimento\n\n", alt, larg, comp);

    /*Fim do bloco*/

    /*Realiza Certas Operações*/

    xc = (float)comp/2;
    yc = (float)larg/2;

    c = alt/2;

    if (alt > larg || alt > comp){
        aux = 1;
    }
    
    a = 0;
    b = 0;

    /*Fim do bloco*/

    /*Alocação de matriz*/
    
    matriz = (int ***) malloc (sizeof(int ***)*alt);

    for (int i = 0; i < alt; i++){
        matriz[i] = (int **) malloc(sizeof(int*)*larg);
        for (int j = 0; j < larg; j++){
            matriz[i][j] = (int *) malloc(sizeof(int)*comp);
        }
    }

    /*Fim do bloco*/

    /*Preenche com Zero ou Um*/

    for (int i = 0;i < alt;i++){
        for (int j = 0;j < larg;j++){
            for (int k = 0;k < comp;k++){
                rx = pow(((j - yc)/b),2);
                ry = pow(((k - xc)/a),2);
                if(rx + ry <= 1){
                    matriz[i][j][k] = 1;
                }
                else{
                    matriz[i][j][k] = 0;
                }
            }
        }
        if (aux == 0){
            if (i > (c-1)){
               a = a - 1.5;
               b = b - 1.5;
            }
            else if(i == (c-1)){
               a = xc;
               b = yc;
            }
            else{
               a = a + 1.5;
               b = b + 1.5;
            }
        }
        else{
            if (i > (c-1) && (i%2==0)){
               a--;
               b--;
            }
            else if(i == (c-1)){
               a = xc;
               b = yc;
            }
            else if(i < (c-1) && (i%2==0)){
               a++;
               b++;
            }
        }
        
        
    }

    /*Fim do bloco*/  

    /*Imprime a Matriz no Corte Desejado*/
    
    char plano;
    int corte;
    
    printf("Digite o Plano que Quer Imprimir\n");
    printf("x para Comprimento\ny para Largura\nz para Altura\n");
    scanf(" %c", &plano);

    printf("Digite O Corte do Plano que Quer Imprimir\n");
    scanf("%d", &corte);
    printf("Elipsoide de dimensoes (%d,%d,%d) com corte no plano %d:%c\n", alt, larg, comp, corte, plano);
    
    switch (plano){
    case 'x':
        for (int i = 0;i < alt;i++){
            for (int j = 0;j < larg;j++){
                printf("%d ", matriz[i][j][corte-1]);
            }
            printf("\n");
        }
        break;
    case 'y':
        for (int i = 0;i < alt;i++){
            for (int k = 0;k < comp;k++){
                printf("%d ", matriz[i][corte-1][k]);
            }
            printf("\n");
        }
        break;
    case 'z':
        for (int j = 0;j < larg;j++){
            for (int k = 0;k < comp;k++){
                printf("%d ", matriz[corte-1][j][k]);
            }
            printf("\n");
        }
        break;    
    }    
        
    /*Fim do bloco*/

    /*Libera a Memória*/

    for (int j = 0;j < alt; j++){
        for (int k = 0;k < larg;k++){
            free(matriz[j][k]);
        }
        free(matriz[j]);        
    }
    free(matriz);

    /*Fim do bloco*/
    
    printf("\n");
    return 0;
}
