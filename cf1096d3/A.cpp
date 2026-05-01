#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int a, b;
        cin >> a >> b;

        bool isOdd = false;
        if ((a % 2 == 1) && (b % 2 == 1)) isOdd = true;

        cout << (isOdd? "NO" : "YES") << '\n';
    }

    return 0;
}