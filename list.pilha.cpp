#include<iostream>
#include<list>

using namespace std;

int main()
{
	int x;
	int i;
	list<int>pilha; // PONTEIRO PARA PILHA

	for(i = 0; i < 4; i++)
	{
		cin >> x;
		pilha.push_front(x);
	}

	while(!pilha.empty())
	{
		// Mostrando dado inserido na pilha
		x = *pilha.begin();
		cout << x << " " ;
		pilha.pop_front(); // remove o primeiro nó da pilha
	}
	return 0;

}