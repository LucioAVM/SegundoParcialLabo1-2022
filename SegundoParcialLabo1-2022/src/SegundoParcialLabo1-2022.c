/*
 ============================================================================
 Name        : SegundoParcialLabo1-2022.c
 Author      : Monsalbo Lucio
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 El programa contará con el siguiente menú:
1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
del mismo.
2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de los servicios.
3) Asignar totales: Se deberá hacer uso de la función map la cual recibirá el linkedlist y una
función que asignará a cada servicio el total calculado de la siguiente forma: cantidad x
totalServicio.
4) Filtrar por tipo: Se deberá generar un archivo igual al original, pero donde solo aparezcan
servicios del tipo seleccionado.
5) Mostrar servicios: Se deberá mostrar por pantalla un listado de los servicios ordenados por
descripción de manera ascendente.
6) Guardar servicios: Se deberá guardar el listado del punto anterior en un archivo de texto.
7) Salir.

 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

int main(void)
{
	setbuf(stdout, NULL);

	int menu;
	int banderaArchivos;

	LinkedList listaServicios;

	menu = getMenu;

	switch(menu)
	{
	case 1:
		archivo_servicios(listaServicios, &banderaArchivos);
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:

		break;
	case 7:

		break;
	}


	return EXIT_SUCCESS;
}
