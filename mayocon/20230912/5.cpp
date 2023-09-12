#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

string AGCT = "AGCT";
set<string> NG{
    "AGCA", "AGCC", "AGCG", "AGCT", "AAGC", "CAGC", "GAGC", "TAGC",
    "ACGA", "ACGC", "ACGG", "ACGT", "AACG", "CACG", "GACG", "TACG",
    "GACA", "GACC", "GACG", "GACT", "AGAC", "GGAC", "CGAC", "TGAC",
    "AAGC", "ACGC", "AGGC", "ATGC", "AGAC", "AGGC", "AGCC", "AGTC"
};

int main() {
    int N;
    cin >> N;

    if (N == 3) {
        cout << 61 << endl;
        return 0;
    }

    vector<string> X;
    X.reserve(4*4*4*4);
    for (int i0 = 0; i0 < 4; i0++) {
        for (int i1 = 0; i1 < 4; i1++) {
            for (int i2 = 0; i2 < 4; i2++) {
                for (int i3 = 0; i3 < 4; i3++) {
                    string S = "xxxx";
                    S[0] = AGCT[i0];
                    S[1] = AGCT[i1];
                    S[2] = AGCT[i2];
                    S[3] = AGCT[i3];
                    X.push_back(S);
                }
            }
        }
    }

    vector<map<string, ll>> V(N+1);
    for (string x : X) {
        if (!NG.count(x)) V[4][x] = 1;
        else V[4][x] = 0;   
    }

    for (int i = 5; i <= N; i++) {
        for (string x : X) V[i][x] = 0;
        for (string x : X) {
            if (V[i-1][x] == 0) continue;
            for (char c : "AGCT") {
                string y = "____";
                for (int i = 0; i < 3; i++) y[i] = x[i+1];
                y[3] = c;
                if (!NG.count(y)) V[i][y] = (V[i][y] + V[i-1][x]) % MOD;
            }
        }
    }

    ll ans = 0;
    for (string x : X) {
        ans = (ans + V[N][x]) % MOD;
    }

    cout << ans << endl;
}
