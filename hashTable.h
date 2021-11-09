
/*
Class that creates the rows of the hashtable, with the capability
of inputing key on the left and value on the right.
*/
template<typename K, typename T> /* K key, T value*/
class HashPair{
  public:
    K key;
    T value;
    HashPair(K key, T value ){
      this->key = key;
      this->value  = value;
    }
     HashPair(){}

};
/*
Class for creating a hashtable.
*/
template<typename K, typename T> /* K key, T value*/
class Hashtable{
    private:
        int size;
        HashPair<K, T> * tabla;
        HashPair<K, T> null_hash;
        bool empty = true;

        int fh(K key){
            hash<K> khash;
            return khash(key) % size;
        }

    public:
    /*
    Builder
    */
      Hashtable(int size = 20){
        this->size = size;
        tabla = new HashPair<K,T>[size];  // hashpair array creation
        for(int i = 0; i < size; i++) tabla[i] = HashPair<K,T>();
        null_hash = tabla[0];
      }
      /*
      Destructor
      */
      ~Hashtable(){
        delete tabla;
        size = 0;
        empty = true;
      }
      /*
      Method for inputting rows to the hastable.
      */
      bool put(K key, T value){
         int posicion = fh(key);
         this ->empty = false; 
         tabla[posicion] = HashPair<K,T>(key, value);
         return 1;
      }
    /*
    Method for getting a value depending of some Key as parameter.
    */
      T get(K key){
        return tabla[fh(key)].value;
      }
    /*
    Method for printing the whole hashtable-
    */
      void print(){
        for(int i = 0; i < size; i++){
          cout <<"i: " << i << " k: " << tabla[i].key  << " v: " << tabla[i].value;
          cout << endl;
        }
      }
    /*
    Method for deleting all values from the hashtable.
    */
      void clear(){
        for(int i = 0; i < size; i++){
          tabla[i] = null_hash;
        }
      }
    /*
    Method for checking if there is some key.
    */
      bool contains_key(K k){
        if(tabla[fh(k)].key == k) return true;
        return false;
      }
      /*
      Method for getting the value depending of key, if it doestn exist
      on hastable, it will return a default value.
      */
      T get_or_default(K k, T def = 0){
        if(contains_key(k)) return tabla[fh(k)].value;
        return def;
      }
      /*
      Method for checking whether the hashtable is full or empty.
      */
      bool is_empty(){
        for(int i = 0; i < size; i++) if(tabla[i].value != null_hash.value) return false;
        return true; 
      }
      /*
      Method that takes another hastable of the same type and inputs all the value.
      */
      void put_all(const Hashtable<K,T>& other){
        for(int i = 0; i < size; i++){
          if(other.tabla[i].key != tabla[i].key) tabla[i].key = other.tabla[i].key;
          tabla[i].value = other.tabla[i].value;
        }
      }
      /*
      Method for removing some row  depending of its key 
      */
      bool remove(K key){
        if(contains_key(key))tabla[fh(key)] = null_hash;
        else return false;
        return true;
      }
      /*
      Method that return the number of not empty rows
      */
      int the_size(){
        int counter = 0;
        for(int i = 0; i < size; i++)if(tabla[i].value != null_hash.value) counter++;
        return counter;
      }
      /*
      operator overloading for checking whether two hastables are the same or not.
      */
      bool operator == (const Hashtable<K, T> & other) const{
        if(size != other.size) return false;
        for(int i = 0; i < size; i++) if(tabla[i].value != other.tabla[i].value && tabla[i].key != other.tabla[i].key) return false;
        return true;
      }


      // ================================
      // additional methods for 
      // ================================
      int no_elements_in(){
        int counter = 0;
        for(int i = 0; i < size; i++) if(tabla[i].value != null_hash.value) counter ++;
        return counter;
      }
      void counter_addition(K key, int to_add){
        tabla[fh(key)].value += to_add;
      }
      void print_filled(){
        for(int i = 0; i < size; i++) if(tabla[i].value != null_hash.value) cout <<"i: " << i << " k: " << tabla[i].key  << " v: " << tabla[i].value << endl;
      }
      void delete_values(int quantity){
        for(int i = 0; i < size; i++)if(tabla[i].value < quantity) tabla[i] = null_hash;
      }
      void print_starting_with(char letter){
        for(int i = 0; i < size; i++)if(tabla[i].key[0] == letter) cout <<"i: " << i << " k: " << tabla[i].key  << " v: " << tabla[i].value << endl;
      }

};