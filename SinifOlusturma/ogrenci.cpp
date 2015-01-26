#include "ogrenci.h"
#include <iostream>
#include "tarih.h"


#include <cstring>

using namespace std;
//using std::cout;
//using std::cin;
//using std::endl;

ogrenci::ogrenci():ogr_no(0)//ogrenci sinifinin yapicisi...
{

}
ogrenci::ogrenci(int arg_ogr, char adi[10],char soyadi[20],tarih d_tarih,tarih k_tarih,bilgisayar bil,int sinif,float notu ):ogr_no(arg_ogr)//yeni ogrencinin bilgileri ayrilan yere aktarilir...
{

    ad.Setstring(adi);
    soyad.Setstring(soyadi);
    dogum_tarihi=d_tarih;
    kayit_tarihi=k_tarih;
    tasinabilir_bilgisayar=bil;
    this->sinifi=sinif;
    this->not_ort=notu;

}

char *ogrenci:: GetAd()//ogrenci adi elde edilir...
{
    return ad.Getstring();
}

char *ogrenci::GetSoyad()//ogrenci soyadi elde edilir...
{
    return soyad.Getstring();
}

tarih ogrenci :: getTarih_dogum()//ogrenci dogum tarihi elde edilir...
{
    return dogum_tarihi.get();


}
tarih  ogrenci:: k_tarihi_oku()
{
    return kayit_tarihi;
}
tarih ogrenci::d_tarihi_oku()
{
    return dogum_tarihi;
}

tarih ogrenci :: getTarih_kayit()//ogrenci kayit tarihi elde edilir...
{
    return kayit_tarihi.get();
}
bilgisayar ogrenci::get_tasinabilir_pc()//ogrenciye ait pc elde edilr...
{
    return tasinabilir_bilgisayar;
}

void ogrenci:: setSinif()//ogrencinin sinifi ayarlanir...
{
    cout<<"ogrencinin sinifini giriniz:"<<endl;
    cin>>sinifi;
}
void ogrenci:: SetNot()//ogrencinin not ortalamasi ayarlanir...
{
    cout<<"ogrencinin notunu giriniz:"<<endl;
    cin>>not_ort;
}
int ogrenci:: get_sinif()//ogrencinin sinifi elde edilir...
{
    return sinifi;
}
float ogrenci::get_not_ort()//ogrencinin not ortalamasi elde edilir...
{
    return not_ort;
}
int ogrenci:: getOgrNo() const//ogrencinin no su elde edilir...
{
    return ogr_no;
}


ostream& operator <<(ostream &output,const ogrenci &birOgrenci)//cikti operatorü asiri yükleniyor...
{
    output<<birOgrenci.ogr_no<<"          " <<birOgrenci.ad<<"        "<<birOgrenci.soyad<<"       "<<birOgrenci.sinifi<<"       "<<birOgrenci.not_ort   ;

    return output;
}




