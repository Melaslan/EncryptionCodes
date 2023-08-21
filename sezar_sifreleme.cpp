#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
 
#define GIRIS_DOSYASI "acik_metin.txt" 
#define CIKIS_DOSYASI "sifreli_metin.txt" 
#define COZME_DOSYASI "cozulen_metin.txt"

char * dosyadan_oku (char *yol){
	char *text;
	int uzunluk;
	FILE *file = fopen(yol,"r");
	
	
	if(file)
{
	fseek(file, 0, SEEK_END);
	uzunluk = ftell(file); 
	fseek(file, 0, SEEK_SET);
	text = (char*)malloc(uzunluk);
	if(text)
	{
		fread(text,sizeof(char),uzunluk,file);
	}
	else{
		printf("\natanamadi");
	}
	fclose(file);
}
else{
	printf("\nDosya Acilamadi! Okuma Basarisiz !");
}
	 return text;
}


void dosyaya_yaz (char *yol, char *metin)
{
	FILE *file = fopen(yol,"w");
	if(file) 
	{
		fputs(metin, file);
		printf("\nDosyaya Yazma Basarili !");
		fclose(file);
}
else{
	
	printf("\nYazmak Icin Dosya Acilamadi !");

}	
}


void sezar_sifrele (char *acik_metin, int anahtar)
{
	if (anahtar<0)
		anahtar*= -1;
	anahtar=anahtar % 26;
	int uzunluk = strlen(acik_metin); 
	char sifreli_metin[uzunluk];
	int i;
	for(i=0;i<uzunluk;i++) 
	{
		if(acik_metin[i]<='Z' && acik_metin[i]>='A')
		{
			sifreli_metin[i] = ((acik_metin[i]-65+anahtar)%26)+65;
		}	
		else if (acik_metin[i] <= 'z' && acik_metin[i]>='a')
		{
			sifreli_metin[i] = ((acik_metin[i]-97+anahtar)%26)+97;
		}
		else
		{
			sifreli_metin[i] = acik_metin[i];
		}
	}
	dosyaya_yaz(CIKIS_DOSYASI,sifreli_metin);
}


void sezar_coz (char *sifreli_metin, int anahtar)
{
	if (anahtar<0)
		 anahtar*= -1;
	anahtar = anahtar % 26;
	anahtar=26-anahtar;
	int uzunluk= strlen(sifreli_metin);
	char cozulen_metin[uzunluk];
	int i;
	for(i=0;i<uzunluk;i++) 
	{
		if(sifreli_metin[i]<='Z' && sifreli_metin[i]>='A')
		{
			cozulen_metin[i] = ((sifreli_metin[i]-65+anahtar)%26)+65;
		}	
		else if (sifreli_metin[i] <= 'z' && sifreli_metin[i]>='a')
		{
			cozulen_metin[i] = ((sifreli_metin[i]-97+anahtar)%26)+97;
		}
		else
		{
			cozulen_metin[i] = sifreli_metin[i];
		}
	}
	dosyaya_yaz(COZME_DOSYASI,cozulen_metin);
}


int main(int argc, char *argv[])
{
	char *text = dosyadan_oku(GIRIS_DOSYASI);
	printf("okunan: %s", text);
	sezar_sifrele(text,1);
	text= dosyadan_oku(CIKIS_DOSYASI);
	sezar_coz(text,1);

	return 0;
}
