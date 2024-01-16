#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    N--;

    vector<ll> x(100, 0);
    for (int i = 0; N > 0; i++) {
        x[i] = N % 5;
        N /= 5;
    }
    while (x.back() == 0) x.pop_back();

    string s = "02468";

    if (x.empty()) cout << 0 << endl;
    else {
        reverse(x.begin(), x.end());
        for (int i = 0; i < (int)x.size(); i++) {
            cout << s[x[i]];
        }
        cout << endl;
    }
}
