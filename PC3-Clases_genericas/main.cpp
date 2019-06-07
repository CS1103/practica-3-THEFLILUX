#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include "matriz.h"
using namespace std;

int main(){
    std::cout << "Dimensiones de la primera matriz:";
    int filas = 0, columnas = 0;
    std::cin >> filas >> columnas;
    Matrix<double > primeraMatrix(filas, columnas);
    std::cout << "Ingresa los valores de la matriz:\n";
    std::cin >> primeraMatrix;

    std::cout << "Dimensiones de la segunda matriz:";
    std::cin >> filas >> columnas;
    Matrix<double > segundaMatrix(filas, columnas);
    std::cout << "Ingresa los valores de la matriz:\n";
    std::cin >> segundaMatrix;

    std::cout << primeraMatrix + segundaMatrix;

    return 0;
}
