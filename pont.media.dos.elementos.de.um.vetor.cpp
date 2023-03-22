#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int *vetor; //vetor ponteiro
	int n; // tamanho
	int i; // contador
	int j; // contador
	int *p; // ponteiro para leitura
	double media = 0;

	cin >> n;

	vetor = new int[n]; // alocacao

	p = vetor;

	for(i = 0; i < n; i++) // leitura
	{
		cin >> *p;
		p++;
	}
    
    p = vetor;
    
	for(j = 0; j < n; j++) //fazendo a média
	{
		media = media + *p;
	    *p++;
	}

	cout << fixed << setprecision(2) << media / (n * 1.0) << endl;

	delete []vetor;
	return 0;
}
