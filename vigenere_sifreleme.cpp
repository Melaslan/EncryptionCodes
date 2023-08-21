#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char**argv) 
{
	char matris[26][26];
	string alfabe= "abcdefghijklmnopqrstuvwxyz";
	
	for(int i=0; i<26; i++)  
	{
		for(int j=0; j<26;j++) 
		{
			matris[i][j] = alfabe[(j+i)%26];
			cout<<matris[i][j]<<"  ";
		}
		cout<<endl;
	}
	string acik= "edanur erdogan";
	string key= "ada";
	string sifreli="";
	int au=key.length();
	int sa,su;
	for(int i=0; i<acik.length(); i++)
	{
		if(acik[i]>=97 && acik[i]<=122) {
			su= acik[i]-'a';
			sa= key[i%au]-'a';
			sifreli +=matris[sa][su];
		}
		
		else{
			sifreli += acik[i];	
		}
		
	}
	int sira;
	string cozulmus="";
	
	for( int i=0; i<sifreli.length(); i++)
	{
		if(sifreli[i]>=97 && sifreli[i]<=122)
		{
			sa= key[i%au]-'a';
			for(int j=0; j<26; j++)
			{
				if(matris[sa][j]==sifreli[i])
				{
					sira= j;
					break;
				}
			}
			cozulmus+=alfabe[sira];
		}
		else
		{
			cozulmus+=sifreli[i];
		}
	}
	
		
	cout<<sifreli<<endl<<cozulmus;
}
