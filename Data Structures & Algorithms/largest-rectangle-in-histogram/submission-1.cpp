class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea=0;
        stack<int>sk;
        for (int i=0;i<=n;i++){
            while(!sk.empty()&& (i==n||heights[sk.top()]>=heights[i])){
                int height = heights[sk.top()];
                sk.pop();
                int width = sk.empty()? i : i-sk.top()-1;
                maxArea = max(maxArea,height*width);
            }
            sk.push(i);
        }
        return maxArea;
    }
};
