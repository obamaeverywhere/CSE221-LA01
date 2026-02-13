#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    bool flag = true;

    while(flag) {
        flag = false;
        for (int i = 0; i + 1 < n;i++) {
            if(arr[i]>arr[i+1] && arr[i]%2==  arr[i+1]%2) {
                //swap
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = true;
            }
        }
    }
    for(int x : arr) {
        cout << x << " ";
    }
}