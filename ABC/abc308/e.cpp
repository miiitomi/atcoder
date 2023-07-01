#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    string S;
    cin >> S;

    vector<vector<int>> M(N, vector<int>(3, 0));
    vector<vector<int>> X(N, vector<int>(3, 0));
    for (int i = 0; i < N; i++) {
        if (i > 0) M[i] = M[i-1];
        if (S[i] == 'M') M[i][A[i]]++;
    }
    for (int i = N-1; i >= 0; i--) {
        if (i < N-1) X[i] = X[i+1];
        if (S[i] == 'X') X[i][A[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] != 'E') continue;

        for (int x = 0; x < 3; x++) {
            int y = A[i];
            for (int z = 0; z < 3; z++) {
                ll l = 0;
                while (x == l || y == l || z == l) l++;
                ll h = (ll)M[i][x] * (ll)X[i][z];
                ans += h*l;
            }
        }
    }

    cout << ans << endl;
}
