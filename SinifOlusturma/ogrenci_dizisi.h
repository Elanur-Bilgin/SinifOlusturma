#ifndef OGRENCI_DIZISI_H_INCLUDED
#define OGRENCI_DIZISI_H_INCLUDED

#ifndef OGRENCI_DIZISI_H
#define OGRENCI_DIZISI_H


class ogrenci_dizisi
{
public:
    ogrenci_dizisi();
    void ekle(ogrenci *,int);
    ogrenci *ara(int);
    ogrenci *cikar(int);
    void listele();
    void ada_gore_listele(char []);
    void sinifa_gore_listele(int);
    void doguma_gore_listele(tarih &);
   void pc_ara(String );
    void pc_ara_model_ile(char [],String);
    void yila_gore_listele(int yil);
    void ogrenci_getir(int );
    ogrenci*  ogrenci_dondur(int);

private:
    ogrenci *ogrenciler[1001];// ogrencilerin tutulacagi isaretci dizisi ...
};

#endif // OGRENCI_DIZISI_H


#endif // OGRENCI_DIZISI_H_INCLUDED
