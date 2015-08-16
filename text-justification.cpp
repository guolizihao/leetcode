// https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, L = maxWidth;
        while (i < words.size()) {
            int j = i, len = 0;
            // the length of spaces is j - i
            while (j < words.size() && (len + words[j].size() + j - i <= L)) {
                len += words[j++].size();
            }
            // the line
            string out;
            // the total number of spaces
            int space = L - len;
            for (int k = i; k < j; ++k) {
                out += words[k];
                if (space > 0) {
                    // the current space
                    int tmp;
                    // the last line
                    if (j == words.size()) {
                        // the last word in the last line
                        if (j - 1 - k == 0) {
                            tmp = space;
                        } else {
                        // the other word in the last line
                            tmp = 1;
                        }
                    } else {
                    // other lines
                        // the word is not the last word in the line
                        if (j - 1 - k > 0) {
                            if (space % (j - 1 - k) == 0) {
                                tmp = space / (j - 1 - k);
                            } else {
                                tmp = space / (j - 1 - k) + 1;
                            }
                        } else {
                        // the last word in the line
                            tmp = space;
                        }
                    }
                    out.append(tmp,' ');
                    space -= tmp;
                }
            }
            res.push_back(out);
            i = j;
        }
        return res;
    }
};
