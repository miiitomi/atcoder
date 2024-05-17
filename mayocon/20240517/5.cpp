// https://atcoder.jp/contests/abc200/tasks/abc200_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] %= 200;
    }
    vector<vector<vector<int>>> V(200);
    V[0].push_back({});

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 200; j++) {
            int k = (j + A[i]) % 200;
            for (vector<int> v : V[j]) {
                if (!v.empty() && v.back() == i) continue;
                v.push_back(i);
                if (V[k].size() >= 2 || (k != 0 && V[k].size() >= 1)) {
                    vector<int> w = V[k].back();
                    cout << "Yes\n";
                    cout << w.size() << " ";
                    for (int x : w) cout << x+1 << " ";
                    cout << "\n";
                    cout << v.size() << " ";
                    for (int x : v) cout << x+1 << " ";
                    cout << "\n";
                    return;
                } else {
                    V[k].push_back(v);
                }
            }
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
