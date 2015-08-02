// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int low = 0, high = nums.size() - 1;
//         int mid;
//         while (low <= high) {
//             mid = (high + low) / 2;
//             if (nums[mid] == target) {
//                 return mid;
//             } 
//             if (nums[mid] >= nums[high]) {  //转折点在右边部分，这样左边部分是升序排列的
//                 if (nums[low] <= target && target < nums[mid]) { //满足这个条件就进入了没有转折点、全部都是升序的序列
//                     high = mid - 1;
//                 } else {
//                     low = mid + 1;
//                 }
//             } else { //这里表示转折点在左边或者已经没有转折点了，既已经进入了完全升序的序列
//                 if (nums[mid] < target && target <= nums[high]) {
//                     low = mid + 1;
//                 } else {
//                     high = mid - 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = (high + low) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            if (nums[mid] >= nums[low]) { // 与II这里有区别 //转折点在右边部分，这样左边部分是升序排列的
                if (nums[low] <= target && target < nums[mid]) { //满足这个条件就进入了没有转折点、全部都是升序的序列
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            // } else if (nums[mid] < nums[low]) { //这里表示转折点在左边或者已经没有转折点了，既已经进入了完全升序的序列
            } else { //这里表示转折点在左边或者已经没有转折点了，既已经进入了完全升序的序列
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } 
            // else {
            //     low++;
            // }
        }
        return -1;
    }
};
