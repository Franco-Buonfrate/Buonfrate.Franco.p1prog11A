#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

typedef struct
{
    int id;
    char procesador[21];
    char marca[21];
    int precio;
} eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char caracter);
int ordenarArray(eNotebook notebook[], int tam);

int main()
{
    eNotebook notebook[TAM]={{1, "a", "Intel", 20000},{2,"b","intel",30000},{3, "a", "intel", 100000}};

    printf("DESCUENTO: %.2f\n", aplicarDescuento(10));

    printf("CONTAR CARACTERES: %d\n", contarCaracteres("cocina", 'c'));

    ordenarArray(notebook,TAM);

    for (int i=0; i<TAM;i++)
    {
        printf("ID: %d\n PROCESADOR: %s\n MARCA:%s\n PRECIO: %d\n", notebook[i].id, notebook[i].procesador, notebook[i].marca, notebook[i].precio);
    }


    return 0;
}

float aplicarDescuento(float precio)
{
    float precioConDescuento;

    precioConDescuento=(float) precio-(precio*5/100);
    return precioConDescuento;
}

int contarCaracteres(char cadena[], char caracter)
{
    int contador=0;

    for(int i=0; i<strlen(cadena); i++)
    {
        if(cadena[i]==caracter)
       {
           contador++;
       }
    }

    return contador;
}

int ordenarArray(eNotebook notebook[], int tam)
{
    int validacion=0;
    eNotebook auxNotebook;

    if(notebook!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(notebook[i].marca, notebook[j].marca)>0 ||
                   (strcmp(notebook[i].marca, notebook[j].marca)==0
                    && notebook[i].precio<notebook[j].precio))
                {
                    auxNotebook=notebook[i];
                    notebook[i]=notebook[j];
                    notebook[j]=auxNotebook;
                }
            }
        }
        validacion=1;
    }
    return validacion;
}
