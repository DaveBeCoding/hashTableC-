#include <cstdlib>
#include <iostream>
#include <string>
#include "tableHash.h"
using namespace std;

hashTable::hashTable(){
    for(int i = 0; i < tableSize; i++){
        h_table[i] = new item;
        h_table[i]->name = "empty";
        h_table[i]->book = "empty";
        h_table[i]->next = nullptr;
    }
}//end of constructor

int hashTable::Hash(string key){
    int hash = 0;   
    int index;
    for (int i = 0; i < key.length(); i++){
        hash = (hash + (int)key[i]); //* 32; // orig hash + (int)key[i]
    }
    index = hash % tableSize;
    return index;
}//end hashtable

void hashTable::AddItem(string name, string book){
    int index = Hash(name);
    if (h_table[index]->name == "empty"){
        h_table[index]->name = name;
        h_table[index]->book = book;   
    }else{
        item* Ptr = h_table[index];
        item* n = new item;
        n->name = name;
        n->book = book;
        n->next = nullptr;
        while (Ptr->next != nullptr)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}//end AddItem


int hashTable::NumberOfItems(int index){
    int count = 0;
    if(h_table[index]->name == "empty"){
        return count;
    }else{
        count++;
        item* Ptr = h_table[index];
        while (Ptr->next != nullptr){
            count++;
            Ptr = Ptr->next;
        }
    }
    return count;
}//end NumberOfItems


void hashTable::PrintTable(){
    int number;
    for (int i = 0; i < tableSize; i++){
        number = NumberOfItems(i);
        cout << "-----------------------\n";
        cout << "index = " << i << endl;
        cout << h_table[i]->name << endl;
        cout << h_table[i]->book << endl;
        cout << " # of items = " << number << endl;
        cout << "-----------------------\n";
    }
}//end PrintTable

void hashTable::PrintItems(int index){
    item* Ptr = h_table[index];
    if(Ptr->name == "empty"){
        cout << "index = " << index << " is empty\n";
    }else{
        cout << "index = " << index << "contains \n"; 
        while (Ptr->next != nullptr){
            cout << "-----------------------\n";
            cout << Ptr->name << endl;
            cout << Ptr->book << endl;
            cout << "-----------------------\n";
            Ptr = Ptr->next;
        }
    }
}//end PrintItems

void hashTable::FindBook(string name){
    int index = Hash(name);
    bool foundName = false;
    string book;
    item* Ptr = h_table[index];
    while (Ptr != nullptr){
        if (Ptr->name == name){
            foundName = true;
            book = Ptr->book;
        }
        Ptr = Ptr->next;
    }
    if (foundName == true){
        cout << "Found Book = " << book << endl;
    }else{
        cout << name << "'s info not found in table\n";
    }
}