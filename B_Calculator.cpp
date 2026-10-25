#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string w, op;
        long long a, b;
        cin >> w >> a >> op >> b;
        if (op == "+")
            cout << a + b << "\n";
        else if (op == "-")
            cout << a - b << "\n";
        else if (op == "*")
            cout << a * b << "\n";
        else if (op == "/")
            cout << fixed << setprecision(10) << (double)a / (double)b << "\n";
        else if (op == "%")
            cout << a % b << "\n";
        else if (op == "&")
            cout << (a & b) << "\n";
        else if (op == "|")
            cout << (a | b) << "\n";
        else if (op == "^")
            cout << (a ^ b) << "\n";
        else if (op == "<<")
            if (a == 0 || b >= 63)
                cout << 0 << "\n";
            else
                cout << (a << b) << "\n";
        else if (op == ">>")
            if (b >= 63)
                cout << 0 << "\n";
            else
                cout << (a >> b) << "\n";
    }
}