
#include <stdio.h>
#include "articulo.h"

articulo* nuevoArticulo() {
    articulo *a;
    a = malloc(sizeof (articulo));
    return a;
}

int estadoArticulo(articulo a) {
    return a.estado_articulo;
}

void devolverArticulo(articulo *a, int diasTranscurridos) {
    int penalizacion, dias_retraso;
    if (estadoArticulo(*a) == 0) //no está alquilado
        printf("ERROR 8374-a, el artículo no está alquilado.\n");

    else {//está alquilado
        if (diasTranscurridos > (a->semanas_alquiler * 7)) { //si hay retraso
            printf("Se pagó un alquiler de %d semena(s).\n", a->semanas_alquiler);
            dias_retraso = diasTranscurridos - (((a->semanas_alquiler)*7));
            if (a->tipo_articulo == 0) { //si es pelicula 5 euros la semana
                penalizacion = 5 + 5 * ((dias_retraso - 1) / 7);
                if (dias_retraso == 1)
                    printf("tienes una penalizacion de %d euros por el %d día de retraso en la pelicula\n", penalizacion, dias_retraso);
                else printf("tienes una penalizacion de %d euros por los %d dias de retraso en la pelicula\n", penalizacion, dias_retraso);
            } else { //si es videojuego 10 euros la semana
                penalizacion = 10 + 10 * ((dias_retraso - 1) / 7);
                if (dias_retraso == 1)
                    printf("tienes una penalizacion de %d euros por el %d día de retraso en el videojuego\n", penalizacion, dias_retraso);
                else printf("tienes una penalizacion de %d euros por los %d dias de retraso en el videojuego\n", penalizacion, dias_retraso);

            }

        }
        //reseteamos el artículo.
        a->estado_articulo = 0;
        a->semanas_alquiler = 0;
        printf("Devolución efectuada exitosamente!\n");
    }

}

void alquilarArticulo(articulo *a, int semanasAlquiler) {
    int precio_alquiler;
    
    if (estadoArticulo(*a) == 1)//está alquilado
        printf("ERROR 8374-a, el artículo está alquilado actualmente.\n");
    
    else {//no está alquilado
        a->semanas_alquiler = semanasAlquiler; //se establece las semanas alquiladas
        a->estado_articulo = 1; //se establece el estado alquilado
        
        if (a->tipo_articulo == 0)//si es pelicula
            precio_alquiler = 5 * semanasAlquiler;
        
        else //si es videojuego
            precio_alquiler = 10 * semanasAlquiler;
        
        printf("Precio alquiler: %d euros\n", precio_alquiler);
        printf("Alquiler efectuado exitosamente\n");

    }
}

void escribirArticulo(articulo a) {

    char tipoArt[20];
    char estado[20];
    char ESTADO[100];
    if (a.tipo_articulo == 0)
        strcpy(tipoArt, "Pelicula");
    else
        strcpy(tipoArt, "Videojuego");

    if (a.estado_articulo == 0)
        strcpy(estado, "No alquilado");
    else
        strcpy(estado, "Alquilado");

    printf("%s ID: %d, Titulo: %s, estado: %s \n", tipoArt, a.ID_articulo, a.titulo, estado);


}

int getID(articulo *a) {
    int ID = a->ID_articulo;
    return ID;
}

void establecerTitulo(articulo *a, char *titulo) {
    strcpy(a->titulo, titulo);
}

