// https://atcoder.jp/contests/abc117/tasks/abc117_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    for (int i = 0; i < M; i++) cin >> X[i];

    if (N >= M) {
        cout << 0 << endl;
        return 0;
    }

    sort(X.begin(), X.end());

    vector<int> V;
    for (int i = 1; i < M; i++) {
        V.push_back(X[i]-X[i-1]);
    }
    sort(V.begin(), V.end());

    N--;
    while (N--) {
        V.pop_back();
    }

    ll ans = 0;
    for (int v : V) ans += v;

    cout << ans << endl;
}
