// https://atcoder.jp/contests/abc230/tasks/abc230_b
#include <bits/stdc++.h>
using namespace std;

string S = "oxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxx";

int main() {
    string T;
    cin >> T;
    for (int i = 0; i < 3; i++) {
        bool ok = true;
        for (int j = 0; j < (int)T.size(); j++) {
            if (S[i+j] != T[j]) ok = false;
        }
        if (ok) {
            cout <<"Yes" << endl;
            return 0;
        }
    }

    cout << "No" <<  endl;
}
