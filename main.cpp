#include <bits/stdc++.h>

using namespace std;

int main() {
    // Read all input numbers (tree nodes in level order followed by cnt)
    vector<int> nums;
    int val;
    while (cin >> val) {
        nums.push_back(val);
    }
    if (nums.empty()) return 0;
    int cnt = nums.back();
    nums.pop_back(); // remaining are node values

    // To find the cnt-th largest value, sorting is sufficient (O(n log n))
    sort(nums.begin(), nums.end(), greater<int>());
    if (cnt <= 0 || cnt > (int)nums.size()) return 0;
    cout << nums[cnt - 1] << '\n';
    return 0;
}

