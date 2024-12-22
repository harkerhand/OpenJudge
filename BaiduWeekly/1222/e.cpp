// 15/20 WA

#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    vector<int> NBP;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    for (int i = 0; i < N; i++)
    {
        bool flag = true;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                A[i][j] = 1;
                continue;
            }
            int ans = A[i][j] * A[j][i];
            A[i][j] = ans;
            A[j][i] = ans;
            if (A[i][j] == 0)
                flag = false;
        }
        if (flag)
            NBP.push_back(i);
    }
    vector<int> Left, Right;
    vector<int> position(N, 0);
    // 0 未访问 1 左 2 右
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (find(NBP.begin(), NBP.end(), i) != NBP.end())
            continue;
        else
        {
            position[i] = 1;
            Left.push_back(i);
            q.push(i);
            break;
        }
    }
    if (q.empty())
    {
        cout << "Yes" << endl;
        cout << N / 2 + N % 2 << endl;
        return 0;
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (position[u] == 0)
            continue;
        if (position[u] == 1)
        {
            for (int v = 0; v < N; v++)
            {
                if (v == u)
                    continue;
                if (A[u][v] == 0)
                {
                    if (position[v] == 2)
                        continue;
                    if (position[v] == 0)
                    {
                        position[v] = 2;
                        Right.push_back(v);
                        q.push(v);
                    }
                    else if (position[v] == 1)
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
        else
        {
            for (int v = 0; v < N; v++)
            {
                if (v == u)
                    continue;
                if (A[u][v] == 0)
                {
                    if (position[v] == 1)
                        continue;
                    if (position[v] == 0)
                    {
                        position[v] = 1;
                        Left.push_back(v);
                        q.push(v);
                    }
                    else if (position[v] == 2)
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    // Left.erase(
    //     remove_if(Left.begin(), Left.end(),
    //               [&NBP](int x)
    //               { return find(NBP.begin(), NBP.end(), x) != NBP.end(); }),
    //     Left.end());

    // Right.erase(
    //     remove_if(Right.begin(), Right.end(),
    //               [&NBP](int x)
    //               { return find(NBP.begin(), NBP.end(), x) != NBP.end(); }),
    //     Right.end());

    // print Left
    // for (int i = 0; i < Left.size(); i++)
    // {
    //     cout << Left[i] << " ";
    // }
    // cout << endl;
    // // print Right
    // for (int i = 0; i < Right.size(); i++)
    // {
    //     cout << Right[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < NBP.size(); i++)
    // {
    //     cout << NBP[i] << " ";
    // }
    if (NBP.size() == 0)
    {
        cout << "Yes" << endl;
        cout << max(Left.size(), Right.size()) << endl;
    }
    else
    {
        cout << "Yes" << endl;
        int delta = ((Left.size() - Right.size()) >= 0) ? (Left.size() - Right.size()) : (Right.size() - Left.size());
        if (NBP.size() >= delta)
        {
            delta = NBP.size() - delta;
            cout << max(Left.size(), Right.size()) + delta / 2 + delta % 2 << endl;
        }
        else
            cout << max(Left.size(), Right.size()) << endl;
    }
}