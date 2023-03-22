#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void insercaoDireta(int vetor[], int tamanho)
{
    int i, j; // contadores
    int chave;
    for (j = 1; j < tamanho; j++)
    {
        chave = vetor[j];
        i = j - 1;
        while ((i >= 0) && (vetor[i] > chave))
        {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = chave;
    }
}

int main()
{
    int vetor[100];
    int tamanho;
    int i = 0; // contador
    int aux;   // variavel auxiliar para ler o vetor

    // lendo vetor com aux e while !=0
    cin >> aux;

    while (aux != 0)
    {
        vetor[i] = aux;
        cin >> aux;
        i++;
    }
    tamanho = i;

    // rodando a função insertion sort
    insercaoDireta(vetor, tamanho);

    // mostrando vetor com a logica de saida invertida

    for (i = tamanho; i >= 0; i++)
        cout << vetor[i] << " " << endl;

    return 0;
}