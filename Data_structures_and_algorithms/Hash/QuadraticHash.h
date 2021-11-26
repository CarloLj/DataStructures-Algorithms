/**
 * @brief Esta clase es la encargada de funcionar como un hash con algoritmo cuadratico 
 * para el almacenamiento de valores con keys unicas para cada valor
*/
template<class T> class QuadraticHash {
    public:
        static const int hashGroup = 11; // Must be a prime number
        int usedSpaces{};
        list<pair<int, int>> tableHashQuadratic[hashGroup];

        /**
         * @brief Constructor de la clase
        */
        QuadraticHash() {}
        
        /**
         * @brief Funcion encargada de generar el valor de indice unico para la insercion por 
         * el metodo hash cuadratico 
         * Complejidad O(1) ya que solo efectua una operacion.
        */
        int quadraticHashFunction(T value, int count) {
            int modulo = (value + count * count) % hashGroup;
            return modulo;
        }

        /**
         * @brief Funcion encargada de insertar un nuevo valor a un indice vacio, o hasta
         * encontrarlo... por medio del metodo hash cuadratico.
         * En el peor de los casos la complejidad sera O(n^2) ya que debera intentar insertar un elemento 
         * hasta encontrar el ultimo indice vacio dentro del tamaño completo del hash, sin embargo comunmente 
         * y entre mas espacios vacios hayan en el mapa la insercion tendera a complejidad O(1). 
        */
        void insertItem(T value, int hashValue, int count) {
            hashValue = quadraticHashFunction(value, count);
            count++;
            if (usedSpaces == hashGroup) {
                cout << "Sorry there's no space left" << endl;
                return;
            }
            auto& cell = tableHashQuadratic[hashValue];
            auto bItr = begin(cell);
            bool keyExist = false;
            for (; bItr != end(cell); bItr++) {
                if (bItr->first == hashValue) {
                    if (bItr->second == value) {
                        cout << "El valor ya existia en ese indice. Regresando..." << endl;
                        return;
                    }
                    keyExist = true;
                    break;
                }
            }
            if (keyExist) {
                insertItem(value, hashValue, count);
            }
            else {
                cell.emplace_back(hashValue, value);
                usedSpaces++;
                cout << value << " fue insertado en el index " << hashValue << endl;
            }
            //If the slot hash(x) % S is full, then we try (hash(x) + 1*1) % S.
            //If (hash(x) + 1*1) % S is also full, then we try (hash(x) + 2*2) % S.
            //If (hash(x) + 2*2) % S is also full, then we try (hash(x) + 3*3) % S.
            //This process is repeated for all the values of i until an empty slot is found.
        }

        /**
         * @brief Funcion encargada de imprimir el mapa hash completo.
         * Complejidad O(n) ya que recorre el mapa por cada uno de los valores de su tamaño,
         * se usa un iterador por cada uno de los valores para recuperar los datos de 
         * cada "par" al interior de la lista, sin embargo al ser de forma constante dos operaciones 
         * la complejidad se mantiene en O(n) 
        */
        void imprimirQuadratic() {
            for (int i{}; i < hashGroup; i++) {
                auto bItr = tableHashQuadratic[i].begin();
                for (; bItr != tableHashQuadratic[i].end(); bItr++) {
                    cout << "Key: " << bItr->first << " Values: " << bItr->second;
                }
                cout << endl;
            }
        }
};
