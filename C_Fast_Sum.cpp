#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long ans=(n*(n+1))/2;

        cout << ans << endl;
    }
}