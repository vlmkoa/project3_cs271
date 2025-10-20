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
            long password = stoull(passwordStr);
             
            // store username with the hash of password as the key (password is not stored, only used for hashing)
            //ht->securedInsert(username, password);
            //Element<T>* e = new Element<T>(d, -1);
            int hashk = ht->h(password);
            ht->insert(username, hashk);
            /*
            if (slots[hashk] == nullptr) {
                slots[hashk] = e;
            }
            else {
                slots[hashk]->prev = e;
                e->next = slots[hashk];
                slots[hashk] = e;
            }
            */

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
        long passwordInt = stoull(password);
        //return ht->isMemberInSlot(username, passwordInt);
        int hashk = h(passwordInt);
        /*Element<T>* curr = slots[hashk];
        while ((curr != nullptr) && (curr->get_data() != data)) {
            curr = curr->next;
        }

        if (curr != nullptr && curr->get_data() == data) {
            return true;
        }
        return false;
        */
        return ht->member(username, hashk);
    } catch (const invalid_argument& e) {
        // password is not a valid integer
        return false;
    }
}
