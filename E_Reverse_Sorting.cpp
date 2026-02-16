#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;

    int arr[n];
    vector<int> arr2;

    for (int i = 0; i < n;i++) {
        cin >> arr[i];
    }

    bool sorted = true;
    bool repeated = true;
    while(repeated) {
        repeated = false;
        for (int i = 0; i < n-2;i++) {
            if(arr[i+2]<arr[i]) {
                int temp = arr[i + 2];
                arr[i + 2] = arr[i];
                arr[i] = temp;
                arr2.push_back(i+1);
                repeated = true;
            }
        }
    }
    for (int i = 0; i < n-1;i++) {
        for (int j = i + 1; j < n;j++) {
            if(arr[i]>arr[j]) {
                sorted = false;
                break;
            }
        }
    }
    if(!sorted) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << arr2.size() << endl;
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " " << arr2[i] + 2 << endl;
    }
}