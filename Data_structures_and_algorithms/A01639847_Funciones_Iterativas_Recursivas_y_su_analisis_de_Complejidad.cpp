/* 
* Autor: Carlo Angel Lujan Garcia A01639847
* 17/08/2021
* Actividad 1: Contiene 3 distintos tipos de funciones (Iterativa, recursiva, metodo matematico directo) 
* para calcular la sumatoria hasta un numero n. 
*/
#include <iostream>

using namespace std;

int auxCount = 0;

int sumaIterativa(int);
int sumaRecursiva(int);
int sumaDirecta(int);

int main()
{
    for (int i = 0; i < 4 ; i++) {
        int n =  rand()%(100)+1;
        cout << "Caso prueba " << i+1 <<"\n" << "Probando con el numero: [" << n << "]" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Suma iterativa = " << sumaIterativa(n) << endl;
        cout << "Numero de iteraciones: " << auxCount <<endl<<endl;
        auxCount = 0;      
	    cout << "Suma recursiva = " << sumaRecursiva(n) << endl;
        cout << "Numero de llamadas recursivas: " << auxCount <<endl<<endl;
        auxCount = 0; 
	    cout << "Suma directa = " << sumaDirecta(n) << endl;
        cout << "Numero de iteraciones: " << auxCount <<endl;
        cout << "-------------------------------------------------" << endl;
        auxCount = 0; 
        cout << endl;
    }
}

/*
* Esta funcion se encarga de calcular la suma desde el numero 1 hasta un n maximo
* de forma iterativa
* Complejidad computacional O(n) debido a que se tiene un ciclo for que se irá recorriendo desde el numero 1
* hasta el numero de entrada otorgado al llamar a la funcion n.
* @param n numero hasta donde se calculara la suma
* @return retorna el resultado de la suma de numeros desde el numero 1 hasta el numero n especificado
*/
int sumaIterativa(int n) {
    //Verificamos si el numero no es negativo para efectuar la suma
    if (n >= 0) {
        int sum = 0;
	    for (int i = 1; i < n+1; i++) {
		    sum += i;
            auxCount++;
	    }
	    return sum;
    }
    return -1;
}

/*
* Calcula la suma desde el numero n hasta el numero 0 haciendo uso de recursividad
* Complejidad computacional O(n) debido a que la funcion vuelve a ejecutarse la misma cantidad de 
* veces que la entrada n recibida.La funcion se seguira llamando recursivamente restando uno al 
* valor recibido en la funcion original, hasta que el numero recibido en la nueva funcion llamada sea 0, 
* es decir no quede nada mas que sumar.
* @param n numero hasta donde se calculara la suma
* @return retorna el resultado de la suma de numeros desde el numero 1 hasta el numero n especificado
*/
int sumaRecursiva(int n) {
    if (n >= 0) {
        if (n == 0) {    
            return 0;
        }
        auxCount++;
        return n + sumaRecursiva(n - 1);
    }
    return -1;
}

/*
* Esta funcion calcula una sumatoria de numeros de un numero otorgado n, usando la suma de gauss 
* Complejidad computacional O(1) debido a que solo hay una operacion computacional de forma constante,
* es decir, todo el tiempo. Ya que es una ecuacion previamente probada y abstraida, llamada suma de gauss.
* @param n numero hasta donde se calculara la suma
* @return retorna el resultado de la suma de numeros desde el numero 1 hasta el numero especificado
*/
int sumaDirecta(int n) {
    if (n >= 0) {
        auxCount++;
        return n * (n + 1) / 2;
    }
    return -1;
}