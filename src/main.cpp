#include <iostream>
#include <string>
#include "models/Banco.h"
using namespace std;

int main()
{
    Banco bancoUno = Banco("12932");
    cout << "ID del banco: " << bancoUno.getId() << endl;
    return 0;
};