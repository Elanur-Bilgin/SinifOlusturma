#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>

using namespace std;
#include "bilgisayar.h"

bilgisayar::bilgisayar(const String a, const String b, const String c):seri_no(a),marka(b),model(c)//bilgisayar sinifinin yapicisi...
{

}
void bilgisayar::setSeri_no(char *metin)//girilen metin seri_no ya atanir...
{
    seri_no.Setstring(metin);
}
void bilgisayar::setMarka(char  *metin)//girilen metin markaya ya atanir...
{
   marka.Setstring(metin);
}
void bilgisayar::setModel(char  *metin)//girilen metin modele ya atanir...
{
    model.Setstring(metin);

}
char *bilgisayar:: marka_al()//ogrenci adi elde edilir...
{
    return marka.Getstring();
}

String bilgisayar::Getserino()//seri_no elde edilir...
{
    return seri_no;
}

String bilgisayar::Getmarka()//marka elde edilir...
{
    return marka;
}
String bilgisayar ::Getmodel()//model elde edilir...
{
    return model;
}


ostream& operator <<(ostream &output,const bilgisayar &pc)//cikti operatorü asiri yükleniyor...
{
    output<<pc.seri_no <<"          "<<pc.marka<<"          "<<pc.model<<" \n"<<endl;

    return output;
}
istream &operator>>(istream &girdi, bilgisayar &pc)//girdi operatoru asiri yükleniyor...
{
   String s1;
   char seri_no[12];
   char marka[10];
   char model[10];
    cout<<"seri no giriniz:";
    girdi>>seri_no;
    s1.Setstring(seri_no);
    pc.setSeri_no(seri_no);
  cout<<"marka giriniz:";
    girdi>>marka;
    s1.Setstring(marka);
    pc.setMarka(marka);
    cout<<"model  giriniz:";
    girdi>>model;
    s1.Setstring(model);
    pc.setModel(model);
    return girdi;
}

