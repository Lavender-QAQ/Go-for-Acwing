#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                t.push(')');
            else if(s[i]=='{')
                t.push('}');
            else if(s[i]=='[')
                t.push(']');
            else if(s[i]==')'||s[i]=='}'||s[i]==']'){
                if(t.empty())
                    return false;
                else{
                    if(t.top()==s[i])
                        t.pop();
                    else
                        return false;
                }
            }
        }
        if(t.empty())
            return true;
        else
            return false;
    }
};