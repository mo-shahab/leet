#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}


void preorder(TreeNode* root){
    if(root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode* root){
    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void dfs_iterative(TreeNode* root){
    if(root == nullptr) return;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();

        cout << node->val << " ";
        if (node->right != nullptr) st.push(node->right);
        if (node-> left != nullptr) st.push(node->left);
    }
}

void bfs_iterative(TreeNode* root){
    if (root == nullptr) return;
    
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

// this will only do the preorder traversal
void dfs_iterative(TreeNode* root){
    if (root == nullptr) return;

    stack<TreeNode*> st;
    st.push(root);

    whiile(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        // if i cout the value here it will be inorder but iteratively so yeah
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }
}

void inorder_iterative(TreeNode* root){
    if(root == nullptr) return;

    TreeNode* curr = root;
    stack<TreeNode*> st;

    while(curr != nullptr || !st.empty()){
        while(curr != nullptr){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->val << " ";
        
        curr = curr->right;
    }
}

int main() {
    TreeNode* root = createSampleTree();

    bfs_iterative(root); cout << endl;

    return 0;
}
