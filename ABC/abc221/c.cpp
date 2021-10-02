#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string N;
    cin >> N;
    int n = (int)N.size();
    ll ans = 1LL;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> a, b;
        for (int j = 0; j < n; j++) {
            int x = (int)(N[j] - '0');
            if (i & (1 << j)) {
                a.push_back(x);
            } else {
                b.push_back(x);
            }
        }
        if ((int)a.size() == 0 || (int)b.size() == 0) {
            continue;
        }
        do {
            if (a[0] == 0) continue;
            ll A = 0;
            ll keta = 1;
            for (int j = (int)a.size()-1; j >= 0; j--) {
                A += keta * a[j];
                keta *= 10;
            }
            do {
                if (b[0] == 0) continue;
                ll B = 0;
                ll keta2 = 1;
                for (int k = (int)b.size()-1; k >= 0; k--) {
                    B += keta2 * b[k];
                    keta2 *= 10;
                }
                ans = max(ans, A*B);
            } while (next_permutation(b.begin(), b.end()));
        } while (next_permutation(a.begin(), a.end()));
    }
    cout << ans << endl;
}
