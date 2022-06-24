/*
 * Servicios.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Monsalbo Lucio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicios.h"

/******************************************************************************************************
											Nuevo
 ******************************************************************************************************/

eServicio* eServicio_new()
{
    eServicio* this = (eServicio*) malloc(sizeof(eServicio));
    if(this != NULL)
    {
        this->id_servicio = 0;
        strcpy(this->descripcion,"");
        this->tipo = 0;
        this->precioUnitario = 0;
        this->cantidad = 0;
        this->totalServicio = 0;
    }
    return this;
}

/******************************************************************************************************

 ******************************************************************************************************/

eServicio* eServicio_newParametros(char id_servicioStr[], char descripcion[], char tipoStr[], char precioUnitarioStr[], char cantidadStr[], char totalServicioStr[])
{
    eServicio* retorno = NULL;
    eServicio* pServicio;

    int id_servicio;
    int tipo;
    float precioUnitario;
    int cantidad;
    int totalServicio;

    if(id_servicioStr != NULL && descripcion != NULL && tipoStr != NULL && precioUnitarioStr != NULL && cantidadStr != NULL && totalServicioStr != NULL)
    {
    	pServicio = eServicio_new();

        if(pServicio != NULL)
        {
        	//printf("%s ANTES \n",id_servicioStr);

        	id_servicio    = atoi(id_servicioStr);
        	tipo           = atoi(tipoStr);
        	precioUnitario = atof(precioUnitarioStr);
        	cantidad       = atoi(cantidadStr);
        	totalServicio  = atoi(totalServicioStr);

        	//printf("%d DESPUES\n",id_servicio);

            eServicio_setId(pServicio,id_servicio);
            eServicio_setDescripcion(pServicio,descripcion);
            eServicio_setTipo(pServicio,tipo);
            eServicio_setPrecioUnitario(pServicio,precioUnitario);
            eServicio_setCantidad(pServicio,cantidad);
            eServicio_setTotalServicio(pServicio,totalServicio);

            retorno = pServicio;
        }
    }
    return retorno;
}
/******************************************************************************************************
										Borrar
 ******************************************************************************************************/
