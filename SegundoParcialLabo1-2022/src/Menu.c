/*
 * Menu.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Monsalbo Lucio
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Servicios.h"
#include "Parcer.h"
#include "LinkedList.h"

int getMenu(void)
{
	int menu;
	int bandera;

	bandera = 0;

	do
	{
		if(bandera < 0)
		{
			printf("error, ingrese una opcion valida\n");
		}
		printf("		Menu\n"
				"		----\n"
				"1- Cargar Archivo\n"
				"2- Imprimir Lista\n"
				"3- Asignar Totales\n"
				"4- Filtrar por tipos\n"
				"5- Mostrar Servicios\n"
				"6- Guardar Servicios\n"
				"7- Salir\n");

		fflush(stdout);
		scanf("%d", &menu);

		bandera++;
	}while(menu < 0 && menu > 7);

	return menu;
}

void archivo_servicios(LinkedList* listaServicios,int* bandera)//hacer una validacion para cuando cargue un archivo por segunda ves
{
	char path[20];
	int validacionCarga;

	printf("ingrese el nombre del archivo que desea cargar\n");
	fflush(stdout);
	scanf("%s", path);

	validacionCarga = cargaDeArchivo(path, listaServicios);

	if(validacionCarga == 0)
	{
		*bandera = 1;
	}else{
		printf("error al intentar cargar archivo, intente unevamente\n");
	}
}


int cargaDeArchivo(char* path, LinkedList* listaServicios)
{
	int retorno;

	FILE* pArchivo = NULL;

	retorno = -1;

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

void listarServicios(LinkedList* listaServicios)
{
	int i;
	int tam;

	tam = ll_len(listaServicios);
	//primer printf con plantilla
	printf("Listado de Servicios:\n"
				"ID-------Descripcion-------Tipo-------Precio Unitario-------Cantidad-------Total\n");

	if(tam > 0)
	{
		for(i = 0 ; i < tam ; i++)
		{
			if(!mostrarUnServicio(listaServicios, i))
			{
				printf("error al cargar el servicio en la pocision N° %d\n", i);
			}
		}
	}
}

void ordenar_tipo(LinkedList* listaServicios)
{
	int submenu;
	int tam;
	int contador;

	int id_servicio;
	char descripcion[25];
	char tipo[15];
	float precioUnitario;
	int cantidad;
	float totalServicio;

	eServicio* servicio;

	LinkedList* listaFiltradaPorTipo;

	int (*pFuncion)(void* pElement);

	contador = 0;

	if(listaServicios != NULL)
	{
		FILE* pArchivo = NULL;

		do
		{
			printf("elija el tipo de servicio por el que quiere filtrar\n"
					"1- Minorista\n"
					"2- Mayorista\n"
					"3- Exportar\n"
					"4- volver\n");
			fflush(stdout);
			scanf("%d", &submenu);

		}while(submenu < 1 && submenu > 4);

		if(submenu != 4)
		{
			pArchivo = fopen("Lista-Ordenada-Por-Tipo.csv","w");

			fprintf(pArchivo,"id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");

			switch(submenu)
			{
			case 1:
				pFuncion = filtrarTipo_Minorista;
				listaFiltradaPorTipo = ll_filter (listaServicios, pFuncion);
				break;
			case 2:
				pFuncion = filtrarTipo_Mayorista;
				listaFiltradaPorTipo = ll_filter (listaServicios, pFuncion);
				break;
			case 3:
				pFuncion = filtrarTipo_Exportar;
				listaFiltradaPorTipo = ll_filter (listaServicios, pFuncion);
				break;
			}

			tam = ll_len(listaFiltradaPorTipo);

			do{
				servicio = ll_get(listaFiltradaPorTipo, contador);

				if(!(validacion_gets(servicio, &id_servicio, descripcion, tipo, &precioUnitario, &cantidad, &totalServicio)))
				{
					fprintf(pArchivo,"%d,%s,%s,%2.f,%d,%2.f\n",id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio);
				}

				contador++;
			}while(contador <= tam);

			fclose(pArchivo);
		}
	}else{
		printf("ERROR, Lista de servicios no encontrada");
	}
}

void mostrarServiciosAsendente(LinkedList* listaServicios)
{
	int validacion;

	int (*pfuncion)(void*,void*);

	pfuncion = ordenarServicio;

	validacion = ll_sort(listaServicios,pfuncion, 1);

	if(validacion == -1)
	{
		printf("ERROR, Lista de servicios no encontrada");//el puntero de la lista es NULL
	}
}


void guardarArchivo(LinkedList* listaServicios)
{
	FILE* pArchivoTexto;
	eServicio* servicio;
	int tam;
	int i;

	tam = ll_len(listaServicios);

	if(listaServicios !=NULL)
	{
		pArchivoTexto = fopen("servicios-ordenados.csv","w");

		if(pArchivoTexto !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				servicio = (eServicio*)ll_get(listaServicios,i);
				fwrite(servicio,sizeof(servicio),1,pArchivoTexto);
			}
		}
		fclose(pArchivoTexto);
		printf("se guardo existosamente la lista de servicios en ´servicios-ordenados.csv´");
	}
	printf("lista de servicios inexistente");
}
