#include <climits>
#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

struct no
{
	int v; // info de adjacencia
	int peso; // peso da aresta
};

// Cria aresta do vértice origem u ao vértice destino v, com peso p
void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux; // variavel auxiliar p inserir o no na lista

	aux.v = v;
	aux.peso = p;
	adj[u].push_back(aux);
	aux.v = u;
	adj[v].push_back(aux);

}

//Função arvore geradora minina
void prim(list<no>adj[], int nVertices, int start)
{
	list<no>::iterator p; // iterador
	int custo = 0; // custo dos pesos do grafo
	int destino; // variavel de destino
	bool intree[1000]; // verifica se o vertice ja foi gerado
	int weight; // peso
	int parent[1000]; // pai
	int u; // varievel aucliar, origem
	int v; // variavel auxiliar, destino
	int dist; // variavel auxiliar para menor peso
	int distance[1000]; // peso mínimo aresta

	for(u = 0; u < nVertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}
	v = start;
	distance[start] = 0;

	while(intree[v] == false)
	{
		intree[v] = true;
		for(p = adj[v].begin(); p != adj[v].end(); p++)
		{
			destino = p->v;
			weight = p->peso;
			if(distance[destino] > weight && intree[destino] == false)
			{
				distance[destino] = weight;
				parent[destino] = v;
			}
		}
		dist = INT_MAX;
		v = 0;

		for(u = 0; u < nVertices; u++)
		{

			if(intree[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
		}
	}
	cout << "Arvore Geradora Minima:" << endl;
	for(int i = 1; i < nVertices; i++)
	{
		p = adj[i].begin();
		cout << parent[i] << " ";
		for(u = 1; u < nVertices; u++)
		{
			if(p->peso == distance[i])
				destino = i;
			p++;
		}
		cout << destino << endl;

		custo = custo + distance[i];
	}
	cout << "Custo: " << custo << endl;
	cout << endl;

}

int main(){
	list <no> adj[1000]; //lista de adjacencias
	int s; // start, vertice inicial
	int orientado; // orientado (1) ou não orientado (0)
	int p; // peso
	int nVertices; // numero de vertices
	int u; // variavel auxiliar, origem
	int v; // variavel auxiliar, destino

	cin >> nVertices;
	cin >> orientado;
	cin >> s;
	cin >> u >> v >> p;

	while(p != -1 && u != -1 && v != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}

	prim(adj, nVertices, s);

	return 0;
}