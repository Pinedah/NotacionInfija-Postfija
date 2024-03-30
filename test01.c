
/*
    Pineda Hernandez Francisco
    Algoritmos y Estructuras de Datos
    Proyecto Primer Parcial
    "Algoritmo que convierte expresión aritmetica Infija a PostFija"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define TAM_CADENA 100

char *leerCadenaDesdeArchivo(char *nombreArchivo);

int main(){

    char *cadenaLeida = leerCadenaDesdeArchivo("entrada.txt");

    if (cadenaLeida != NULL) {
        printf("La cadena leída del archivo es: %s\n", cadenaLeida);
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
        return NULL; // Retorna NULL si hay un error
    }

    // Lee la cadena de texto del archivo
    if (fgets(cadena, TAM_CADENA, archivo) != NULL) {
        fclose(archivo); // Cierra el archivo después de la lectura
        return cadena; // Retorna la cadena leída del archivo
    } else {
        printf("El archivo está vacío.\n");
        fclose(archivo); // Cierra el archivo si está vacío
        free(cadena); // Libera la memoria asignada para la cadena
        return NULL; // Retorna NULL si el archivo está vacío
    }
}