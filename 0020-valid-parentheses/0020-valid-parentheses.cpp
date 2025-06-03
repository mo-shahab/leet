class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        st.push(s[0]);
        
        for(int i = 1; i < s.length(); i++){
            if (
                !st.empty()
                &&
                (
                (st.top() == '(' && s[i] == ')' )
                ||
                (st.top() == '{' && s[i] == '}')
                || 
                (st.top() == '[' && s[i] == ']')
                )
            ){
                st.pop();
                continue;
            }
            else {
                st.push(s[i]);
            }
        }

        return st.empty() ? true : false;
    }
};