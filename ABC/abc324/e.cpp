#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mae_check(string &S, string &T) {
    int cnt=0, i=0, j=0;
    while (i < (int)S.size() && j < (int)T.size()) {
        if (S[i] == T[j]) {
            cnt++;
            i++;
            j++;
        } else {
            i++;
        }
    }
    return cnt;
}

int uchiro_check(string &S, string &T) {
    int cnt=0, i=(int)S.size()-1, j=(int)T.size()-1;
    while (i >= 0 && j >= 0) {
        if (S[i] == T[j]) {
            cnt++;
            i--;
            j--;
        } else {
            i--;
        }
    }
    return cnt;
}

int main() {
    int N;
    string T;
    cin >> N >> T;

    vector<int> mae(N, 0), ushiro(N, 0), v(N, 0);
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        mae[i] = mae_check(S, T);
        ushiro[i] = uchiro_check(S, T);
    }
    v = ushiro;

    sort(v.begin(), v.end());
    ll ans = 0;

    for (int i = 0; i < N; i++) {
        auto iter = lower_bound(v.begin(), v.end(), (int)T.size()-mae[i]);
        ans += distance(iter, v.end());
    }

    cout << ans << endl;
}
