#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include "ogrenci.h"
#include <assert.h>

String::String( int a):boy(a) //girilecek olan stringin uzunluguna gore yeni bir string dizisi olusturuluyor...
{

    ptr=new char[boy];
    ptr[boy-1]='\0';


}

int String::boy_oku()//girilecek olan stringin boyu geri doner...
{
    return boy;
}
String &String::operator=( String &right)
{
    if(&right!=this)
    {
        if(boy!=right.boy)
        {
            delete[]ptr;
            boy=right.boy;
            ptr=new char[boy];
            assert(ptr!=0);
        }

        for(int i=0; i<boy; i++)
            ptr[i]=right.ptr[i];
    }

    return *this;
}


void String::Setstring(const  char *metin)//strcpy kullanilarak gelen argüman ptr e atanir...
{
strcpy(ptr,metin);
}
char* String::Getstring()//geriye ptr doner....
{
    return ptr;
}


bool String::operator==(const String &karsilastirilan) const//== operatoru asiri yukleniyor...
{
    if(strcmp(ptr,karsilastirilan.ptr)==0)
        return true;
    else return false;
}

ostream& operator <<(ostream &output,const  String &str)//cikti operatoru asiri yükleniyor...
{
   output<<str.ptr;
    return output;
}
istream& operator >>(istream &input,String &str)//girdi operatoru asiri yükleniyor...
{
  input>>str.Getstring();

  return input;
}
const String& String::operator=(const String &atanan)//=operatoru asiri yukleniyor...
{
    boy=atanan.boy;
    ptr=atanan.ptr;

    return *this;

}




