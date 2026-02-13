#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool hasDuplicate = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                hasDuplicate = true;
                break;
            }
        }
        if (hasDuplicate)
            break;
    }

    long long inv = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                inv++;
        }

    if (!hasDuplicate && inv % 2 == 1)
    {
        cout << "NO\n";
        return 0;
    }

    vector<pair<int, int>> op;
    for (int i = 0; i < n; i++)
    {
        int pos = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[pos])
            {
                pos = j;
            }
        }
        while (pos - i >= 2)
        {
            int temp = arr[pos - 2];
            arr[pos - 2] = arr[pos];
            arr[pos] = temp;
            op.push_back({pos - 1, pos + 1});
            pos -= 2;
        }
        if (pos - i == 1)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << op.size() << endl;
    for (auto it : op)
    {
        cout << it.first << " " << it.second << endl;
    }
}