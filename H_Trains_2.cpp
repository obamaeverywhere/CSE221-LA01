#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string train[n];
    string destination[n];
    string time[n];
    int serial[n];
    string word;
    for (int i = 0; i < n; i++)
    {
        cin >> train[i] >> word >> word >> word >> destination[i] >> word >> time[i];
        serial[i] = i;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool swapped = false;
            
            if (train[i] != train[j])
            {
                int minimum = min(train[i].length(), train[j].length());
                bool flag = false;

                // char by char check
                for (int k = 0; k < minimum; k++)
                {
                    char c1 = train[i][k];
                    char c2 = train[j][k];
                    if (c1 == c2)
                        continue;

                    if ((c1 >= 'a' && c1 <= 'z') && !(c2 >= 'a' && c2 <= 'z'))
                    {
                        flag = true;
                        break;
                    }
                    else if (!(c1 >= 'a' && c1 <= 'z') && (c2 >= 'a' && c2 <= 'z'))
                    {
                        swapped = true;
                        flag = true;
                        break;
                    }
                    else
                    {
                        // same case
                        if (c1 > c2)
                            swapped = true;
                        flag = true;
                        break;
                    }
                }
                
                // Check prefix
                if (!flag)
                {
                    if (train[i].length() > train[j].length())
                        swapped = true;
                }
            }
            else
            {
                int t1 = (time[i][0] - '0') * 10 + (time[i][1] - '0');
                t1 = t1 * 60;
                t1 += (time[i][3] - '0') * 10 + (time[i][4] - '0');

                int t2 = (time[j][0] - '0') * 10 + (time[j][1] - '0');
                t2 = t2 * 60;
                t2 += (time[j][3] - '0') * 10 + (time[j][4] - '0');

                if (t1 < t2)
                    swapped = true;
                else if (t1 == t2)  // If times equal, preserve input order
                {
                    if (serial[i] > serial[j])
                        swapped = true;
                }
            }

            if (swapped)
            {
                swap(train[i], train[j]);
                swap(destination[i], destination[j]);
                swap(time[i], time[j]);
                swap(serial[i], serial[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << train[i] << " will depart for "
             << destination[i] << " at "
             << time[i] << "\n";
    }
}