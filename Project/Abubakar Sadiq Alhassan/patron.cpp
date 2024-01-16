#include "patron.h"

Patron::Patron(const string name, int lbc)
    : name(name), lbc(lbc) {}

void Patron::getp() const {
    cout<<"\nlibrary card number: "<<lbc<<'\n';  
}
int Patron::getn() const{
    cout<<"\nName: " <<name<<'\n';
    return 0;
}
void Patron::setname(const string newname) {
    name = newname;
}

void Patron::setlbc(int newlbc) {
    lbc = newlbc;
}