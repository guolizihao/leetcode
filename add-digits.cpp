// https://leetcode.com/problems/add-digits/

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};

// class Solution {
// public:
//     int addDigits(int num) {
//         int res;
//         while (true) {
//             res = 0;
//             while (num > 0) {
//                 res += num % 10;
//                 num /= 10;
//             }
//             if (res / 10 == 0) {
//                 break;
//             } else {
//                 num = res;
//             }
//         }
//         return res;
//     }
// };
