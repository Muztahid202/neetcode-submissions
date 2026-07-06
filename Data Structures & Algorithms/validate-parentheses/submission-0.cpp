class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> closeToOpen{
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for(char c : s){
            //checking if it's a closing brack
            if(closeToOpen.count(c)){
                if(!st.empty() && st.top() == closeToOpen[c]){
                    st.pop();
                }else{
                    return false;
                }
            }
            else{
                //opening bracket then push
                st.push(c);
            }
        }
        return st.empty();
    }
};
