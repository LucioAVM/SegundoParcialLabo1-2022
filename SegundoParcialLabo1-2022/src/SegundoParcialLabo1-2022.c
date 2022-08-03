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
#include "Servicios.h"
#include "Parcer.h"


int main(void)
{
	setbuf(stdout, NULL);

	int menu;
	int orden;

	orden = -1;

	menu = 0;

	LinkedList* listaServicios = ll_newLinkedList();

	do
	{
		if(menu != 0 &&( menu > 7 || menu < 0))
		{
			printf("ingrese una opcion valida/n");
		}

		menu = getMenu();

			switch(menu)
			{
			case 1:
				if(!(archivo_servicios(listaServicios, "data.csv")))
				{
					printf("se ah cargado el archivo correctamente\n");
					orden = 0;
				}else{
					printf("error al intentar cargar archivo, intente nuevamente\n");
				}
				break;


			case 2:
				if(listarServicios(listaServicios) != 0 && orden == 0)
				{
					printf("\nPara listar los servicios primero se debe cargar un archivo\n");
				}
				break;


			case 3:
				if(eServicio_Totales(listaServicios) != 0 && orden == 0)
				{
					printf("\nPara asignar totales a los servicios primero se debe cargar un archivo\n");
				}
				break;


			case 4:
				if(ordenar_tipo(listaServicios) != 0 && orden == 0)
				{
					printf("\nPara filtrar por tipo los servicios primero se debe cargar un archivo\n");
				}

				break;


			case 5:
				if(mostrarServiciosAsendente(listaServicios) != 0 && orden == 0)
				{
					printf("\nPara mostrar los servicios primero se debe cargar un archivo\n");
				}else{
					printf("servicios ordenados correctamente\n");
				}
				break;


			case 6:
				if(!(guardarArchivo(listaServicios,"servicios-ordenados.csv")) && orden == 0)
				{
					printf("se guardo existosamente la lista de servicios en ´servicios-ordenados.csv´");
				}else{
					printf("\nPara mostrar los servicios primero se debe cargar un archivo\n");
				}

				break;


			case 7:
				if(menu_TotalCantidades(listaServicios) == -1 && orden == 0 )
				{
					printf("\nPara mostrar los servicios primero se debe cargar un archivo\n");
				}
				break;
			case 8:
				printf( "\n           GRACIAS POR UTILIZAR ESTE PROGRAMA\n"
										"             PRODUCIDO POR Monsalbo lucio\n"
										"              EDITADO POR Lucio Monsalbo\n"
										"         BUILDEADO POR Alejandro Lucio Monsalbo\n"
										"        TESTEADO POR Valerio Alejandro Monsalbo\n"
										"        ENVIADO POR Monsalbo Lucio Alejandro Valerio\n"
										"   AGRADECIMIENTO ESPECIAL A Lucio Alejandro Valerio Monsalbo\n");
				break;
			default:
				printf("ERROR,Ingrese una opcion valida");
				break;
			}
	}while(menu != 8);

	return EXIT_SUCCESS;
}
