#ifndef BILGISAYAR_H_INCLUDED
#define BILGISAYAR_H_INCLUDED

#include "String.h"

using namespace std;


class bilgisayar
{
    friend ostream& operator << (ostream &,const bilgisayar&);
    friend istream& operator >>(istream &,bilgisayar &);

private: //bilgisayar sinifinin private üyeleri tanimlaniyor...
   String seri_no;
    String marka;
  String model;
public:
    bilgisayar(String=NULL,String=NULL,String=NULL);

    void setSeri_no(char* ) ;
    void setMarka(char *) ;
    void setModel(char *)  ;
    char * get_seri_no();
     char * get_marka();
     char *get_model();
     String Getserino();
     String Getmodel();
     String Getmarka();
     char * marka_al();//ogrenci adi elde edilir...

};

#endif

