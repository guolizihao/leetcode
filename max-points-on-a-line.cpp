// https://leetcode.com/problems/max-points-on-a-line/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();
        int res = 0;
        unordered_map<double, int> m;
        for (int i = 0; i < points.size(); ++i) {
            int same_point = 1;
            int no_slope_point = 0;
            double slope;
            m.clear();
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++same_point;
                    continue;
                } else if (points[i].x == points[j].x) {
                    ++no_slope_point;
                    continue;
                } else if (points[i].y == points[j].y) slope  = 0.0;
                else slope = (double) (points[i].y - points[j].y) / (points[i].x - points[j].x);
                ++m[slope];
            }
            no_slope_point += same_point;
            res = max(res, no_slope_point);
            for (auto i : m) {
                res = max(res, i.second + same_point);
            }
        }
        return res;
    }
};
