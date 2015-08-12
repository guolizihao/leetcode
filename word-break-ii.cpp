// https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.size() == 0) return res;
        string solution;
        int len = s.size();
        vector<bool> possible(len + 1, true);
        DFS(s, wordDict, 0, possible, res, solution);
        return res;
    }
    void DFS(string &s, unordered_set<string> &wordDict, int start, vector<bool> &possible, vector<string> &res, string &solution) {
        if (start == s.size()) {
            res.push_back(solution.substr(0, solution.size() - 1)); 
            // the last element in solution is a space which shoud not in the solution
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i - start + 1);
            if (wordDict.find(word) != wordDict.end() && possible[i + 1]) {
                //solution.append(word).append(" ");
                solution = solution + word + " ";
                int old_size = res.size();
                DFS(s, wordDict, i + 1, possible, res, solution);
                if (res.size() == old_size) {
                    possible[i + 1] = false;
                }
                solution.resize(solution.size() - word.size() - 1);
            }
        }
    }
};
