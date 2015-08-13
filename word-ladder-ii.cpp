// https://leetcode.com/problems/word-ladder-ii/

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        vector<vector<string>> res;
        queue<vector<string>> paths;
        vector<string> p;
        p.push_back(start);
        paths.push(p);
        int level = 1, min_level = INT_MAX;
        unordered_set<string> words;
        while(!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {
                for (auto &w: words) dict.erase(w);
                words.clear();
                level = path.size();
                if (level > min_level) break;
            }
            string last = path.back();
            for (int i = 0; i < last.size(); ++i) {
                string new_last = last;
                for (char ch = 'a'; ch != 'z'; ++ch) {
                    new_last[i] = ch;
                    if (dict.find(new_last) != dict.end()) {
                        words.insert(new_last);
                        vector<string> new_path = path;
                        new_path.push_back(new_last);
                        if (new_last == end) {
                            res.push_back(new_path);
                            min_level = level;
                        } else {
                            paths.push(new_path);
                        }
                    }
                }
            }
        }
        return res;
    }
};
