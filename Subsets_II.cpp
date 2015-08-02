class Solution {
public:
    void dfs(vector<vector<int> >& ans , vector<int>&s , vector<int>&tmp , int start) {
        ans.push_back(tmp);
        
        for(int i = start ; i < s.size() ; ++i) {
            if(i != start && s[i] == s[i-1]) continue; //select only once in every layer
            tmp.push_back(s[i]); //select
            dfs(ans , s , tmp , i + 1); //do recusive
            tmp.pop_back(); //delete
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans;
        if(S.size() <= 0) return ans;
        vector<int> tmp;
        sort(S.begin() , S.end()); // sort
        dfs(ans , S , tmp , 0);
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> result;
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         if (nums.size() == 0) return result;
//         sort(nums.begin(),nums.end());
//         vector<int> temp;
//         BuildTree(nums, temp, 0);
//         return result;
//     }
    
//     void BuildTree(vector<int> &nums, vector<int> temp, int level) {
//         if (level == nums.size()) {
//             for (int i = 0; i < result.size(); i++) {
//                 if (result[i] == temp) return;
//             }
//             result.push_back(temp);
//             return;
//         } else {
//             BuildTree(nums, temp, level + 1);
//             temp.push_back(nums[level]);
//             BuildTree(nums, temp, level + 1);
//         }
//     }
// };
