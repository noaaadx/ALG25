
/* 
 * File:   FuncionLista.cpp
 * Author: USUARIO
 * 
 * Created on 2 de mayo de 2025, 06:55 PM
 */

#include <cstddef>

#include "FuncionLista.h"
#include "Nodo.hpp"
#include "Lista.hpp"
using namespace std;

void construir(Lista &tad){
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.colaMay = nullptr;
    tad.colaMen = nullptr;
    tad.longitud = 0;
}

const bool esListaVacia(const struct Lista &tad){
    return (tad.cabeza == nullptr);
}

int longitud(struct Lista &tad){
    return tad.longitud;
}

void insertaEnCola(struct Lista &tad, struct Paciente elemento){
    struct Nodo *ultimoNodo = tad.cola;
    struct Nodo *nuevoNodo = crearNodo(elemento, nullptr);
    if(ultimoNodo == nullptr){
        tad.cabeza = nuevoNodo;
        tad.cola = nuevoNodo;
    }else{
        ultimoNodo->siguiente = nuevoNodo;
        tad.cola = nuevoNodo;
    }
    tad.longitud++;
}

struct Nodo *crearNodo(struct Paciente elemento, struct Nodo *siguiente){
    struct Nodo *nuevoNodo = new struct Nodo;
    nuevoNodo->Elemento =elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

int retornaCabeza(const struct Lista  &tad){
    return tad.cabeza->Elemento.fecha;
}

void eliminaCabeza(struct Lista &tad){
    struct Nodo *nodoAEliminar = tad.cabeza;
    if(nodoAEliminar != nullptr){
        tad.cabeza = tad.cabeza->siguiente;
        delete nodoAEliminar;
        tad.longitud--;
    }
}

void eliminaCola(struct Lista &tad){
    struct Nodo *ultimo = nullptr;
    struct Nodo *penultimo = nullptr;
    struct Nodo *recorrido = tad.cabeza;
    while(recorrido != nullptr){
        if(ultimo != nullptr){
            penultimo = ultimo;
        }
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    
    if(ultimo != nullptr){
        if(penultimo == nullptr){
            tad.cabeza =nullptr;
        }else{
            penultimo->siguiente = nullptr;
        }
        delete ultimo;
        tad.longitud--;
    }
}

void destruir(struct Lista &tad){
    struct Nodo *recorrido = tad.cabeza;
    while(recorrido != nullptr){
        struct Nodo *nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    tad.cabeza = nullptr;
    tad.longitud = 0;
}
void imprimir(const struct Lista &tad){
    cout<<fixed;
    cout<<setprecision(2);
    if(esListaVacia(tad)){
        cout<<"La lista está vacia no se puede mostrar"<<endl;
        return;
    }else{
        struct Nodo *recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout<<"[";
        
        while(recorrido != nullptr){
            if(!estaImprimiendoLaCabeza)
                cout<<", ";
            estaImprimiendoLaCabeza = 0;
            imprimirFecha(recorrido);
            cout<<" "<<recorrido->Elemento.codigo;
            recorrido = recorrido->siguiente;
        }
        cout<<"]"<<endl;
    }
}

void imprimirFecha(struct Nodo *recorrido){
    int dia, mes, anho;
    int fecha = recorrido->Elemento.fecha;
    anho = fecha/10000;
    fecha = fecha%10000;
    mes = fecha/100;
    fecha = fecha %100;
    dia = fecha;
    cout<<dia<<"/"<<mes<<"/"<<anho;
}

int obtenerEdad(struct Nodo *paciente){
    int diaHoy = 20250502;
    return diaHoy - paciente->Elemento.fecha;
}

void InsertarConPrioridad(struct Lista &tad, struct Paciente paciente){
    struct Nodo *nuevoNodo = crearNodo(paciente, nullptr);
    int edadNuevo = obtenerEdad(nuevoNodo);
    if(esListaVacia(tad)){
        tad.cabeza = nuevoNodo;
        if(edadNuevo>800000)tad.colaMay = nuevoNodo;
        if(edadNuevo<100000)tad.colaMen = nuevoNodo;
        tad.cola = nuevoNodo;
    }else{
        if(edadNuevo>800000){
            if(tad.colaMay != nullptr){
                nuevoNodo->siguiente = tad.colaMay->siguiente;
                tad.colaMay->siguiente = nuevoNodo;
                tad.colaMay = nuevoNodo;
                if(tad.colaMay->siguiente == nullptr)tad.cola = nuevoNodo;
            }else{
                nuevoNodo->siguiente = tad.cabeza;
                tad.cabeza = nuevoNodo;
                tad.colaMay = nuevoNodo;
            }
        }
        else if(edadNuevo<100000){
            if(tad.colaMen != nullptr){
                nuevoNodo->siguiente = tad.colaMen->siguiente;
                tad.colaMen->siguiente = nuevoNodo;
                tad.colaMen = nuevoNodo;
                if(tad.colaMen->siguiente == nullptr)tad.cola = nuevoNodo;
            }else{
                if(tad.colaMay != nullptr){
                    nuevoNodo->siguiente = tad.colaMay->siguiente;
                    tad.colaMay->siguiente = nuevoNodo;
                    tad.colaMen = nuevoNodo;
                    if(tad.colaMen->siguiente == nullptr)tad.cola = nuevoNodo;
                }else{
                    nuevoNodo->siguiente = tad.cabeza;
                    tad.cabeza = nuevoNodo;
                    tad.colaMen = nuevoNodo;
                }
            }
        }
        else{
            tad.cola->siguiente = nuevoNodo;
            tad.cola = nuevoNodo;
        }
    }
    tad.longitud++;
}

