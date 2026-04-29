#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> cp(k+1, 0);
        for (int i = 1; i <= k; i++) cin >> cp[i];

        vector<int> b(n, 0);
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            return b[x] > b[y];
        });

        queue<int> q;
        int m = 0;

        for (int i = 0; i < n; i++) {
            while (b[idx[i]] != k+1) {
                m++;
                q.push(idx[i]);
                b[idx[i]]++;
            }
        }

        cout << m << '\n';
        if (m == 0) cout << '\n';
        else {for (int i = 0; i < m; i++) {
            cout << q.front() + 1 << " \n"[i == m-1];
            q.pop();
        }}
    }

    return 0;
}