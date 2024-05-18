#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A, B;
vector<int> V;

void mover_win(int s, bool takahashi_turn) {
    V[s] = 0;
    for (int i = 0; i < N; i++) {
        if (s & (1 << i)) continue;
        for (int j = i+1; j < N; j++) {
            if (s & (1 << j) || (A[i] != A[j] && B[i] != B[j])) continue;
            if (V[s + (1 << i) + (1 << j)] == -1) mover_win(s + (1 << i) + (1 << j), !takahashi_turn);
            if (V[s + (1 << i) + (1 << j)] == 0) {
                V[s] = 1;
            }
        }
    }
    return;
}

void solve() {
    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    V.resize((1 << N), -1);
    mover_win(0, true);

    if (V[0]) cout << "Takahashi\n";
    else cout << "Aoki\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
