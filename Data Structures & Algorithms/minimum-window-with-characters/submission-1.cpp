class Solution {
public:
    string minWindow(string s, string t) {
       if(t.empty()){return "";}
       unordered_map<char, int>countT, window;
       for (char c : t){
            countT[c]++;
       }
       int reslen = INT_MAX;
       int l =0, have =0,need =countT.size();
       pair res = {-1,-1};
       for (int r= 0;r<s.size();r++){
            char c = s[r];
            window[c]++;
            if(countT.count(c)&&window[c]==countT[c]){
                have++;
            }
            while(have == need){
                if((r-l+1) < reslen){
                    reslen = r-l+1;
                    res ={l,r};
                }
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
       }
       return reslen == INT_MAX ? "":s.substr(res.first,reslen);

    }
};
