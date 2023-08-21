
#include <iostream> 
#include "desmatris.h"
using namespace std;

string to_binary(string karakterler)
{
	int sayi, dizi[8];
	string sonuc= "";
	for (int i=0;i<karakterler.length();i++)
	{
		sayi= int(karakterler[i]);
		
		for (int j=7;j>=0;j--)
		{
			if (sayi>0)
			{
				dizi[j]= sayi%2;
				sayi /= 2;
			}
			else
			{
				dizi[j]=0;
			}
		}
		for(int j=0;j<8;j++)
		{
			if(dizi[j]==0)
				sonuc += "0";
			else
				sonuc+="1";
		}
	}
	return sonuc;
}

int to_decimal(string p)
{
	return p[0]*128+p[1]*64+ p[2]*32+ p[3]*16+ p[4]*8+ p[5]*4+ p[6]*2+ p[7];
}

string to_string(string binary)
{
	string cozum= "";
	for(int i=0; i<=binary.length()-8;i++)
	{
		cozum+= char(to_decimal(binary.substr(i,8)));
	 } 
	 return cozum;
}

string to_binary(int x)
{
	int sayi,dizi[4],k;
	string sonuc;
	sayi=x;
	for(int j=3; j>=0; j--)
	{
		if(sayi>0)
		{
			dizi[j]= sayi%2;
			sayi=sayi/2;
		}
		else
		{
			dizi[j]=0;
		}
	}
	for(int j=0; j<4; j++)
	{
		if(dizi[j]==0)
			sonuc+="0";
		else
			sonuc+="1";
	}
	return sonuc;
}

int ctoi(char a)
{
	if(a=='1')
		return 1;
	return 0;
}

string permutasyon(string x, int tablo[],int boyut)
{
	string sonuc= "";
	int indis;
	for(int i=0; i<boyut; i++)
	{
		indis = tablo[i]-1;
		sonuc += x[indis];
	}
	return sonuc;
}

string left_shift(string x, int k)
{
	if(k==1) 
	{
		char ilk = x[0];
		for(int i=0; i<x.length()-1; i++)
		{
			x[i] = x[i+1];
		}
		x[x.length()-1] = ilk;
	}
	else
	{
			char ilk = x[0];
			char iki = x[1];
		for(int i=0; i<x.length()-1; i++)
		{
			x[i] = x[i+2];
		}
		x[x.length()-1] = iki;
		x[x.length()-2] = iki;

	}

	return x;
	
}

string x_or(string x, string y)
{
	string sonuc= "";
	for(int i; i<x.length(); i++)
	{
		if(x[i]==y[i])
		{
			sonuc+= "0";
		}
		else
		{
			sonuc += "1";
		}
	}
	return sonuc;
}

int main( int argc, char**argv)
{
	string metin = "ABCDEFGH";
	string anahtar= "ABCDEFGH";
	string binary_metin = to_binary(metin);
	string binary_anahtar= to_binary(metin);
//	cout<<binary_metin<<endl;
	string perm_metin = permutasyon(binary_metin,initial_permutation_table,64);
	//saðlamasý --- cout<<binary_metin[57]<<binary_metin[49]<<binary_metin[41]<<binary_metin[33]<<binary_metin[25]<<binary_metin[17]<<endl;
	string left_metin = perm_metin.substr(0,32);
	string right_metin = perm_metin.substr(32,32);
	//cout<<perm_metin<<endl;
	//cout<<left_metin<<right_metin<<endl;
	
	//anahtar kýsmý 5.hafta 5. uyg. dersi
	string perm_anahtar= permutasyon(binary_anahtar,PC1,56);
	string left_anahtar = perm_anahtar.substr(0,28);
	string right_anahtar = perm_anahtar.substr(28,28);
	//anahtar kontrol için yazdýrdýk
	//cout<<perm_anahtar<<endl<<left_anahtar<<" "<<right_anahtar;				
	string ls_left_anahtar = "";
	string ls_right_anahtar = "";
	cout<<"acik_metin: "<<binary_metin<<endl;
	
	for(int i=0; i<16;i++)
	{
			
		ls_left_anahtar = left_shift(left_anahtar,2);
		ls_right_anahtar = left_shift(right_anahtar,2);
	
	
		string anahtar_48 = permutasyon(ls_left_anahtar+ls_right_anahtar,PC2,48);
		string exp_right_metin = permutasyon(right_metin, E,48);
	
		string x_or_sonuc = x_or(anahtar_48,exp_right_metin);
		cout<<x_or_sonuc<<endl;
	
	
		string altililar[8];
	
		int k=0;
		for(int j=0; j<x_or_sonuc.length(); j+=6)
		{
			altililar[k] = x_or_sonuc.substr(j,6);
			k++;
			cout<<altililar[j]<<endl;
		}
	
		for(int j=0; j<8; j++)
	 	{
			cout<<altililar[j]<<endl;
		}
		string sbox_ciktisi = "";
		for(int j=0; j<8; j++)
		{
			int satir = ctoi(char(altililar[j][0]))*2+ ctoi(char(altililar[j][5]));
			int sutun = ctoi(char(altililar[j][1]))*8+ ctoi(char(altililar[j][2]))*4 + ctoi(char(altililar[j][3]))*2+ ctoi(char(altililar[j][4]));
			sbox_ciktisi += to_binary(S[j][satir][sutun]);
		}
		sbox_ciktisi= permutasyon(sbox_ciktisi,P,32);
		
		string temp = x_or(sbox_ciktisi,left_metin);
		
		left_metin= right_metin;
		right_metin = temp;
		left_anahtar=ls_left_anahtar;
		right_anahtar=ls_right_anahtar;
	
	
	
	}
	string temp=right_metin;
	right_metin= left_metin;
	left_metin=temp;
	string sifreli=permutasyon(left_metin+right_metin,final_permutation_table,64);
	cout<<sifreli<<endl;
	cout<<"sifreli_metin: "<<to_string(sifreli);
	

	return 0;
}










