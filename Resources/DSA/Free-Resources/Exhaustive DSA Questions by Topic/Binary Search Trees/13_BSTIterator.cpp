class BSTIterator {
    public:
        stack<TreeNode*> st;
        BSTIterator(TreeNode* root) {
            TreeNode* temp = root;
            while(temp){
                st.push(temp);
                temp = temp->left;
            }
        }
        
        int next() {
            TreeNode* t = st.top();
            st.pop();
            if(t->right){
                TreeNode* temp = t->right;
                while(temp){
                    st.push(temp);
                    temp = temp->left;
                }
            }
            return t->val;
        }
        
        bool hasNext() {
            if(!st.empty()) return true;
            return false;
        }
    };