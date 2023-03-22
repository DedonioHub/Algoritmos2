#include<iostream>
#include<cmath>

using namespace std;

struct dado
{
	int k; // info a ser armazenada
	int status; // 0:vazio, 1:ocupado

};

//função hash auxiliar
int h1(int k, int m)
{
	int j;

	j = k % m;

	if(j < 0)

		return j = j + m;

	else return j;
}

//função hash 2 auxiliar
int h2(int k, int m)
{

	int j;

	j = 1 + k % (m - 1);

	if(j < 0)

		return j = j + m;

	else return j;

}
//função double hashing
int hash(int k, int m, int i)
{
	int j;

	j = (h1(k, m) + (i * h2(k, m))) % m;

	return j;
}
int hash_insert(dado t[], int k, int m)
{
	int i; //numero de tentativas
	int j; //posição onde a chave k vai ser inserida

	i = 0;
	do
	{
		j = hash(k, m, i);
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else i = i + 1;
	}
	while(i != m);
	return -1; // vetor cheio

}
//função hash de procura
int hash_search(dado t[], int m, int k)
{
	int i = 0;//contador
	int j = 0;//contador

	do
	{
		j = hash(k, m, i);
		if(t[j].k == k)
			return j;
		i++;
	}
	while(t[j].status != 0 && i != m);

	return -1;

}
int main()
{
	int k; //chave
	int m;//tamanho do vetor
	int i;//contador
	dado t[100];//vetor
	int x;//chave a ser procurada
	int pos;//posicao onde x esta

	//Ler m(tamanho do vetor)
	cin >> m;

	//inicializar o vetor
	for(i = 0; i < m; i++)
	{
		t[i].k = -1;
		t[i].status = 0;
	}

	//Ler elementos e armazenar no vetor
	//0 para terminar
	cin >> k;
	while(k != 0)
	{
		hash_insert(t, k, m);
		cin >> k;
	}
	
	cin >> x;
	pos = hash_search(t, m, x);
	if(pos == -1)
		cout << "Chave " << x<< " nao encontrada" << endl;
	else cout << "Chave " << x << " encontrada na posicao " << pos +3 << endl;


	return 0;
}