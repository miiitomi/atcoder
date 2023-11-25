#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> f(vector<ll> &X) {
    vector<pair<ll, ll>> v;
    ll left = 0;
    ll right = (int)X.size() - 1;

    v.push_back(make_pair(X[right] - X[left], 0));
    while (right != left) {
        if (left+1 < (int)X.size()-right || (left+1 == (int)X.size()-right) && abs(X[left] - X[left+1]) <= abs(X[right] - X[right-1])) {
            ll c = v.back().second + (left + 1)*abs(X[left] - X[left+1]);
            left++;
            v.push_back(make_pair(X[right] - X[left], c));
        } else {
            ll c = v.back().second + ((int)X.size() - right)*abs(X[right] - X[right-1]);
            right--;
            v.push_back(make_pair(X[right] - X[left], c));
        }
    }
    sort(v.begin(), v.end());
    return v;
}

ll g(vector<pair<ll,ll>> &v, ll x) {

    int left = -1, right = v.size();
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (v[mid].first >= x) {
            right = mid;
        } else {
            left = mid;
        }
    }

    if (right == v.size()) return 0;
    if (v[right].first == x) return v[right].second;

    right--;
    ll a = v[right].first, y1 = v[right].second;
    right++;
    ll b = v[right].first, y2 = v[right].second;

    ll c = (y2 - y1) / (b - a);
    return y1 + c*abs(x - a);
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<pair<ll,ll>> v = f(X), w = f(Y);

    ll left = -1, right = 1e+9;
    while (right - left > 1) {
        ll mid = (right + left) / 2;

        ll a = g(v, mid), b = g(w, mid);
        if (a + b <= K) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;
    return 0;
}
