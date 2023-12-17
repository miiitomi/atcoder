#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string add(string s, string t) {
    if (s.size() < t.size()) swap(s, t);
    for (int i = 0; i < t.size(); i++) {
        s[s.size()-1-i] = s[s.size()-1-i] + (int)(t[t.size()-1-i] - '0');
    }
    return s;
}

bool cmp(string &s, string &t) {
    if (s.size() != t.size()) return s.size() < t.size();
    else return s < t;
}

int main() {
    set<string> S;
    int N;
    cin >> N;

    string s = "", t = "", u = "";
    for (int i = 0; i < 120; i++) {
        s.push_back('1');
        t = "";
        u = "";
        for (int j = 0; j < 120; j++) {
            t.push_back('1');
            u = "";
            for (int k = 0; k < 120; k++) {
                u.push_back('1');
                string x = add(s, add(t, u));
                S.insert(x);
            }
        }
    }

    vector<string> v;
    for (string s : S) v.push_back(s);
    sort(v.begin(), v.end(), cmp);
    cout << v[N-1] << endl;
}
