#include <iostream>
#include "HTable.h"

int main(int argc, char *argv[]){

  HTable *l1 = new HTable();

  std::cout << "A new hash table of size 100 is created\n\n";

  //Insert function
  l1->insert("a");
  std::cout << "\"a\" is inserted into the hash table as follows:" << std::endl;
  std::cout << "\t" << l1->toStringSimplified("a") << std::endl;
  l1->insert("c");
  std::cout << "\"c\" is inserted into the hash table as followed:" << std::endl;
  std::cout << "\t" << l1->toStringSimplified("c") << std::endl;
  l1->insert("apple pie");
  std::cout << "\"apple pie\" is inserted into the hash table as followed:" << std::endl;
  std::cout << "\t" << l1->toStringSimplified("apple pie") << std::endl;
  l1->insert("~~");
  std::cout << "\"~\" is inserted into the hash table as followed:" << std::endl;
  std::cout << "\t" << l1->toStringSimplified("~~") << std::endl;

  //has_key function
  std::cout << "\nThis hash table:\n\t";
  std::cout << (l1->has_key("a") ? "does include \"a\"" : "doesn't include \"a\"") << std::endl;
  std::cout << (l1->has_key("d") ? "\tdoes include \"d\"" : "\tdoesn't include \"d\"") << std::endl;

  std::cout << "\nPrinting the hash table (only the list with value is shown)" << std::endl;
  std::cout << l1->toString() << "\n";

  return 0;

}
