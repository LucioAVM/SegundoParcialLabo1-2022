/*
 * Parcer.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Monsalbo Lucio
 */

#include <stdio.h>
#include <stdlib.h>
#include "Parcer.h"
#include "Servicios.h"

int parser_PasajeroDesdeTexto(FILE* pArchivo , LinkedList* listaServicios)
{
	int retorno;

	eServicio* pServicio;

	retorno = -1;


	char id_servicio[5];
	char descripcion[25];
	char tipo[2];
	char precioUnitario[5];
	char cantidad[5];
	char totalServicio[5];

	char basura[25];

	int numeroScanf;

	fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^/n]/n",basura,basura,basura,basura,basura,basura);//falsa lectura para el titulo

	//printf("%s      %s      %s      %s       %s        %s\n", id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);

	do{
		numeroScanf = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);
		if(numeroScanf == 6)
		{
			printf("\nID   STRING: %s\n", id_servicio);
			printf("\nDES  STRING: %s\n", descripcion);
			printf("\nTIPO STRING: %s\n", tipo);
			printf("\nPU STRING: %s\n\n", precioUnitario);
			pServicio = eServicio_newParametros(id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);

			if(!(ll_add(listaServicios,pServicio)))
			{
				retorno = 0;
			}
		}

		//printf("%s      %s      %s      %s       %s        %s\n", id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);
	}while(!(feof(pArchivo)));

	return retorno;
}

/*
int parser_PasajeroDesdeTexto(FILE* pArchivo , LinkedList* listaServicios)
{

	int retorno;

	retorno = -1;

	eServicio servicio;

	fread(&servicio,sizeof(eServicio),1, pArchivo);

	do
	{
		fread(&servicio,sizeof(eServicio),1, pArchivo);
		printf("\n\nPU STRING: %f\n\n", servicio.precioUnitario);
	}while(!feof(pArchivo));

	if(ll_add(listaServicios, &servicio))
	{
		retorno = 0;
	}

	return retorno;
}
*/
