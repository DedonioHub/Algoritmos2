#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int *vetor; //vetor ponteiro
	int n; // tamanho
	int i; // contador
	int *p; // ponteiro para leitura
	int pp = 0; // variavel de verificacao de pares positivos

	cin >> n;

	vetor = new int[n]; // alocacao

	p = vetor;

	for(i = 0; i < n; i++) // leitura e verificacao
	{
		cin >> *p;
		if(*p >= 0 & *p % 2 == 0)
			pp++;
		p++;
	}
	cout << pp << endl;


	delete []vetor;
	return 0;
}