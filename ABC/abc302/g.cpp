#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> d2{"01", "02", "03", "12", "13", "23"};
vector<string> d3{"012", "013", "021", "023", "031", "032", "123", "132"};
vector<string> d4{"0123", "0132", "0213", "0231", "0312", "0321"};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    vector<int> B = A;
    sort(B.begin(), B.end());

    vector<vector<int>> G(4, vector<int>(4, 0));
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            G[A[i]][B[i]]++;
        }
    }

    ll ans = 0;

    for (string s : d2) {
        int m = 1e+9;
        for (int i = 0; i < (int)s.size(); i++) {
            int x = (int)(s[i] - '0');
            int y = (int)(s[(i+1)%(int)s.size()] - '0');
            m = min(m, G[x][y]);
        }
        ans += m * 1;
        for (int i = 0; i < (int)s.size(); i++) {
            int x = (int)(s[i] - '0');
            int y = (int)(s[(i+1)%(int)s.size()] - '0');
            G[x][y] -= m;
        }
    }
    for (string s : d3) {
        int m = 1e+9;
        for (int i = 0; i < (int)s.size(); i++) {
            int x = (int)(s[i] - '0');
            int y = (int)(s[(i+1)%(int)s.size()] - '0');
            m = min(m, G[x][y]);
        }
        ans += m * 2;
        for (int i = 0; i < (int)s.size(); i++) {
            int x = (int)(s[i] - '0');
            int y = (int)(s[(i+1)%(int)s.size()] - '0');
            G[x][y] -= m;
        }
    }
    for (string s : d4) {
        int m = 1e+9;
        for (int i = 0; i < (int)s.size(); i++) {
            int x = (int)(s[i] - '0');
            int y = (int)(s[(i+1)%(int)s.size()] - '0');
            m = min(m, G[x][y]);
        }
        ans += m * 3;
        for (int i = 0; i < (int)s.size(); i++) {
            int x = (int)(s[i] - '0');
            int y = (int)(s[(i+1)%(int)s.size()] - '0');
            G[x][y] -= m;
        }
    }

    cout << ans << endl;
}
