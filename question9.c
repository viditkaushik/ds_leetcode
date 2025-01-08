void inorderTraversal(struct TreeNode* root, struct TreeNode** lastNode, struct TreeNode** newRoot) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left, lastNode, newRoot);

    if (*lastNode != NULL) {
        (*lastNode)->right = root;  
        (*lastNode)->left = NULL;   
    }
    if (*newRoot == NULL) {
        *newRoot = root;
    }
    *lastNode = root;
    inorderTraversal(root->right, lastNode, newRoot);
}
struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode* newRoot = NULL;  
    struct TreeNode* lastNode = NULL; 
    inorderTraversal(root, &lastNode, &newRoot);
    return newRoot;
}
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void printTree(struct TreeNode* root) {
    while (root != NULL) {
        printf("%d -> ", root->val);
        root = root->right;
    }
    printf("NULL\n");
}
