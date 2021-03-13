#include <bits/stdc++.h>
using namespace std;

int g2(int x) {
    string s = to_string(x);
    int m = s.size();
    vector<int> V(m);
    for (int i = 0; i < m; i++) {
        V.at(i) = (int)s.at(i);
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < m; i++) {
        s.at(i) = (char)V.at(i);
    }
    int ans = stoi(s);
    return ans;
}

int g1(int x) {
    string s = to_string(x);
    int m = s.size();
    vector<int> V(m);
    for (int i = 0; i < m; i++) {
        V.at(i) = (int)s.at(i);
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < m; i++) {
        s.at(i) = (char)V.at(m-i-1);
    }
    int ans = stoi(s);
    return ans;
}

int f(int x) {
    return g1(x) - g2(x);
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(K+1);
    a.at(0) = N;

    for (int i = 0; i < K; i++) {
        a.at(i+1) = f(a.at(i));
    }
    cout << a.at(K) << endl;
}