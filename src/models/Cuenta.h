#include <iostream>
#include <string>
using namespace std;

class Cuenta
{
private:
    double saldo;
    double limiteDeCredito;
    string status;
    string idUsuario;
    string tipoDeCuenta;
    string numeroDeCuenta;

public:
    Cuenta();
    Cuenta(string tipo, double saldo, string status);
    Cuenta(string tipo, double saldo, string status, double limiteCredito);
    /**
     * Realiza la operacion de retirar una cantidad de la cuenta
     * @param double cantidad: la cantidad a retirar
     * @return double: el saldo despues del retiro, si no se realizo el saldo es el mismo
     */
    double retirar(double cantidad);

    /**
     * Realiza la operacion de depositar una cantidad en la cuenta
     * @param double cantidad: la cantidad a depositar
     * @return double: el saldo despues del deposito
     */
    double depositar(double cantidad);
};

Cuenta::Cuenta()
{
    saldo = 0;
    status = "INACTIVA";
    idUsuario = "0";
    tipoDeCuenta = "DEBITO";
    numeroDeCuenta = "0000000000";
}

Cuenta::Cuenta(string tipo, double saldo, string status)
{
    this->tipoDeCuenta = tipo;
    this->saldo = saldo;
    this->status = status;
    if (tipo.compare("CREDITO") == 0)
    {
        this->limiteDeCredito = saldo;
        this->saldo = 0;
    }
}

double Cuenta::retirar(double cantidad)
{
    if (status.compare("INACTIVA") == 0)
    {
        cout << "No se puede retirar de una cuenta incativa" << endl;
        return saldo;
    }
    if (tipoDeCuenta.compare("CREDITO") == 0)
    {
        string desicion = "N";
        cout << "se aplicara comision del 5% al retirar, desea continuar? S/N" << endl;
        cin >> desicion;
        if (desicion.compare("S") == 0)
        {
            if (limiteDeCredito + saldo - (cantidad * 1.05) < 0)
            {
                cout << "No se puede retirar " << (cantidad * 1.05) << " porque el saldo pasa el limite de credito: " << limiteDeCredito << endl;
                return saldo;
            }
            else
            {
                cout << "Limite de credito: " << limiteDeCredito << endl;
                saldo -= cantidad * 1.05;
                return saldo;
            }
        }
        else
        {
            return saldo;
        }
    }
    if (saldo < cantidad)
    {
        cout << "No se puede retirar " << cantidad << " porque el saldo es insuficiente" << endl;
        return saldo;
    }
    saldo -= cantidad;
    cout << "Retiro de " << cantidad << endl;
    if (tipoDeCuenta.compare("CREDITO") == 0)
    {
        cout << "Limite de credito: " << limiteDeCredito << endl;
    }
    return saldo;
};

double Cuenta::depositar(double cantidad)
{
    if (status.compare("INACTIVA") == 0)
    {
        cout << "No se puede depositar a una cuenta inactiva" << endl;
        return saldo;
    }
    if (tipoDeCuenta.compare("CREDITO") == 0)
    {
        if (saldo + cantidad > 0)
        {
            cout << "No se puede depositar a una cuenta de credito con balance positivo, limite de credito: " << limiteDeCredito << endl;
            return saldo;
        }
    }
    cout << "Deposito de " << cantidad << endl;
    return saldo + cantidad;
};