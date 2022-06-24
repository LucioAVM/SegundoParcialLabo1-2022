/*
 * Parcer.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Monsalbo Lucio
 */

#ifndef PARCER_H_
#define PARCER_H_

#include "LinkedList.h"

/**
 * @brief lee el archivo, lo parsea y carga a la LL
 *
 * @param pArchivo
 * @param listaServicios
 * @return -1 = ERROR  0 = OK
 */
int parser_PasajeroDesdeTexto(FILE* pArchivo , LinkedList* listaServicios);

#endif /* PARCER_H_ */
