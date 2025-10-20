#ifndef USECASE_H
#define USECASE_H

#include "hash_table.h"
#include <string>

using namespace std;

/*
 * Creates a hash table from a CSV file containing username,password pairs
 * fname - name of the CSV file
 * m - intended size of the hash table
 * 
 * Precondition: existing CSV file with ("username, password" format each line) 
 * Postcondition: Returns the pointer to the created hash table
 */
HashTable<string>* create_table(string fname, int m);

/*
 * Attempts to login with given username and password
 * ht - hash table containing user credentials
 * username - username to check
 * password - password to verify
 * 
 * Precondition: existing HashTable of data from the CSV file, valid password of numbers within 10-digits
 * Postcondition: Returns true if username and hash of password match, false otherwise 
 */
bool login(HashTable<string>* ht, string username, string password);

#endif
