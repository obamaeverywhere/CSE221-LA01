#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int first;
        cin >> first;
        bool flag = true;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            if(first>x)
                flag = false;
            first = x;
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}