// https://leetcode.com/problems/ugly-number/

class Solution {
public:
    // bool isUgly(int num) {
    //     vector<int> array(1,1);
    //     int index2 = 0, index3 = 0, index5 = 0;
    //     int i = 0;
    //     while(num > array[i]) {
    //         array.push_back(0);
    //         ++i;
    //         array[i] = min(array[index2] * 2, min(array[index3] * 3, array[index5] * 5));
    //         if (array[index2] * 2 == array[i]) ++index2;
    //         if (array[index3] * 3 == array[i]) ++index3;
    //         if (array[index5] * 5 == array[i]) ++index5;
    //     }
    //     return num == array[array.size() - 1];
    // }
    bool isUgly(int number){
        if (number <= 0) return false;
        while(number % 2 == 0)
            number /= 2;
        while(number % 3 == 0)
            number /= 3;
        while(number % 5 == 0)
            number /= 5;
        return (number == 1) ? true : false;
    }
};
