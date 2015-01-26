#include <iostream>
#include <cstring>

using namespace std;

#include "ogrenci.h"
#include "ogrenci_dizisi.h"


ogrenci_dizisi::ogrenci_dizisi()// 1000 elemanli isaretci dizisi olusturuluyor...
{
    for (int i=0; i<1001; i++)
        ogrenciler[i]=NULL;
}
void ogrenci_dizisi::ogrenci_getir(int sayi)//yil sonunda ogrenci bilgierinin guncellenmesini saglayan fonksiyon...
{
    if(ogrenciler[sayi]!=NULL)//okuldaki tüm ogrenciler sirayla cagriliyor...
    {
        cout<<ogrenciler[sayi]->getOgrNo()<<" bu numarali ";
        ogrenciler[sayi]->setSinif();//sinifi güncelleniyor...
        cout<<ogrenciler[sayi]->getOgrNo()<<" bu numarali ";
        ogrenciler[sayi]->SetNot();//not_ortalamasi güncelleniyor...
    }
}
void ogrenci_dizisi::ekle(ogrenci *yeniOgrenci,int no)
{
    ogrenciler[no]=yeniOgrenci;//yeni ogrenci ogrenci dizisine ekleniyor...
}
ogrenci *ogrenci_dizisi::ara(int arananNo)
{
    if (ogrenciler[arananNo] == NULL)//girilen no ya sahip ogrenci olup olmadigina bakiliyor...
        return NULL;
    else
        return ogrenciler[arananNo];
}
ogrenci *ogrenci_dizisi::cikar(int girilenNo)//nosu girilen ogrenci diziden cikariliyor...
{
    ogrenci *cikarilan;

    cikarilan = ogrenciler[girilenNo];

    ogrenciler[girilenNo] = NULL;//cikarilan ogrenic yerine NULL ataniyor...

    return cikarilan;

}
ogrenci* ogrenci_dizisi:: ogrenci_dondur(int index)
{
    return ogrenciler[index];
}
void ogrenci_dizisi::listele()
{
    tarih d1,d2;
    ogrenci *ogr;
    for (int i=0; i<1000; i++)//okuldaki tüm ogrencilr listeleniyor..
    {
        if (ogrenciler[i+1] != NULL)
        {
            ogr=ogrenciler[i+1];
            d1=ogr->d_tarihi_oku();
            d2=ogr->k_tarihi_oku();
            cout << *ogr<< "          "<<d1<<"           "  <<d2<<endl;

        }

    }
}
void ogrenci_dizisi::ada_gore_listele(char girilen_ad[])
{
    tarih d1,d2;
    ogrenci *ogr;
    for (int i=0; i<1000; i++)//girlen bir ada sahip olan ogr ler listeleniyor...
    {
        if(ogrenciler[i+1]!=NULL)
        {
            ogr=ogrenciler[i+1];
            d1=ogr->d_tarihi_oku();
            d2=ogr->k_tarihi_oku();
            if(strcasecmp(girilen_ad,ogr->GetAd())==0)//strcasecmp ile harf ayrimi olmadan isimler karsilastiriliyor...
            {
                cout<<*ogr<<"          "<<d1<<"          "<<d2<<endl;
            }
        }
    }
}
void ogrenci_dizisi::sinifa_gore_listele(int sinif)//kullanicinin girdigi siniftaki ogrenciler listeleniyor...
{
    tarih d1,d2;
    ogrenci *ogr;
    int bulundu=0,ogr_say=0;
    for (int i=0; i<1000; i++)
    {
        if(ogrenciler[i+1]!=NULL)
        {
            ogr=ogrenciler[i+1];
            d1=ogr->d_tarihi_oku();
            d2=ogr->k_tarihi_oku();
            if(sinif==ogr->get_sinif())
            {
                bulundu=1;
                ogr_say++;
                cout<<*ogr<<d1<<d2<<endl;
            }
        }
    }
    if(bulundu!=0)
    {
        cout<<"Sinifin ogrenci sayisi:";
        cout<<ogr_say<<endl;
    }
    else
        cout<<"bu sinifta ogrenci yok ki!!!"<<endl;
}
void ogrenci_dizisi::doguma_gore_listele(tarih &trh)//ogrenciler dogum tarihlerine gore listelenir...
{
    tarih d1,d2;
    ogrenci *ogr;
    int bulundu=0;
    for (int i=0; i<1000; i++)
    {
        if(ogrenciler[i+1]!=NULL)
        {
            ogr=ogrenciler[i+1];
            d1=ogr->d_tarihi_oku();
            d2=ogr->k_tarihi_oku();
            if((ogr->getTarih_dogum()<trh)==true)
            {
                cout<<*ogr<<d1<<d2<<endl;
                bulundu=1;
            }
        }

    }
    if(bulundu==0)
        cout<<"ogrenci yok ki!!!"<<endl;
}

void ogrenci_dizisi::pc_ara(String seri_no)//seri _no ya gore ogrenci aranir...
{
    ogrenci *ogr;
    tarih d1,d2;
    int bulundu=0;
    for (int i=0; i<1000; i++)
    {
        if(ogrenciler[i+1]!=NULL)
        {
            ogr=ogrenciler[i+1];
            if((((ogr->get_tasinabilir_pc()).Getserino())==seri_no)==true)
            {
                cout<<*ogr;
                bulundu=1;
                d1=ogr->d_tarihi_oku();
                d2=ogr->k_tarihi_oku();
                cout<<"ogrencinin dogum tarihi:";
                cout<<d1<<endl;
                cout<<"ogrencinin kayit tarihi:";
                cout<<d2<<endl;


            }
        }

    }
    if(bulundu==0)
        cout<<"bu bilgisayar henuz kimseye verilmemis ki!!!"<<endl;

}
void ogrenci_dizisi::pc_ara_model_ile(char marka [],String model)//marka ve modele gore ogrenci listelenir...
{
    tarih d1,d2;
    ogrenci *ogr;
    int bulundu=0;
    for (int i=0; i<1000; i++)
    {
        if(ogrenciler[i+1]!=NULL)
        {
            ogr=ogrenciler[i+1];

            if(strcasecmp(marka,ogr->get_tasinabilir_pc().marka_al())==0)
            {
                if((model==(ogr->get_tasinabilir_pc()).Getmodel())==true)
                {
                    cout<<*ogr;
                    bulundu=1;

                    d1=ogr->d_tarihi_oku();
                    d2=ogr->k_tarihi_oku();
                    cout<<"ogrencinin dogum tarihi:";
                    cout<<d1<<endl;
                    cout<<"ogrencinin kayit tarihi:";
                    cout<<d2<<endl;

                }
            }
        }
    }
    if(bulundu==0)
        cout<<"bu bilgisayar henüz kimseye verilmemis ki!!!"<<endl;
}
void ogrenci_dizisi::yila_gore_listele(int yil)//kayit yilina gore ogrenci listelenir...
{
    ogrenci *ogr;
    int bulundu=0;
    tarih d1,d2;
    for (int i=0; i<1000; i++)
    {
        if(ogrenciler[i+1]!=NULL)
        {
            ogr=ogrenciler[i+1];
            d1=ogr->d_tarihi_oku();
            d2=ogr->k_tarihi_oku();
            if((ogr->getTarih_kayit()>yil)==true)
            {
                cout<<*ogr<<     d1<<      d2<<endl;
                bulundu=1;
            }

        }
    }
    if(bulundu==0)

        cout<<"ogr yok ki!!!"<<endl;

}










