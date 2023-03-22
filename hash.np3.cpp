#include<iostream>
#include<climits>
#include <list>
#include<iomanip>
#include<cstring>
using namespace std;

struct dado
{
	int status; // 0:vazio, 1:ocupado, 2:removido
	int k; // info a ser armazenada
};
//hash auxiliar
int h1(int k, int m)
{
	int j;

	j = k % m;

	if(j < 0)

		return j = j + m;

	else return j;
}
//hash  auxiliar
int h2(int k, int m)
{

	int j;

	j = 1 + k % (m - 1);

	if(j < 0)

		return j = j + m;

	else return j;

}
//double hashing
int hash(int k, int m, int i)
{
	int j;

	j = (h1(k, m) + (i * h2(k, m))) % m;

	return j;
}
//hash insert
int hash_insert(dado t[], int m, int k)
{
	
	int j; //posição onde a chave k vai ser inserida
	int i; //numero de tentativas

	i = 0;
	do
	{
		j = hash(k, m, i);
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else i = i + 1;
	}
	while(i != m);
	return -1; // vetor cheio

}
//hash search
int hash_search(dado t[], int m, int k)
{
	int j = 0;
	int i = 0;

	do
	{
		j = hash(k, m, i);
		if(t[j].k == k)
			return j;
		i++;
	}
	while(t[j].status != 0 && i != m);
	return -1;

}

//hash remove
int hash_remove(dado t[], int m, int k)
{
	int pos;

	pos = hash_search(t, m, k);
	if( pos != -1)
	{
		t[pos].k = -1;
		t[pos].status = 2;
		return 0;
	}
	else return -1;
}

// funçao de saida de dados
void hashcout(dado t[], int m, int k)
{
    for(int i = 0; i < m; i++)
        cout << t[i].k << " ";
}

int main()
{
	int k;//chave
    int m;//tamanho 
	int i; //contador
	int p;//posicao
	
    string op = "A";

    cin >> m;
    dado t[m];

    for(i = 0; i < m; i++)
    {
        t[i].k = -1;
        t[i].status = 0;
    }
    while(op != "X"){

        cin >> op;

        if (op == "I"){
            cin >> k;
            hash_insert(t,m,k);
        }else{
            if (op == "P"){
                cin >> k;
                p = hash_search(t,m,k);
                cout << p << endl;
            }else{
                if (op == "R"){
                    cin >> k;
                    p = hash_remove(t,m,k);
                    cout << p << endl;
                }else{
                    if (op == "L")
                        hashcout(t,m,k);
                }
            }
        }

    }

	return 0;

}
