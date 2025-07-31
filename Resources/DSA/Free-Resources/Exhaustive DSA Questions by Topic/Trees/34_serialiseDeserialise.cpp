/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    public:
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            if(!root) return "";
            string ser = "";
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                auto p = q.front();
                q.pop();
                if(!p) ser.append("#,");
                else ser.append(to_string(p->val)+',');
                if(p){
                    q.push(p->left);
                    q.push(p->right);
                }
            }
            return ser;
        }
    
        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            if(data.length()==0) return nullptr;
            queue<TreeNode*> q;
            string temp = "";
            int pos = 0;
            while(pos<data.length()){
                if(data[pos]!=','){
                    temp = temp+data[pos];
                }
                else{
                    pos++;
                    break;
                }
                pos++;
            }
            q.push(new TreeNode(stoi(temp)));
            TreeNode* root = q.front();
            while(!q.empty()){
                int len = q.size();
                for(int i = 0; i<len; i++){
                    TreeNode* p = q.front();
                    q.pop();
                    temp = "";
                    while(pos<data.length()){
                        if(data[pos]!=','){
                            temp = temp+data[pos];
                        }
                        else{
                            pos++;
                            break;
                        }
                        pos++;
                    }
                    if(temp == "#"){
                        p->left = nullptr;
                    }
                    else{
                        p->left = new TreeNode(stoi(temp));
                        q.push(p->left);
                    }
                    temp = "";
                    while(pos<data.length()){
                        if(data[pos]!=','){
                            temp = temp+data[pos];
                        }
                        else{
                            pos++;
                            break;
                        }
                        pos++;
                    }
                    if(temp == "#"){
                        p->right = nullptr;
                    }
                    else{
                        p->right = new TreeNode(stoi(temp));
                        q.push(p->right);
                    }
                }
            }
            return root;
        }
    };
    
    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));