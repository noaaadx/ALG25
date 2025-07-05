/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include "NodoCola.h"
struct Lista {
    struct NodoCola * cabeza; /*apunta al inicio de la lista*/
    struct NodoCola * cola; /*NEW   apunta al final de la lista*/
    int longitud; /*guarda la longitud de la lista*/
};

#endif /* LISTA_H */

