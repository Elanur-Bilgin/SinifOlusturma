#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;
using std::ostream;
class String
{
    friend ostream &operator << (ostream &,const String &);
    friend istream &operator >> (istream &, String &) ;
      friend bool operator==(char [],const String &);//== operatoru asiri yukleniyor...
public:
    String(int=10);
    void Setstring(const char *);
    char *Getstring();
    String &operator=(String &right);
   int boy_oku();

bool operator==(const String &karsilastirilan)const;

 const String& operator=(const String &);//atama
bool operator!=(const String &karsilastirilan) const//esitsizlik karsilastirma
        { return !(*this==karsilastirilan); }


private://String sinifinin private üyeleri tanimlaniyor...
   int boy;
   char *ptr;
};

#endif


