#include<iostream>
#include<cmath>
using namespace std;

//função que fará o h'(k) mod m
int hash_aux(int k, int m)
{
	int r;

	r = k % m;

	if(r < 0)

		return r = r + m;

	else return r;
}

//função hash com a sondagem linear
int hash1(int k, int i, int m)
{
	int r;

	r = hash_aux(k, m);


    return (r + i) % m;

}

int main()
{

	int i;//contador
	int k;//chave
	int m;//tamanho do vetor
	int vet[100];// vetor de hash

	cin >> k >> m ;
	for(i = 0; i < m ; i++)

		vet[i] = hash1(k, i, m);



	for(i = 0; i < m ; i++)

		cout << vet[i] << " ";

	return 0;
}