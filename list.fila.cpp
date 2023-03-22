#include<iostream>
#include<list>

using namespace std;

int main()
{
	int x;// var aux
	int i;//contador

	list<int>fila; // PONTEIRO PARA FILA

	//lendo os valores
	for(i=0;i<4;i++)
	{
		cin >> x;
		fila.push_back(x);
	}

	while(!fila.empty())
	{
		// Mostrando dado inserido na fila
		x = *fila.begin();
		cout << x << " ";
		fila.pop_front(); // remove o primeiro nó na fila
	}
	return 0;

}
