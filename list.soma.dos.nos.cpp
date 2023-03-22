#include<iostream>
#include<list>

using namespace std;

int soma(list<int> lista)
{
	list<int>::iterator p;
	int aux = 0;

	for(p = lista.begin(); p != lista.end(); p++)
		aux = aux + *p;

	return aux;
}

int main()
{
	int x;

	list<int>lista; // PONTEIRO PARA FILA

	cin >> x;
	lista.push_back(x);
	while(x != 0)
	{
		cin >> x;
		lista.push_back(x); // inserindo no começo
	}

	cout << soma(lista) << endl;

	return 0;
}