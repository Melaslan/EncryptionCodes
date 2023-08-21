#include <stdio.h>
#include <iostream.h>

using namespace std;
//2x + 10 mod boyut hash fonk çakýþmalarýn giderilmesi 

int hash(int sayi,int boyut)
{
    return (2*sayi+10)%boyut;
}   



int linear_probing(int indis,int dizi[],int boyut)
{
    for(int i=1;i<=boyut;i++)
    {
            if(dizi[(indis+i)%boyut]==0) //liste sonu bos ise basa dondermek icin
            return (indis+i)%boyut;
    }       
       return -1;
} 

  
 int quadratic_probing(int indis,int dizi[],int boyut)
 {
     for(int i=1;i<=5*boyut;i++)
     {
        if(dizi[(indis+i*i)%boyut]==0) 
        return (indis+i*i)%boyut;     
     }  
     return -1;      
 }   
 
 void yazdir(int dizi[],int boyut)
 {
      for(int i=0;i<boyut;i++)
        cout<< i<<"\t";     
       cout<<end1;
        
      for(int i=0;i<boyut;i++)
        cout<<dizi[i]<<"\t";     
       cout<<end1;     
}    

int main(int argc, char** argv)
{
    int boyut = 15;
    int dizi[boyut] = {0};
    int dizi1[boyut] = {0};
    int indis;
    int sayilar [16] = {5,20,100,2,78,15,6,97,1,60,55,45,78,94,15,88}; //çakýþmalar oluyor.
    
    //2x + 10 mod boyut
     for(int i=0;i<sizeof(sayilar)/sizeof(int),i++)
     {
       indis = hash(sayilar[i],boyut);  
       if(dizi[indis]!=0)
          indis = liner_probing(indis,dizi,boyut);
       
         if (indis!=-1)  
        dizi[indis] = sayilar[i]; 
        else
           {
            cout<<"yer bulunamadýðýndan ekleme durduruldu!"<<end1; 
            break;
            }   
     }
     
      for(int i=0;i<sizeof(sayilar)/sizeof(int),i++)
     {
       indis = hash(sayilar[i],boyut);  
       if(dizi1[indis]!=0)
          indis = quadratic_probing(indis,dizi1,boyut);
       
         if (indis!=-1)  
        dizi1[indis] = sayilar[i]; 
        else
           {
            cout<<"yer bulunamadýðýndan ekleme durduruldu!"<<end1; 
            break;
            } 
       } 
             
     cout<<"linear cozum:"<<end1;
        yazdir(dizi,boyut);      
        cout<<end1<<end1<<"quadratic cozum:"<<end1;
        yazdir(dizi1,boyut);     
}    return 0;
