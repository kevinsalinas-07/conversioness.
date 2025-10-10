#include <iostream>

using namespace std;

int main()
{
    int i, n;

    cout << "Digite un numero " << endl;
    cin >> n;

    for (i = 1; i <= 20; i++)
    {

        cout << n << "x" << i << "=" << n * i << endl;
    }

    return 0;
}
