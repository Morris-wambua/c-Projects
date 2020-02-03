#include <iostream>

class A {
public:
  A() {
    std::cout << "constructing object of class A" << std::endl;
  }
  ~A() {
    std::cout << "destroying object of class A" << std::endl;
  }
  void setDatum(int i) {
    theDatum = i;
  }
  int getDatum(void) {
    return theDatum;
  }
private:
  int theDatum;
};

int main(int argc, char** argv) {
  A a;
  a.setDatum(5);
  std::cout << a.getDatum() << std::endl;
  return 0;
}

