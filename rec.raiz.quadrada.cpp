#include<iostream> 
#include<cmath> 
#include<iomanip>  
using namespace std;

//função p calculo da raiz
double raiz (double x, double x0, double e)
{
    if(e >= abs( pow(x0, 2) - x))
        return x0;
    else
        return raiz(x, (pow(x0, 2) + x) / (2 * x0), e);
}

int main()
{
    double x;  //número do qual se quer calcular a raiz
    double x0; //estimativa inicial para raiz de x
    double e;  //limitante superior para o erro
    double r;  //resp
    
    cin >> x >> x0 >> e;
    
    r = raiz(x, x0, e);
    
    cout << fixed << setprecision(4) << r << endl;
    
    return 0;
}