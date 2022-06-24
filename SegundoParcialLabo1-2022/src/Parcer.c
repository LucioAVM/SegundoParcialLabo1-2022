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
	int validacionAdd;

	eServicio* pServicio;

	retorno = -1;

	char id_servicio[5];
	char descripcion[25];
	char tipo[2];
	char precioUnitario[5];
	char cantidad[5];
	char totalServicio[5];

	int numeroScanf;

	fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^/n]/n",id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);//falsa lectura para el titulo

	//printf("%s      %s      %s      %s       %s        %s\n", id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);

	do{
		numeroScanf = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]/n", id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);
		if(numeroScanf == 6)
		{

			pServicio = eServicio_newParametros(id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);

			validacionAdd = ll_add(listaServicios,(eServicio*) &pServicio);//(puede necesitar parceo)

			if(validacionAdd == 0)
			{
				retorno = 0;
			}
		}

		//printf("%s      %s      %s      %s       %s        %s\n", id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);
	}while(!feof(pArchivo));

	return retorno;
}
