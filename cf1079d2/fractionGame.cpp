#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long p, q;
        cin >> p >> q;
        bool isBob = false;
        if (q > p) {
            if (3 * p >= 2 * q) {
                isBob = true;
            }
        }

        cout << (isBob ? "Bob" : "Alice") << '\n';
    }
    return 0;
}