class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>Q;
        Q.push(root);
        bool leftToRight=true;

        while(!Q.empty()){
            int size=Q.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                TreeNode* node=Q.front();
                Q.pop();
                int index=(leftToRight)?i:(size-1-i);

                row[index]=node->val;
                if(node->left){
                    Q.push(node->left);
                }
                if(node->right){
                    Q.push(node->right);
                }

            }
            leftToRight=!leftToRight;
            result.push_back(row);
        }
        return result;
    }
};
