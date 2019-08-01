#include "prioridad.h"

/*
 * Crear Nodo
 * --------------------------------------------------------------------------
 */
struct nodo    *
crear_nodo(char cliente, int pr)
{
	struct nodo    *nuevo_nodo = (struct nodo *)malloc(sizeof(struct nodo));
	nuevo_nodo->dato = cliente;
	nuevo_nodo->prioridad = pr;
	return nuevo_nodo;
}

/*
 * Formar
 * --------------------------------------------------------------------------
 */
void 
encolar(struct cola *q, char valor, int prioridad)
{
	struct nodo    *aux = crear_nodo(valor, prioridad);
	aux->siguiente = NULL;

	if (q->adelante == NULL) {
		q->adelante = aux;
		//encola el primer elemento
	} else {
		(q->atras)->siguiente = aux;
	}
	q->atras = aux;
	//apuntador al ultimo elemento
}

/*
 * Mostrar Cola
 * --------------------------------------------------------------------------
 */
void 
mostrar(struct cola q)
{
	struct nodo    *aux;

	aux = q.adelante;
	puts("");
	puts("Cliente    Prioridad");
	puts("---------------------");

	while (aux != NULL) {
		printf("%c       |     %d\n", (aux->dato), (aux->prioridad));
		aux = aux->siguiente;
	}
}

/*
 * Ordenar elementos por prioridad (ordenamiento por burbuja)
 * --------------------------------------------------------------------------
 */
void 
ordenar_elementos(struct cola *q)
{
	struct nodo    *aux1;
	struct nodo    *aux2;
	int		p_auxiliar;
	int		c_auxiliar;

	aux1 = q->adelante;

	while (aux1->siguiente != NULL) {
		aux2 = aux1->siguiente;

		while (aux2 != NULL) {
			if (aux1->prioridad > aux2->prioridad) {
				p_auxiliar = aux1->prioridad;
				c_auxiliar = aux1->dato;

				aux1->prioridad = aux2->prioridad;
				aux1->dato = aux2->dato;

				aux2->prioridad = p_auxiliar;
				aux2->dato = c_auxiliar;
			}
			aux2 = aux2->siguiente;
		}
		aux1 = aux1->siguiente;
	}
}

/*
 * Insertar elementos (caracteres)
 * --------------------------------------------------------------------------
 */
void 
insertar(struct cola *q, char c, int pr)
{
	encolar(q, c, pr);
	ordenar_elementos(q);
}

/*
 * Menú
 * -----
 */
void 
menu(void)
{
	printf("\n");
	puts("COLA DE PRIORIDAD ");
	puts("----------------------");
	puts("1. INGRESAR CLIENTE");
	puts("2. MOSTAR CLIENTES");
	puts("3. ATENDER");
	puts("4. SALIR");
	puts("INGRESE OPCION: ");
}

/*
 * Atender y Desformar
 * --------------------------------------------------------------------------
 */
void 
atender(struct cola *q)
{
	struct nodo    *aux;

	if (q->adelante == NULL) {
		puts("Cola Vacia");
		exit(0);
	} else {
		aux = q->adelante;
		printf("atender a: %c", aux->dato);
		q->adelante = q->adelante->siguiente;
	}
}
