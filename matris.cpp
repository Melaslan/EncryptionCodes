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

int matris_boyutu_bul(int uzunluk)
{
	int i=1;
	while(1)
	{
		if(i*i>uzunluk)
			return i;
		i++;
	}
}
void matris_sifrele (char *metin)
{
	int i,j,k= matris_boyutu_bul (strlen(metin));
	char sifreli_metin [strlen(metin)]; 
	char matris [k][k];
	for(i=0;i<k; i++)
	{
		for(j=0;j<k; j++)	
		{
			if(!((i*k)+j>strlen(metin)-1))
				 matris[i][j] = metin[(i*k)+j];
			else
				matris[i][j]=' ';
		}

	}
	for (i=0;i<k; i++)
	{
		for(j=0;j<k;j++)
		{
			if(!((i*k)+j>strlen(metin)-1))
				sifreli_metin[(i*k)+j] = matris[j][i];


		}
	}
	dosyaya_yaz(CIKIS_DOSYASI,sifreli_metin);
}


void matris_coz (char *metin)
{
	int i,j,k = matris_boyutu_bul(strlen(metin)); 
	char cozulen_metin [strlen(metin)];
	char matris [k][k];
	for (i=0;i<k; i++)
	{
		for(j=0;j<k;j++)
		{
			matris[j][i] = metin[(i*k)+j];
		}
	}
	for(i=0;i<k; i++)
	{
		for(j=0;j<k;j++)
		{
			if(!((i*k)+j>strlen(metin)-1))
				cozulen_metin[(i*k)+j] = matris[i][j];
		}
	}
	dosyaya_yaz (COZME_DOSYASI, cozulen_metin);
}


int main(int argc, char *argv[])
{
	char *text = dosyadan_oku(GIRIS_DOSYASI);
	matris_sifrele(text);
	text= dosyadan_oku(CIKIS_DOSYASI);
	matris_coz(text);
	return 0;
}
