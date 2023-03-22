#include<iostream>
#include<list>
using namespace std;

struct no
{
	int v; // info de adjacencia
	int peso; // peso da aresta
};
// Cria aresta do vértice origem u ao vértice destino v, com peso p

void cria_aresta(list<no>adj[], int u, int v, int p)
{
	no aux; // variavel auxiliar p inserir o no na lista

	aux.v = v;
	aux.peso = p;
	adj[u].push_back(aux);
	aux.v = u;
	adj[v].push_back(aux);

}
// Obtem o percurso em largura do grafo em analise

void bfs(list<no>adj[], int nVertices, int s)
{
	int p[100];// armazena os pais
	int u;// variavel auxiliar p identificação dos vertices
	int v;// variavel auxiliar p identificação dos vertices
	int state[100];// nao descoberto= -1, descoberto =0, processado =1
	list<no>::iterator it;// ponteiro p lista de adjacencias
	list<int> Q;// fila auxiliar

	for(int i = 0; i < nVertices; i++)
		if(i != s)
		{
			state[i] = -1;// nao descoberto
			p[i] = -1;
		}
	state[s] = 0;// descoberto
	p[s] = -1;
	Q.push_back(s) ;

	while(!Q.empty())
	{
		u = *Q.begin();
		Q.pop_front();
		cout << u << endl;
		for(it = adj[u].begin(); it != adj[u].end(); it++)
		{
			v = it->v;
			cout << u << " " << v << endl;
			if(state[v] == -1)
			{
				state[v] = 0;// descoberto
				p[v] = u;
				Q.push_back(v);
			}
		}
		state[u] = 1; // processado
	}
}

int main()
{
	int u; //vertice de origem
	int nVertices; //numero de vertices do grafo
	int peso; //Peso da aresta
	int s; //vertice inicial
	int v; //vertice de destino
	list <no> adj[100]; //vetor das listas de adjacencias

	cin >> nVertices;
	cin >> s;
	cin >> u >> v >> peso;

	while(u != -1 && v != -1 && peso != -1)
	{
		cria_aresta(adj, u, v, peso);
		cin >> u >> v >> peso;
	}

	bfs(adj, nVertices, s);

	return 0;
}