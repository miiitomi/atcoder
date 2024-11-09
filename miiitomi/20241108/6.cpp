// https://atcoder.jp/contests/abc308/tasks/abc308_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int Q;
    cin >> Q;
    multiset<int> st1, st2;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            auto iter = st1.lower_bound(x);
            if (iter != st1.begin()) {
                auto iter2 = iter;
                iter2--;
                if (iter != st1.end()) {
                    st2.erase(st2.find((*iter)^(*iter2)));
                }
                st2.insert(x^(*iter2));
            }
            if (iter != st1.end()) {
                st2.insert(x ^ (*iter));
            }
            st1.insert(x);
        } else if (t == 2) {
            int x;
            cin >> x;
            auto iter = st1.find(x);
            if (iter == st1.begin()) {
                auto iter2 = iter;
                iter2++;
                if (iter2 != st1.end()) {
                    st2.erase(st2.find(x ^ *iter2));
                }
                st1.erase(iter);
            } else {
                auto iter_l = iter;
                iter_l--;
                st2.erase(st2.find(*iter_l ^ x));
                iter = st1.erase(iter);
                if (iter != st1.end()) {
                    st2.erase(st2.find(x ^ *iter));
                    st2.insert(*iter_l ^ *iter);
                }
            }
        } else {
            cout << *st2.begin() << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
