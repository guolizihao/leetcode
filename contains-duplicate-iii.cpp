// https://leetcode.com/problems/contains-duplicate-iii/

// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//         map<long long, int> m;
//         int j = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             // the size of m euqals to k 
//             if (i - j > k && m[nums[j]] == j) m.erase(nums[j++]);
//             auto lb = m.lower_bound(nums[i] - t);
//             if (lb != m.end() && abs(lb->first - nums[i]) <= t) return true;
//             m[nums[i]] = i;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> bst;
        for (int i = 0; i < nums.size(); ++i) {
            if (bst.size() == k + 1) bst.erase(bst.find(nums[i - k - 1]));
            auto lb = bst.lower_bound(nums[i] - t);
            if (lb != bst.end() && *lb - nums[i] <= t) return true;
            bst.insert(nums[i]);
        }
        return false;
    }
};
