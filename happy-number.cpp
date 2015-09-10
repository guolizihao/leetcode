// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        unordered_set<int> s;
        while (n != 1 && s.find(n) == s.end()) {
            s.insert(n);
            int temp = 0;
            while (n) {
                temp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = temp;
        }
        return n == 1 ? true : false;
    }
};
