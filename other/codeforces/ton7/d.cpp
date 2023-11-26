#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    set<int> ones;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] == 1) ones.insert(i);
    }

    for (int q = 0; q < Q; q++) {
        int op;
        cin >> op;
        if (op == 1) {
            int s;
            cin >> s;
            int all_sum = 2 * N - (int)ones.size();
            if (s % 2 == all_sum % 2) {
                if (s <= all_sum) cout << "YES\n";
                else cout << "NO\n";
            } else if (!ones.empty()) {
                int x = max(all_sum - 2*(*ones.begin()) - 1, all_sum - 2*(N-1 - (*ones.rbegin())) -1);
                if (s <= x) cout << "YES\n";
                else cout << "NO\n"; 
            } else {
                cout << "NO\n";
            }
        } else {
            int i, v;
            cin >> i >> v;
            i--;
            if (a[i] == v) continue;
            else if (a[i] == 1) ones.erase(i);
            else ones.insert(i);
            a[i] = v;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
