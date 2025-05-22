/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 17 de mayo de 2025, 05:03 AM
 */

#include <iostream>
#include <fstream>
#include "Estructuras.h"
#include "funcionLista.h"

using namespace std;

void recopilacionDatos(struct Lista* &camiones, int &cantCamiones, int tortugas[],const char*nomArch){
    ifstream archivo(nomArch, ios::in);
    if(!archivo.is_open()){
        cout<<"ERROR al abrir el archivo "<<nomArch<<endl;
        exit(10);
    }
    archivo>>cantCamiones;
    
    for(int i=0; i<4; i++){
        archivo>>tortugas[i];
    }
    
    camiones = new Lista[cantCamiones];            
    for(int i=0; i<cantCamiones; i++){
        construir(camiones[i]);
        int peso;
        while(archivo>>peso){
            insertaAlFinal(camiones[i], peso);
            if(peso ==0)break;
        }
//        imprimirLista(camiones[i]);
//        cout<<endl;
    }
    archivo.close();
}

void verificarSolucion(struct TortuNinja tortuNinja, int numTortuga){
    
}
int main(int argc, char** argv) {
    
    Lista* camiones;
    int cantCamiones, tortugas[4];
    TortuNinja tortuNinja[4];
    
    //llenar los datos
    recopilacionDatos(camiones, cantCamiones, tortugas, "camiones.txt");
    
    //implementar funcion para determinar una posible solucion
    if(verificarSolucion(tortuNinja, 4)){
        //imprimirListaFinal(tortuNinja, 4);
        cout<<"La mision se completó con exito"<<endl;
    }else{
        cout<<"La mision fallo"<<endl;
    }
    return 0;
}

