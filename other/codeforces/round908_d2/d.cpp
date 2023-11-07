#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());

    vector<int> c;
    c.reserve(N+M);

    while (!a.empty() || !b.empty()) {
        if (a.empty()) {
            c.push_back(b.back());
            b.pop_back();
        } else if (b.empty()) {
            c.push_back(a.back());
            a.pop_back();
        } else {
            if (a.back() <= b.back()) {
                c.push_back(b.back());
                b.pop_back();
            } else {
                c.push_back(a.back());
                a.pop_back();
            }
        }
    }

    for (int x : c) cout << x << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
