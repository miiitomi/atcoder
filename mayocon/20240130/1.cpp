// https://atcoder.jp/contests/abc241/tasks/abc241_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    multiset<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.insert(a);
    }
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        if (A.count(b)) A.erase(A.find(b));
        else {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
