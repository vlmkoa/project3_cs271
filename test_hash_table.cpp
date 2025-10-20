#include <iostream>
#include "hash_table.cpp"

using namespace std;

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

        //different data type
        Element<string> str_elem("apple", 5);
        if (str_elem.get_key() != 5)
        {
            cout << "Incorrect string element key. Expected 5 but got : " << str_elem.get_key() << endl;
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

        //test with string type
        Element<string> str_elem("apple", 7);
        if (str_elem.get_data() != "apple")
        {
            cout << "Incorrect string element data. Expected 'apple' but got : " << str_elem.get_data() << endl;
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
            cout << "Incorrect result of inserting into table. Expected an empty string but got\n\n"
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
        ht.insert(1, 22);
        ht.insert(12, 18);
        ht.insert(17, 20);
        ht.insert(8, 24);
        if (ht.to_string() != "0: (17,20) \n1: (10,6) \n2: (1,22) \n3: (12,18) \n4: (8,24) \n")
        {
            cout << "Incorrect result of inserting into table. Expected \n0: (17,20) \n1: (10,6) \n2: (1,22) \n3: (12,18) \n4: (8,24) \n but got\n\n"
                 << ht.to_string() << endl;
        }

        //Collision handling check
        HashTable<int> coll_ht(3);
        coll_ht.insert(10, 3);
        coll_ht.insert(20, 6);
        coll_ht.insert(30, 9);
        if (coll_ht.to_string() != "0: (30,9) (20,6) (10,3) \n1: \n2: \n")
        {
            cout << "Incorrect result of collision handling. Expected \n0: (30,9) (20,6) (10,3) \n1: \n2: \nbut got\n\n"
                 << coll_ht.to_string() << endl;
        }

        //Insert with string type
        HashTable<string> str_ht(4);
        str_ht.insert("apple", 1);
        str_ht.insert("banana", 4);
        str_ht.insert("pear", 7);
        str_ht.insert("orange", 5);
        if (str_ht.to_string() != "0: (banana,4) \n1: (orange,5) (apple,1) \n2: \n3: (pear,7) \n")
        {
            cout << "Incorrect result of collision handling. Expected \n0: (banana,4) \n1: (orange,5) (apple,1) \n2: \n3: (pear,7) \n but got\n\n"
                 << str_ht.to_string() << endl;
        }

    }
    catch (exception &e)
    {
        cerr << "Error inserting into table : " << e.what() << endl;
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
            cout << "Incorrect membership in table " << ht.to_string() << endl;
        }
        if (!ht.member(10, 6))
        {
            cout << "Incorrect non-membership in table " << ht.to_string() << endl;
        }

        //Check multiple members
        ht.insert(20, 11);
        ht.insert(30, 16);
        ht.insert(40, 18);
        if (!ht.member(30, 16)) //first member in linked list
            cout << "Failed to find inserted element (30,16) in " << ht.to_string() << endl;
        if (!ht.member(10, 6)) //last member in linked list
            cout << "Failed to find inserted element (40,18) in " << ht.to_string() << endl;
        if (!ht.member(20, 11)) //middle member in linked list
            cout << "Failed to find inserted element (30,16) in " << ht.to_string() << endl;

        //Check string type membership
        HashTable<string> str_ht(3);
        str_ht.insert("apple", 1);
        str_ht.insert("banana", 2);
        if (!str_ht.member("banana", 2))
            cout << "Failed to find string element (banana,2) in " << ht.to_string() << endl;
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
            cout << "Incorrect result removing from empty table. Expected empty string but got\n\n"
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
        ht.remove(6);
        if (ht.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect removal result. Expected empty table but got\n\n" << ht.to_string() << endl;
        }

        //Chain removal test
        HashTable<int> chain_ht(3);
        chain_ht.insert(1, 3);
        chain_ht.insert(2, 6);
        chain_ht.insert(3, 9);
        string before = chain_ht.to_string();
        //cout << "Before chained removal:\n" << chain_ht.to_string();

        chain_ht.remove(6);
        if (chain_ht.to_string() != "0: (3,9) (1,3) \n1: \n2: \n") {
            cout << "Incorrect removal result. Expected to remove (2,6) from " << before << " but got " << chain_ht.to_string() << endl;
        }
        //cout << "After removing (2,6):\n" << chain_ht.to_string();

        chain_ht.remove(3);
        chain_ht.remove(9);
        if (chain_ht.to_string() != "0: \n1: \n2: \n")
        {
            cout << "Incorrect removal result. Expected empty table but got\n\n" << chain_ht.to_string() << endl;
        }

        //Clear function test
        HashTable<int> ht2(4);
        ht2.insert(1, 1);
        ht2.insert(2, 2);
        ht2.insert(3, 3);
        ht2.clear();
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n")
        {
            cout << "Incorrect removal result. Expected empty table but got\n\n" << ht2.to_string() << endl;
        }

    }
    catch (exception &e)
    {
        cerr << "Error removing member from table : " << e.what() << endl;
    }
}

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
