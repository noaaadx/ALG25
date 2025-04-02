
/* 
 * File:   main.cpp
 * Author: sebas
 *
 * Created on 28 de marzo de 2025, 07:47 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;

//funcion burbuja
void bubleSort(int array[], int n){
    for(int i=0; i<= n-2; i++){
        for(int j=0; j<=n-2-i; j++){
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1]  = temp;
            }
        }
    }
}

int main(int argc, char** argv){
    int arrNum[8] = {90, 87, 88, 99, 23, 14, 7, 24};
    
    bubleSort(arrNum, 8);
    for(int i =0 ; i<8; i++){
        cout<<arrNum[i]<<endl;
    }
    
    return 0;
}

