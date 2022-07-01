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

/******************************************************************************************************
										Menu
 ******************************************************************************************************/
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

/******************************************************************************************************
										Opcion 1
 ******************************************************************************************************/
int archivo_servicios(LinkedList* listaServicios)//hacer una validacion para cuando cargue un archivo por segunda ves
{
	char path[20];
	int retorno;

	retorno = -1;

	if(listaServicios != NULL)
	{
		printf("ingrese el nombre del archivo que desea cargar\n");
		fflush(stdout);
		scanf("%s", path);

		if(!(cargaDeArchivo(path, listaServicios)))
		{
			retorno = 0;
		}
	}
	return retorno;
}

int cargaDeArchivo(char* path, LinkedList* listaServicios)
{
	int retorno;

	FILE* pArchivo = NULL;

	retorno = -1;

	if(listaServicios != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo == NULL)
		{
			printf("error");
		}else{
			parser_PasajeroDesdeTexto(pArchivo, listaServicios);//=>parser.c
			retorno = 0;
		}
		fclose(pArchivo);
	}
	return retorno;
}

/******************************************************************************************************
										Opcion 2
 ******************************************************************************************************/
int listarServicios(LinkedList* listaServicios)
{
	int i;
	int tam;
	int retorno;

	retorno = -1;

	if(listaServicios != NULL)
	{
		tam = ll_len(listaServicios);

		printf("Listado de Servicios:\n"
				"ID-------Descripcion-------Tipo-------Precio Unitario-------Cantidad-------Total\n");

		if(tam > 0)
		{
			for(i = 0 ; i < tam ; i++)
			{
				printf("\n\ncontador: %d\n\n", i);
				if(mostrarUnServicio(listaServicios, i) != 0)
				{
					printf("error al cargar el servicio en la pocision N° %d\n", i);
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}

/******************************************************************************************************
										Opcion 3
 ******************************************************************************************************/
int eServicio_Totales(LinkedList* listaServicios)
{
	LinkedList* listaConTotales = NULL;

	int i;
	int tam;
	int retorno;

	retorno = -1;

	void*(*pFuncion)(void*);

	if(listaServicios != NULL)
	{
		pFuncion = asignarTotales;

		listaConTotales = ll_map(listaServicios,pFuncion);

		if(listaConTotales != NULL)
		{
			printf("se cargo con exito la siguiente lista:\n");

			printf("Listado de Servicios:\n"
					"ID-------Descripcion-------Tipo-------Precio Unitario-------Cantidad-------Total\n");

			tam = ll_len(listaConTotales);

			for(i = 0 ; i < tam ; i++)
			{
				mostrarUnServicio(listaConTotales,i);
			}
			if(i == tam)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

/******************************************************************************************************
										Opcion 4
 ******************************************************************************************************/
int ordenar_tipo(LinkedList* listaServicios)
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
	int retorno;

	retorno = -1;

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
				break;
			case 2:
				pFuncion = filtrarTipo_Mayorista;
				break;
			case 3:
				pFuncion = filtrarTipo_Exportar;
				break;
			}

			listaFiltradaPorTipo = ll_filter (listaServicios, pFuncion);

			tam = ll_len(listaFiltradaPorTipo);

			do{
				servicio = ll_get(listaFiltradaPorTipo, contador);

				//preguntar si esta bien esto
				//logica: primero valida servicio y despues entra a funcion
				if(servicio != NULL && !(validacion_gets(servicio, &id_servicio, descripcion, tipo, &precioUnitario, &cantidad, &totalServicio)))
				{
					fprintf(pArchivo,"%d,%s,%s,%2.f,%d,%2.f\n",id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio);
				}

				contador++;
			}while(contador <= tam);

			if(contador == tam)
			{
				retorno = 0;
			}
			fclose(pArchivo);
		}
	}
	return retorno;
}

/******************************************************************************************************
										Opcion 5
 ******************************************************************************************************/
int mostrarServiciosAsendente(LinkedList* listaServicios)
{
	int retorno;

	retorno = -1;

	int (*pfuncion)(void*,void*);

	if(listaServicios != NULL)
	{
		pfuncion = ordenarServicio;

		if(!(ll_sort(listaServicios,pfuncion, 1)))
		{
			retorno = 0;
		}
	}
	return retorno;
}

/******************************************************************************************************
										Opcion 6
 ******************************************************************************************************/
int guardarArchivo(LinkedList* listaServicios, char path[])
{
	FILE* pArchivoTexto;
	eServicio* servicio;
	int tam;
	int i;
	int retorno;

	retorno = -1;

	tam = ll_len(listaServicios);

	if(listaServicios !=NULL)//"servicios-ordenados.csv"
	{
		pArchivoTexto = fopen(path,"w");

		if(pArchivoTexto !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				servicio = (eServicio*)ll_get(listaServicios,i);
				fwrite(servicio,sizeof(servicio),1,pArchivoTexto);
			}
			if(i == tam)
			{
				retorno = 0;
			}
		}
		fclose(pArchivoTexto);
	}
	return retorno;
}


int filtrarPorPrecio(LinkedList* listaServicios)
{
	int retorno;
	int tam;
	int i;
	int validacion;

	LinkedList* LL_Aux;

	retorno = -1;

	int (*pFunc)(void*);

	if(listaServicios != NULL)
	{
		pFunc = validadorPrecio;

		LL_Aux = ll_filter(listaServicios,pFunc, 1);

		printf("Listado de Servicios que superan los $1000 en valor total:\n"
				"ID-------Descripcion-------Tipo-------Precio Unitario-------Cantidad-------Total\n");

		tam = ll_len(LL_Aux);

		for(i = 0 ; i < tam ; i++)
		{
			mostrarUnServicio(LL_Aux,i);
		}
		validacion = guardarArchivo(LL_Aux,"FiltradoPorPrecio.csv");
		if(validacion == -1)
		{
			printf("\nError, al guardar la lita filtrada en un nuevo documento\n");
		}else{
			retorno = 0;
		}
	}
	return retorno;
}



int CargaArchivoYDescuento()
{
	int retorno;
	int validacion;
	LinkedList* listaServiciosFiltrada = ll_newLinkedList();

	retorno = -1;

	if(listaServiciosFiltrada != NULL)
	{
		archivo_servicio(listaServiciosFiltrada);

		validacion = aplicarDescuento(listaServiciosFiltrada);
		if(validacion == 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}
