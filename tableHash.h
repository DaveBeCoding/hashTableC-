#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#ifndef HASH_H
#define HASH_H

class hashTable{
    private:
        static const int tableSize = 10; //(> 10) can change to have less collisions
        struct item{
            string name;
            string book;
            item* next;
        };
        item* h_table[tableSize]; //

    public:
        hashTable();
        int Hash(string key);
        void AddItem(string name, string book);
        int NumberOfItems(int index);
        void PrintTable();
        void PrintItems(int index);
        void FindBook(string name);
};
#endif
