/*
 * Menu.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Monsalbo Lucio
 */

#ifndef MENU_H_
#define MENU_H_

#include "LinkedList.h"
#include "Servicios.h"
#include "Parcer.h"

/**
 * @brief muestra el menu
 *
 * @return devuelve la opcion elegida del menu
 */
int getMenu(void);

/**
 * @brief pide el nombre del archivo y guarda los datos en la LinkedList
 *
 * @param listaServicios
 * @param bandera
 */
int archivo_servicios(LinkedList* listaServicios,char* path);

/**
 * @brief abre/cierra el archivo y parsea los datos
 *
 * @param path
 * @param listaServicios
 *
 * @return -1 = ERROR  0 = OK
 */
int cargaDeArchivo(char* path, LinkedList* listaServicios);

/**
 * @brief muestra los datos de la LinkedList
 *
 * @param listaServicios
 */
int listarServicios(LinkedList* listaServicios);

/**
 *
 * @param listaServicios
 */
int eServicio_Totales(LinkedList* listaServicios);

/**
 * @brief genera un archivo con los servicios del tipo seleccionado
 *
 * @param listaServicios
 */
int ordenar_tipo(LinkedList* listaServicios);

/**
 * @brief muestra un listado de los servicios ordenados por descripcion de manera ascendente
 *
 * @param listaServicios
 */
int mostrarServiciosAsendente(LinkedList* listaServicios);

/**
 * @brief guarda los datos en un archivo llamado "servicios-ordenados.csv"
 *
 * @param listaServicios
 */
int guardarArchivo(LinkedList* listaServicios, char path[]);


int filtrarPorPrecio(LinkedList* listaServicios);

int CargaArchivoYDescuento();

int promedio(LinkedList* listaMain);

int menu_TotalCantidades(LinkedList* listaMain);

#endif /* MENU_H_ */
