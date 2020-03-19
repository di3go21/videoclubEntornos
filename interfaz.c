
#include "interfaz.h"
int menu(){
    
    int opcion=0;     

      printf("Menu de opciones:\n");
      printf("%d.- Registrar alquiler\n",ALQUILER);
      printf("%d.- Registrar devolucion\n",DEVOLUCION);
      printf("%d.- Mostrar el estado de un artículo\n",ESTADO_CONCRETO);
      printf("%d.- Mostrar el estado de todos los artículos\n",MOSTRAR_ARTICULOS);
      printf("%d.- Establecer titulo\n",ESTABLECER_TITULO);
      printf("%d.- Salir\n",SALIR);
      printf("Que desea hacer:");
      scanf("%d",&opcion);
    
    
    
    return opcion;
};