/*
 * Menu.c
 *
 *  Created on: 21 jun. 2022
 *      Author: UGIO
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

int getMenu(void)
{
	int menu;
	int bandera;

	bandera = 0;

	do
	{
		if(bandera < 0)
		{
			printf("error, ingrese una opcion valida/n");
		}
		printf("		Menu/n"
				"		----/n"
				"1- Cargar Archivo/n"
				"2- Imprimir Lista/n"
				"3- Asignar Totales/n"
				"4- Filtrar por tipos/n"
				"5- Mostrar Servicios/n"
				"6- Guardar Servicios"
				"7- Salir/n");

		fflush(stdout);
		scanf("%d", menu);

		bandera++;
	}while(menu < 0 && menu > 7);

	return menu;
}

void archivo_servicios(LinkedList* listaServicios[],int* bandera)//hacer una validacion para cuando cargue un archivo por segunda ves
{
	int path[20];
	int validacionCarga;

	if(listaServicios != NULL)
	{
		printf("ingrese el nombre del archivo que desea cargar/n");
		fflush(stdout);
		scanf("%d", &path);

		validacionCarga = cargaDeArchivo(path, listaServicios);

		if(validacionCarga == 0)
		{
			bandera = 1;
		}else{
			printf("error al intentar cargar archivo, intente unevamente/n");
		}
	}
}


int cargaDeArchivo(char* path, LinkedList* listaServicios[])
{
	int retorno;

	FILE* pArchivo = NULL;

	retorno = 0;

	pArchivo = fopen(path,"r");

	if(pArchivo == NULL)
	{
		printf("error");
	}else{
		parser_PasajeroDesdeTexto(pArchivo, listaServicios);
		retorno = 0;
	}
	fclose(pArchivo);

	return retorno;
}
