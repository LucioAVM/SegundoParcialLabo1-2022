/*
 * Parcer.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Monsalbo Lucio
 */

#include <stdio.h>
#include <stdlib.h>
#include "Servicios.h"

int parser_PasajeroDesdeTexto(FILE* pArchivo , LinkedList* listaServicios[])
{
	int retorno;
	eServicio pServicio;

	retorno = -1;

	char id_servici[5];
	char descripcion[25];
	char tipo[2];
	char precioUnitario[5];
	char cantidad[5];
	char totalServicio[5];

	int numeroScanf;

	fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]/n");//falsa lectura para el titulo

	do{
		numeroScanf = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]/n",id_servici,descripcion,tipo,precioUnitario,cantidad,totalServicio);
		if(numeroScanf == 6)
		{

			pServicio = ePasajero_newParametros(id_servici, descripcion, tipo, precioUnitario, cantidad, totalServicio);

			ll_add(listaServicios, pServicio);//(puede necesitar parceo)
		}
	}while(!feof(pArchivo));

	return 1;
}
