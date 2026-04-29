#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        vector<long long> T(n);
        T[0] = 0;
        for (int i = 1; i < n; i++) {
            T[i] = T[i - 1] + a[i - 1];
        }

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            return T[x] > T[y];
        });

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[idx[i]] = i + 1;
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}