#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    set<ll> st;
    while (N != 1) {
        if (st.contains(N)) {
            cout << "No\n";
            return 0;
        }
        st.insert(N);
        ll m = 0;
        while (N > 0) {
            m += (N % 10) * (N % 10);
            N /= 10;
        }
        N = m;
    }
    cout << "Yes\n";
}
