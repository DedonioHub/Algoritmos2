#include<iostream>
#include<list>

using namespace std;
struct no
{
	int v; //vertice adjacente
	int peso; //peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int peso, int orientado)
{
	no aux; //variavel para inserir a aresta na lista  de adjacencias

	aux.v = v;
	aux.peso = peso;

	adj[u].push_back(aux);
	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

}

int main()
{
	list<no>adj[10]; //lista de adjacencias
	int nVertices = 3; //numero de vertices do grafo
	int u, v; // vertices de origem  e destino de uma aresta u=origem v=destino
	int peso; //peso da aresta
	int orientado = 0; //1:orientado  0: nao orientado
	int i; //contador
	list<no>::iterator p; //iterador para varrer lista de adjacencias

	cin >> nVertices;
	cin >> orientado;
	
	cin >> u >> v >> peso;
	while(u != -1 && v != -1 && peso != -1)
	{
		cria_aresta(adj, u, v, peso, orientado);
		cin >> u >> v >> peso;
	}

	for(i = 0; i < nVertices; i++)
		for(p = adj[i].begin(); p != adj[i].end(); p++)
			cout << i << " " << p->v << " " << p->peso << endl;

	return 0;
}
