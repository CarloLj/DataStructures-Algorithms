/*
  Act 5.1 - Implementación individual de operaciones sobre conjuntos
  implementacion de una tabla de dispersión que incluye la técnica de hashing 
  así como el manejo de colisiones a través de dirección abierta y sondeo cuadratico.
  Autor: Carlo Angel Lujan Garcia
  Matricula: A01639847
  Fecha: 21/11/21
*/

#include <iostream>
#include <list>
#include <utility>
#include <vector>

using namespace std;

#include "linkedlist.h"
#include "ChainHash.h"
#include "QuadraticHash.h"

//Programa principal encargado de correr los casos de prueba
int main() {
  ChainHash<int> chainHash;
  QuadraticHash<int> quadraticHash;
  cout << "Selecciona que tipo de hash quieres usar" << endl;
  cout << "[1] Hash por encadenamiento" << endl;
  cout << "[2] Hash cuadratico" << endl;
  cout << "[0] Salir" << endl;

  int caso;
  cin >> caso;
  switch (caso) {
    case 1:
      cout << "Selecciona el caso de prueba que deseas ejecutar" << endl;
      cout << "[1] Caso tipico" << endl;
      cout << "[2] Caso tipico 2" << endl;
      cout << "[3] Caso de full house" << endl;
      cout << "[4] Caso de desbordamiento" << endl;
      int caso1;
      cin >> caso1;
      switch (caso1) {
        case 1:
          chainHash.insertItemChain(5);
          chainHash.insertItemChain(6);
          chainHash.insertItemChain(521);
          chainHash.insertItemChain(84);
          chainHash.imprimirChain();
          break;
        case 2:
          chainHash.insertItemChain(213);
          chainHash.insertItemChain(21412);
          chainHash.insertItemChain(24214);
          chainHash.insertItemChain(123);
          chainHash.insertItemChain(495);
          chainHash.insertItemChain(2);
          chainHash.insertItemChain(5);
          chainHash.insertItemChain(55);
          chainHash.insertItemChain(1213);
          chainHash.imprimirChain();
          break;
        case 3:
          chainHash.insertItemChain(11);
          chainHash.insertItemChain(10);
          chainHash.insertItemChain(9);
          chainHash.insertItemChain(8);
          chainHash.insertItemChain(7);
          chainHash.insertItemChain(6);
          chainHash.insertItemChain(5);
          chainHash.insertItemChain(4);
          chainHash.insertItemChain(3);
          chainHash.insertItemChain(2);
          chainHash.insertItemChain(1);
          chainHash.imprimirChain();
          break;
        case 4:
          chainHash.insertItemChain(11000);
          chainHash.insertItemChain(10000);
          chainHash.insertItemChain(9000);
          chainHash.insertItemChain(8000);
          chainHash.insertItemChain(7000);
          chainHash.insertItemChain(6000);
          chainHash.insertItemChain(5000);
          chainHash.insertItemChain(4000);
          chainHash.insertItemChain(3000);
          chainHash.insertItemChain(2000);
          chainHash.insertItemChain(1000);
          chainHash.insertItemChain(12000);
          chainHash.insertItemChain(13000);
          chainHash.imprimirChain();
          break;
        default:
          break;
      }
      break;
    case 2:
      cout << "Selecciona el caso de prueba que deseas ejecutar" << endl;
      cout << "[1] Caso tipico" << endl;
      cout << "[2] Caso tipico 2" << endl;
      cout << "[3] Caso de full house" << endl;
      cout << "[4] Caso de desbordamiento" << endl;
      int caso2;
      cin >> caso2;
      switch (caso2) {
        case 1:
          quadraticHash.insertItem(5,0,0);
          quadraticHash.insertItem(6,0,0);
          quadraticHash.insertItem(521,0,0);
          quadraticHash.insertItem(84,0,0);
          quadraticHash.imprimirQuadratic();
          break;
        case 2:
          quadraticHash.insertItem(213,0,0);
          quadraticHash.insertItem(21412,0,0);
          quadraticHash.insertItem(24214,0,0);
          quadraticHash.insertItem(123,0,0);
          quadraticHash.insertItem(495,0,0);
          quadraticHash.insertItem(2,0,0);
          quadraticHash.insertItem(5,0,0);
          quadraticHash.insertItem(55,0,0);
          quadraticHash.insertItem(1213,0,0);
          quadraticHash.imprimirQuadratic();
          break;
        case 3:
          quadraticHash.insertItem(11,0,0);
          quadraticHash.insertItem(10,0,0);
          quadraticHash.insertItem(9,0,0);
          quadraticHash.insertItem(8,0,0);
          quadraticHash.insertItem(7,0,0);
          quadraticHash.insertItem(6,0,0);
          quadraticHash.insertItem(5,0,0);
          quadraticHash.insertItem(4,0,0);
          quadraticHash.insertItem(3,0,0);
          quadraticHash.insertItem(2,0,0);
          quadraticHash.insertItem(1,0,0);
          quadraticHash.imprimirQuadratic();
          break;
        case 4:
          quadraticHash.insertItem(11000,0,0);
          quadraticHash.insertItem(10000,0,0);
          quadraticHash.insertItem(9000,0,0);
          quadraticHash.insertItem(8000,0,0);
          quadraticHash.insertItem(7000,0,0);
          quadraticHash.insertItem(6000,0,0);
          quadraticHash.insertItem(5000,0,0);
          quadraticHash.insertItem(4000,0,0);
          quadraticHash.insertItem(3000,0,0);
          quadraticHash.insertItem(2000,0,0);
          quadraticHash.insertItem(1000,0,0);
          quadraticHash.insertItem(12000,0,0);
          quadraticHash.insertItem(13000,0,0);
          quadraticHash.imprimirQuadratic();
          break;
        default:
          break;
      }
      break;

      default:
        return 0;
        break;
    }
} 