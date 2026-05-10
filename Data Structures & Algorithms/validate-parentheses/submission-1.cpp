class Solution {
public:
    bool isValid(string s) {
        stack<char> contain;

        for(char c : s)
        {
            if(c=='('||c=='['||c=='{')
            {
                contain.push(c);
            }
            else if(!contain.empty() && c ==']'&& contain.top()=='[')
            {
                contain.pop();
            }
            else if(!contain.empty() && c =='}'&& contain.top()=='{')
            {
                contain.pop();
            }
            else if(!contain.empty() && c ==')'&& contain.top()=='(')
            {
                contain.pop();
            }
            else
            {
                return false;
            }
            
        }
        return contain.empty();
    }
};
