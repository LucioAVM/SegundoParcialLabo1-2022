/*
 * LinkedList.c
 *
 *  Created on: 21 jun. 2022
 *      Author: UGIO
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList*));

	if(this!=NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}

	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int retorno = -1;
	if(this!=NULL)
	{
		retorno = this->size;
	}

	return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex) // nodeindex<ll_lend  nodeIndex >=0
{
	Node* pNode;// hacer con while
	int i;

	pNode = NULL;

	if(this!=NULL && nodeIndex<ll_len(this) && nodeIndex > -1)
	{
		pNode = this->pFirstNode;

		for(i = 0; i< nodeIndex; i++)
		{
			pNode = pNode->pNextNode;
		}
	}
	return pNode;
}


/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node* pNodoAnterior;
	Node* pNuevoNode;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		pNuevoNode = (Node*) malloc(sizeof(Node*));// CREO ESPACIO
		if(pNuevoNode != NULL)
		{
			pNuevoNode->pElement = pElement;
			pNuevoNode->pNextNode = NULL;

			if(nodeIndex == 0)
			{
				pNuevoNode->pNextNode = this->pFirstNode; // PRIMER PUNTERO LL == NULL
				this->pFirstNode = pNuevoNode;// NODO PELEMENT Y APUNTA AL SIGUIENTE
			}else{
				pNodoAnterior = getNode(this,nodeIndex-1); // PINDE EL NODO ANTERIOR PARA LINKEAR
				pNuevoNode->pNextNode = pNodoAnterior->pNextNode;// SACA EL NULL Y APUNTA AL SIGUIENTE
				pNodoAnterior->pNextNode = pNuevoNode;
			}
			this->size++;
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int retornoAux;
	int tamNode;

	retornoAux = -1;
	tamNode = ll_len(this);

	if(this!=NULL)
	{
		if(tamNode == 0)
		{
			addNode(this,0,pElement);
			retornoAux = 0;
		}else{
			addNode(this, tamNode, pElement);
			retornoAux = 0;
		}
	}
	return retornoAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* retornoAux;
	Node* aux;

	retornoAux = NULL;

	if(this != NULL && index<ll_len(this) && index > -1)
	{
		aux = getNode(this,index);
		if(aux != NULL)
		{
			retornoAux = aux->pElement;
		}
	}
	return retornoAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int retornoAux = -1;
	Node* pNode;

	if(this !=NULL && index > -1 && index < ll_len(this))
	{
		pNode = getNode(this, index);
		if(pNode != NULL)
		{
			pNode->pElement = pElement;
			retornoAux = 0;
		}
	}
	return retornoAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int retornoAux = -1;
	Node* removerNodo;
	Node* nodoPrevio;

	removerNodo = NULL;
	nodoPrevio = NULL;

	if(this != NULL && index > -1 && index < ll_len(this))
	{
		removerNodo = getNode(this, index);

		if(index == 0)
		{
			this->pFirstNode = removerNodo->pNextNode;
		}else{
			nodoPrevio = getNode(this,index - 1);
			nodoPrevio->pNextNode = removerNodo->pNextNode;
		}
		free(removerNodo);
		this->size--;
		retornoAux = 0;
	}
	return retornoAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int retorno;
	int tam;

	retorno = -1;

	if(this != NULL)
	{
		tam = ll_len(this);
		do
		{
			ll_remove(this,tam);
			tam--;
		}while(this->pFirstNode != NULL);
		retorno = 0;
	}
	return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int retorno;
	Node* pNode;
	int i;
	Node* auxiliarNodo;

	retorno = -1;

	if(this != NULL)
	{
		pNode = this->pFirstNode;
		for(i=0 ; i<this->size ; i++)			// RECORRE THIS (SIZE) VECES
		{
			if(pNode == NULL)
			{
				pNode = auxiliarNodo;
			}
			pNode = pNode->pNextNode;
			auxiliarNodo = pNode;
			free(pNode);
		}
		free(this->pFirstNode);
		retorno = 0;
	}
	return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int retorno = -1;
	void* pAuxElement;
	int i;
	int tam;

	tam = ll_len(this);

	if(this != NULL)
	{
		for(i=0; i<tam; i++)
		{
			pAuxElement = ll_get(this, i);

			if(pAuxElement == pElement)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int retorno;
	int i;
	int tam;

	retorno = -1;

	if(this != NULL)
	{
		tam = ll_len(this);

		for(i=0; i<tam; i++)
		{

			if((ll_get(this, i)) == NULL)
			{
				retorno = 0;
				break;
			}
		}
		if(i == tam && retorno == -1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int retorno;

	retorno = -1;

	if(this != NULL && index >=0 && index <= ll_len(this))//valido para las 2 funciones
	{
		retorno = addNode(this,index, pElement);
	}
	return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* retorno;
	int tam;

	retorno = NULL;
	tam = ll_len(this);

	if(this != NULL && index >= 0 && index < tam)
	{
		retorno = ll_get(this,index);
		ll_remove(this,index);
	}
	return retorno;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList* this, void* pElement)
{
	int retorno = -1;
	int i;


	if(this != NULL)
	{
		i = ll_indexOf( this, pElement);
		if(i >= 0)
		{
			retorno = 1;
		}else{
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int retorno = -1;
	int i;
	void* elemento;
	int resultadoContain;

	if(this != NULL && this2 != NULL)
	{
		retorno = 1;
		for(i = 0; i<ll_len(this); i++)
		{
			elemento = ll_get(this2,i);

			if(elemento != NULL)
			{
				resultadoContain = ll_contains(this,elemento);
				if(resultadoContain == 0)
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* cloneArray;
	int i;
	void* elemento;
	int tam;

	cloneArray = NULL;
	tam = ll_len(this);

	if(this != NULL && from >= 0 && from < to && to > from && to <= tam)
	{
		cloneArray = ll_newLinkedList();

		for(i = from ; i<to ; i++)
		{
			elemento = ll_get(this,i);
			ll_add(cloneArray, elemento);
		}
	}
	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneArray;
	int tam;

	cloneArray = NULL;

	if(this != NULL)
	{
		tam = ll_len(this);
		cloneArray = ll_subList(this, 0, tam);
	}
	return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (pFunc)(void* ,void*), int order)
{
	int retorno =-1;
	void* pElement1;
	void* pElement2;
	void* aux;
	int verificacion;
	int i;
	int j;
	int len;

	if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
	{
		len = ll_len(this);

		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				pElement1 = ll_get(this, i);
				pElement2 = ll_get(this, j);
				verificacion = pFunc(pElement1, pElement2);
				if(verificacion > 0 && order == 1)
				{
					aux = pElement1;
					pElement1 = pElement2;
					pElement2 = aux;

					ll_set(this, i, pElement1);
					ll_set(this, j, pElement2);
				}
				else
				{
					if(verificacion < 0 && order == 0)
					{
						aux = pElement2;
						pElement2 = pElement1;
						pElement1 = aux;

						ll_set(this, i, pElement1);
						ll_set(this, j, pElement2);
					}
				}
			}
		}
		retorno=0;
	}
	return retorno;
}

