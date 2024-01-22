// https://atcoder.jp/contests/abc276/tasks/abc276_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    vector<int> p;
    while (!v.empty()) {
        reverse(p.begin(), p.end());
        p.push_back(v.back());
        v.pop_back();
        reverse(p.begin(), p.end());
        vector<int> q = p;
        sort(q.begin(), q.end());
        if (p == q) continue;
        int x = p[0] - 1;
        bool ok = false;
        while (!ok) {
            for (int a : p) if (x == a) ok = true;
            if (!ok) x--;
        }
        vector<int> r;
        for (int a : p) if (a != x) r.push_back(a);
        sort(r.begin(), r.end());
        r.push_back(x);

        while (!v.empty()) {
            r.push_back(v.back());
            v.pop_back();
        }

        reverse(r.begin(), r.end());
        for (int a : r) cout << a << " ";
        cout << endl;
        return;
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
