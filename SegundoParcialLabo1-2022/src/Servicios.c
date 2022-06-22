/*
 * Servicios.c
 *
 *  Created on: 21 jun. 2022
 *      Author: UGIO
 */

#include <stdio.h>
#include <stdlib.h>
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

eServicio* eServicio_newParametros(char* id_servicioStr, char* descripcion, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr)
{
    eServicio* retorno = NULL;
    eServicio* pServicio;

    int id_servicio;
    int tipo;
    float precioUnitario;
    int cantidad;
    int totalServicio;

    if(id_servicio != NULL && descripcion != NULL && tipo != NULL && precioUnitario != NULL && cantidad != NULL && totalServicio != NULL)
    {
    	pServicio = eServicio_new();

        if(pServicio != NULL)
        {

        	id_servicio    = atoi(id_servicioStr);
        	tipo           = atoi(tipoStr);
        	precioUnitario = atof(precioUnitarioStr);
        	cantidad       = atoi(cantidadStr);
        	totalServicio  = atoi(totalServicioStr);


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
    free(this);
}

/******************************************************************************************************
									  id_servicio
 ******************************************************************************************************/

int eServicio_setId(eServicio* this,int id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->id_servicio = id;
        retorno = 0;
    }
    return retorno;
}


int eServicio_getId(eServicio* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id_servicio;
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
										Descripcion
 ******************************************************************************************************/

int eServicio_setDescripcion(eServicio* this,char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno = 0;
    }
    return retorno;
}


int eServicio_getDescripcion(eServicio* this,char* descripcion)
{
    int retorno = -1;
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

int eServicio_setTipo(eServicio* this,int Tipo)
{
    int retorno = -1;
    if(this != NULL && Tipo < 4 && Tipo > 0)
    {
        this->tipo = Tipo;
        retorno = 0;
    }
    return retorno;
}
int eServicio_getTipo(eServicio* this,int* Tipo)
{
    int retorno = -1;
    if(this != NULL && Tipo != NULL)
    {
        *Tipo = this->tipo;
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
										PrecioUnitario
 ******************************************************************************************************/

int eServicio_setPrecioUnitario(eServicio* this,float precioUnitario)
{
    int retorno = -1;
    if(this != NULL && precioUnitario < 4 && precioUnitario > 0)
    {
        this->precioUnitario = precioUnitario;
        retorno = 0;
    }
    return retorno;
}
int eServicio_getPrecioUnitario(eServicio* this,float* precioUnitario)
{
    int retorno = -1;
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

int eServicio_setCantidad(eServicio* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad < 4 && cantidad > 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}
int eServicio_getCantidad(eServicio* this,int* cantidad)
{
    int retorno = -1;
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

int eServicio_setTotalServicio(eServicio* this,float totalServicio)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->totalServicio = totalServicio;
        retorno = 0;
    }
    return retorno;
}
int eServicio_getTotalServicio(eServicio* this,float* totalServicio)
{
    int retorno = -1;
    if(this != NULL && totalServicio != NULL)
    {
        *totalServicio = this->totalServicio;
        retorno = 0;
    }
    return retorno;
}
/******************************************************************************************************
											Estado
 ******************************************************************************************************/

//int eServicio_setEstado(eServicio* this,float estado)
//{
//    int retorno = -1;
//    if(this != NULL && estado >= 0)
//    {
//        this->estado = estado;
//        retorno = 0;
//    }
//    return retorno;
//}
//int eServicio_getEstado(eServicio* this,float* estado)
//{
//    int retorno = -1;
//    if(this != NULL && estado != NULL)
//    {
//        *estado = this->estado;
//        retorno = 0;
//    }
//    return retorno;
//}

