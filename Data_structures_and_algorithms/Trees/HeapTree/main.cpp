#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
#include "MaxHeap.h"

int main(){
    MaxHeap* PriorityQueue = new MaxHeap();
    cout <<endl;
    cout <<endl;
    if (PriorityQueue->empty()) {
        cout << "Inicializando PriorityQueue, esta vacia, tal como se esperaba..." << endl;
    } else {
        cout << "Tenemos un problema, la funcion empty() es incorrecta"  << endl;
    }
    cout <<endl;
    cout <<endl;
    cout << "Insertando numero 4" << endl;
    PriorityQueue->push(4);
    cout << "Insertando numero 10" << endl;
    PriorityQueue->push(10);
    cout << "Insertando numero 3" << endl;
    PriorityQueue->push(3);
    cout << "Insertando numero 5" << endl;
    PriorityQueue->push(5);
    cout << "Insertando numero 1" << endl;
    PriorityQueue->push(1);
    cout << "Insertando numero 8" << endl;
    PriorityQueue->push(8);
    cout << "Insertando numero 11" << endl;
    PriorityQueue->push(11);
    cout << "Insertando numero 6" << endl;
    PriorityQueue->push(6);
    cout << "Insertando numero 90" << endl;
    PriorityQueue->push(90);

    cout <<endl;
    cout <<endl;
    cout << "La representacion del arbol en forma de vector se ve de la siguiente manera:" << endl;
    PriorityQueue->printTree();
    cout <<endl;
    cout << "La representacion del arbol en 2D se ve de la siguiente manera:" << endl;
    cout << "            90          " << endl;
    cout << "      11          10    " << endl;
    cout << "   6      1    3      8 " << endl;
    cout << " 4   5                  " << endl;
    cout << "El maximo numero dentro de la priority queue es: " << PriorityQueue->top() <<endl;
    cout << "Borrando el elemento mas grande de la priority queue... "<<endl;
    PriorityQueue->pop();
    cout << "Se ha borrado el elemento mas grande de la priority queue"<<endl;
    cout << endl;
    cout << "La representacion del arbol en forma de vector se ve de la siguiente manera:" << endl;
    PriorityQueue->printTree();
    cout <<endl;
    cout << "La representacion del arbol en 2D se ve de la siguiente manera:" << endl;
    cout << "            11          " << endl;
    cout << "      6           10    " << endl;
    cout << "   5      1    3      8 " << endl;
    cout << " 4                      " << endl;
    cout << endl;
    cout << "El maximo numero dentro de la priority queue es: " << PriorityQueue->top() <<endl;
    cout << "Borrando el elemento mas grande de la priority queue... "<<endl;
    PriorityQueue->pop();
    cout << "Se ha borrado el elemento mas grande de la priority queue"<<endl;
    cout <<endl;
    cout << "La representacion del arbol en forma de vector se ve de la siguiente manera:" << endl;
    PriorityQueue->printTree();
    cout <<endl;
    cout << "La representacion del arbol en 2D se ve de la siguiente manera:" << endl;
    cout << "           10          " << endl;
    cout << "      6          8      " << endl;
    cout << "   5     1    3     4    " << endl;
    cout << endl;
    return 0; 
}