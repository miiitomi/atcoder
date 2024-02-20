// https://atcoder.jp/contests/abc263/tasks/abc263_c
#include <bits/stdc++.h>
using namespace std;

int N, M;
set<vector<int>> S;

void rec(vector<int> v) {
    if (v.size() == N) {
        S.insert(v);
        return;
    }
    int a = 0;
    if (!v.empty()) a = v.back();
    for (int b = a+1; b <= M; b++) {
        v.push_back(b);
        rec(v);
        v.pop_back();
    }
    return;
}

void solve() {
    cin >> N >> M;
    rec(vector<int>{});
    for (vector<int> v : S) {
        for (int a : v) cout << a << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
