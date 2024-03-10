#include <iostream>
#include <string>
#include "./models/Cuenta.h"
using namespace std;

int main()
{
    Cuenta cuentaDePablito = Cuenta("CREDITO", 5000, "ACTIVA");
    cout << "Saldo despues del retiro - " << cuentaDePablito.retirar(2000) << endl;
    cout << "Saldo despues del deposito - " << cuentaDePablito.depositar(2000) << endl;
    return 0;
};