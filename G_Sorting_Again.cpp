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
        int id[n];
        int marks[n];
        int pos[n];
        for (int i = 0; i < n; i++)
        {
            cin >> id[i];
            pos[i] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> marks[i];
        }       
        for (int i = 0; i < n;i++) {
            int best = i;
            for (int j = i + 1; j < n;j++) {
                if (marks[j] > marks[best] ||
                   (marks[j] == marks[best] && id[j] < id[best])) {
                    best = j;
                }
            }
            if(best!=i) {
                swap(marks[i], marks[best]);
                swap(id[i], id[best]);
                swap(pos[i], pos[best]);
            }
        }
        bool visited[n] = {false};
        int swapCount = 0;
        for (int i = 0; i < n;i++) {
            if(visited[i] || pos[i]==i) {
                continue;
            }
            int cnt = 0;
            int j = i;
            while (!visited[j])
            {
                visited[j] = true;
                j = pos[j];
                cnt++;
            }
            if(cnt>1) {
                swapCount += cnt - 1;
            }
        }
        cout << "Minimum swaps: " << swapCount << endl;
        for (int i = 0; i < n; i++) {
            cout << "ID: " << id[i] << " Mark: " << marks[i] << endl;
        }
    }
}