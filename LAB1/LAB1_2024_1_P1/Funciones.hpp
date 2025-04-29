/* 
 * File:   Funciones.hpp
 * Author: sebas
 *
 * Created on 4 de abril de 2025, 08:04 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#define MAX_GUERREROS 3
#define MAX_ARMAS 12
using namespace std;

void test01();
void cargaCromosoma(int combinaciones, int *cromosoma);
void Guerrero1(int PoderFila[MAX_GUERREROS +1], char armas[MAX_ARMAS][3],int armas_poder[MAX_ARMAS]);


#endif /* FUNCIONES_HPP */