void eServicio_delete(eServicio* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/******************************************************************************************************
									  id_servicio
 ******************************************************************************************************/

int eServicio_setId(eServicio* this, int id)
{
	int retorno;

	retorno = -1;

    if(this != NULL && id > 0)
    {
        this->id_servicio = id;
        retorno = 0;
    }
    return retorno;
}


int eServicio_getId(eServicio* this, int* id)
{
	int retorno;

	retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id_servicio;
        printf("%d\n\n\n",*id);
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
										Descripcion
 ******************************************************************************************************/

int eServicio_setDescripcion(eServicio* this, char* descripcion)
{
	int retorno;

	retorno = -1;

    if(this != NULL && descripcion != NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno = 0;
    }
    return retorno;
}


int eServicio_getDescripcion(eServicio* this, char* descripcion)
{
	int retorno;

	retorno = -1;

    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
											Tipo
 ******************************************************************************************************/

int eServicio_setTipo(eServicio* this, int Tipo)
{
	int retorno;

	retorno = -1;

    if(this != NULL && Tipo < 4 && Tipo > 0)
    {
        this->tipo = Tipo;
        retorno = 0;
    }
    return retorno;
}
int eServicio_getTipo(eServicio* this, char* TipoStr)
{
    int retorno;
    int tipo;

    retorno = -1;

    if(this != NULL && TipoStr != NULL)
    {
    	tipo = this->tipo;
        switch(tipo)
        {
        case 1:
        	strcpy(TipoStr, "Minorista");
        	break;
        case 2:
        	strcpy(TipoStr, "Mayorista");
        	break;
        case 3:
        	strcpy(TipoStr, "Exportar ");
        	break;
        }
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
										PrecioUnitario
 ******************************************************************************************************/

int eServicio_setPrecioUnitario(eServicio* this, float precioUnitario)
{
	int retorno;

	retorno = -1;

    if(this != NULL && precioUnitario < 4 && precioUnitario > 0)
    {
        this->precioUnitario = precioUnitario;
        retorno = 0;
    }
    return retorno;
}
int eServicio_getPrecioUnitario(eServicio* this, float* precioUnitario)
{
	int retorno;

	retorno = -1;
    if(this != NULL && precioUnitario != NULL)
    {
        *precioUnitario = this->precioUnitario;
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
										 Cantidad
 ******************************************************************************************************/

int eServicio_setCantidad(eServicio* this, int cantidad)
{
	int retorno;

	retorno = -1;

    if(this != NULL && cantidad < 4 && cantidad > 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}
int eServicio_getCantidad(eServicio* this, int* cantidad)
{
	int retorno;

	retorno = -1;

    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
										TotalServicio
 ******************************************************************************************************/

int eServicio_setTotalServicio(eServicio* this, float totalServicio)
{
	int retorno;

	retorno = -1;

    if(this != NULL)
    {
        this->totalServicio = totalServicio;
        retorno = 0;
    }
    return retorno;
}
int eServicio_getTotalServicio(eServicio* this, float* totalServicio)
{
	int retorno;

	retorno = -1;

    if(this != NULL && totalServicio != NULL)
    {
        *totalServicio = this->totalServicio;
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
									   Validacion Gets
 ******************************************************************************************************/
int validacion_gets(eServicio* servicio, int* id_servicio, char descripcion[], char* tipo, float* precioUnitario, int* cantidad, float* totalServicio)
{
	int retorno;

	retorno = -1;

	if(servicio != NULL && id_servicio != NULL && descripcion != NULL && tipo != NULL && precioUnitario != NULL && cantidad != NULL && totalServicio!= NULL)
	{
		if((!(eServicio_getId(servicio,id_servicio)) &&
				!(eServicio_getDescripcion(servicio,descripcion)) &&
				!(eServicio_getTipo(servicio,tipo)) &&
				!(eServicio_getPrecioUnitario(servicio,precioUnitario)) &&
				!(eServicio_getCantidad(servicio,cantidad)) &&
				!(eServicio_getTotalServicio(servicio,totalServicio))))
		{
			retorno = 0;
		}
	}

	return retorno;
}

/******************************************************************************************************
										Opcion 3
 ******************************************************************************************************/
void* asignarTotales(void* pElement)
{
	int cantidad;
	float precioUnitario;
	float total;

	eServicio* servicio = NULL;

	servicio = pElement;

	eServicio_getCantidad(servicio,&cantidad);
	eServicio_getPrecioUnitario(servicio,&precioUnitario);

	total = cantidad * precioUnitario;

	eServicio_setTotalServicio(servicio, total);

	return servicio;
}

/******************************************************************************************************
										Mostrar
 ******************************************************************************************************/
int mostrarUnServicio(LinkedList* listaServicios, int index)
{
	eServicio* servicio = NULL;

	int retorno;

	int id_servicio;
	char descripcion[25];
	char tipo[15];
	float precioUnitario;
	int cantidad;
	float totalServicio;

	retorno = -1;

	servicio =(eServicio*) ll_get(listaServicios, index);

	if(!(validacion_gets(servicio, &id_servicio, descripcion, tipo, &precioUnitario, &cantidad, &totalServicio)))
	{
		printf("%d      %s      %s      %f.2       %d        %f.2\n", id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);

		retorno = 0;
	}
	return retorno;
}

/******************************************************************************************************
										Opcion 5
 ******************************************************************************************************/
int ordenarServicio(void* pElement1, void* pElement2)
{
	int retorno;//1 o -1

	char descripcion_1[25];
	char descripcion_2[25];

	retorno = 0;//no hace nada en ll_sort

	if(!(eServicio_getDescripcion(pElement1,descripcion_1)) && !(eServicio_getDescripcion(pElement2,descripcion_2)))
	{
		retorno = strcmp(descripcion_1,descripcion_2);
	}

	return retorno;
}

/******************************************************************************************************
										Opcion 4
 ******************************************************************************************************/
int filtrarTipo_Minorista(void* element)
{
	int retorno;

	retorno = -1;

	eServicio* servicio = element;

	if(servicio->tipo == 1)
	{
		retorno = 1;
	}

	return retorno;
}


int filtrarTipo_Mayorista(void* element)
{
	int retorno;

	retorno = -1;

	eServicio* servicio = element;

	if(servicio->tipo == 2)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarTipo_Exportar(void* element)
{
	int retorno;

	retorno = -1;

	eServicio* servicio = element;

	if(servicio->tipo == 3)
	{
		retorno = 1;
	}

	return retorno;
}
/******************************************************************************************************
											fin
 ******************************************************************************************************/
