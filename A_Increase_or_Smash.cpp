#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    
    std::set<int> distinct_elements;
    
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        distinct_elements.insert(val);
    }
    
    // Get the number of distinct elements, k
    int k = distinct_elements.size();
    
    // The minimum number of operations is k increases and k-1 smashes
    // Total operations = k + (k-1) = 2k - 1
    // This formula works for k=1 as well (1 increase, 0 smashes)
    int result = 2 * k - 1;
    
    // If k is 0 (empty array case, though constraints say n>=1), handle it
    // But based on constraints n>=1, a_i>=1, k will be at least 1
    if (k == 0) {
        result = 0;
    }
    
    std::cout << result << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}