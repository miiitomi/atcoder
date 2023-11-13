#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> v;

void dfs(string s) {
    v.push_back(s);
    if (s.size() > 10) return;
    char c = '1';
    if (s.size() > 0) c = s[s.size()-1];
    while (c <= '9') {
        dfs(s + c);
        c++;
    }
    return;
}

bool is_ok(ll N, ll B, string s) {
    ll a = 1;
    for (char c : s) a *= (int)(c - '0');

    ll x = B + a;

    if (!(1 <= x && x <= N)) return false;

    if (a == 0) {
        while (x > 0) {
            if (x % 10 == 0) return true;
            x /= 10;
        }
        return false;
    }

    string t;
    while (x > 0) {
        t.push_back((char)(x % 10 + '0'));
        x /= 10;
    }
    sort(t.begin(), t.end());
    return s == t;
}

int main() {
    dfs("");
    v[0] = "0";

    ll N, B;
    cin >> N >> B;

    int ans = 0;
    for (string s : v) {
        ans += is_ok(N, B, s);
    }

    cout << ans << endl;
}
