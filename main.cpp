#include <iostream>
#include <fstream> // leer el archivo
#include <sstream>// tokenizar el string 
#include <vector>
#include <string>
#include <list>
#include <functional>
#include "hashTable.h"

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
  // for(int i = 0; i < genoma.size(); i++)
  //   cout << genoma[i] << endl;
  
  for(int i = 0; i < genoma.size(); i++){
    if(genoma[i] == "T") genoma[i] = "U";
    cout << genoma[i] << endl;
  }


  // vector dictionary of bases
  vector<vector<string>> bases_dictionary = {{"UUU", "Phe"}, {"UUC", "Phe"}, {"UUA", "Leu"}, {"UUG", "Leu"},
                                             {"CUU", "Leu"}, {"CUC", "Leu"}, {"CUA", "Leu"}, {"CUG", "Leu"},
                                             {"UCU", "Ser"}, {"UCC", "Ser"}, {"UCA", "Ser"}, {"UCG", "Ser"},
                                             {"CCU", "Pro"}, {"CCC", "Pro"}, {"CCA", "Pro"}, {"CCG", "Pro"},
                                             {"UAU", "Tyr"}, {"UAC", "Tyr"}, {"UAA", "sto"}, {"UAG", "sto"},
                                             {"CAU", "His"}, {"CAC", "His"}, {"CAA", "Gln"}, {"CAG", "Gln"},
                                             {"UGU", "Cys"}, {"UGC", "Cys"}, {"UGA", "sto"}, {"UGG", "Trp"},
                                             {"CGU", "Arg"}, {"CGC", "Arg"}, {"CGA", "Arg"}, {"CGG", "Arg"},
                                             {"AUU", "Ile"}, {"AUC", "Ila"}, {"AUA", "Ile"}, {"AUG", "Met"},
                                             {"ACU", "Thr"}, {"ACC", "Thr"}, {"ACA", "Thr"}, {"ACG", "Thr"},
                                             {"AAU", "Asn"}, {"AAC", "Asn"}, {"AAA", "Lys"}, {"AAG", "Lys"},
                                             {"AGU", "Ser"}, {"AGC", "Ser"}, {"AGA", "Arg"}, {"AGG", "Arg"},
                                             {"GUU", "Val"}, {"GUC", "Val"}, {"GUA", "Val"}, {"GUG", "Val"},
                                             {"GCU", "Ala"}, {"GCC", "Ala"}, {"GCA", "Ala"}, {"GCG", "Ala"},
                                             {"GAU", "Asp"}, {"GAC", "Asp"}, {"GAA", "Glu"}, {"GAG", "Glu"},
                                             {"GGU", "Gly"}, {"GGC", "Gly"}, {"GGA", "Gly"}, {"GGG", "Gly"}};
  
// count number of group bases for creating hashtable
// read 3 by 3 letters, translate and add to hashtable with base name
// key = "UUU" and value = "Phe"
// replace function
// for(int i = 0; i < genoma.size(); i += 3){

// }

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