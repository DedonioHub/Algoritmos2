#include<iostream> 
using namespace std;
//função recursiva p calculo da pot
int pot( int n, int a)
{
    if(n == 0)
        return 1;
    else
        return a * pot(n - 1, a);
}

int main()
{
    int n; // expoente
    int a; // base
    int r; // resp
    
    cin >> a >> n;
    
    r = pot(n, a);
    
    cout<< r << endl;
    
    return 0;
}