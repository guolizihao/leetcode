class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> solution;
        PartitionDFS(s, 0, solution, res);
        return res;
    }
    
    void PartitionDFS(string s, int start, vector<string> &solution, vector<vector<string>> &res) {
        if (start == s.size()) {
            res.push_back(solution);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                solution.push_back(s.substr(start, i - start + 1));
                PartitionDFS(s, i + 1, solution, res);
                solution.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
