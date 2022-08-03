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
	char descripcion[30];
	char tipo[5];
	char precioUnitario[10];
	char cantidad[5];
	char totalServicio[5];

	int numeroScanf;

	do{
		numeroScanf = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);
		if(numeroScanf == 6 && atoi(id_servicio) > 0)
		{
			pServicio = eServicio_newParametros(id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);

			retorno = ll_add(listaServicios,pServicio);
		}
	}while(!(feof(pArchivo)));

	return retorno;
}
