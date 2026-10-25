#include <bits/stdc++.h>
using namespace std;

struct Train {
    string name, dest, time;
};

// returns true if a must come strictly before b
bool before(const Train &a, const Train &b) {
    if (a.name != b.name) return a.name < b.name;
    return a.time > b.time; // later departure first
}

int main() {
    int n;
    cin >> n;
    Train v[105];
    string w1, w2, w3, w4;
    for (int i = 0; i < n; i++) {
        cin >> v[i].name >> w1 >> w2 >> w3 >> v[i].dest >> w4 >> v[i].time;
    }

    // insertion sort (stable)
    for (int i = 1; i < n; i++) {
        Train key = v[i];
        int j = i - 1;
        while (j >= 0 && before(key, v[j])) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }

    for (int i = 0; i < n; i++) {
        cout << v[i].name << " will departure for " << v[i].dest
             << " at " << v[i].time << "\n";
    }
    return 0;
}