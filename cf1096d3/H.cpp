#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n + 1, 0), order;
        order.reserve(n);

        stack<int> st;
        st.push(1);
        parent[1] = -1;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                st.push(v);
            }
        }

        vector<int> leaf_cnt(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            leaf_cnt[u] = (adj[u].size() <= 1);

            for (int v : adj[u]) {
                if (parent[v] == u) {
                    leaf_cnt[u] += leaf_cnt[v];
                }
            }
        }

        ll base = 0;
        for (int u = 2; u <= n; u++) {
            if (leaf_cnt[u] % 2 == 1) {
                base++;
            }
        }

        int total_leaves = leaf_cnt[1];
        if (total_leaves % 2 == 0) {
            cout << base << '\n';
            continue;
        }

        vector<int> path_delta(n + 1, 0);
        ll ans = LLONG_MAX;

        if (adj[1].size() <= 1) {
            ans = min(ans, base);
        }

        for (int u : order) {
            if (u == 1) continue;

            int edge_delta = (leaf_cnt[u] % 2 == 1 ? -1 : 1);
            path_delta[u] = path_delta[parent[u]] + edge_delta;

            if (adj[u].size() <= 1) {
                ans = min(ans, base + path_delta[u]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
