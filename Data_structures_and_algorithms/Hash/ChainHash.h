template<class T> class ChainHash{
  private:  
    static const int hashGroup = 11; // Must be a prime number
    list<pair<int, LinkedList<T>>> tableHash[hashGroup];

  public:
    ChainHash() {}
    
    /**
      * @brief Funcion encargada de generar el valor de indice unico para la insercion por 
      * el metodo hash convencional
      * Complejidad O(1) ya que solo efectua una operacion.
    */
    int hashFunction(T value) {
        int modulo = value % hashGroup;
        return modulo;
    }
    
    /**
      * @brief Funcion encargada de insertar un nuevo valor a un indice dentro del mapa hash
      * Complejidad O(l) ya que el algoritmo de insercion por medio de la funcion hash calcula
      * un indice unico a partir del valor recibido lo cual se consideraria tiempo constante, sin embargo
      * para en caso de que un indice se repita es agregar el valor correspondiente insertandolo
      * dentro de la lista ligada, lo cual toma O(l) donde "l" es el tamaño de la lista ligada en el indice
      * especificado.
    */
    void insertItemChain(T value) {
      int hashValue = hashFunction(value);
      auto& cell = tableHash[hashValue];
      auto bItr = begin(cell);
      bool keyExist = false;
      for(; bItr != end(cell); bItr++) {
        if(bItr->first == hashValue) {
          keyExist = true;
          if(bItr->second.add_endNoRepeat(value)) {
            cout<<"Value " << value << " not inserted, already in linked list"<<endl;
          } else {
            cout<<"Value " << value << " inserted to linked list"<<endl;
          }
        } 
      }
      if (!keyExist) {
        LinkedList<int> newList;
        newList.add_end(value);
        cout<<"Value " << value << " inserted to linked list"<<endl;
        cell.emplace_back(hashValue,newList);
      }
    }

    /**
      * @brief Funcion encargada de imprimir el mapa hash completo.
      * Complejidad O(n + l) ya que recorre el mapa por cada uno de los valores de su tamaño,
      * se usa un iterador por cada uno de los valores para recuperar los datos de 
      * cada "par" al interior de la lista, sin embargo tambien se debe recorrer una lista ligada al
      * interior de cada uno de los indices del mapa, su tamaño estara definido por la variable por cada
      * uno de ellos "l". 
    */
    void imprimirChain() {
      for (int i{}; i < hashGroup; i++) {
        auto bItr = tableHash[i].begin();
        for (; bItr != tableHash[i].end(); bItr++) {
          cout<<"Key: "<<bItr->first << " Values: ";
          bItr->second.print_list();
        }
      }
    }
};