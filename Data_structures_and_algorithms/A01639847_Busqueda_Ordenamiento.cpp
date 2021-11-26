/* 
* Autor: Carlo Angel Lujan Garcia A01639847
* 2/09/2021
* Actividad 1.2: Algoritmos de Búsqueda y Ordenamiento: en este programa se hace la implementacion de 3 
* metodos de ordenamiento (intercambio, burbuja y merge sort) y de 2 metodos de busqueda (secuencial y binaria) 
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <ctime>

using namespace std;


/*
* Esta funcion se encarga de imprimir una lista y darle formato
* Complejidad computacional O(n) debido a que se tiene un ciclo for que se irá recorriendo desde inicio de la lista
* hasta el final de la misma
* @param lista vector de tipo entero que queremos imprimir con formato
*/
void imprimeLista(vector<int> lista) {
    for (int i = 0; i < lista.size(); i++) {
        cout << lista[i] ;
        if (i != lista.size()-1) {
            cout << ",";
        }
    }
    cout << endl;
}

/*
Ejemplo de corrida de algoritmo de ordenacion por metodo intercambio
[3,4,2,1]
[2,4,3,1]
[1,4,3,2]
[1,4,3,2]
[1,3,4,2]
[1,2,4,3]
[1,2,3,4]
*/
/*
* Esta funcion se encarga de ordenar en forma ascendente los datos con el método de Intercambio
* Complejidad computacional O(n^2) debido a que se tiene un ciclo for que se irá recorriendo desde inicio de la lista
* hasta el final de la misma por cada uno de los elementos en la lista.
* @param lista vector de tipo entero desordenado que se busca ser ordenado
*/
vector<int> ordenaIntercambio(vector<int> lista){
    int temp;
    for (int i = 0; i < lista.size(); i++) {
        for (int j = i; j < lista.size(); j++) {
            if (lista[i] > lista[j]) {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
    return(lista);
}

/*
Ejemplo de corrida de algoritmo de ordenacion por metodo burbuja
[3,4,2,1]
[3,4,1,2]
[3,1,4,2]
[3,1,2,4]
[1,3,2,4]
[1,2,3,4]
*/
/*
* Esta funcion se encarga de ordenar en forma ascendente los datos con el método de Burbuja
* Complejidad computacional O(n^2) debido a que se tiene un ciclo for que se irá recorriendo desde inicio de la lista
* hasta el final de la misma por cada uno de los elementos en la lista.
* @param lista vector de tipo entero desordenado que se busca ser ordenado
*/
vector<int> ordenaBurbuja(vector<int> lista) {
	int temp;
	for (int i = 0; i < lista.size(); i++) {
		for (int j = 0; j< lista.size()-1; j++) {
			if (lista[j] > lista[j+1]) {
                temp = lista[j]; 
                lista[j] = lista[j+1]; 
                lista[j+1] = temp;
			}
		}
	}
    return(lista);
}

/*
* Esta funcion se encarga de mezclar dos sublistas (una izquierda y una derecha) ordenandolas
* de menor a mayor en una lista auxiliar que modificara valores de una lista pasada por referencia
* Complejidad computacional O(n) debido a que recorre cada uno de los valores de las sublistas una sola vez
* @param &lista vector de tipo entero pasado por referencia en el que se buscaran los valores a mezclar 
* @param ini entero que sera usado para saber el inicio de sublista izquierda
* @param med entero que sera usado para saber donde termina la sublista izquierda
* @param fin entero que sera usado para saber donde termina la sublista derecha
*/
void mezclarLista(vector<int> &lista, int ini, int med, int fin) {
    int izq = ini;
    int der = med+1;
    vector<int> listaAux;
    // Mientras el lado izquierdo y el lado derecho no lleguen a su 
    // tope se seguiran añadiendo elementos a la lista auxiliar de 
    // del valor menor de la comparacion del lado izquierdo con el 
    // el lado derecho.  
    while(izq <= med && der <= fin) {
        if (lista[izq] < lista[der]) {
            listaAux.push_back(lista[izq]);
            izq++;
        } else {
            listaAux.push_back(lista[der]);
            der++;
        }
    }
    // En caso de que uno de los lados haya terminado, pero el otro no
    // es necesario que copiemos todo lo que resta desde donde se quedo
    // hasta la parte final del lado correspondiente, en estos dos ciclos
    // for solo entrara a uno o al otro dependiendo si el lado izquierdo
    // o el lado derecho quedo desbalanceado, copiando los valores restantes.
    for (int k = der; k <= fin; k++) {
        listaAux.push_back(lista[k]);
    }
    for (int k = izq; k <= med; k++) {
        listaAux.push_back(lista[k]);
    }
    // Copiamos la lista auxiliar generada al mezclar
    // a la lista original
    for (int k = 0; k < listaAux.size(); k++) {
        lista[ini+k] = listaAux[k];
    }
}

/*
Ejemplo de corrida de algoritmo de ordenacion por merge sort
1,3,4,1,2,5,6,7
1,3,4,1 - 2,5,6,7
1,3 - 4,1 - 2,5 - 6,7
1 - 3 - 4 - 1 - 2 - 5 - 6 - 7
1,3 - 1,4 - 2,5 - 6,7
1,1,3,4 - 2,5,6,7
1,1,2,3,4 + 5,6,7
1,1,2,3,4,5,6,7
*/
/*
* Esta funcion se encarga de ordenar una lista de forma ascendente por el metodo de mergesort,
* usando recursividad
* Complejidad computacional O(nlog(n)) debido a que el metodo merge sort parte la lista original en dos partes
* por cada una de las iteraciones O(log(n)) y la funcion mezclarlista tiene complejidad o(n), el producto
* nos habla de que por cada iteracion log(n) tendra que hacerlo O(n) veces resultando asi la complejidad O(nlog(n))
* @param &lista vector de tipo entero pasado por referencia el cual se busca ordenar ascendentemente usando merge sort
* @param ini entero que sera usado para saber el inicio de la lista
* @param fin entero que sera usado para saber donde termina la lista
*/
void mergeSort(vector<int> &lista, int ini, int fin) {
    if (ini < fin) {
        int med = floor((ini+fin)/2);
        mergeSort(lista, ini, med);
        mergeSort(lista, med+1, fin);
        mezclarLista(lista, ini, med, fin);
    }
}

/*
Ejemplo de busqueda secuencial cuando buscado = 5
3,4,2,1,5,6,8,91,1002
i
lista[i] == buscado = false
3,4,2,1,5,6,8,91,1002
  i
lista[i] == buscado = false
3,4,2,1,5,6,8,91,1002
    i
lista[i] == buscado = false
3,4,2,1,5,6,8,91,1002
      i
lista[i] == buscado = false
3,4,2,1,5,6,8,91,1002
        i
lista[i] == buscado = true
return i
*/
/*
* Esta funcion se encarga de buscar un valor dentro de una lista de numeros enteros
* por medio de busqueda secuencial
* Complejidad computacional O(n) debido a que ira buscando coincidencias por cada uno de los valores dentro de 
* la lista
* @param lista vector de tipo entero en donde se busca encontrar un numero buscado
* @param buscado entero a buscar dentro de la lista
* return un indice dentro de la lista indicando la posicion del valor encontrado o un -1 en caso de no existir
*/
int busquedaSecuencial(vector<int> lista, int buscado) {
    for (int i = 0; i < lista.size(); i++) {
        if(lista[i] == buscado) {
            return i;
        }
    }
    return -1;
}

/*
1,2,3,4,5,6,8,91,1002
inf                  sup
 (9+0)/2 = 4.5 = 4
1,2,3,4,5,6,8,91,1002
inf     mid          sup
 lista[mid] == buscado = false
 mid = (9+4)/2 = 6.5 = 6
1,2,3,4,5,6,8,91,1002
        inf mid      sup
 lista[mid] == buscado = false
 (9+6)/2 = 7.5 = 7
1,2,3,4,5,6,8,91,1002
            inf mid  sup
 lista[mid] == buscado = false
 (9+7)/2 = 8
1,2,3,4,5,6,8,91,1002
              inf mid sup
 lista[mid] == buscado = true
 return mid
*/
/*
* Esta funcion se encarga de buscar un valor dentro de una lista de numeros enteros previamente ordenada
* ascendentemente, por medio de busqueda binaria
* Complejidad computacional O(log(n))‎ debido a que la lista se va partiendo en mitades por cada iteracion
* @param lista vector de tipo entero en donde se busca encontrar un numero buscado
* @param buscado entero a buscar dentro de la lista
* return un indice dentro de la lista indicando la posicion del valor encontrado o un -1 en caso de no existir
*/
int busquedaBinaria(vector<int> lista, int buscado) {
    int inf = 0;
    int sup = lista.size();
    while (inf <= sup) {
        int mid = (inf+sup)/2;
        if (lista[mid] == buscado) {
            return mid;
        }
        if (lista[mid] < buscado) {
            inf = mid+1;
        } else {
            sup = mid-1;
        }
    }
    return -1;
}

int main(){
    srand(unsigned(time(nullptr)));
    vector<int> v(15);
    generate(v.begin(), v.end(), rand);
    int option = 1;
    while (option != -1) {
        cout << endl;
        vector<int> v(15);
        generate(v.begin(), v.end(), rand);
        cout << "Se ha generado la siguiente lista" << endl;
        imprimeLista(v);
        cout << endl;
        cout << "Ordenando por metodo de insercion: " << endl;
        imprimeLista(ordenaIntercambio(v));
        cout << endl;
        cout << "Ordenando por metodo burbuja: " << endl;
        imprimeLista(ordenaBurbuja(v));
        cout << endl;
        cout << "Ordenando por metodo merge sort: " << endl;
        mergeSort(v, 0, v.size()-1);
        imprimeLista(v);
        cout << "La lista se ha modificado por referencia" << endl << endl;
        cout << "Cuantas busquedas quiere hacer? (Escriba -1 para salir)" << endl;
        cin >> option;
        int dato = 0;
        if (option != -1) {
            for (int i = 0; i < option ; i++) {
                imprimeLista(v);
                cout << "Que numero desea buscar dentro de la lista" << endl;
                cin >> dato;
                int posSec = busquedaSecuencial(v, dato);
                int posBin = busquedaBinaria(v, dato);
                if(posSec==-1 && posBin==-1) {
                    cout << "Valor no encontrado en el vector" << endl;
                } else {
                    cout << "El valor fue encontrado en la posicion [" << posSec+1 << "] de la lista por el metodo de busqueda secuencial" << endl;
                    cout << "El valor fue encontrado en la posicion [" << posBin+1 << "] de la lista por el metodo de busqueda binaria" << endl;
                }
                system("pause");
            }
        }
    }
    return 0;
}