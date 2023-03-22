#include<iostream>
#include<cmath>

using namespace std;

struct dado
{
	int k; // info a ser armazenada
	int status; // 0:vazio, 1:ocupado, 2:removido

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

//função hash que insere elementos no vetor
int hash_insert(dado t[], int m, int k)
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

// remove a chave k da tabela t
// retorna 0  se a chave for removida, -1 caso contrario
int hash_remove(dado t[], int m, int k)
{
	int pos; //posição de k no vetor t

	pos = hash_search(t, m, k);
	if( pos != -1)
	{
		t[pos].k = -1;
		t[pos].status = 2;
		return 0;
	}
	else return -1;
}

int main()
{
	int k; //chave
	int m;//tamanho do vetor
	int i;//contador
	dado t[100];//vetor
	int s;//chave a ser procurada
	int r;//chave a ser removida
	int op;//opção do menu
	int pos; //posição de k no vetor

	//Ler m(tamanho do vetor)
	cin >> m;

	//inicializar o vetor
	for(i = 0; i < m; i++)
	{
		t[i].k = -1;
		t[i].status = 0;
	}
	//Ler opção do menu
	cin >> op;

	//Menu
	while(op != 5)
	{
		switch(op)
		{
		case 1:
			cin >> k;
			pos = hash_insert(t, m, k);
			break;

		case 2:

			cin >> s;
			pos = hash_search(t, m, s);
			cout << pos << endl;
			break;

		case 3:

			cin >> r;
			pos = hash_remove(t, m, r);
			break;

		case 4:

			for(i = 0; i < m; i++)
				cout << t[i].k << " ";
			break;

		}
		cin >> op;
	}
	return 0;
}
