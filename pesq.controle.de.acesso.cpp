#include<iostream>

using namespace std;


// função de busca binária
int binaria(int tamanho, int x,int vetor[])
{
	bool achou; // variavel para busca sendo X o numero procurado
	int baixo, meio, alto; //var aux

	baixo = 0;
	alto = tamanho - 1;
	achou = false;

	while((baixo <= alto) && (achou == false))
	{
		meio = (baixo + alto) /	2;
		if (x < vetor[meio])
			alto = meio - 1;
		else if(x > vetor[meio])
			baixo =  meio + 1;
		else
			achou = true;
	}
	if(achou)
		return meio;
	else
		return -1;
}
int main()
{
	
	int x; // numero a ser procurado
	int num; //numero de entrada
	int vetor[100]; // tabela
	int tamanho; // tamanho da tabela

	int i = 0; // contador



	cin >> num;
	while(num != -1)
	{
		vetor[i] = num;
		cin >> num;
		i++;
	}
	tamanho = i;
	cin >> x;

	if(binaria(tamanho, x, vetor) == -1)
		cout<<"Nao Possui acesso"<<endl;
	else
		cout<<"Possui acesso"<<endl;

		return 0;
}