#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    int N, Q;
    cin >> N >> Q;
    
    fenwick_tree<ll> fw(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        fw.add(i, a);
    }

    for (int q = 0; q < Q; q++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            fw.add(b, c);
        } else {
            cout << fw.sum(b, c) << endl;
        }
    }
}
