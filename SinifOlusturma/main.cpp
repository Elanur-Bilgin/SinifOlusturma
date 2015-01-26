//28.05.2013 1.sınıf son projemiz:)
//oh be sonunda 1.sınıf bitti kaldı 3 sene.........

#include <iostream>
#include "ogrenci.h"
#include "String.h"
#include "ogrenci_dizisi.h"

#include <stdio.h>

using namespace std;

int main()
{
    tarih d1,d2; // Nurum umarım anlarsın, tarihi burada tanımladım, ögrenci dizisinde ögrenci_dondur diye fonksiyon yazdım, dizinin
    // elemanlarını dönduruyor tek tek, 6.case de de yazdırıyorum, bak bakalım anlmazsan tekrar anlatırım


    int no,girilen_sinif,yil;
    String s1;
    ogrenci ogr;
    ogrenci *yeni_ogr,*bir_ogr;
    char girilen_ad[10],girilen_soyad[20],pc_marka[10];
    ogrenci_dizisi ogrenciler;
    int secim,i;
    tarih dogum,kayit;
    String pc_model,pc_seri;
    do
    {
        cout<<"\n-----------------MENU-----------------------------------"<<endl;
        cout<<"1)  Yeni kazanan bir ogrencinin okula kaydedilmesi"<<endl;
        cout<<"2)  Yatay gecisle gelen bir ogrencinin okula kaydedilmesi"<<endl;
        cout<<"3)  Yil sonunda tum ogrencilerin siniflarinin ve not ortalamasinin guncellenmesi"<<endl;
        cout<<"4)  Bir ogrencinin okuldan kaydinin silinmesi"<<endl;
        cout<<"5)  Bir ogrencinin bilgilerinin goruntulenmesi"<<endl;
        cout<<"6)  Okula kayitli tum ogrencilerin listelenmesi"<<endl;
        cout<<"7)  Bir sinifda okuyan ogrencilerin listelenmesi"<<endl;
        cout<<"8)  Belirli bir ada sahip ogrencilerin listelenmesi"<<endl;
        cout<<"9)  Belirli bir tarihden once dogan ogrencilerin listelenmesi"<<endl;
        cout<<"10) Belirli bir yildan sonra bolume kaydedilmis ogrencilerin listelenmesi"<<endl;
        cout<<"11) Bir tasinabilir bilgisayarin verilmis oldugu ogrencinin bilgilerinin goruntulenmesi"<<endl;
        cout<<"12) Belirli bir marka ve model bilgisayarin verilmis oldugu ogrencilerin listelenmesi"<<endl;
        cout<<"13)Cikis"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"Seciminizi giriniz :";
        cin>>secim;
        switch (secim)
        {
        case 1:

            cout<<"ogrencinin numarasini giriniz:"<<endl;
            cin>>no;
            if(ogrenciler.ara(no)==NULL) //kaydedilmek istenilen ogr_no kontrol ediliyor...
            {
                //kaydedilecek olan ogrencinin bilgileri kullanicidan aliniyor...
                cout<<"ogrencinin adi:"<<endl;
                cout<<"Buyuk harfle yaziyorsaniz turkce karakter girmeyiniz"<<endl;
                fflush(stdin);
                gets(girilen_ad);
                s1.Setstring(girilen_ad);
                cout<<"ogrencinin soyadi:"<<endl;
                fflush(stdin);
                gets(girilen_soyad);
                s1.Setstring(girilen_soyad);
                cout<<"dogum tarihi bilgileri:"<<endl;
                cin>>dogum;
                cout<<"kayit tarihi bilgileri:"<<endl;
                cin>>kayit;
                bilgisayar pc(0,0,0);
                cout<<"verilen bilgisayar bilgileri:"<<endl;
                cin>>pc;
                yeni_ogr= new ogrenci(no,girilen_ad,girilen_soyad,dogum,kayit,pc,1,0.00);//yeni ogrencinin eklenmesi icin bellekten new ile yer ayriliyor...
                ogrenciler.ekle(yeni_ogr,no);//yeni ogrenci ogrenciler dizisine eklenir...
                cout<<"ekleme islemi basari ile gerceklesti..."<<endl;
            }
            else
                cout<<"bu ogrenci zaten var ki!!!"<<endl;
            break;

        case 2:
            cout<<"ogrencinin numarasini giriniz:"<<endl;
            cin>>no;
            if(ogrenciler.ara(no)==NULL) //kaydedilmek istenilen ogr_no kontrol ediliyor...
            {
                cout<<"Buyuk harfle yazıyorsaniz turkce karakter girmeyiniz"<<endl;
                //elkenecek ogrencinin bilgileri isteniyor...
                cout<<"ogrencinin adi:"<<endl;
                cout<<"Buyuk harfle yazİyorsaniz turkce karakter girmeyiniz"<<endl;
                fflush(stdin);
                gets(girilen_ad);
                cout<<"ogrencinin soyadi:"<<endl;
                fflush(stdin);
                gets(girilen_soyad);
                cout<<"dogum tarihi bilgileri:"<<endl;
                cin>>dogum;
                cout<<"kayit tarihi bilgileri:"<<endl;
                cin>>kayit;
                cout<<" verilen bilgisayar  bilgileri:"<<endl;
                bilgisayar pc(0,0,0);
                cin>>pc;
                ogr.setSinif();
                ogr.SetNot();
                yeni_ogr= new ogrenci(no,girilen_ad,girilen_soyad,dogum,kayit,pc,ogr.get_sinif(),ogr.get_not_ort());//eklenecek olan ogrenci icin new ile bellekten yer ayriliyor...
                ogrenciler.ekle(yeni_ogr,no);//yeni ogrenci ogrenci dizisine ekleniyor...
                cout<<"ekleme islemi basari ile gerceklesti..."<<endl;
            }
            else
                cout<<"bu ogrenci zaten var ki!!!"<<endl;
            break;
        case 3://yil sonunda ogrencilerin not_ortalamalari ve sinifari güncellenir...
            for(i=0; i<1000; i++)
            {
                ogrenciler.ogrenci_getir(i+1);
            }
            cout<<"guncelleme islemi gerceklesti..."<<endl;
            break;
        case 4:
            cout<<"silmek istediiniz ogrencinin numarsini giriniz:"<<endl;
            cin>>no;
            if(ogrenciler.ara(no)!=NULL)//silinecek olan ogrencinin olup olmadigi arastirilir...
            {
                ogrenciler.cikar(no);//ogrenci ogrenciler dizisinden cikarilir..
                cout<<"silme islemi basari ile gerceklesti..."<<endl;
            }
            else
                cout<<"boyle bir ogrenci zaten yok ki!!!"<<endl;
            break;
        case 5://numarasi girilen ogrencinin bilgileri bilgileri gorüntülenir...
            cout<<" ogrencinin numarasini giriniz:"<<endl;
            cin>>no;
            if(ogrenciler.ara(no)!=NULL)
            {
                bir_ogr=ogrenciler.ara(no);
                cout<<"ogr no     ad    soyad    sinif    not ortalamasi"<<endl;
                cout<<"------    ----   -----    ------   --------------"<<endl;
                cout<<*bir_ogr;
                cout<<"Verilen Bilgisayar"<<endl;
                cout<<"Seri Numarasi   Marka      Model"<<endl;
                cout<<"-------------   ------    -------"<<endl;
                bilgisayar pc(0,0,0);
                pc=bir_ogr->get_tasinabilir_pc();//numarasi girilen ogrenciye verilen pc bilgileri listelenir...
                cout<<pc;
            }
            else
                cout<<"boyle bir ogrenci zaten yok ki!!!"<<endl;
            break;
        case 6:
            cout<<"ogr no     ad    soyad    sinif    not ortalamasi   dogum tarihi    kayit tarihi    "<<endl;
            cout<<"------    ----   -----    ------   --------------   ------------    -------------"<<endl;
             //ogrenciler.listele();//okuldaki ogrencilerin hepsi listelenir...

            ogrenci *ogren;
            for (int i=0; i<1000; i++)//okuldaki tüm ogrencilr listeleniyor..
            {
                ogren=ogrenciler.ogrenci_dondur(i+1);
                if (ogren != NULL)
                {
                    //ogren=ogrenciler[i+1];
                    d1=ogren->d_tarihi_oku().get();
                    d2=ogren->k_tarihi_oku().get();
                    cout << *ogren<< "          "<<d1<<"           "  <<d2<<endl;
                }
            }
            break;
        case 7:
            cout<<"ogrencilerini gormek istediginiz sinifi giriniz:"<<endl;
            cin>>girilen_sinif;
            cout<<"ogr no     ad    soyad    sinif    not ortalamasi   dogum tarihi    kayit tarihi   "<<endl;
            cout<<"------    ----   -----    ------   --------------   ------------    ------------"<<endl;
            ogrenciler.sinifa_gore_listele(girilen_sinif);//girilen bir siniftaki ogrenciler listelenir...
            break;
        case 8:
            cout<<"goruntulemek istediginiz ogrenci adi:"<<endl;
            cout<<"Buyuk harfle yaziyorsaniz turkce karakter girmeyiniz"<<endl;
            cin>>girilen_ad;//kullanicidan bir ad istenir...
            cout<<"ogr no     ad    soyad    sinif    not ortalamasi dogum tarihi    kayit tarihi "<<endl;
            cout<<"------    ----   -----    ------   -------------- ------------    ------------"<<endl;
            ogrenciler.ada_gore_listele(girilen_ad);//girlen ada sahip olan ogrenciler listelenir...
            break;
        case 9:
            cout<<"tarih giriniz:"<<endl;
            cin>>dogum;//kullanicidan dogum tarihi istenir...
            cout<<"ogr no     ad    soyad    sinif    not ortalamasi  dogum tarihi   kayit tarihi "<<endl;
            cout<<"------    ----   -----    ------   --------------  ------------   -----------"<<endl;
            ogrenciler.doguma_gore_listele(dogum);//girilen dogum tarihinden once doganlar listelenir...
            break;
        case 10:
            cout<<"yil  giriniz:"<<endl;
            cin>>yil;//kullanicidan kayit yili istenir...
            cout<<"ogr no     ad    soyad    sinif    not ortalamasi  dogum tarihi    kayit tarihi"<<endl;
            cout<<"------    ----   -----    ------   --------------  -------------   -----------"<<endl;
            ogrenciler.yila_gore_listele(yil);//girilen yildan sonra kaydolanlar listelenir...

            break;
        case 11:
            cout<<"seri no giriniz:"<<endl;
            cin>>pc_seri;//kullanicidan seri no istenir...
            cout<<"ogr no     ad    soyad    sinif    not ortalamasi"<<endl;
            cout<<"------    ----   -----    ------   --------------"<<endl;
            ogrenciler.pc_ara(pc_seri);//girilen seri_ noya sahip pc kime verildiyse o ogrenci  listenir...

            break;
        case 12:
            cout<<"marka ve model giriniz:"<<endl;
            cin>>pc_marka;//kullanicidan marka ve model istenir...
            cin>>pc_model;
            cout<<"ogr no     ad    soyad    sinif    not ortalamasi"<<endl;
            cout<<"------    ----   -----    ------   --------------"<<endl;
            ogrenciler.pc_ara_model_ile(pc_marka,pc_model);//girilen marka ve modele sahip pc kime verildiyse o ogrenci listelenir...
            break;
        }
    }
    while(secim!=13);//cikis...
    return 0;
}

