class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>sk;
        for (const string& c: tokens){
            if(c=="+"){
                int a = sk.top();sk.pop();
                int b = sk.top();sk.pop();
                sk.push (b+a);
            }else if (c=="-"){
                int a = sk.top();sk.pop();
                int b = sk.top();sk.pop();
                sk.push (b-a);
            }else if(c=="*"){
                int a = sk.top();sk.pop();
                int b = sk.top();sk.pop();
                sk.push(b * a);
            }else if (c=="/"){
                int a = sk.top();sk.pop();
                int b = sk.top();sk.pop();
                sk.push (b/a);
            }else{
                sk.push(stoi(c));
            }

        }
        return sk.top();
    }
};
