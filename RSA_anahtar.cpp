#include <iostream>
using namespace std;

bool asalmi(int x)
{
	for(int i=2; i<x; i++)
		if(x%i==0)
			return 0;
	return 1;
}
bool aralarinda_asal(int x, int y)
{
	int buyuk, kucuk;
	if(x,y)
	{
		buyuk = x;
		kucuk= y;
	}
	else
	{
		buyuk = y;
		kucuk= x;
	}	
	
	for(int i=2; i<=kucuk; i++)
	{
		if(kucuk%i==0 &&buyuk%i==0)
			return 0;
	}
	return 1;
}

int e_bul(int t)
{
	for(int i=2; i<t; i++)
	{
		if(aralarinda_asal(t,i))
		{
			return i;
		}
	}
	return -1;
}

int d_bul(int e, int t)
{
	for(int i=1;;i++)
	{
		if((i*e)%t==1)
			return i;
	}
}

int sifrele(int x,int e,int n)
{
	int sonuc = 1;
	for(int i=0; i<e; i++)
	{
		sonuc *=x;
	}
	return sonuc%n;
}

int coz(int x,int d,int n)
{
	int sonuc=1;
	for(int i=0;i<d;i++)
	{
		sonuc*=x;
	}
	return sonuc%n;
}

int main ( int argc, char** argv)
{
	int p=2,q=2,n,t,e,d;
	
	while(true)
	{
		cout<<"asal p girin: ";
		cin>>p;
		if(asalmi(p))
			break;
	}	
	while(true)
	{
		cout<<"asal q girin: ";
		cin>>q;
		if(asalmi(q))
			break;
	}
	
	n= p*q;
	t=(p-1)*(q-1);
	e= e_bul(t);
	d= d_bul(e,t);
	
	cout<<"p: "<<p<<endl<<"q: "<<q<<endl;
	cout<<"n: "<<n<<endl<<"t: "<<t<<endl<<"e: "<<e<<endl<<"d: "<<d<<endl;;
	cout<<"sifreli: "<<sifrele(12,e,n)<<endl;
	cout<<"cozulmus "<<coz(sifrele(12,e,n),d,n);
	
	return 0;
	
	
}






















