#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    int N, Q;
    cin >> N >> Q;

    dsu uf(N);

    for (int q = 0; q < Q; q++) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 0) {
            uf.merge(u, v);
        } else {
            if (uf.same(u, v)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }    
}
