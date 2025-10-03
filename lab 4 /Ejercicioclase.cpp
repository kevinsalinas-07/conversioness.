#include <iostream>
using namespace std;
int main()
{

    int numsecreto = 5, numintento;
    do
    {
        cout << "ingresa un numero entero";
        cin >> numintento;
        if (numintento == numsecreto)
        {
            cout << "Adinivinaste el numero! ";
        }
        else if (numintento > numsecreto)
        {
            cout << "El numero ingresado es muy alto";
        }
        else
        {
            cout << " El numero ingresado es muy bajo";
        }

    } while (numsecreto != numintento);

    return 0;
}