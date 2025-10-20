#include <iostream>
#include "hash_table.cpp"

using namespace std;


/*Original Test Cases*/

void test_get_key()
{
    try
    {
        Element<int> empty_elem;
        if (empty_elem.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << empty_elem.get_key() << endl;
        }
        Element<int> e(10, 6);
        if (e.get_key() != 6)
        {
            cout << "Incorrect result from get key. Expected 6 but got : " << e.get_key() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
}

void test_get_data()
{
    try
    {
        Element<int> empty_elem;
        if (empty_elem.get_data() != 0)
        {
            cout << "Incorrect result from get data. Expected 0 for an empty element but got : " << empty_elem.get_data() << endl;
        }
        Element<int> e(10, 6);
        if (e.get_data() != 10)
        {
            cout << "Incorrect result from get data. Expected 10 but got : " << e.get_data() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting data from element : " << e.what() << endl;
    }
}

void test_insert()
{
    try
    {
        HashTable<int> empty_ht(0);
        empty_ht.insert(10, 6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to insert into empty table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if (ht.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht.to_string() << endl;
        }
        ht.insert(1, 21);
        if (ht.to_string() != "0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht.insert(12, 16);
        ht.insert(17, 20);
        cout << ht.to_string();
    }
    catch (exception &e)
    {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }
}

void test_member()
{
    try
    {
        HashTable<int> empty_ht(0);
        if (empty_ht.member(10, 6))
        {
            cout << "Incorrect membership in empty table" << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to determine membership in empty table : " << e.what() << endl;
    }
    
    try
    {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if (ht.member(11, 6))
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (!ht.member(10, 6))
        {
            cout << "Incorrect non-membership in table" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error determining membership from table : " << e.what() << endl;
    }
    
}

void test_remove()
{
    try
    {
        HashTable<int> empty_ht(0);
        empty_ht.remove(6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to remove from empty table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        ht.remove(5);
        if (ht.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing non-member from table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht2(5);
        ht2.insert(10, 6);
        ht2.remove(6);
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht2.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing member from table : " << e.what() << endl;
    }
}

/*Extended Test Cases*/

void test_collision_handling()
{
    try
    {
        HashTable<int> ht(3);
        ht.insert(10, 3); // h(3)=0
        ht.insert(20, 6); // h(6)=0, collision
        ht.insert(30, 9); // h(9)=0, collision
        cout << "Collision handling test table:\n" << ht.to_string() << endl;

        if (!ht.member(10, 3) || !ht.member(20, 6) || !ht.member(30, 9))
            cout << "Collision test membership failed.\n";
    }
    catch (exception &e)
    {
        cerr << "Error testing collision: " << e.what() << endl;
    }
}

void test_clear()
{
    try
    {
        HashTable<int> ht(4);
        ht.insert(1, 1);
        ht.insert(2, 2);
        ht.insert(3, 3);
        cout << "Before clear:\n" << ht.to_string();
        ht.clear();
        cout << "After clear:\n" << ht.to_string();
    }
    catch (exception &e)
    {
        cerr << "Error testing clear: " << e.what() << endl;
    }
}

void test_string_type()
{
    try
    {
        HashTable<string> ht(3);
        ht.insert("apple", 1);
        ht.insert("banana", 4);
        ht.insert("pear", 7);
        cout << "String hash table:\n" << ht.to_string();
        if (!ht.member("banana", 4))
            cout << "String member test failed.\n";
    }
    catch (exception &e)
    {
        cerr << "Error testing string type: " << e.what() << endl;
    }
}

void test_chain_removal()
{
    try
    {
        HashTable<int> ht(3);
        ht.insert(1, 3);  // h(3)=0
        ht.insert(2, 6);  // h(6)=0
        ht.insert(3, 9);  // h(9)=0
        cout << "Before chain removals:\n" << ht.to_string();
        ht.remove(6); // remove middle element
        cout << "After removing (2,6):\n" << ht.to_string();
        ht.remove(3); // remove tail
        ht.remove(9); // remove head
        cout << "After removing all:\n" << ht.to_string();
    }
    catch (exception &e)
    {
        cerr << "Error in chain removal test: " << e.what() << endl;
    }
}

int main()
{
    // Original tests
    test_get_key();
    test_get_data();
    test_insert();
    test_member();
    test_remove();

    // Extended tests
    test_collision_handling();
    test_clear();
    test_string_type();
    test_chain_removal();

    cout << "Testing completed" << endl;
    return 0;
}
