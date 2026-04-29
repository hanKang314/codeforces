#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        long long t, h, u;
        cin >> t >> h >> u;

        long long ans = 0;

        if (t > 0 && u > 0) {
            long long a = min(t, u);
            ans += a * 4;
            t -= a;
            u -= a; 
        }

        if (t > 0) {
            if (h > 0) {
                long long a = min(t / 2, h);
                t -= 2*a;
                h -= a;
                ans += a * 7;
            }
            if (t == 1) {
                if (h > 0) {
                    h--;
                    t--;
                    ans += 5;
                }
            }
            if (t > 0) {
                ans += 2 * t + 1;
            }
        } else if (u > 0) {
            long long a = 3 * u;
            ans += a + 3 * h;
            h = 0;
            u = 0;
        }

        if (h > 0) {
            ans += 3*h;
        }

        cout << ans << '\n';
    }

    return 0;
}