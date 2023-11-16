#include <fstream>
#define MAX_CIFRE 10
using namespace std;
void anagramabil(int numar, int & nrCifre, int cifra[]);
int main()
{
	int numar, nrCifre=0, cifra[MAX_CIFRE];
	ifstream fin("anagramabil.in");
	fin >> numar;
	fin.close();
	anagramabil(numar, nrCifre, cifra);
	ofstream fout("anagramabil.out");
	if (!nrCifre)
		fout << "NU";
	else
	{
		fout << "DA\n";
		for (int i = 0; i < nrCifre; i++)
			fout << cifra[i];
	}
	fout.close();
	return 0;
}
void calculeazaFrecventaCifre(long long numar, int frecventaCifra[])
{
	while (numar)
	{
		frecventaCifra[numar%10]++;
		numar /= 10;
	}
}
bool anagrama(long long a, long long b)
{
	int fa[MAX_CIFRE], fb[MAX_CIFRE], i;
	for (i = 0; i <= 9; i++)
		fa[i] = fb[i] = 0;
	calculeazaFrecventaCifre(a, fa);
	calculeazaFrecventaCifre(b, fb);
	for (i = 0; i <= 9; i++)
		if (fa[i] != fb[i])
			return 0;
	return 1;
}
void anagramabil(int numar, int & nrCifre, int cifra[])
{
	for (int i = 2; i <= 9; i++)
	{
		long long produs = numar*i;
		if (anagrama(numar, produs))
			cifra[nrCifre++] = i;
	}
}
