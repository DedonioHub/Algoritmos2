#include<list>
#include<iomanip>
#include <cmath>
#include<iostream>

using namespace std;

struct no
{
	int peso;
	int v;

};
void cria_aresta(list<no>adj[], int u, int v, int orientado)
{
	no aux;
	aux.v = v;
	adj[u].push_back(aux);
	
	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}

void ordenacao_topologica(int f[], int nVertices)
{
	int vet[100];
	int u;
	int i;
	int uai;

	for(i = 0; i < nVertices; i++)
		vet[i] = i;
	for(u = 0; u < nVertices; u++)
		for(i = u + 1; i < nVertices; i++)
			if(f[vet[u]] < f[vet[i]])
			{
				uai = vet[u];
				vet[u] = vet[i];
				
				vet[i] = uai;
			}
	for(u = 0; u < nVertices; u++)
		cout << vet[u] << " ";
	cout << endl;
}

void dfs_visit(list<no> adj[], int nVertices, char color[], int  pi[], int f[], int d[], int &time, int u)
{
	list<no>::iterator v;

	color[u] = 'g'; // White vertex u has just been discovered.
	d[u] = ++time;
	
	for(v = adj[u].begin(); v != adj[u].end(); v++)
	{
		if(color[v->v] == 'w')
		{
			pi[v->v] = u;
			dfs_visit(adj, nVertices, color, pi, f, d, time, v->v);
		}
	}
	color[u] = 'b'; // Blacken u; it is finished.
	f[u] = ++time;
}
void dfs(list<no> adj[], int nVertices)
{
	int pi[100]; //pais
	char color[100]; //cor
	int time; // tempo
	int i;
	int f[100]; //finalizr o vertice
	int d[100]; //descoberta do vertice


	for(i = 0; i < nVertices; i++)
	{
		color[i] = 'w';
		pi[i] = -1;
	}
	time = 0;
	for(i = 0; i < nVertices; i++)
		if(color[i] == 'w')
			dfs_visit(adj, nVertices, color, pi, f, d, time, i);

	ordenacao_topologica(f, nVertices);
}
int main()
{
	int x;//vertice
	int orient;// 0: não orientado; 1: orientado
	list<no> adj[10]; //lista de adjacencias
	int nVertices;
	int y;// aresta
	list<no>::iterator it; //iterador

	cin >> nVertices;
	cin >> orient;
	cin >> x >> y;
	
	while(x != -1 && y != -1)
	{
		
		cria_aresta(adj, x, y, orient);
		cin >> x >> y;
	}

	//chamando a função dfs
	dfs(adj, nVertices);
	return 0;
}
