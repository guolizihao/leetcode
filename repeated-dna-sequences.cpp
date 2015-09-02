// https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10) return res;
        unordered_map<int, int> m;
        int val = 0;
        for (int i = 0; i < 9; ++i) {
            val = (val << 2) | convert(s[i]);
        }
        for (int i = 9; i < s.size(); ++i) {
            val = ((val << 2) | convert(s[i])) & 0xfffff;
            if(m.find(val) != m.end()) {
                if (m[val] == 1) res.push_back(s.substr(i - 9, 10));
            }
            ++m[val];
        }
        return res;
    }
    
    int convert(char ch) {
        if (ch == 'A') return 0;
        if (ch == 'C') return 1;
        if (ch == 'G') return 2;
        if (ch == 'T') return 3;
    }
};

// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         vector<string> result;
//         if (s.size() <= 10) return result;
//         set<int> unique_string_set;
//         int hash_map[1024 * 1024] = {0};
//         int hash_value = 0;
//         for (int i = 0; i < 10; i++) {
//             hash_value <<= 2;
//             hash_value |= convert(s[i]);
//         }
//         hash_map[hash_value]++;
//         for (int i = 10; i < s.size(); i++) {
//             hash_value <<= 2;
//             hash_value |= convert(s[i]);
//             hash_value &= (0xfffff);
//             if (hash_map[hash_value]) {
//                 if(unique_string_set.find(hash_value) == unique_string_set.end()) {
//                     result.push_back(s.substr(i - 9, 10));
//                     unique_string_set.insert(hash_value);
//                 }
//             } else {
//                 hash_map[hash_value]++;
//             }
//         }
//         return result;
//     }
    
//     int convert(char ch) {
//         if (ch == 'A') return 0;
//         if (ch == 'C') return 1;
//         if (ch == 'G') return 2;
//         if (ch == 'T') return 3;
//     }
// };
