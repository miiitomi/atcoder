#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    if (N <= K && (N%2 == K%2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
        return;
    }

    vector<string> S(2*N + 1, string(2*M+1, '+'));
    S[0][(2*M+1)-2] = 'S';
    S[(2*N+1)-1][(2*M+1)-2] = 'G';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            S[2*i+1][2*j+1] = 'o';
            if (j != M-1) S[2*i+1][2*j+1+1] = '|';
            if (i != N-1) {
                if (j != M-1) S[2*i+2][2*j+1] = '-';
                else S[2*i+2][2*j+1] = '.';
            }
        }
    }

    K -= N;
    int i = 0, j = M-1;
    while (K > 0) {
        if (i+1 <= N-1) {
            S[2*i + 2][2*j + 1] = '-';
            S[2*i + 1][2*j] = '.';
            S[2*i + 3][2*j] = '.';
            S[2*i + 2][2*j-1] = '.';

            j--;
            if (j == 0) {
                i += 2;
                j = M-1;
            }
        } else {
            S[2*(i-1)+1][2*(j-2)+1+1] = '|';
            S[2*(i-1)+2][2*(j-2)+1] = '.';
            S[2*(i-1)+2][2*(j-2)+3] = '.';
            S[2*(i-1)+3][2*(j-2)+2] = '.';
            j -= 2;
        }
        K -= 2;
    }

    for (string s : S) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
