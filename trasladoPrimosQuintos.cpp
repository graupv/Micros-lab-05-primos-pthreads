#include <iostream>
#include <cstdlib>
#include <pthread.h>
//Librerias para sqrt
#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <cmath>
#include <fstream>
  

using namespace std;

//Struct que contiene el id de la thread y el valor primo que se calculó.
struct parameters {
	int id;
    int val1;

};



//Función isPrime que mira si es primo
void *isPrime (void *threadid)
{

    int posicion = 1;
    //ps que es el struct
    struct parameters *ps;
	ps=(struct parameters *)threadid;
    long tid = (long)ps -> id;
    //Divi es igual al id.
    int divi = (int)tid;
    //No se hace nada si es 0 o 1.
	if (tid == 0 || tid == 1)
	{
        ;
	}
	else{
	    //Saca el primo.
    	int divisor;
    	for (divisor = divi/2; divi%divisor != 0; --divisor)
    	{
    		;
    	}
    	if (divisor == 1)
    	{
        	if(posicion < 10)
        			{
						ofstream MiArchivo("primos.txt", ios::app);
						//	abrir en append para no borrar valores ya escritos

						if (!MiArchivo)
						{
							cerr<<"Error creando archivo\n\0";
							exit(EXIT_FAILURE);
						}
        			    //	imprimimos el primo
        			    // cout<<divi<<endl;
						MiArchivo<<divi<<"\n";
        				++posicion;
        				//	Guardamos el valor primo en una variable para 
						// que luego la podamos meter en el archivo txt

        				ps -> val1 = divi;

						MiArchivo.close();
						//	cerrar archivo
        			}
        			else
        			{
        			     //	reset
        				posicion=1;
        				

        				ps -> val1 = divi;
        			}
    	}else{
    	    //Se asigna 0 a la variable si no es primo.
    	    ps -> val1=0;
    	}
	}
	pthread_exit(NULL);
}


//	funcion que escribe cada 5to primo a nuevo archivo
void *cincoPrimos(void *threadid)
{
	int a;
	int b = 1;
	int c = 1;
	ifstream Primos("primos.txt", ios::in);
	//	abrir archivo que contiene primos
	if (!Primos)
	{
		cerr<<"Error encontrando primos.txt\n\0";
		exit(EXIT_FAILURE);
	}

	while(Primos>>a)
	{
		if (b == 5)
		//	cada 5ta linea de archivo primos.txt
		{
			ofstream cadaQuinto("quintosPrimos.txt", ios::app);
			//	abrir en append para no borrar valores ya escritos

			if (!cadaQuinto)
			{
				cerr<<"Error creando archivo\n\0";
				exit(EXIT_FAILURE);
			}
			//	imprimimos el 5to primo
			cout<<c<<". "<<a<<endl;
			cadaQuinto<<a<<"\n";
			cadaQuinto.close();
			b = 1;
			c++;
		}
		b++;
	}

	Primos.close();
	
	pthread_exit(NULL);
}
// Sequential test of primes


int main () {
    


	int rc;
   // Declaramos el struct
   struct parameters p;
   int exponente = 2;
	char expChar;
	cout<<"Ingrese el valor del exponente para base 10: ";
	cin>>expChar;
	
	// Numbers in ASCII begin at decimal 48
	exponente = int(expChar) - 48;

	// Asignamos 0 a val1 para inicializarlo.
	p.val1 = 0;
	long limit = pow(10,exponente);
	cout<<"Search for primes between 0 and "<<limit<<" ?";
	cout<<endl;
	// Todo lo de los pthreads

	pthread_t threads[limit];
	pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	//	

	for(int i = 0; i < limit; i++ ) {
	    //Creamos valores primos

	    p.id = i;
    	rc = pthread_create(&threads[i], &attr, isPrime, (void *)&p);
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
        rc = pthread_join(threads[i], NULL);
        if (rc) {
          printf("ERROR; return code from pthread_join() is %d\n", rc);
          exit(-1);
        }
        // En este espacio podemos meter el valor de val1 al archivo de txt.
		// rc = pthread_create(&threads[i], &attr, cincoPrimos, (void *)&p);
		

        if(p.val1 != 0){
            cout<<p.val1<<endl;
        }
	}
	// pthread_attr_destroy(&attr);
	// pthread_exit(NULL);
	cout << "ya fueron encontrados los primos"<<endl;

	for(int i = 0; i < limit; i++ ) {
	    //	ingresamos valores primos cada 5to

	    p.id = i;
    	rc = pthread_create(&threads[i], &attr, cincoPrimos, (void *)&p);
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
        rc = pthread_join(threads[i], NULL);
        if (rc) {
          printf("ERROR; return code from pthread_join() is %d\n", rc);
          exit(-1);
        }

        break;
	}
	pthread_attr_destroy(&attr);
	pthread_exit(NULL);
    return 0;
}