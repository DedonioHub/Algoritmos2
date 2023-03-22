#include<iostream>
#include<locale.h>

using namespace std;


int sequencial(int vet[], int tam, int x)
{
	int i; // contador
	int posicao; // posição
	int entrada; // numero a ser atribuido ao vetor
	for(i = 0; i < tam; i++)
	{
		entrada = vet[i];
		if(entrada == x)
		{
			posicao = i;
		}
	}
	if(entrada == x)
		return posicao;
	else return -1;
}

int main()
{
	int vet[1000]; //vetor a ser preenchido
	int tam; // tamanho do vetor
	int x; // numero a ser procurado
	int i = 0; // contador
	int entrada; // numero a ser atribuido ao vetor


	//inserir elementos no vetor
	cin >> entrada;
	while(entrada != -1)
	{
		vet[i] = entrada;
		cin >> entrada;
		i++;
	}
	tam = i;

	//inserir elemento a ser procurado
	cin >> x;
	setlocale(LC_ALL, "Portuguese");
	//chamar a função e escrever saida compativel ao URI
	if(sequencial(vet, tam, x) != -1)
		cout << x << " encontrado na posicao " << sequencial(vet, tam, x) << endl;
	else cout << x << " não foi encontrado" << endl;


	return 0;
}





