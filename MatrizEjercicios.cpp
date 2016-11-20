// MatrizEjercicios.cpp : Defines the entry point for the console application.
//

/*
Angel Odiel Treviño Villanueva		A01336559
Descripcion: Ejercicios de Matrices 
LOC: 279	Tiempo: 2 horas 
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

void despliega(int iMat[7][7], int iRen, int iCol) {
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			cout << iMat[i][j] << ' ';
		}
		cout << endl;
	}
}

//inicializa con 0s
void inicializaMatriz1(int iMat[7][7], int iRen, int iCol) {
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			iMat[i][j] = 0;
		}
	}
}

//inicializa con numero de su columna
void inicializaMatriz2(int iMat[7][7], int iRen, int iCol) {
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			iMat[i][j] = j;
		}
	}
}

//inicializa con numero de su renglon
void inicializaMatriz3(int iMat[7][7], int iRen, int iCol) {
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			iMat[i][j] = i;
		}
	}
}

//inicializa con numero consecutivo  en forma de renglon
void inicializaMatriz4(int iMat[7][7], int iRen, int iCol) {
	int iCont = 0;
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			iMat[i][j] = iCont;
			iCont++;
		}
		
	}
}

//inicializa con numero consecutivo en forma de columna
void inicializaMatriz5(int iMat[7][7], int iRen, int iCol) {
	int iCont = 0;
	for (int j = 0; j < iCol; j++) {
		for (int i = 0; i < iRen; i++) {
			iMat[i][j] = iCont;
			iCont++;
		}
	}
}

//busca el mayor dentro de la matriz3x3
int mayor(int iMat3x3[7][7], int iRen, int iCol) {
	int iMax = iMat3x3[0][0];
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			if (iMat3x3[i][j] > iMax) {
				iMax = iMat3x3[i][j];
			}
		}
	}
	return iMax;
}

//Posicion del mayor de la matrix3x3
void posicionDelMayor(int iMat3x3[7][7], int iRen, int iCol) {
	int iMax = mayor(iMat3x3, iRen, iCol);
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			if (iMat3x3[i][j] == iMax) {
				cout << "el mayor se encuentra en el renglon: " << i << " en la columna: " << j;//si se toma que la matriz va de 0 a (iRen*iCol)-1 
			}
		}
	}
}

//identifica si es una matriz de identinad o no
bool matrizIdentidad(int iMatId[7][7], int iRen, int iCol) {
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			if (i == j && iMatId[i][j] != 1) {
				return false;
			}else if (i != j && iMatId[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

//Metodo que suma el contenido de la matriz
int suma(int iMat[7][7], int iRen, int iCol) {
	int iSuma = 0;
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			iSuma = iSuma + iMat[i][j];
		}
	}
	return iSuma;
}

//calcula el promedio de la matriz
double promedio(int iMat[7][7], int iRen, int iCol) {
	double dProm;
	dProm = suma(iMat, iRen, iCol) / (iRen*iCol);
	return dProm;
}

//suma de la diagonal inversa
int sumaDiagonalInversa(int iMat[7][7], int iRen, int iCol) {
	if (iRen == iCol) {
		int iSuma = 0;
		iCol = 0;
		for (int i = iRen - 1; i >= 0; i--) {
			iSuma = iSuma + iMat[i][iCol];
			iCol++;
		}
		return iSuma;
	}
	return -1;
}

//Suma de la diagonal principal
int sumaDiagonalPrincipal(int iMat[7][7], int iRen, int iCol) {
	if (iRen == iCol) {
		int iSum = 0;
		for (int i = 0; i < iRen; i++) {
			iSum = iSum + iMat[i][i];
		}
		return iSum;
	}
	return -1;
}

//busca x dentro de la matrix
bool busca(int iMat[7][7], int iRen, int iCol, int iX) {
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			if (iX == iMat[i][j]) {
				return true;
			}
		}
	}
	return false;
}

//cuenta cuantas veces se encuentra un numero dentro de la matriz 
int cuentaIguales(int iMat[7][7], int iRen, int iCol, int iX) {
	int iCont = 0;
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			if (iX == iMat[i][j]) {
				iCont++;
			}
		}
	}
	return iCont;
}

void copia(int iMat3x3[7][7], int iMatId[7][7], int iRen, int iCol) {
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			iMatId[i][j] = iMat3x3[i][j];
		}
	}
}
bool sonIguales(int iMat3x3[7][7], int iMatId[7][7], int iRen, int iCol) {
	for (int i = 0; i < iRen; i++) {
		for (int j = 0; j < iCol; j++) {
			if (iMat3x3[i][j] != iMatId[i][j])
				return false;
		}
	}
	return true;
}

int main() {

	cout << "Practica de MATRICES\n";
	int iMat[7][7] = { { 2, 1, 3 },{ 5, 6, 9 },{ 1, 8, 4 } };

	cout << "\nInicializa Matriz 1" << endl;
	inicializaMatriz1(iMat, 3, 3);
	despliega(iMat, 3, 3);

	cout << "\nInicializa Matriz 2" << endl;
	inicializaMatriz2(iMat, 3, 3);
	despliega(iMat, 3, 3);

	cout << "\nInicializa Matriz 3" << endl;
	inicializaMatriz3(iMat, 3, 3);
	despliega(iMat, 3, 3);

	cout << "\nInicializa Matriz 4" << endl;
	inicializaMatriz4(iMat, 3, 3);
	despliega(iMat, 3, 3);

	cout << "\nInicializa Matriz 5" << endl;
	inicializaMatriz5(iMat, 3, 3);
	despliega(iMat, 3, 3);

	int iMat3x3[7][7] = { { 2, 1, 3 },{ 5, 6, 9 },{ 1, 8, 4 } };
	int iMat3x4[7][7] = { { 2, 1, 3, 6 },{ 5, 6, 9, 8 },{ 1, 8, 4, 7 } };
	int iMatId[7][7] = { { 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 } };

	cout << "\nEl mayor de la matriz iMat3x3 es " << mayor(iMat3x3, 3, 3) << endl;

	posicionDelMayor(iMat3x3, 3, 3);
	cout << endl;

	cout << "\niMatId..." << endl;
	despliega(iMatId, 3, 3);
	if (matrizIdentidad(iMatId, 3, 3) == true)
		cout << "La matriz iMatId Si es identidad... yei !!";
	else
		cout << "La matriz iMatId NO es identidad... buu !!";

	cout << endl;

	cout << "\nMatriz 3 x 3" << endl;
	despliega(iMat3x3, 3, 3);

	cout << "\nMatriz 3 x 4" << endl;
	despliega(iMat3x4, 3, 4);

	cout << "\nSuma de matriz 3x4 = " << suma(iMat3x4, 3, 4) << endl;
	cout << "\nSuma de matriz 3x3 = " << suma(iMat3x3, 3, 3) << endl;

	cout << "\nPromedio de matriz 3x4 = " << promedio(iMat3x4, 3, 4) << endl;
	cout << "\nPromedio de matriz 3x3 = " << promedio(iMat3x3, 3, 3) << endl;

	cout << "\nSuma diagonal inversa de matriz 3x4 = " << sumaDiagonalInversa(iMat3x4, 3, 4) << endl;
	cout << "\nSuma diagonal inversa de matriz 3x3 = " << sumaDiagonalInversa(iMat3x3, 3, 3) << endl;

	cout << "\nSuma diagonal princ de matriz 3x4 = " << sumaDiagonalPrincipal(iMat3x4, 3, 4) << endl;
	cout << "\nSuma diagonal princ de matriz 3x3 = " << sumaDiagonalPrincipal(iMat3x3, 3, 3) << endl;

	if (busca(iMat3x3, 3, 3, 9))
		cout << "\nEl numero buscado Si se encuentra en la matriz iMat3x3";
	else
		cout << "\nEl numero buscado NO se encuentra en la matriz iMat3x3";

	cout << "\nCuenta cuantos 1 hay dentro de iMatId = " << cuentaIguales(iMatId, 3, 3, 1);

	copia(iMat3x3, iMatId, 3, 3);

	if (sonIguales(iMat3x3, iMatId, 3, 3))
		cout << "\nLas matrices iMat3x3 y iMatId, Si son iguales =)" << endl;
	else
	cout << "\nLas matrices iMat3x3 y iMatId, No son iguales =)" << endl;

	cout << "....... FIN......." << endl;
	system("pause");

	return 0;

}



