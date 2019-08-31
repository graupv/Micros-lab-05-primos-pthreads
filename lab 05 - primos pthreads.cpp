/*

Lab 05 - pthreads, primos y philes


Martin Ortega 18020
Gerardo Pineda 18848

*/

#include <pthread.h>
#include <stdio.h>
#include <cmath>
#include <iostream>	
#include <fstream>	//	directivo para archivos
#include <sys/types.h>
#include <stdlib.h>

#define NTHREADS 100

/*

	1. Calcule los números primos usando Pthreads
	2. Los escriba a un archivo. 
	3. Leer archivo creado
	4. Crear 2ndo archivo
	5. guardar cada 5 primo en 2ndo archivo
	6. fin.


*/

int main()
{
	if (!ifstream MiArchivo("primos"))
		//	verificar que existe archivo
	{
			cerr<<"No encontramos archivos\n\0";
			exit(EXIT_FAILURE);

	}
	
	//	crear
	ofstream MiArchivo("primos", ios::out);

	/*
	realmente podriamos meter cada 5to primo al archivo
	en lugar de crear dos archivos con joins

	calcular primo --> cast a string y agregar "\n\0"

	*/

	//	cerrar archivo
	outClientFile.close();
	//	leer primer archivo
	ifstream MiArchivo("primos", ios::in);

	
	//	crear 2ndo
	ofstream MiArchivo("cinco primos", ios::out);

	/*
	meter cada 5 "\n" o endl  de primer archivo un numero a
	cinco primos.txt hasta EOF
	*/

	//	leer segundo
	ifstream MiArchivo("cinco primos", ios::in);



	

	//	cerrar archivos
	outClientFile.close();
	cout<<"FIN."<<endl';
}