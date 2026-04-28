class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>sk;
        int maxarea =0;

        for (int i =0;i<=n;i++){
            while(!sk.empty() && (i == n ||heights[sk.top()]>=heights[i])){
                int h = heights[sk.top()];
                sk.pop();
                int w = sk.empty() ? i:i - sk.top()-1;
                maxarea = max (maxarea, w*h);
            }
            sk.push(i);
        }
        return maxarea;
    }
};
