// https://leetcode.com/problems/subsets/



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        vector<int> v;
        DFS(nums, v, res, 0);
        return res;
    }
    
    void DFS(vector<int> &nums, vector<int> &v, vector<vector<int>> &res, int depth) {
        res.push_back(v);
        for (int i = depth; i < nums.size(); ++i) {
            v.push_back(nums[i]);
            DFS(nums, v, res, i + 1);
            v.pop_back();
        }
    }
};
// 求子集问题就是求组合问题。数组中的n个数可以用n个二进制位表示，
// 当某一位为1表示选择对应的数，为0表示不选择对应的数。
// vector<vector<int> > subsets(vector<int> &S,int n)
//   {
//      //n个数有0~max-1即2^n中组合，1<<n表示2^n
//     int max = 1<<n;
//     vector<vector<int> >result;
//     for(int i = 0;i < max;i++)
//     {
//       vector<int> temp;
//       int idx = 0;
//       int j = i;
//       while(j > 0)
//       {
//         //判断最后一位是否为1，若为1则将对应数加入到当前组合中
//         if(j&1)
//         {
//           temp.push_back(S[idx]);
//         }
//         idx++;
//         //判断了这一位是否为1后要右移
//         j = j>>1;
//       }
//       //判断完了一种组合，加入到结果集中
//       result.push_back(temp);
//     }
//     return result;
//   }

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> res(1);
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); ++i) {
//             int size = res.size();
//             for (int j = 0; j < size; ++j) {
//                 res.push_back(res[j]);
//                 res.back().push_back(nums[i]);
//             }
//         }
//         return res;
//     }
// };
