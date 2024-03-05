// https://atcoder.jp/contests/abc200/tasks/abc200_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<vector<int>>> v(200);
    v[0].push_back({});
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 200; j++) {
            for (int k = 0; k < (int)v[j].size(); k++) {
                vector<int> w = v[j][k];
                if (!w.empty() && w.back() == i) continue;
                w.push_back(i);
                int l = (j + A[i]) % 200;
                v[l].push_back(w);
                if (v[l].size() >= 3 || (l != 0 && v[l].size() >= 2)) {
                    cout << "Yes\n";
                    cout << v[l].back().size() << " ";
                    for (int x : v[l].back()) cout << x+1 << " ";
                    cout << "\n";
                    v[l].pop_back(); 
                    cout << v[l].back().size() << " ";
                    for (int x : v[l].back()) cout << x+1 << " ";
                    cout << "\n";
                    return;
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
