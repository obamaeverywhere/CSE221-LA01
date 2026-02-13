#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        string s;
        double a, b;
        char c;

        cin >> s >> a >> c >> b;

        double ans=0.0;
        if (c=='+')
            ans = a + b;
        else if(c=='-')
            ans = a - b;
        else if(c=='*')
            ans = a * b;
        else
            ans = a / b;
        cout <<fixed <<setprecision(6) << ans << endl;
    }
}
