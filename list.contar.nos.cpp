#include<iostream>
#include<list>

using namespace std;

int contar(list<int> lista)
{
	list<int>::iterator p;
	int aux = 0;

	for(p = lista.begin(); p != lista.end(); p++)
		aux++;

	return aux;
}

int main()
{
	int x;

	list<int>lista; // PONTEIRO PARA FILA

	cin >> x;

	while(x != 0)
	{
		lista.push_back(x); 
		cin >> x;
	}

	cout << contar(lista) << endl;

	return 0;
}