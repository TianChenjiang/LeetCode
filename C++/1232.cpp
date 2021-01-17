class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) return true;
        double k = getK(coordinates[0], coordinates[1]);
        for (int i = 2; i < coordinates.size(); i++) {
            double curK = getK(coordinates[i], coordinates[i-1]);
            if (abs(curK - k) > 0.001) return false;
        }
        return true;
    }
    double getK(vector<int> point1, vector<int> point2) {
        if (point1[0] - point2[0] == 0) return INT_MAX;
        return double(point1[1] - point2[1]) / (point1[0] - point2[0]);
    }
};