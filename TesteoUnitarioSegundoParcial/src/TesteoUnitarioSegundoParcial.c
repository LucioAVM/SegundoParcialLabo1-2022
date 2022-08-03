/*
 ============================================================================
 Name        : TesteoUnitarioSegundoParcial.c
 Author      : Monsalbo Lucio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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

			HardcodeoServicios(listaServicios);
			orden = 0;

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
			}
			break;


		case 6:
			if(!(guardarArchivo(listaServicios)) && orden == 0)
			{
				printf("se guardo existosamente la lista de servicios en ´servicios-ordenados.csv´");
			}else{
				printf("\nPara mostrar los servicios primero se debe cargar un archivo\n");
			}

			break;


		case 7:
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
	}while(menu != 7);

	return EXIT_SUCCESS;
}
