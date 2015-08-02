// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x <= 0) return x;
//         double pre;
//         double curr = 1;
//         do {
//             pre = curr;
//             curr = pre / 2.0 + x / (pre * 2);
//         } while (abs(pre - curr) > 0.0001);
//         return (int)curr;
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
        unsigned long long begin = 0, end = x , mid, temp;
        while (begin <= end) {
            mid = begin + (end - begin) / 2;
            temp = mid * mid;
            if (temp == x) return mid;
            else if (temp < x) begin = mid + 1;
            else end = mid -1;
        }
        // if (mid * mid > x) {
        //     return end - 1;
        // } else {
        //     return end;
        // }
        return end;
    }
};
