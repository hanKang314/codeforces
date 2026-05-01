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

        string s;
        cin >> s;

        int lcnt = 0;
        int rcnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') lcnt++;
            else rcnt++;
        }

        cout << ((lcnt == rcnt) ? "YES" : "NO") << '\n';
    }

    return 0;
}
