#include <bits/stdc++.h>
using namespace std;

bool ok(string s) {
    int n = (int)s.size();
    stack<int> st;
    for (int j = 0; j < n; j++) {
        if (s[j] == '(') st.push(j);
        else if (st.empty()) return false;
        else st.pop();
    }
    if (st.empty()) return true;
    else return false;
}

int main() {
    int N;
    cin >> N;
    int K = (1 << N);
    vector<string> ans;
    for (int i = 0; i < K; i++) {
        string S;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) S = S + '(';
            else S = S + ')'; 
        }
        if (ok(S)) ans.push_back(S);
    }
    sort(ans.begin(), ans.end());
    for (string s : ans) {
        cout << s << endl;
    }
}
