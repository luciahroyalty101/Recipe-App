
#include "QuadraticProbing.h"
#include "LinearProbing.h"
#include "DoubleHashing.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit(1) call
using namespace std;

// InsertWordsIntoHashTable() opens words_filename and inserts the words
// into a hash table. The type of hash table, specified by hash_table, could
// be linear, quadratic, or double probing. 

template <typename HashTableType>
void InsertWordsIntoHashTable( HashTableType &hash_table, const string &words_filename ) {
  string word_in_file;
  ifstream input_words_filename(words_filename);
  if (input_words_filename.fail()) {
    cerr << "Could not open <words_filename>\n";
    exit(1); // 1 indicates an error occurred
  }
  while ( input_words_filename >> word_in_file ) {
    hash_table.Insert(word_in_file);
  }
  input_words_filename.close();
}

// CheckWordInQueryFile() opens and parces query_filename. Prints the words
// that match the words in hash_table, counts and prints total number of
// collisions 
//

template <typename HashTableType>
void CheckWordInQueryFile( HashTableType &hash_table, const string &query_filename ) {
  string word_in_file;
  ifstream input_query_filename(query_filename);
  if (input_query_filename.fail()) {
    cerr << "Could not open <query_filename>\n";
    exit(1); // 1 indicates an error occurred
  }
  size_t total_number_of_collisions;
  while ( input_query_filename >> word_in_file ) {
    hash_table.resetCollisions();
    if ( hash_table.Contains(word_in_file) ) {
      hash_table.getTotalNumberOfCollisions( total_number_of_collisions );
      cout << word_in_file << " Found " << total_number_of_collisions+1 << endl;
    }
    else if ( !hash_table.Contains(word_in_file) ){
      hash_table.getTotalNumberOfCollisions( total_number_of_collisions );
      cout << word_in_file << " Not Found " << total_number_of_collisions+1 << endl;
    }
  }
  input_query_filename.close();
}

// TestFunctionForHashTable() inserts words from words_filename into hash_table
// outputs total number of collisions, total number of elements in the table
// size of table, load factor, average number of collisions, and calls 
// CheckWordInQueryFile()

template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;
  hash_table.MakeEmpty();  
  //..Insert your own code
 
}

