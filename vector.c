#include <stdio.h>
#include <stdbool.h>

void invetirOrden(int v[], int tam){
    for(int i = 0; i< tam/2; ++i){
        int aux = v[i];
        v[i] = v[tam-1-i];
        v[tam-1-i]=aux;
    }
}

int pedirEntero(int inf, int sup, const char mensaje[]){
    int valor;
    do{
        printf("Introduzca el %s:", mensaje);
        if(scanf("%d", &valor) != 1){
            while(getchar()!='\n');
            printf("\n Error: %s fuera de rango o no es un numero valido.\n",mensaje);
        }else if(valor > sup || valor < inf){
            printf("\n Error:%s fuera de rango.\n", mensaje);
        }
    }while(valor > sup || valor < inf);
    return valor;
}

int main(){
    int tam = pedirEntero(1,100,"numero de elementos del vector");
    int v[tam];
    for(int i = 0; i < tam; ++i){
        printf("v[%d]=", i);
        if(scanf("%d",&v[i])!=1){
            while(getchar()!='\n');
            printf("Error:Entrada no valida. Introduzca un numero.\n");
            --i;
        }
    }
    invetirOrden(v,tam);
    printf("Vector invertido:\n");
    for(int i = 0; i < tam; ++i){
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}

