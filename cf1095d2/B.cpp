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

        int ans = 0;
        vector<int> p(n);
        cin >> p[0];
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            if (gcd(p[i], p[i-1]) == abs(p[i] - p[i-1])) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}