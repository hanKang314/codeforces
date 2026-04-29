#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int x;
        cin >> x;
        
        bool isPossible = false;
        for (int i = 1; i <= 81; i++) {
            int k = x + i;
            int sum = k % 10;
            for (int j = 2; j <= 9; j++) {
                int a = pow(10, j);
                int b = pow(10, j-1);
                sum += (k % a) / b;
            }
            sum += k / 1000000000;
            if (x == k - sum) {
                isPossible = true;
                break;
            }
        }

        cout << (isPossible ? 0 : 10) << '\n';
    }
    return 0;
}