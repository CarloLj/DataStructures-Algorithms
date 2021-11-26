/*
    Este programa es la implementacion de una estructura de datos de arbol binario autobalanceable
    por el metodo de AVL 
    Autor:
    Carlo Angel Lujan Garcia
    20/10/2021
*/

#include <iostream>
#include <vector>

using namespace std;

/*
This class represents a Node object wich contains data, a key and a right and left children
*/
template <class T>
class Node
{
public:
    T data;         // The data inside the Node object (Wich can be from any class)
    int key;        // key of the value
    Node<T> *left;  // Pointer to the left node element
    Node<T> *right; // Pointer to the right node element

    Node(T new_data, int key)
    {
        this->data = new_data;
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }

    Node(T new_data, int key, Node<T> *left, Node<T> *right)
    {
        this->data = new_data;
        this->key = key;
        this->left = left;
        this->right = right;
    }
};

/*  
    self-balancing binary tree structure class 
*/
template <class T>
class BinarySearchTree
{
public:
    Node<T> *root;
    int tree_size;

    BinarySearchTree()
    {
        this->root = NULL;
        this->tree_size = 0;
    }

    ~BinarySearchTree(){}

    /*
    Esta funcion inserta un nuevo nodo en el arbol y retorna un nodo que sera el padre
    @param current_node nodo actual a evaluar en el arbol
    @param node_insert nodo que sera insertado en la estructura
    @returns Retorna el nodo hijo recursivamente
    Complejidad O(n) ya que en el peor de los casos recorre una rama completa del arbol O(logn), 
    pero las rotaciones tiene complejidad e O(n)
    */
    Node<T> *insert(Node<T> *current_node, Node<T> *node_insert)
    {
        if (current_node == NULL)
            return node_insert;

        if (node_insert->key < current_node->key)
            current_node->left = this->insert(current_node->left, node_insert);
        else
            current_node->right = this->insert(current_node->right, node_insert);

        Node<T> *aux = applyRotations(current_node);

        return (aux == NULL) ? current_node : aux;
    }

    /*
    Esta funcion aplica las rotaciones necesarias ara balancear el arbol en el caso de insercion
    @param node nodo que se le va a aplicar la rotacion
    @returns retorna el nuevo nodo raiz que sale de la rotacion
    Complejidad O(n) ya que las rataciones tienen complejidad O(1), sin embargo
    la funcion de balance en el peor de los casos recorre todo el arbol O(n)
    */
    Node<T> *applyRotations(Node<T> *node)
    {
        int balance = this->balance(node);
        int balanceLeft = this->balance(node->left);
        int balanceRight = this->balance(node->right);

        if (balance == 2 && balanceLeft == 1)
            return this->left_left(node);
        if (balance == -2 && balanceRight == -1)
            return this->right_right(node);
        if (balance == -2 && balanceRight == 1)
            return this->right_left(node);
        if (balance == 2 && balanceLeft == -1)
            return this->left_right(node);

        return NULL;
    }

    /*
    Esta funcion se encarga de insertar un nuevo nodo en el arbol
    @data nuevo valor a insertar en el arbol
    @key la qkey que contendra el nuevo nodo que sera insertado
    Complejidad O(n) debido a que la funcion insertar toma esa complejidad en el peor
    de los casos
    */
    void insert(T data, int key)
    {
        Node<T> *node_insert = new Node<T>(data, key);
        if (this->root)
            root = this->insert(this->root, node_insert);
        else
            this->root = node_insert;
        this->tree_size++;
    }

    /*
    Busca y retorna un nodo de manera recursiva
    @param current_node el nodo actual en la recursion hasta ser o no encontrado
    @param key_searched nodo que contiene la llave a buscar

    @returns Retorna el nodo buscado o en caso de no encontrarlo un NULL
    Complejidad O(logn) ya que en el peor de los casos se tendria que 
    recorrer una rama completa del arbol
    */
    Node<T> *find(Node<T> *current_node, int key_searched)
    {
        if (!current_node)
            return NULL;
        if (key_searched == current_node->key)
            return current_node;

        if (key_searched < current_node->key)
            return find(current_node->left, key_searched);
        return find(current_node->right, key_searched);
    }

    /*
    Busca y retorna un nodo en caso de haberlo encontrado:
    @param key_searched llave del nodo que se quiere buscar
    @returns Retorna el nodo buscado o en caso de no encontrarlo un NULL
    Complejidad O(logn)
    */
    Node<T> *find(int key_searched)
    {
        return this->find(this->root, key_searched);
    }

    /*
    Esta funcion se encarga de retornar el nodo mas pequeño de nuestro arbol
    
    @param current_node nodo actual del arbol
    @return el menor nodo en todo el arbol
    Complejidad O(logn), debido a que lo hara n veces de acuerdo del height del arbol, y el arbol
    ya esta balanceado
    */
    Node<T> *minimum_element(Node<T> *current_node)
    {
        if (!current_node->left)
            return current_node;
        return minimum_element(current_node->left);
    }

