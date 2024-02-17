// https://atcoder.jp/contests/abc314/tasks/abc314_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    string S;
    cin >> N >> M >> S;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
    }

    vector<deque<char>> V(M);
    for (int i = 0; i < N; i++) {
        V[C[i]].push_back(S[i]);
    }

    for (int i = 0; i < M; i++) {
        if (V[i].empty()) continue;
        V[i].push_front(V[i].back());
        V[i].pop_back();
    }

    for (int i = 0; i < N; i++) {
        cout << V[C[i]].front();
        V[C[i]].pop_front();
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
