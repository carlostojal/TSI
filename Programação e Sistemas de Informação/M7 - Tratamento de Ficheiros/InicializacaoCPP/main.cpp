#include <iostream>
#include <string>
using namespace std;

#include "Retangulo.h"

int main()
{
    std::cout << "Hello world!" << endl;
    int x=100;
    int y=20;
    float soma = x + y;
    cout << "Soma de " <<x<< " com " <<y<< " = " <<soma<< endl;
    float comp,larg;
    Retangulo ret;
    cout << "Comprimento: ";
    cin >> comp;
    cout << "Largura: ";
    cin >> larg;
    cout << "Area: " << ret.AreaRect(comp,larg) << endl;
}
