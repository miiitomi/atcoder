#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    unordered_map<int, vector<ll>> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        M[a].push_back(i);
    }

    ll ans = 0;
    for (auto iter = M.begin(); iter != M.end(); iter++) {
        int a = iter->first;
        for (ll i = 0; i < (int)M[a].size()-1; i++) {
            ans += (1+i)*((ll)M[a].size()-i-1)*(M[a][i+1]-1-M[a][i]);
        }
    }

    cout << ans << endl;
}
