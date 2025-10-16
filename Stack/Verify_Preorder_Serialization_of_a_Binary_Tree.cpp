class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        if(n == 1 && preorder == "#") return true;

        stringstream ss(preorder);
        string token = "";
        stack<string> st;
        while(getline(ss, token, ',')){
            st.push(token);

            while(st.size() >= 3){
                string top1 = st.top(); st.pop();
                string top2 = st.top(); st.pop();
                string top3 = st.top(); st.pop();

                if(top1 == "#" && top2 == "#" && top3 != "#"){
                    st.push("#");
                } else {
                    st.push(top3);
                    st.push(top2);
                    st.push(top1);
                    break;
                }
            }
        }
        return st.size() == 1 && st.top() == "#"? true: false;
    }
};