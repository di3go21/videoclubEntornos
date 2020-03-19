/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   articulo.h
 * Author: diego
 *
 * Created on 24 de febrero de 2020, 16:57
 */

typedef struct{
    int tipo_articulo;
    int ID_articulo;
    int estado_articulo;
    int semanas_alquiler;
    char titulo [50]; 
    
} articulo;

articulo* nuevoArticulo();
int estadoArticulo(articulo a);
void devolverArticulo(articulo *a,int diasTranscurridos);
void alquilarArticulo(articulo *a,int semanasAlquiler);
int getID (articulo *a);
void escribirArticulo (articulo a);
void establecerTitulo (articulo *a, char *titulo);

