/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 16 de noviembre de 2024, 18:23
 */

#include <iostream>
using namespace std;
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"

/*
 * 
 */
int main(int argc, char** argv) {

    struct ArbolBinario arbol, arbol1, arbol2, arbol3, arbol4, arbol5,
            arbol6, arbol7, arbol8, arbol9, arbol10, arbol11, arbol12,
            arbol13, arbol14, arbol15, arbol16, arbol17, arbol18;

    struct Elemento elementos[19] = {
        {'O'}, {'S'}, {'S'}, {'A'}, {'A'}, {'N'}, {'A'}, {'O'},
        {'O'}, {'B'}, {'N'}, {'R'}, {'E'}, {'L'}, {'E'}, {'R'},
        {'I'}, {'U'}, {'B'}};

    //falta la lectura de datos
    
    plantarArbolBinario(arbol1, nullptr, elementos[0], nullptr);
    plantarArbolBinario(arbol2, nullptr, elementos[1], nullptr);
    plantarArbolBinario(arbol3, nullptr, elementos[2], nullptr);

    plantarArbolBinario(arbol4, nullptr, elementos[3], nullptr);
    plantarArbolBinario(arbol5, nullptr, elementos[4], nullptr);

    plantarArbolBinario(arbol6, nullptr, elementos[5], nullptr);

    plantarArbolBinario(arbol7, arbol1, elementos[6], nullptr);
    plantarArbolBinario(arbol8, nullptr, elementos[7], arbol2);
    plantarArbolBinario(arbol9, nullptr, elementos[8], arbol3);

    plantarArbolBinario(arbol10, arbol7, elementos[9], nullptr);
    plantarArbolBinario(arbol11, arbol4, elementos[10], arbol8);
    plantarArbolBinario(arbol12, arbol5, elementos[11], arbol9);

    plantarArbolBinario(arbol13, arbol6, elementos[12], nullptr);
    plantarArbolBinario(arbol14, arbol10, elementos[13], nullptr);
    plantarArbolBinario(arbol15, arbol11, elementos[14], nullptr);
    plantarArbolBinario(arbol16, nullptr, elementos[15], arbol12);

    plantarArbolBinario(arbol17, arbol13, elementos[16], arbol14);
    plantarArbolBinario(arbol18, arbol15, elementos[17], arbol16);

    plantarArbolBinario(arbol, arbol17, elementos[18], arbol18);

    recorrerPreOrden(arbol);

    return 0;
}

