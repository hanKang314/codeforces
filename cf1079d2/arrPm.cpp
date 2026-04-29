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
        vector<int> p(n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> temp1(n);
        vector<int> temp2(n);
        temp1 = temp2 = p;
        while (true) {
            temp1 = temp2;
            bool changed = false;
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    if (a[0] == temp1[0] || a[0] == temp1[1]) {
                        if (temp2[0] != a[0]) changed = true;
                        temp2[0] = a[0];
                        temp1 = temp2;
                       
                    }
                } else if (i == n-1) {
                    if (a[n-1] == temp1[n-1] || a[n-1] == temp1[n-2]) {
                        if (temp2[n - 1] != a[n - 1]) changed = true;
                        temp2[n-1] = a[n-1];
                        temp1 = temp2;
                    }
                } else {
                    if (a[i] == temp1[i] || a[i] == temp1[i-1] || a[i] == temp1[i+1]) {
                        if (temp2[i] != a[i]) changed = true;
                        temp2[i] = a[i];
                        temp1 = temp2;
                        
                    }
                }
            }
            if (!changed) break;
        }
        cout << (temp2 == a ? "YES" : "NO") << '\n';
    }

    return 0;

}