/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 8 de junio de 2025, 16:56
 */

#include <iostream>
using namespace std;
#include "ArbolB.h"
#include "Elemento.h"
#include "funcionesAB.h"

/*
 *  ARBOLES BINARIOS 2025-1
 *  Clase ABB
 */
int main(int argc, char** argv) {

    /*   Árbol binario             
     *         100                    arbol    
     *        /   \                  /     \
     *      50     125           arbol5    arbol6
     *     /  \    /  \         /     \     /     \
     *   25   75  110  150  arbol1  arbol2 arbol3  arbol4
     */

    struct Elemento elementos[7] = {
        {25},
        {75},
        {110},
        {150},
        {50},
        {125},
        {100}};

    //    for (int i = 0; i < 7; i++) {
    //        cin>>elementos[i].numero;
    //    }

    struct ArbolBinario arbol, arbol1, arbol2, arbol3, arbol4, arbol5, arbol6;

    construir(arbol);
    
    //primero las hojas
    plantarArbolBinario(arbol1, nullptr, elementos[0], nullptr);
    plantarArbolBinario(arbol2, nullptr, elementos[1], nullptr);
    plantarArbolBinario(arbol3, nullptr, elementos[2], nullptr);
    plantarArbolBinario(arbol4, nullptr, elementos[3], nullptr);
    
    plantarArbolBinario(arbol5, arbol1, elementos[4], arbol2);
    plantarArbolBinario(arbol6, arbol3, elementos[5], arbol4);
    plantarArbolBinario(arbol, arbol5, elementos[6], arbol6);
    
    recorrerPreOrden(arbol);
    cout << endl;
    recorrerEnOrden(arbol);
    cout << endl;
    recorrerPostOrden(arbol);
    cout << endl;
    
    cout << endl;
    cout << "Altura del árbol: " << altura(arbol) << endl;
    return 0;
}
