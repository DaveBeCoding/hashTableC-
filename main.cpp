#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
#include "tableHash.cpp"


int main(int argc, char* argv[]){
    hashTable hash_table;
    string name = "";
    hash_table.AddItem("John", "The Art of War");
    hash_table.AddItem("dan", "TWar");
    hash_table.AddItem("ron", "Art War");
    hash_table.AddItem("steve", "The War");
    hash_table.AddItem("Jane", "of War");
    hash_table.AddItem("Jack", "T War");
    hash_table.AddItem("Bill", "The A War");
    hash_table.AddItem("dustin", "The f War");
    hash_table.AddItem("rick", "The Aro War");
    // hash_table.PrintTable(); //prints out table on init level
    // hash_table.PrintItems(7); //prints item that have collisions

    while (name != "exit")
    {
        cout << " Search for ";
        cin >> name;
        if (name != "exit"){
            hash_table.FindBook(name);
        }
    }
    
    return 0;
}