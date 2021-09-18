#include <bits/stdc++.h>
using namespace std;

string X;

bool cmp(const string &a, const string &b) {
    int m = min((int)a.size(), (int)b.size());
    for (int i = 0; i < m; i++) {
        int s = X.find(a[i]);
        int t = X.find(b[i]);
        if (s < t) return true;
        else if (t < s) return false;
    }
    return ((int)a.size() <= (int)b.size());
}

int main() {
    cin >> X;
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    sort(S.begin(), S.end(), cmp);

    for (string s : S) {
        cout << s << endl;
    }
}
