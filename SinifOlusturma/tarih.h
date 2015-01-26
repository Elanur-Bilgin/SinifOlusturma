#ifndef TARIH_H_INCLUDED
#define TARIH_H_INCLUDED
#include "String.h"
#include <iostream>
using namespace std;
using std::ostream;

class tarih
{
    friend ostream& operator << (ostream &,tarih &);
    friend istream& operator >>(istream &,tarih &);
private://tarih sinifinin private uyeleri...
 int gun;
int ay;
 int yil;
public:
    tarih( const int=1, const int=1, const int=1900);

   void set(int,int,int);
    tarih get();
    int gun_oku();
    int ay_oku();
    int yil_oku();
    bool operator>(int yil);// > operatoru asiri yukleniyor..
    bool operator<(const  tarih &);//< operatoru asiri yukleniyor...
     bool operator==(const tarih &);//esitlik karsilastirma
      const tarih &operator=(tarih);
};


#endif

