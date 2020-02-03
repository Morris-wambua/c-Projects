#include <stdio.h>
#include <stdlib.h>

#include<iostream>
#include<fstream>
int main(int argc, char** argv) {
  using namespace std;
  ifstream ifs(argv[0]);
  char c;
  int characters = 0;
  int printables = 0;
  while(true) {
    ifs.get(c);
    if (ifs.eof()) {
      break;
    }
    characters++;
    if (isalnum(c) > 0 || ispunct(c) > 0 || isspace(c) > 0) {
      printables++;
    }
  }
  ifs.close();
  cout << "file size: bytes = " << characters << ", printable characters = "
       << printables << endl;
  return 0;
}

