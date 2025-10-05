#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int ops = a[0]; //first element=> need a[0] Increase
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i-1])
                ops += a[i] - a[i-1];
        }

        cout << ops << endl;
    }

    return 0;
}