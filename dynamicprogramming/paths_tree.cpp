#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void getPaths(TreeNode* root, vector<string>& paths, string path) {
    if (root == NULL) {
        return;
    }
    path += to_string(root->val);
    if (root->left == NULL && root->right == NULL) {
        paths.push_back(path);
    } else {
        path += "->";
        getPaths(root->left, paths, path);
        getPaths(root->right, paths, path);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    getPaths(root, paths, "");
    return paths;
}

int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(4);

    vector<string> result = binaryTreePaths(root);
    for (string path : result) {
        cout << path << endl;
    }
    return 0;
}
