#include <iostream>
using namespace std;

int n;

int f(int n) 
{
    int a = 0, b = 1;
    while (n --)
    {
        int c = a + b;
        a = b, b = c;
    }
    return a;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        cout << f(i) << ' ';
    return 0;
}
