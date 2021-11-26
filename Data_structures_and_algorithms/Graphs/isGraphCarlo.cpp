/*
Act 4.2 - Grafos: Algoritmos complementarios 
Esta es una aplicación en C++ que dado un grafo dirigido (DAG), con n vertices y a arcos, 
dirá si el grafo es un árbol y desplegará su orden topológico.
Autor: Carlo Angel Lujan Garcia
Matricula: A01639847
Fecha: 15/11/21
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class Grafo {
	public:
    //La lista de adyacencia será un mapa en donde cada key sera el identificador de cada uno de los nodos
	//Y cada una de las keys tendra un value que representara el set hacia los nodos a los que tiene contacto tal nodo key
    map<string, set<string>> listaAdyacencia;

    //Representa el numero de nodos en la lista de adyacencia.
    int n;
	//Representa el numero de arcos en la lista de adyacencia.
    int a;

    Grafo() {}
	
    /**
     * @brief Carga al grafo el numero especificado de nodos y arcos
     * @param n Numero de nodos
	 * @param a Numero de arcos
     */
    void loadGraph(int n, int a) {
        this->n = n;
        this->a = a;
    }

    /**
     * @brief Crea la conexion entre un nodo A hacia un nodo B (arco)
     * @param a Nodo a
	 * @param a Nodo b
     */
    void addEdge(string a, string b) {
        listaAdyacencia[a].insert(b);
    }

    /**
     * @brief Esta funcion despliega el orden topologico del grafo
	 * Complejidad O(N+A) debido a que recorre cada uno de los nodos y cada una de las respectivas
	 * conexiones que tiene dentro de su respectivo set de valores
     */
    void imprimir() {
        for (auto const& x : listaAdyacencia)
        {
            cout << x.first  // string (key)
                << ": ";
            for (auto y : x.second) {
                cout << y << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

	/**
     * @brief Esta funcion implementa el recorrido de grafo depth first search, cuando encuentra que uno de
	 * los valores leidos ya estaba dentro de nuestro stack significa que hay un ciclo dentro de nuestro grafo
	 * y por tanto tenemos un arbol.
	 * Complejidad O(N+A) debido a que recorre cada uno de los nodos y cada una de las respectivas
	 * conexiones que tiene dentro de su respectivo set de valores
	 * @param node string que representa la key del nodo actual a revisar si ya se encuentra en nuestro stack
	 * @param visited set de string pasado por referencia con los nodos visitados
	 * @param stack set de string pasado por referencia con los nodos que se encuentran actualmente en el stack
	 * @returns Retorna falso en caso de ser no ser un arbol y un true en caso de serlo
     */
    bool DFS(string node, set<string>& visited, set<string>& stack) {
        if (stack.find(node) != stack.end()) 
            return false;
        visited.insert(node);
        stack.insert(node);
        for (auto x : listaAdyacencia[node])
        {
            bool res = DFS(x, visited, stack);
            if (!res)
                return false;
        }
        return true;
    }

	/**
     * @brief Funcion encargada de retornar al programa principal si el grafo es un arbol o no
	 * Complejidad O(N(N+A)) debido a que recorre cada uno de los nodos y cada una de las respectivas
	 * conexiones que tiene dentro de su respectivo set de valores esto por cada uno de los nodos dentro 
	 * de la lista de adyacencia
	 * @returns Retorna falso en caso de ser no ser un arbol y un true en caso de serlo
     */
    bool isTree() {
        set<string> visited;
        //Se recorre cada uno de los nodos de la lista de adyacencia y se corre un DFS por cada uno de ellos
        for (auto const& node : listaAdyacencia) {
            set<string> stack;
            // Si encontramos que en los visitados está el nodo actual, el cuál es igual al último visitado..
            if (visited.find(node.first) == visited.end()) {
                bool found = DFS(node.first, visited, stack);
                if (!found)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    int caso = 0;
	Grafo grafo;
    cout << "Casos disponibles, selecciona uno:" << endl;
	cout << "1.- [A->B->C->D->E]" << endl;
	cout << "2.- [A->B->C->D->E->A]" << endl;
	cout << "3.- [A->B->C->D<->E]" << endl;
	cout << "4.- [(A:B C),(B:D E),(C:F)]" << endl;
    cin >> caso;
    switch (caso)
    {
    case 1:
		cout << "Caso 1:" << endl;
		cout << "Este caso deberia retornar que es un arbol" << endl;
		cout << "  A  " << endl;
		cout << "   B" << endl;
		cout << "    C  " << endl;
		cout << "     D" << endl;
		cout << "      E" << endl;
		cout << endl;
		grafo.addEdge("A", "B");
		grafo.addEdge("B", "C");
		grafo.addEdge("C", "D");
		grafo.addEdge("D", "E");
		grafo.loadGraph(5, 4);
		grafo.imprimir();
		cout << endl;
		if (grafo.isTree()) {
			cout << "Es un arbol" << endl;
		} else {
			cout << "No es un arbol" << endl;
		}
		break;
    case 2:
		cout << "Caso 2:" << endl;
		cout << "Este caso deberia retornar que no es un arbol" << endl;
		cout << "  A  " << endl;
		cout << "   B" << endl;
		cout << "    C  " << endl;
		cout << "     D" << endl;
		cout << "      E->A" << endl;
		cout << endl;
		grafo.addEdge("A", "B");
		grafo.addEdge("B", "C");
		grafo.addEdge("C", "D");
		grafo.addEdge("D", "E");
		grafo.addEdge("E", "A");
		grafo.loadGraph(5, 5);
		grafo.imprimir();
		cout << endl;
		if (grafo.isTree()) {
			cout << "Es un arbol" << endl;
		} else {
			cout << "No es un arbol" << endl;
		}
    	break;
    case 3:
        cout << "Caso 3:" << endl;
		cout << "Este caso deberia retornar que no es un arbol" << endl;
		cout << "  A  " << endl;
		cout << "   B" << endl;
		cout << "    C  " << endl;
		cout << "     D" << endl;
		cout << "      E->D" << endl;
		cout << endl;
		grafo.addEdge("A", "B");
		grafo.addEdge("B", "C");
		grafo.addEdge("D", "E");
		grafo.addEdge("E", "D");
		grafo.loadGraph(6, 5);
		grafo.imprimir();
		cout << endl;
		if (grafo.isTree()) {
			cout << "Es un arbol" << endl;
		} else {
			cout << "No es un arbol" << endl;
		}
        break;
    case 4:
        cout << "Caso 4:" << endl;
		cout << "Este caso deberia retornar que es es un arbol" << endl;
		cout << "      A  " << endl;
		cout << "   B     C" << endl;
		cout << "  D E      F" << endl;
		cout << endl;
		grafo.addEdge("A", "B");
		grafo.addEdge("A", "C");
		grafo.addEdge("B", "D");
		grafo.addEdge("B", "E");
		grafo.addEdge("C", "F");
		grafo.loadGraph(6, 5);
		grafo.imprimir();
		cout << endl;
		if (grafo.isTree()) {
			cout << "Es un arbol" << endl;
		} else {
			cout << "No es un arbol" << endl;
		}
        break;
    default:
        break;
    }
}



