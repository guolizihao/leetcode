// https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> array(n);
        array[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        for (int i = 1; i < n; ++i) {
            array[i] = min(array[index2] * 2, min(array[index3] * 3, array[index5] * 5));
            if (array[index2] * 2 == array[i]) ++index2;
            if (array[index3] * 3 == array[i]) ++index3;
            if (array[index5] * 5 == array[i]) ++index5;
        }
        return array[n - 1];
    }
};
