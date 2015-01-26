#include "ogrenci.h"
#include <iostream>
using namespace std;
#include "tarih.h"




tarih :: tarih( const int a, const int b,const int c):gun(a),ay(b),yil(c)//tarih sinifinin yapici fonksiyonu...
{

}
void tarih::set(int a,int b,int c)//gun ay ve yil ayarlanir...
{
    gun=a;
    ay=b;
    yil=c;
}
tarih tarih::get()// geriye ayarlari yapilan tarih bilgileri dondürülür...
{
    return *this;
}
int tarih::gun_oku()//gun bilgisi elde edilir...
{
    return gun;
}
int tarih::ay_oku()//ay bilgileri elde edilir...
{
    return ay;
}
int tarih::yil_oku()//yil bilgileri elde edilir...
{
    return yil;
}



bool tarih::operator >(int y)// > operatoru asiri yükleniyor...
{
    if(y<yil)
        return true;
    else return false;
}
bool tarih::operator<(const  tarih &karsilastirilan)//< operatoru asiri yukleniyor...
{
    if((karsilastirilan.yil>yil)||((karsilastirilan.yil==yil) && (karsilastirilan.ay>ay))||((karsilastirilan.ay==ay)&&karsilastirilan.gun>gun))


        return true;
    else return false;
}
ostream& operator <<(ostream &output,tarih &bir_tarih)// cikti peratorü asiri yükleniyor...
{
    output<<bir_tarih.gun_oku()<<"/"<<bir_tarih.ay_oku()<<"/"<<bir_tarih.yil_oku();

    return output;
}
bool tarih::operator==(const tarih &karsilastirilan)// == operatorü asiri yükleniyor...
{
    if (gun==karsilastirilan.gun && ay==karsilastirilan.ay && yil==karsilastirilan.yil)
        return true;

    return false;
}
istream &operator>>(istream &girdi,tarih &trh)//girdi operatorü asiri yükleniyor...
{
    cout<<"gun giriniz:";
    girdi>>trh.gun;
    cout<<"ay giriniz:";
    girdi>>trh.ay;
    cout<<"yil giriniz:";
    girdi>>trh.yil;
    return girdi;
}
const tarih& tarih::operator=(tarih karsilastirilan )//= operatorü asiri yükleniyor...
{
    gun=karsilastirilan.gun;
    ay=karsilastirilan.ay;
    yil=karsilastirilan.yil;
    return *this;
}
