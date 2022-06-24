/*
 * Servicios.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Monsalbo Lucio
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

#include "LinkedList.h"

typedef struct
{
	int id_servicio;
	char descripcion[25];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;
}eServicio;

/**
 * @brief crea una LinkedList con todos sus parametros 0 o nulos
 *
 * @return devuelve la linkedList
 */
eServicio* eServicio_new();

/**
 * @brief crea y la carga con parametros
 *
 * @param id_servicioStr
 * @param descripcion
 * @param tipoStr
 * @param precioUnitarioStr
 * @param cantidadStr
 * @param totalServicioStr
 * @return la LL con parametros ya cargados
 */
eServicio* eServicio_newParametros(char* id_servicioStr, char* descripcion, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr);

/**
 * @brief libera el espacio de memoria ocupado por la estructura
 *
 * @param this
 */
void eServicio_delete(eServicio* this);

/**
 * @brief carga la estructura con el id ingresado
 *
 * @param this
 * @param id
 * @return -1 = ERROR  0 = OK
 */
int eServicio_setId(eServicio* this, int id);

/**
 * @brief devuelve el id de la estructura por parametro
 *
 * @param this
 * @param id
 * @return -1 = ERROR  0 = OK
 */
int eServicio_getId(eServicio* this, int* id);

/**
 * @brief carga la estructura con la descripcion ingresada
 *
 * @param this
 * @param descripcion
 * @return -1 = ERROR  0 = OK
 */
int eServicio_setDescripcion(eServicio* this, char* descripcion);

/**
 * @brief devuelve la decripcion de la estructura por parametro
 *
 * @param this
 * @param descripcion
 * @return -1 = ERROR  0 = OK
 */
int eServicio_getDescripcion(eServicio* this, char* descripcion);

/**
 * @brief carga la estructura con el tipo ingresado
 *
 * @param this
 * @param Tipo
 * @return -1 = ERROR  0 = OK
 */
int eServicio_setTipo(eServicio* this, int Tipo);

/**
 * @brief devuelve el tipo de la estructura por parametro
 *
 * @param this
 * @param TipoStr
 * @return -1 = ERROR  0 = OK
 */
int eServicio_getTipo(eServicio* this, char* TipoStr);

/**
 * @brief carga la estructura con el precio unitario ingresado
 *
 * @param this
 * @param precioUnitario
 * @return -1 = ERROR  0 = OK
 */
int eServicio_setPrecioUnitario(eServicio* this, float precioUnitario);

/**
 * @brief devuelve precioUnitario de la estructura por parametro
 *
 * @param this
 * @param precioUnitario
 * @return -1 = ERROR  0 = OK
 */
int eServicio_getPrecioUnitario(eServicio* this, float* precioUnitario);
/**
 * @brief carga la estructura con el cantidad ingresado
 *
 * @param this
 * @param cantidad
 * @return -1 = ERROR  0 = OK
 */
int eServicio_setCantidad(eServicio* this, int cantidad);

/**
 * @brief devuelve cantidad de la estructura por parametro
 *
 * @param this
 * @param cantidad
 * @return -1 = ERROR  0 = OK
 */
int eServicio_getCantidad(eServicio* this, int* cantidad);

/**
 * @brief carga la estructura con el total ingresado
 *
 * @param this
 * @param totalServicio
 * @return -1 = ERROR  0 = OK
 */
int eServicio_setTotalServicio(eServicio* this, float totalServicio);

/**
 * @brief devuelve servicio de la estructura por parametro
 *
 * @param this
 * @param totalServicio
 * @return -1 = ERROR  0 = OK
 */
int eServicio_getTotalServicio(eServicio* this, float* totalServicio);

/**
 * @brief llama y valida todos los gets usados en eServicios
 *
 * @param servicio
 * @param id_servicio
 * @param descripcion
 * @param tipo
 * @param precioUnitario
 * @param cantidad
 * @param totalServicio
 * @return -1 = ERROR  0 = OK
 */
int validacion_gets(eServicio* servicio, int* id_servicio, char descripcion[], char* tipo, float* precioUnitario, int* cantidad, float* totalServicio);

/**
 * @brief multiplica la cantidad por el precio y lo carga en la estructura
 *
 * @param pElement
 *
 * @return la estructura con el precio total ya cargado
 */
void* asignarTotales(void* pElement);

/**
 * @brief muestra un servicio
 *
 * @param listaServicios
 * @param index
 * @return -1 = ERROR  0 = OK
 */
int mostrarUnServicio(LinkedList* listaServicios, int index);

/**
 * @brief aplica un strcmp a las descripciones de 2 estructuras
 *
 * @param pElement1
 * @param pElement2
 * @return retorna el resultado de strcmp
 */
int ordenarServicio(void* pElement1, void* pElement2);

/**
 * @brief discrimina entre los tipos de servicios (Minorista)
 *
 * @param element
 * @return -1 = no es del tipo pedido  1 = es del tipo pedido
 */
int filtrarTipo_Minorista(void* element);

/**
 * @brief discrimina entre los tipos de servicios (Mayorista)
 *
 * @param element
 * @return -1 = no es del tipo pedido  1 = es del tipo pedido
 */
int filtrarTipo_Mayorista(void* element);

/**
 * @brief discrimina entre los tipos de servicios (Exportar)
 *
 * @param element
 * @return -1 = no es del tipo pedido  1 = es del tipo pedido
 */
int filtrarTipo_Exportar(void* element);



#endif /* SERVICIOS_H_ */
