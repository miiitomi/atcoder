#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
string S;

bool is_ok(ll R) {
    ll m = M, r = R;
    for (char c : S) {
        if (c == '0') {
            m = M;
            r = R;
        } else if (c == '1') {
            if (m > 0) m--;
            else r--;
            if (r < 0) return false;
        } else {
            r--;
            if (r < 0) return false;
        }
    }
    return true;
}


int main() {
    cin >> N >> M;
    cin >> S;

    for (ll R = 0; R <= N; R++) {
        if (is_ok(R)) {
            cout << R << endl;
            return 0;
        }
    }
}
