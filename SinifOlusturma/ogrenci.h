#ifndef OGRENCI_H
#define OGRENCI_H
#include "String.h"
#include "tarih.h"
#include "bilgisayar.h"

using namespace std;

class ogrenci
{
    friend ostream& operator<< (ostream&,const ogrenci & );

private:// ogrenci class inin private uyeleri tanimlaniyor...
   const int ogr_no;
    String ad;
    String soyad;
   tarih dogum_tarihi;
   tarih kayit_tarihi;
    bilgisayar  tasinabilir_bilgisayar;
    int sinifi;
    float not_ort;

public:
    ogrenci();
    ogrenci(int,  char [], char [],tarih,tarih,bilgisayar,int,float);
    char * GetAd();
    char * GetSoyad();
   tarih getTarih_dogum();
   tarih getTarih_kayit();
   bilgisayar get_tasinabilir_pc();
    int getOgrNo() const;
    int get_sinif();
    float get_not_ort();
    void setSinif();
    void SetNot();
    tarih  k_tarihi_oku();
    tarih d_tarihi_oku();

};

#endif // OGRENCI_H
