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
      Hashtable(int size = 20){
        this->size = size;
        tabla = new HashPair<K,T>[size];  // hashpair array creation
        for(int i = 0; i < size; i++) tabla[i] = HashPair<K,T>();
        null_hash = tabla[0];
      }
      ~Hashtable(){
        delete tabla;
        size = 0;
        empty = true;
      }

      bool put(K key, T value){
         int posicion = fh(key);
         this ->empty = false; 
         tabla[posicion] = HashPair<K,T>(key, value);
         return 1;
      }

      T get(K key){
        return tabla[fh(key)].value;
      }

      void print(){
        for(int i = 0; i < size; i++){
          cout <<"i: " << i << " k: " << tabla[i].key  << " v: " << tabla[i].value;
          cout << endl;
        }
      }
      void clear(){
        for(int i = 0; i < size; i++){
          tabla[i] = null_hash;
        }

      }
      bool contains_key(K k){
        if(tabla[fh(k)].key == k) return true;
        return false;
      }

      T get_or_default(K k, T def = 0){
        if(contains_key(k)) return tabla[fh(k)].value;
        return def;
      }


      bool is_empty(){
        for(int i = 0; i < size; i++) if(tabla[i].value != null_hash.value) return false;
        return true; 
      }

      void put_all(const Hashtable<K,T>& other){
        for(int i = 0; i < size; i++){
          if(other.tabla[i].key != tabla[i].key) tabla[i].key = other.tabla[i].key;
          tabla[i].value = other.tabla[i].value;
        }
      }

      bool remove(K key){
        if(contains_key(key))tabla[fh(key)] = null_hash;
        else return false;
        return true;
      }

      int the_size(){
        int counter = 0;
        for(int i = 0; i < size; i++)if(tabla[i].value != null_hash.value) counter++;
        return counter;
      }

      bool operator == (const Hashtable<K, T> & other) const{
        if(size != other.size) return false;
        for(int i = 0; i < size; i++) if(tabla[i].value != other.tabla[i].value && tabla[i].key != other.tabla[i].key) return false;
        return true;
      }

};