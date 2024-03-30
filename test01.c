
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
    char stack[TAM]; 
    char *ptrSt;
};

char *leerCadenaDesdeArchivo(char *nombreArchivo);
void conversionInfijaPostfija(cadenaLeida);
void escribirEnArchivo(char caracter, char *nombreArchivo);
int esOperador(char caracter);
int gradoOperador(char caracter);

int main(){

    char *cadenaLeida = leerCadenaDesdeArchivo("entrada.txt");
    char cadenaNueva[TAM];

    if (cadenaLeida != NULL) {
        printf("La cadena leída del archivo es: %s\n", cadenaLeida);
        free(cadenaLeida); // Liberar la memoria asignada para la cadena
    }

    conversionInfijaPostfija(cadenaLeida);

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
void conversionInfijaPostfija(cadenaLeida){

    char *ptrCadena;

    for(ptrCadena = cadenaLeida; *ptrCadena != '\0'; ptrCadena++){
        if(isalpha(*ptrCadena))
            escribirEnArchivo(*ptrCadena, "expresionPostfija.txt");
        else if(esOperador(*ptrCadena)){
            int grado = gradoOperador(*ptrCadena);
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