class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0.0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    auto &a = points[i];
                    auto &b = points[j];
                    auto &c = points[k];

                    double cross = abs((b[0] - a[0]) * (c[1] - a[1]) - 
                                       (c[0] - a[0]) * (b[1] - a[1]));

                    double area = cross / 2.0;
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};