class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res(temperatures.size(),0);
        stack<pair<int,int>>sk;

        for (int i=0;i<temperatures.size();i++){
            int t = temperatures[i];
            while(!sk.empty()&&t>sk.top().first){
                auto pair = sk.top();
                sk.pop();
                res[pair.second] = i-pair.second;

            }
            sk.push({t,i});

        }
        return res;
    }
};
