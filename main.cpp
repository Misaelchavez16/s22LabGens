#include <iostream>
#include <fstream> // leer el archivo
#include <sstream>// tokenizar el string 
#include <vector>
#include <string>

using namespace std;

void cargaWuhanFasta(vector<string> & datos){
  string archivo = "wuhan.fasta";
  ifstream lector(archivo);
  if(lector.fail()){
    cout << "error ";
    return;
  }

  string linea;
  getline(lector, linea); // salta el primer renglón.
  while( getline(lector, linea)){
      datos.push_back(linea);
  }
  lector.close();
}
int main() {
  cout << "Hello World!\n";
  vector<string> genoma;
  
  cargaWuhanFasta(genoma);
  for(int i = 0; i < genoma.size(); i++)
    cout << genoma[i] << endl;
/*
Laboratorio del Genoma del SARS-COV2 & HashTable
Ejercicio 1:
Usando una tabla hash crea un contador del total de número de bases de toda la secuencia. ¿Recuerdas cuáles son los nucleótidos en un genoma?

Ejercicio 2:

¿Recuerdas el dogma central de la biología molecular?
Revisa los conceptos:
https://www.nature.com/scitable/topicpage/translation-dna-to-mrna-to-protein-393/#:~:text=During%20transcription%2C%20the%20enzyme%20RNA,encoded%20by%20the%20original%20gene.

Revisa una transcripción -> traducción:
http://biomodel.uah.es/en/lab/cybertory/analysis/trans.htm

Utilizando una tabla hash:
  1. Llena la tabla con los codones (o tripletes permitidos SIN repetidos). Cada codón es una llave en una tabla hash. Imprime todas las llaves de la tabla.
  2. Encuentra todas las repeticiones de cada codón utilizando la tabla hash.
  3. Imprime el contenido de toda la tabla.
  4. Borra los codones que no tengan más de 100 repeticiones.
  5. Imprime la tabla.
  6. Imprime las repeticiones de todos los codones que inicien con A.
*/

} 