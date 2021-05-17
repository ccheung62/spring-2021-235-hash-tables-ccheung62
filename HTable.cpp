#include "HTable.h"
#include <string>
#include <cmath>

HTable::HTable(){
    *hashTable = new List[100];
    hashTable[0] = nullptr;
    size = 100;
}

HTable::HTable(int s){
    *hashTable = new List [s];
    hashTable[0] = nullptr;
    size = s;
}

// taken from https://opendsa-server.cs.vt.edu/ODSA/Books/CS3/html/HashFuncExamp.html (10.3.2)
// sums the ASCII values of the letters in a string and module it by the size
int HTable::hash(std::string str){
    int sum = 0;
    for (int i=0; i < str.length(); i++){
        sum += str[i];
    }
    return sum % size;
}

void HTable::insert(std::string str){
    if (hashTable[hash(str)] == nullptr){
        hashTable[hash(str)] = new List();
    }
    hashTable[hash(str)]->insert(str);
}

bool HTable::has_key(std::string str){
    if (hashTable[hash(str)] == nullptr){
        return false;
    }
    else if (hashTable[hash(str)]->containData(str)){
        return true;
    }
    return false;
}

//this prints every list in the array that contains something
std::string HTable::toString(){
    std::string result;
    for(int i=0; i<size; i++){
        if(hashTable[i] != nullptr){
            result += std::to_string(i) + ":   " + hashTable[i]->toString() + "\n";
        }
    }
    return result;
}

//this prints the list in the array that contains the specified string
std::string HTable::toStringSimplified(std::string str){
    for(int i=0; i<size; i++){
        if (hashTable[i] != nullptr && hashTable[i]->containData(str)){
            return std::to_string(i) + ": " + hashTable[i]->toString();
        }
    }
    return "";
}