    /*
    Elimina un nodo del arbol de manera recursiva
    @param current_node nodo actual de la recursion
    @param key_delete llave del nodo a eliminar
    @returns el nodo hijo del nodo eliminado recursivamente
    Complejidad O(n) esto debido a las rotaciones y a la funcion balance()
    */
    Node<T> *del(Node<T> *current_node, int key_delete)
    {
        if (!current_node)
            return NULL;

        else if (key_delete < current_node->key)
            current_node->left = this->del(current_node->left, key_delete);
        else if (key_delete > current_node->key)
            current_node->right = this->del(current_node->right, key_delete);
        else
        {
            if (current_node->left == NULL || current_node->right == NULL)
            {
                Node<T> *aux = current_node->left ? current_node->left : current_node->right;
                delete current_node;
                if (aux == NULL)
                    current_node = NULL;
                else
                    current_node = aux;
            }
            else
            {
                Node<T> *successor = this->minimum_element(current_node->right);
                Node<T> *new_node_minimum = new Node<T>(
                    successor->data, successor->key,
                    current_node->left, current_node->right);

                current_node = new_node_minimum;
                current_node->right = this->del(current_node->right, successor->key);
            }
        }

        if (current_node == NULL)
            return current_node;

        Node<T> *aux = applyRotationsOnDelete(current_node);

        return (aux == NULL) ? current_node : aux;
    }

    /*
    Ejecuta las rotaciones con condiciones de eliminacion de un nodo
    @param node nodo al que se le va a aplicar la rotacion
    @returns el nuevo nodo raiz de la rotacion
    Complejidad O(n) las rotaciones tienen complejidad O(1), 
    pero calcular el balance es O(n)
    */
    Node<T> *applyRotationsOnDelete(Node<T> *node)
    {
        int balance = this->balance(node);
        int balanceLeft = this->balance(node->left);
        int balanceRight = this->balance(node->right);

        if (balance > 1 && balanceLeft >= 0)
            return this->left_left(node);

        if (balance < -1 && balanceRight <= 0)
            return this->right_right(node);

        if (balance < -1 && balanceRight > 0)
            return this->right_left(node);

        if (balance > 1 && balanceLeft < 0)
            return this->left_right(node);

        return NULL;
    }

    /*
    Esta funcion se encarga de borra el nodo especificado del arbol
    @param key_delete key del nodo que se quiere eliminar
    Complejidad O(n)
    */
    void del(int key_delete)
    {
        this->tree_size--;
        this->root = this->del(this->root, key_delete);
    }

    /*
    Esta funcion se encarga de calcular el balance de un nodo especifico del arbol
    @param current nodo al que se le va a calcular el balance
    @returns Retorna el balance del nodo restando alturas entre derecha e izquierda
    Complejidad O(n)
    */
    int balance(Node<T> *current)
    {
        if (current == NULL)
            return 0;
        return height(current->left, 0) - height(current->right, 0);
    }

    /*
    Esta funcion se encarga de calcular la altura de un nodo en el arbol 
    usando la recursividad

    @param current el nodo actual al cual se le quiere calcular la altura
    @param h la altura previa antes de contar

    @returns Retorna la altura del nodo
    Complejidad O(n) debido a que recorre todos los nodos en busqueda de cada una de las alturas
    */
    int height(Node<T> *current, int h)
    {
        if (current == NULL)
            return h;
        return max(height(current->left, h + 1),
                   height(current->right, h + 1));
    }

    /*
    Funcion que se encarga de realizar una rotacion left left
    @param node nodo al que se le va a aplicar la rotacion
    @returns Retorna el nuevo nodo raiz de la rotacion
    Complejidad O(1) ya que solo es mover elementos una sola vez
    */
    Node<T> *left_left(Node<T> *node)
    {
        Node<T> *n2 = node->left;
        node->left = n2->right;
        n2->right = node;
        return n2;
    }

    /*
    Funcion que se encarga de realizar una rotacion right right
    @param node nodo al que se le va a aplicar la rotacion
    @returns Retorna el nuevo nodo raiz de la rotacion
    Complejidad O(1) ya que solo es mover elementos una sola vez
    */
    Node<T> *right_right(Node<T> *node)
    {
        Node<T> *n2 = node->right;
        node->right = n2->left;
        n2->left = node;
        return n2;
    }

    /*
    Funcion que se encarga de realizar una rotacion right left
    @params n1 nodo al que se le va a aplicar la rotacion
    @returns Retorna el nuevo nodo raiz de la rotacion
    Complejidad O(1) ya que solo es mover elementos una sola vez
    */
    Node<T> *right_left(Node<T> *n1)
    {
        Node<T> *n2 = n1->right;
        Node<T> *n3 = n2->left;

        n2->left = n3->right;
        n3->right = n2;

        n1->right = n3->left;
        n3->left = n1;

        return n3;
    }

