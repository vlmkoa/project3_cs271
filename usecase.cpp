#include "hash_table.h"
#include "usecase.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;


HashTable<string>* create_table(string fname, int m) {
    HashTable<string>* ht = new HashTable<string>(m);
    ifstream file(fname);
    string line;
    while (getline(file, line)) {
        // parsing each csv line
        size_t comma_pos = line.find(',');
        if (comma_pos != string::npos) {
            
            string username = line.substr(0, comma_pos); //username before the comma
            string passwordStr = line.substr(comma_pos + 2); //password after the comma and a space as in the file
             
            // converting password to integer for hashing
            size_t password = stoull(passwordStr);
             
            // store username with the hash of password as the key (password is not stored, only used for hashing)
            ht->securedInsert(username, password);

        }
    }
    file.close();
    return ht;
}

bool login(HashTable<string>* ht, string username, string password) {
    if (ht == nullptr) {
        return false;
    }
    
    try {
        size_t passwordInt = stoull(password);
        return ht->isMemberInSlot(username, passwordInt);
    } catch (const invalid_argument& e) {
        // password is not a valid integer
        return false;
    }
}
