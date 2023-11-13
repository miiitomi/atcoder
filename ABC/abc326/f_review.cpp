#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<ll, ll> make_map(vector<ll> &A, int l, int r) {
    vector<ll> v;
    unordered_map<ll, ll> mp;

    if (l == r) {
        mp[0] = 0;
        return mp;
    }

    for (int i = l; i < r; i++) v.push_back(A[i]);
    int N = v.size();
    for (int s = 0; s < (1 << N); s++) {
        ll x = 0;
        for (int i = 0; i < N; i++) {
            if (s & (1 << i)) x += v[i];
            else x -= v[i];
        }
        mp[x] = s;
    }
    return mp;
}

bool is_positive(ll X, vector<ll> &A, vector<bool> &v) {
    int N = A.size();
    unordered_map<ll, ll> mp0 = make_map(A, 0, N/2), mp1 = make_map(A, N/2, N);
    for (auto iter = mp0.begin(); iter != mp0.end(); iter++) {
        ll x = iter->first;
        ll y = X - x;
        if (mp1.count(y)) {
            for (int i = 0; i < N/2; i++) {
                if (mp0[x] & (1 << i)) v[i] = true;
            }
            for (int i = 0; i < N - N/2; i++) {
                if (mp1[y] & (1 << i)) v[i + N/2] = true;
            }
            return true;
        }
    }
    return false;
}

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A, B;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (i % 2 == 0) A.push_back(a);
        else B.push_back(a);
    }

    vector<bool> a((int)A.size(), false), b((int)B.size(), false);
    bool bl = is_positive(Y, A, a) && is_positive(X, B, b);

    if (!bl) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
 
    int s = 0;
    for (int i = 0; i < (int)A.size(); i++) {
        if (a[i]) {
            if (s == 0) cout << 'L';
            else cout << 'R';
            s = 1;
        } else {
            if (s == 0) cout << 'R';
            else cout << 'L';
            s = 3;
        }
        if (i == (int)b.size()) break;
        if (b[i]) {
            if (s == 1) cout << 'R';
            else cout << 'L';
            s = 0;
        } else {
            if (s == 1) cout << 'L';
            else cout << 'R';
            s = 2;
        }
    }
    cout << endl;
}