    /*
    Funcion que se encarga de realizar una rotacion left right
    @params n1 nodo al que se le va a aplicar la rotacion
    @returns Retorna el nuevo nodo raiz de la rotacion
    Complejidad O(1) ya que solo es mover elementos una sola vez
    */
    Node<T> *left_right(Node<T> *n1)
    {
        Node<T> *n2 = n1->left;
        Node<T> *n3 = n2->right;

        n2->right = n3->left;
        n3->left = n2;

        n1->left = n3->right;
        n3->right = n1;

        return n3;
    }

    /*
    Esta funcion se encarga de retornar el tamaño del arbol binario
    Complejidad O(1)
    */
    int size()
    {
        return this->tree_size;
    }

    /*
    Esta funcion se encarga de imprimir el arbol de una forma 2D volteada en 90 grados
    Complejidad O(N) ya que recorre cada uno de los nodos dentro del arbol
    */
    void printUtil(Node<T> *root, int space)
    {
        int COUNT = 2;
        // Base case
        if (root == NULL)
            return;

        // Increase distance between levels
        space += COUNT;

        // Process right child first
        printUtil(root->right, space);

        // Print current node after space
        // count
        cout << endl;
        for (int i = COUNT; i < space; i++)
            cout << " ";
        cout << root->key << "\n";

        // Process left child
        printUtil(root->left, space);
    }

    // Wrapper over printUtil()
    void print()
    {
        cout << "______________________________________" << endl;
        printUtil(root, 0);
        cout << "______________________________________" << endl;
    }
};

/*
Esta funcion se encarga de demostrar que nuestro arbol AVL funciona correctamente
*/
int main()
{
    BinarySearchTree<string> binarySearchTree;
    vector<int> numeros;
   // numeros.push_back(90);
   //numeros.push_back(80);
   // numeros.push_back(70);
   // numeros.push_back(60);
   // numeros.push_back(50);
   // numeros.push_back(40);
   // numeros.push_back(30);
   // numeros.push_back(20);
   // numeros.push_back(10);
   // numeros.push_back(0);

    numeros.push_back(15);
    numeros.push_back(6);
    numeros.push_back(23);
    numeros.push_back(4);
    numeros.push_back(7);
    numeros.push_back(71);
    numeros.push_back(5);
    numeros.push_back(50);


    for (int i = 0; i < numeros.size(); i++)
    {
        cout << "Agregando el numero " << numeros[i] << " al arbol" << endl;
        binarySearchTree.insert("no se ha buscado", numeros[i]);
        cout << "Tamanio del arbol: " << binarySearchTree.size() << endl;
        binarySearchTree.print();
    }

    //Todas por defecto sus datos empiezanc con un no se ha buscado
    //Deberiamos haberlos encontrado pero ahora sus datos seran se ha encontrado en vez de no se ha buscado
    //Al ejecutar la funcion find se busca por el dato y se cambia por un se ha encontrado
    //Cuando lo ejecutamos deberiamos esperar que sus datos cambien a se han encontrado
    cout << "Probando buscar tres numeros dentro del arbol usando find(key)" << endl;
    //Deberiamos haberlos encontrado pero ahora sus datos seran se ha encontrado en vez de no se ha buscado
    cout << binarySearchTree.find(15)->data <<endl;
    cout << binarySearchTree.find(6)->data <<endl;
    cout << binarySearchTree.find(23)->data << endl;

    cout << endl;
    cout << "Ejecutando busqueda y cambiando sus datos..." << endl;
    cout << endl;

    binarySearchTree.find(15)->data = "se ha encontrado el 15";
    binarySearchTree.find(6)->data = "se ha encontrado el 6";
    binarySearchTree.find(23)->data = "se ha encontrado el 23";

    cout << "Una vez encontrados sus datos deberian haber cambiado a -se ha encontrado el [key]-" << endl;
    //Deberiamos haberlos encontrado pero ahora sus datos seran se ha encontrado en vez de no se ha buscado
    cout << binarySearchTree.find(15)->data <<endl;
    cout << binarySearchTree.find(6)->data <<endl;
    cout << binarySearchTree.find(23)->data << endl;

    cout << "Ejemplos de algunos numeros extra que aun no se buscan por medio de find()" << endl;
    //Deberiamos haberlos encontrado pero ahora sus datos seran se ha encontrado en vez de no se ha buscado
    cout << binarySearchTree.find(4)->data <<endl;
    cout << binarySearchTree.find(7)->data <<endl;
    cout << binarySearchTree.find(71)->data << endl;

    cout << endl;
    cout << endl;
    cout << "Probando eliminacion de numeros" << endl;
    for (int i = 0; i < numeros.size(); i++)
    {
        cout << "Eliminando el numero: " << numeros[i] << " del arbol"<< endl;
        binarySearchTree.del(numeros[i]);
        cout << "Tamanio del arbol: " << binarySearchTree.size() << endl;
        binarySearchTree.print();
    }

    return 0;
}
