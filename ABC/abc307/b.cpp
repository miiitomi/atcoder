#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;

bool is_kaibun(string s1, string s2) {
    string t = s1 + s2;

    for (int i = 0; i < (int)t.size() / 2; i++) {
        if (t[i] != t[(int)t.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int k = 0; k < N; k++) cin >> S[k];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            if (is_kaibun(S[i], S[j])) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
