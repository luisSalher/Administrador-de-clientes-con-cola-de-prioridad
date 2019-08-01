#include "prioridad.h"

int 
main(void)
{
	struct cola	una_cola;

	una_cola.adelante = NULL;
	una_cola.atras = NULL;

	char		cliente = '0';
	int		prioridad = 0;
	int		opcion = 0;
	int		x = 0;


	do {
		menu();
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			puts("Ingrese inicial del cliente: ");
			fflush(stdin);
			scanf(" %c", &cliente);
			puts("Ingrese prioridad del cliente:");
			scanf("%d", &prioridad);
			insertar(&una_cola, cliente, prioridad);
			system("/usr/bin/clear");
			//limpiar pantalla por comodidad

				break;

		case 2:
			if (una_cola.adelante != NULL) {
				mostrar(una_cola);
			} else {
				puts("Cola Vacía");
			}
			break;

		case 3:
			atender(&una_cola);
			system("/usr/bin/clear");
			//limpiar pantalla por comodidad
				break;

		default:
			exit(0);
		}

	} while (opcion != 4);

	return 0;
}
