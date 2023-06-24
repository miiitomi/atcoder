#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    string ans = "";
    bool open = false;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        char c = S[i];

        if (open) {
            if (c == ')') {
                int last = v[(int)v.size()-1];
                v.pop_back();
                while ((int)ans.size() > last) ans.pop_back();
                if ((int)v.size() == 0) open = false;
            } else if (c == '(') {
                ans.push_back(c);
                v.push_back((int)ans.size()-1);
            } else {
                ans.push_back(c);
            }
        } else {
            if (c == '(') {
                ans.push_back(c);
                v.push_back((int)ans.size()-1);
                open = true;
            } else {
                ans.push_back(c);
            }
        }
    }
    cout << ans << endl;
}
