#include<iostream>
using namespace std;

void insercaoDireta(int vetor[], int tamanho)
{
	int i, j; // contadores
	int chave;
	for (j = 1; j < tamanho; j++)
	{
		chave = vetor[j];
		i = j - 1;
		while ((i >= 0) && (vetor[i] > chave))
		{
			vetor[i + 1] = vetor[i];
			i = i - 1;
		}
		vetor[i + 1] = chave;
	}
}

int main ()
{
	int vetor[100];
	int tamanho;
	int i = 0; // contador
	int j; // contador
	int numero; // numeros a serem inseridos no vetor

	cin >> numero;
	while(numero != 0)
	{
		vetor[i] = numero;
		cin >> numero;
		i++;
	}

	tamanho = i;
	insercaoDireta(vetor, tamanho);

	for(j = tamanho - 1; j > -1; j--)
		cout << vetor[j] << " ";

	return 0;
}
