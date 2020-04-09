/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: diego
 *
 * Created on 19 de febrero de 2020, 8:47
 */

#include <stdio.h>
#include <stdlib.h>
#include "articulo.h"
#include "interfaz.h"

/*
 * 
 */
int main(int argc, char** argv) {

    /*##########################################################//
    //  PRUEBAS
    //##########################################################*/
/*
    printf("Resultado de introducir -100: %d\n", valido(-100));
    printf("Resultado de introducir -1: %d\n", valido(-1));
    printf("Resultado de introducir 0: %d\n", valido(0));
    printf("Resultado de introducir 1: %d\n", valido(1));
    printf("Resultado de introducir 50: %d\n", valido(50));
    printf("Resultado de introducir 99: %d\n", valido(99));
    printf("Resultado de introducir 100: %d\n", valido(100));
    printf("Resultado de introducir 101: %d\n", valido(101));
    printf("Resultado de introducir 150: %d\n", valido(150));


    articulo *uno = nuevoArticulo(); // alquilado
    uno->estado_articulo = 1;
    articulo *dos = nuevoArticulo(); // no alquilado y pelicula
    dos->estado_articulo = 0;
    dos->tipo_articulo=0;
    articulo *tres = nuevoArticulo(); // no alquilado y videojuego
    tres->estado_articulo = 0;
    tres->tipo_articulo=1;

    alquilarArticulo(uno, 2);
    printf("\n");
    alquilarArticulo(dos, 3);
    printf("\n");
    alquilarArticulo(tres, 3);
    
    
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");



*/






    /*##########################################################//
    //DEFINICION DE NUESTRO VIDEOCLUB
    //##########################################################*/

    articulo * videoclub [100];

    for (int i = 0; i < 100; i++) {
        videoclub[i] = nuevoArticulo();
        videoclub[i]->estado_articulo = (rand() % (1 + 1)); // ESTADO ALEATORIO
        if (videoclub[i]->estado_articulo == 1) {
            videoclub[i]->semanas_alquiler = 1; //SI ESTÁN ALQUILADOS LE DAMOS UNA SEMANA DE ALQUILER
        }
        videoclub[i]->ID_articulo = (i + 1); // ID DE 1 A 100

        strcpy(videoclub[i]->titulo, "No  establecido");

        if (i < 50)
            videoclub[i]->tipo_articulo = 0; //50 PRIMEROS SON PELICULAS
        else
            videoclub[i]->tipo_articulo = 1; // EL RESTO SON VIDEOJUEGOS
    }

    /*##########################################################//
    //  VARIABLES DE APOYO
    //##########################################################*/

    int semanas, articulo, dias;
    char nuevoTitulo[50];
    int opc = 0;
    /*##########################################################//
    //  MENU PROGRAMA
    //##########################################################*/

    do {
        opc = menu();
        printf("Has elegido el %d \n", opc);

        switch (opc) {

            case ALQUILER:
                printf("dime el ID del artículo a alquilar!\n");
                scanf("%d", &articulo);
                while (valido(articulo) == 0) { // VALIDAMOS EL ID INTRODUCIDO
                    scanf("%d", &articulo);
                }
                printf("Cuantas semanas quieres alquilarlo?\n");
                scanf("%d", &semanas);
                alquilarArticulo(videoclub[articulo - 1], semanas); // LA POSCICION DEL ARTÍCULO ES ID-1 EN EL ARRAY         
                break;

            case DEVOLUCION:

                printf("dime el ID del artículo a devolver!\n");
                scanf("%d", &articulo);
                while (valido(articulo) == 0) {
                    scanf("%d", &articulo);
                }
                printf("Cuantos dias han transcurrido desde el alquiler?\n");
                scanf("%d", &dias);
                devolverArticulo(videoclub[articulo - 1], dias);
                break;

            case ESTADO_CONCRETO:

                printf("dime el ID del artículo que quieres conocer el estado:\n");
                scanf("%d", &articulo);
                while (valido(articulo) == 0) {
                    scanf("%d", &articulo);
                }
                for (int i = 0; i < 100; i++) { // BUSQUEDA MEDIANTE RECORRIDO DE ARRAY
                    if (videoclub[i]->ID_articulo == articulo)
                        escribirArticulo(*videoclub[i]);
                }
                break;

            case MOSTRAR_ARTICULOS:

                for (int i = 0; i < 100; i++)
                    escribirArticulo(*videoclub[i]);
                break;

            case ESTABLECER_TITULO:

                printf("dime el ID del artículo para establecer el titulo!:\n");
                scanf("%d", &articulo);
                while (valido(articulo) == 0)
                    scanf("%d", &articulo);
                printf("Escribe el titulo\n");

                /*##########################################################//
                // googleé un poco para slucionar problemas con el salto de linea.
                //##########################################################*/
                while (getchar() != '\n'); // al parecer come el intro que estaba en buffer
                fgets(nuevoTitulo, 50, stdin); // con printf no me leía texto con espacios
                nuevoTitulo[strlen(nuevoTitulo) - 1] = '\0'; // elimina el intro final de la lectura

                establecerTitulo(videoclub[articulo - 1], nuevoTitulo);
                printf("has establecido un nuevo titulo para este artículo!\n"
                        "ha quedado así:\n");
                escribirArticulo(*videoclub[articulo - 1]);

                break;

            case SALIR: printf("ADIOS!!!!");
                break;
            default: printf("opción no válida!\n");
                break;
        }

    } while (opc != 0);
    return (EXIT_SUCCESS);
}

int valido(int numero) {
    if (numero > 100 || numero < 1) {
        //printf("introduce un id valido!!:\n");
        return 0;
    }
    return 1;
}

