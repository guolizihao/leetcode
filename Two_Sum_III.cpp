//170 Two Sum III - Data structure design Total Accepted: 311 Total Submissions: 1345
//Design and implement a TwoSum class. It should support the following operations:add and find.
//add - Add the number to an internal data structure.
//find - Find if there exists any pair of numbers which sum is equal to the value.
//For example,
//add(1); add(3); add(5);
//find(4) -> true
//find(7) -> false


class Solution {
public:
    unordered_map<int,int> table;
    void add(int number) {
        if (table.find(number) == table.end()) {
            // table.insert(pair<int, int>(number, 1));
            table[number] = 1;
        } else {
            table[number]++;
        }
    }
    
    bool find(int value) {
        for (int i = 0; i < table.size(); i++) {
            int key = table[i];
            int another_key = value - table[i];
            if (key == another_key && table[key] > 1) {
                return true;
            } else if (key != another_key && table.find(another_key) != table.end()) {
                return true;
            }
        }
        return false;
    }
};
