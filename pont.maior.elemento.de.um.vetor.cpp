#include<iostream>

using namespace std;

int main()
{
	int *vetor; //vetor ponteiro
	int n; // tamanho
	int i; // contador
	int *p; // ponteiro para leitura
	long int maior = -9999999999999999; // variavel de verificacao de maior

	cin >> n;

	vetor = new int[n]; // alocacao

	p = vetor;

	for(i = 0; i < n; i++) // leitura e verificacao
	{
		cin >> *p;
		if(*p > maior)
			maior = *p;
		p++;
	}

	cout << maior << endl;

	delete []vetor;
	return 0;
}
