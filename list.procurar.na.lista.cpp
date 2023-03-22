#include<iostream>
#include<list>

using namespace std;
bool encontrar(list<float>lista, int x)
{
	list<float>::iterator p;
	int aux = 0;
	for(p = lista.begin(); p != lista.end(); p++)
	{
		if(*p == x)
			aux++;
	}
	if(aux != 0)
		return true;
	else return false;
}

int main()
{
	int x;
	int n;

	list<float>lista; // PONTEIRO PARA FILA

	cin >> x;
	lista.push_back(x);
	while(x != 0)
	{
		cin >> x;
		lista.push_back(x); // inserindo no começo
	}

	cin >> n;

	encontrar(lista, n);

	if(encontrar(lista, n) == true)
		cout << "Encontrado" << endl;
	else cout << "Nao encontrado" << endl;

	return 0;
}