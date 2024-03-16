#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, H, W;
    cin >> N >> H >> W;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    for (int s = 0; s < (1 << N); s++) {
        int tmp_area = 0;
        vector<int> v;
        for (int i = 0; i < N; i++) {
            if (!(s & (1 << i))) continue;
            v.push_back(i);
            tmp_area += A[i] * B[i];
        }

        if (tmp_area != H*W) continue;

        int K = (int)v.size();
        vector<vector<bool>> S;

        do {
            for (int t = 0; t < (1 << K); t++) {
    
                S.assign(H, vector<bool>(W, true));
                int ss = 0;
                for (int j = 0; j < K; j++) {
                    int a = A[v[j]], b = B[v[j]];
                    if (t & (1 << j)) swap(a, b);
                    int ps = ss / W, pt = ss % W;
                    for (int l = 0; l < a; l++) {
                        for (int r = 0; r < b; r++) {
                            if (ps+l < H && pt+r < W) S[ps+l][pt+r] = false;
                        }
                    }
                    while (ss < H*W && !S[ss/W][ss%W]) ss++;
                }
                if (ss == H*W) {
                    cout << "Yes\n";
                    return;
                }
            }
        } while (next_permutation(v.begin(), v.end()));
    }

    cout << "No\n";
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
