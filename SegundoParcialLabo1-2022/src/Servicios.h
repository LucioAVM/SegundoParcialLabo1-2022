/*
 * Servicios.h
 *
 *  Created on: 21 jun. 2022
 *      Author: UGIO
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct
{
	int id_servicio;
	char descripcion[25];
	int tipo;
	int precioUnitario;
	int cantidad;
	int totalServicio;
}eServicio;

#endif /* SERVICIOS_H_ */
