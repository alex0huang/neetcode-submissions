class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        vector<int>s1cnt(26,0);
        vector<int>s2cnt(26,0);
        for(int i=0;i<s1.length();i++){
            s1cnt[s1[i]-'a']++;
            s2cnt[s2[i]-'a']++;
        }
        int matches =0;
        for(int i=0;i<26;i++){
            if(s1cnt[i]==s2cnt[i]){
                matches++;
            }
        }
        int l=0;
        for(int r=s1.length();r<s2.length();r++){
            if(matches==26)return true;
            int index = s2[r]-'a';
            s2cnt[index]++;

            if(s1cnt[index]==s2cnt[index]){
                matches++;

            }
            else if (s1cnt[index]+1==s2cnt[index]){
                matches--;
            }
            int index2 = s2[l]-'a';
            s2cnt[index2]--;

            if(s1cnt[index2]==s2cnt[index2]){
                matches++;

            }
            else if (s1cnt[index2]-1==s2cnt[index2]){
                matches--;
            }
            l++;
        }
        return matches==26;
    }
};
