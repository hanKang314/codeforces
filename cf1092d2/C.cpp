#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        long long p, q;
        cin >> n >> k >> p >> q;

        vector<long long> a(n);
        for (auto& it : a) cin >> it;

        vector<long long> f0(n + 1), f1(n + 1), g(n + 1);

        for (int i = 1; i <= n; i++) {
            f0[i] = a[i - 1] % p % q;
            f1[i] = a[i - 1] % q % p;
            g[i] = g[i - 1] + min(f0[i], f1[i]);
        }

        for (int i = 1; i <= n; i++) {
            f0[i] += f0[i - 1];
            f1[i] += f1[i - 1];
        }

        long long ans = LLONG_MAX;
        for (int i = k; i <= n; i++) {
            long long use_p = f0[i] - f0[i - k];
            long long use_q = f1[i] - f1[i - k];
            ans = min(ans, min(use_p, use_q) + g[i - k] + g[n] - g[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}
