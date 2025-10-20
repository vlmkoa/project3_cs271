#include <iostream>
#include <string>
#include "hash_table.h"
#include "usecase.h"

using namespace std;

int main() {
    cout << "=== Testing Login System ===" << endl;
    
    // Test with a small hash table
    HashTable<string>* userTable = create_table("logins.csv", 11);
    cout << userTable->to_string();

    
    if (userTable == nullptr) {
        cerr << "Failed to create table!" << endl;
        return 1;
    }
    
    // Test some valid credentials from the CSV
    cout << "Testing valid login: C4ZE0r, 9778206113" << endl;
    if (login(userTable, "C4ZE0r", "9778206113")) {
        cout << "PASS: Valid login accepted" << endl;
    } else {
        cout << "FAIL: Valid login rejected" << endl;
    }
    
    // Test invalid credentials
    cout << "Testing invalid login: s1kfKvslx, 1234567890" << endl;
    if (!login(userTable, "s1kfKvslx", "1234567890")) {
        cout << "PASS: Invalid login rejected" << endl;
    } else {
        cout << "FAIL: Invalid login accepted" << endl;
    }
    
    // Test non-existent username
    cout << "Testing non-existent user: nonexistent, 1234567890" << endl;
    if (!login(userTable, "nonexistent", "1234567890")) {
        cout << "PASS: Non-existent user rejected" << endl;
    } else {
        cout << "FAIL: Non-existent user accepted" << endl;
    }
    
    // Test another valid credential
    cout << "Testing valid login: cJHFnXn36, 7478679467" << endl;
    if (login(userTable, "cJHFnXn36", "7478679467")) {
        cout << "PASS: Valid login accepted" << endl;
    } else {
        cout << "FAIL: Valid login rejected" << endl;
    }
    
    delete userTable;
    cout << "All tests completed!" << endl;
    
    return 0;
}
