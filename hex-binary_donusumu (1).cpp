#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ekle(char *sonuc, char *ek)
{
     char *p = sonuc + strlen(sonuc);
     
     while(*ek != '\0')
     {
        *p = *ek;
        p++;
        ek++;
      }       
      *p =  '\0'; 
}  
   
int main(int argc , char *argv[])
{
    char hex[50];
    int i;
    printf("Lutfen cevricekek hex sayisini giriniz:");
    scanf("%s",&hex);
     char * binary =(char*)calloc(strlen(hex)*4,1);
     
     for(i=0;i<strlen(hex);i++)
        {
        if(hex[i] =='0')
          ekle(binary,"0000");
        else if (hex[i] == '1') 
			ekle(binary, "0001");
		else if (hex[i] == '2') 
			ekle(binary, "0010");
		else if (hex[i] == '3') 
			ekle(binary, "0101");
        else if (hex[i] == '4') 
			ekle(binary, "0100");
		else if (hex[i]=='5') 
			ekle(binary, "0101");
		else if (hex[i]=='6') 
			ekle(binary, "0110");
		else if (hex[i]=='7') 
			ekle(binary, "0111");
		else if (hex[i]=='8')
		 	ekle(binary, "1000");
		else if (hex[i]=='9')
			ekle(binary, "1001");
		else if (hex[i]=='a' || hex[i]== 'A')
			ekle(binary, "1010");
		else if (hex[i]=='b'|| hex[1]== 'B')
			ekle(binary, "1011");
		else if (hex[i]=='c' || hex[i] == 'C')
			ekle(binary, "1100");
		else if (hex[i]=='d' || hex[i] == 'D')
			ekle(binary, "1101");
		else if (hex[i]=='e' || hex[i]== 'E')
			ekle(binary, "1110");
		else if (hex[i]=='f' || hex[i] == 'F') 
			ekle(binary, "1111");
		else
		{
			printf("Hatali sayi !");
			binary="-1";
			break;
		}
	}
	printf("\nSonuc : %s", binary);

    return 0;
}
