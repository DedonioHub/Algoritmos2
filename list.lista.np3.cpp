#include<iostream>
#include<climits>
#include <list>
#include<iomanip>
using namespace std;

//recebe um ponteiro para uma lista ligada cujo campo info dos nós armazena a renda
//em reais dos funcionários e retorna o número que ganham menos que X
int nAbaixo(list<int> lista, int X)
{
	list<int>::iterator p;//iterador para varrer a lista
	int i;

	i=0;
	for(p = lista.begin(); p != lista.end(); p++)  //varrendo a lista
		if(*p < X)
			i++;
	return i;
}
int main(){
    
	int x; //salários
	list<int> lista; //ponteiro
	

	//logica fila inserindo
	cin >> x;
	while(x != 0)
	{
	    lista.push_back(x);
		cin >> x;

	}
	cin >> x;
	
	cout << nAbaixo(lista, x) << endl;

	//retirando
	while(!lista.empty())
	{
		x = *lista.begin();
		lista.pop_front();
	}

	return 0;
}