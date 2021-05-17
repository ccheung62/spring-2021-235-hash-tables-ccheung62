#pragma once
#include "List.h"

class HTable {
    private:
        int size;
        List *hashTable[];
    public:
        HTable();
        HTable(int s);
        int hash(std::string str);
        void insert(std::string str);
        bool has_key(std::string str);
        std::string toString();
        std::string toStringSimplified(std::string str);
};