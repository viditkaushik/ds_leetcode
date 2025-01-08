struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct TreeNode* constructBST(int** preorder, int* preorderSize, int lower, int upper) {
    if (*preorderSize == 0) {
        return NULL;
    }
    int val = **preorder;
    if (val < lower || val > upper) {
        return NULL;
    }
    struct TreeNode* node = createNode(val);
    
    (*preorder)++;
    (*preorderSize)--;
    
    node->left = constructBST(preorder, preorderSize, lower, val);
    node->right = constructBST(preorder, preorderSize, val, upper);
    
    return node;
}
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    return constructBST(&preorder, &preorderSize, INT_MIN, INT_MAX);
}
void printTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d -> ", root->val);
    printTree(root->right);
}
