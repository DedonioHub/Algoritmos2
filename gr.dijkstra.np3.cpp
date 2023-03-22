#include <climits>
#include <iostream>
#include <list>
#include <cstring>
#include <iomanip>

using namespace std;

struct no
{
	int v; // info de adjacencia
	int peso; // peso da aresta
};

// Cria aresta do vértice origem u ao vértice destino v, com peso p
void cria_aresta(list<no>adj[], int u, int v, int peso)
{
	no aux;
	aux.v = v;
	aux.peso = peso;
	adj[u].push_back(aux);
	aux.v = u;
	adj[v].push_back(aux);
}

void  dijkstra	(list <no> adj[], int inicio)
{

    string cidades[] = {"Frankfurt","Manhein","Wurzburg","Stuttgart","Karlsruhe","Erfut","Nurnberg","Kassel","Augsburg","Munchen"};

	list<no>::iterator p; // iterador
	int custo = 0; // custo dos pesos do grafo
	int destino; // variavel de destino
	bool intree[1000]; // verifica se o vertice ja foi gerado
	int weight; // peso
	int parent[1000]; // pai
	int u; // varievel auxliar, origem
	int v; // variavel auxiliar, destino
	int dist; // variavel auxiliar para menor peso
	int distance[1000]; // peso mínimo aresta
	
	for(u = 0; u < 10; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}

	distance[inicio] = 0;
	v = inicio;

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

		v = 0;
		dist = INT_MAX;

		for(u = 0; u < 10; u++)
		{
			if(intree[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
		}
	}

    cout <<"Estradas a serem restauradas: "<<endl;
	for(int i =1;i<10;i++){
	    p = adj[i].begin();
        cout << cidades[parent[i]] << " - ";
	    for(u = 1; u < 10; u++)
	    {
		    if(p->peso == distance[i] )
		    {
		        destino = i;
		    }
		    p++;
	    }
	    custo = custo + distance[i];
	    cout << cidades[destino] <<endl;
	}

	cout <<"Total: "<< custo <<" km"<<endl;
	cout<<endl;

}

int main (int argc, char* argv[])
{

    string cidades[] = {"Frankfurt","Manhein","Wurzburg","Stuttgart","Karlsruhe","Erfut","Nurnberg","Kassel","Augsburg","Munchen"};
	int peso; 
    list <no> adj[1000]; //lista de adjacencias
	int u; // variavel auxiliar, origem
	int v; // variavel auxiliar, destino
    string inicial;
    int ini;
	list<no>::iterator p;

    cin >> inicial;

    for(int i = 0; i < 10; i++)
        if(inicial == cidades[i]) ini = i;

    cin >> u >> v >> peso;

    while(u != -1 && v != -1 && peso != -1)
	{
		cria_aresta(adj, u, v, peso);
		cin >> u >> v >> peso;
	}

    dijkstra(adj, ini);

    return 0;
}