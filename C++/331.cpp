class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> v;
        istringstream in(preorder);
        string t = "";
        while(getline(in, t, ',')) v.push_back(t);

        vector<string> st;
        for (string str : v) {
            st.push_back(str);
            while (st.size() >= 3 && *(st.end()-1) == "#" && *(st.end()-2) == "#" && *(st.end()-3) != "#") {
                st.erase(st.end()-1); st.erase(st.end()-1); st.erase(st.end()-1);
                st.push_back("#");
            }
            // for (char chr : st) cout << chr << " ";
            // cout << endl;
        }
        // for (char chr : st) cout << chr << " ";
        // cout << endl;
        return st[0] == "#" && st.size() == 1;
    }
};