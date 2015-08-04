//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;
        string dict[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string solution;
        GenerateString(digits, dict, 0, solution, res);
        return res;
    }
    void GenerateString(string &digits, string dict[], int level, string &solution, vector<string> &res) {
        // 注意string *dict 或者dict[]
        if (level == digits.size()) {
            res.push_back(solution);
            return;
        }
        string str = dict[digits[level] - '2'];
        for (int i = 0; i < str.size(); i++) {
            solution.push_back(str[i]);
            GenerateString(digits, dict, level + 1, solution, res);
            solution.pop_back();
        }
    }
};
