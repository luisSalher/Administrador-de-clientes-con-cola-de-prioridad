#ifndef __PRIORIDAD_H__
#define __PRIORIDAD_H__
/* Proyecto usando cola de prioridad
* Estructuras de datos
* Salinas Hernández Luis Angel
* Descripción: Se encolan caracteres relacionados con los clientes de un negocio
  deacuerdo con su prioridad para ser atendidos
*/

#include <stdio.h>
#include <stdlib.h>

struct nodo {
	char dato;
	int prioridad;
	struct nodo *siguiente;
};

struct cola{
	struct nodo *adelante;
	struct nodo *atras;
};

void enconlar(struct cola , char, int);
void mostrar(struct cola);
void ordenar_elementos(struct cola *);
void insertar(struct cola *, char, int);
void menu(void);
void atender(struct cola *); //Indica el siguiente elemento en atender y lo desforma

#endif
















