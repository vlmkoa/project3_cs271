#include <iostream>
#include <string>
#include "hash_table.h"
#include "usecase.h"

using namespace std;

int main() {
    cout << "=== Hash Table Login System Demo ===" << endl;
    cout << endl;
    
    // create hash table from CSV file
    HashTable<string>* userTable = create_table("logins.csv", 101);
    
    if (userTable == nullptr) {
        cerr << "No credentials data" << endl;
        return 1;
    }
    
    
    // interactive login 
    string username, password;
    bool continueLogin = true;
    
    while (continueLogin) {
        cout << "Enter username: ";
        getline(cin, username);
        
        cout << "Enter password: ";
        getline(cin, password);
        
        // attempt login
        if (login(userTable, username, password)) {
            cout << "Access granted" << endl;
        } else {
            cout << "Access denied" << endl;
        }
        
        cout << endl;
        
        // Ask if user wants to try again
        cout << "Try another login? (y/n): ";
        string response;
        getline(cin, response);
        
        if (response != "y") {
            continueLogin = false;
        }
        
        cout << endl;
    }
    
    
    // Clean up
    delete userTable;
    
    return 0;
}
