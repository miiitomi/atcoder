// https://atcoder.jp/contests/abc324/tasks/abc324_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    string T;
    cin >> N >> T;
    vector<int> A, B;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        int tmp = 0;
        for (int j = 0; j < (int)S.size() && tmp < (int)T.size(); j++) {
            if (S[j] == T[tmp]) tmp++;
        }
        A.push_back(tmp);
        tmp = T.size()-1;
        for (int j = (int)S.size()-1; j >= 0 && tmp >= 0; j--) {
            if (S[j] == T[tmp]) tmp--;
        }
        B.push_back(T.size()-1-tmp);
    }
    sort(B.begin(), B.end());
    ll ans = 0;
    for (int a : A) {
        ans += distance(lower_bound(B.begin(), B.end(), T.size()-a), B.end());
    }

    cout << ans << endl;
}
