
/* 
 * File:   Nodo.h
 * Author: sebas
 *
 * Created on 3 de mayo de 2025, 08:50 AM
 */

#ifndef NODO_H
#define NODO_H

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

struct Nodo *CrearNodo(int numero){
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->elemento = numero;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;            
}

bool EsNodoVacio(Nodo *nodo){
    if(nodo==nullptr){
        return true;
    }else{
        return false;
    }
}
#endif /* NODO_H */

