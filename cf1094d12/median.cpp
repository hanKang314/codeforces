#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<int> sa = a;
        sort(sa.begin(), sa.end());
        int m = sa[n / 2];

        vector<int> B(n+1, 0), C(n+1, 0);
        for (int i = 0; i < n; i++) {
            B[i+1] = B[i] + (a[i] >= m ? 1 : -1);
            C[i+1] = C[i] + (a[i] >  m ? 1 : -1);
        }

        const int NEG_INF = INT_MIN / 2;
        vector<int> dp(n+1, NEG_INF);
        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            int start = (j % 2 == 1) ? 0 : 1;
            for (int i = start; i < j; i += 2) {
                if (dp[i] == NEG_INF) continue;
                if (B[j] >= B[i] + 1 && C[j] <= C[i] - 1) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        cout << dp[n] << '\n';
    }

    return 0;
}