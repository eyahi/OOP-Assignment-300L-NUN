
#include <iostream>
#include <string>
using namespace std;

// patron.h
#ifndef PATRON_H 
#define PATRON_H
class Patron { 
 private:
  string name;
  int lbc;
 public:
  Patron(const string name, int lbc);
    void getp() const;
    int getn() const;
    void setname(const string newname );
    void setlbc(int newlbc );
};
#endif // PATRON_H