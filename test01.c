
/*
    Pineda Hernandez Francisco
    Algoritmos y Estructuras de Datos
    Proyecto Primer Parcial
    "Algoritmo que convierte expresión aritmetica Infija a PostFija"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100
#define TAM_CADENA 100

struct STACK{
    char datos[TAM]; 
    char *ptrDatos;
};

char *leerCadenaDesdeArchivo(char *nombreArchivo);
void conversionInfijaPostfija(char *cadenaLeida, struct STACK *ptrStack);
void escribirEnArchivo(char caracter, char *nombreArchivo);
int esOperador(char caracter);
int gradoOperador(char caracter);
int esParentesis(char caracter);

int main(){

    char *cadenaLeida = leerCadenaDesdeArchivo("entrada.txt");
    //char cadenaNueva[TAM];

    struct STACK stack, *myPtrStack;
    myPtrStack = &stack;
    myPtrStack->ptrDatos = myPtrStack->datos;

    if (cadenaLeida != NULL) {
        printf("La cadena leída del archivo es: %s\n", cadenaLeida);
        conversionInfijaPostfija(cadenaLeida, myPtrStack);
        
        
        free(cadenaLeida); // Liberar la memoria asignada para la cadena
    }

    return 0;
}

// Función para leer una cadena de texto desde un archivo
char *leerCadenaDesdeArchivo(char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r"); // "r" -> indica que es archivo para lectura
    char *cadena = (char *)malloc(TAM_CADENA * sizeof(char)); // Asignación dinámica de memoria para la cadena

    // Verifica si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    // Lee la cadena de texto del archivo
    if (fgets(cadena, TAM_CADENA, archivo) != NULL) {
        fclose(archivo); // Cierra el archivo después de la lectura
        return cadena; // Retorna la cadena leída del archivo
    } else {
        printf("El archivo está vacío.\n");
        fclose(archivo); // Cierra el archivo si está vacío
        free(cadena); // Libera la memoria asignada para la cadena
        return NULL;
    }
}

// Función para administrar todo el procedimiento de conversión
void conversionInfijaPostfija(char *cadenaLeida, struct STACK *ptrStack){

    char *ptrCadena;

    *ptrStack->ptrDatos = '(';
    ptrStack->ptrDatos++;

    for(ptrCadena = cadenaLeida; *ptrCadena != '\0'; ptrCadena++, ptrStack->ptrDatos++){
        
        /* printf("%c \n", *ptrCadena);     // TEST DE ESCRITURA EN EL ARCHIVO XD
        escribirEnArchivo(*ptrCadena, "expresionPostfija.txt"); */
        
        if(esParentesis(*ptrCadena)){
            switch (*ptrCadena){
            case '(':
                push(ptrStack, *ptrCadena);
                //*ptrStack->ptrDatos = *ptrCadena;
                /* code */
                break;
            case ')':
                while(*ptrStack->ptrDatos =! '(')
                    pop(ptrStack);

                break;
            }

        }else if(esOperador(*ptrCadena)){

            if(gradoOperador(*ptrStack->ptrDatos) > gradoOperador(*ptrCadena)){
                escribirEnArchivo(*ptrStack->ptrDatos, "expresionPostfija.txt");
            }
            /*
            int grado = gradoOperador(*ptrCadena);
            switch (grado){
            case 3: // Operador ^

                break;
            
            default:
                break;
            }*/

        }
        
    }

}

void escribirEnArchivo(char caracter, char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "a"); // Abre el archivo en modo de escritura, agregando al final del archivo

    // Verifica si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return; // Termina la función si hay un error
    }

    // Escribe el caracter en el archivo
    fprintf(archivo, "%c", caracter);

    // Cierra el archivo
    fclose(archivo);
}

int esOperador(char caracter){
    return (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/' || caracter == '^') ? 1 : 0;
}
int gradoOperador(char caracter) {
    switch(caracter) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; 
    }
}
int esParentesis(char caracter){
    return (caracter == '(') || caracter == ')' ? 1 : 0;
}

void push(struct STACK *ptrStack, char caracter){
    *ptrStack->ptrDatos = caracter;
    ptrStack->ptrDatos++; 
}

void pop(struct STACK *ptrStack){
    escribirEnArchivo(*ptrStack->ptrDatos, "expresionPostfija.txt");
    ptrStack->ptrDatos--;
}