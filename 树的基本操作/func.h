#pragma once
typedef struct TreeNode {

	int val;
	struct TreeNode* left;
	struct TreeNode* right;

}TreeNode;

TreeNode* CreateLink();//创建

//前序非递归输出：返回数组
int* preorderTraversal(struct TreeNode* root, int* returnSize);
//前序递归
void inorder_1(struct TreeNode* root, int* res, int* returnSize);
//前序递归
int* preorderTraversal_1(struct TreeNode* root, int* returnSize); 

//中序非递归输出：返回数组
int* inorderTraversal(struct TreeNode* root, int* returnSize);
//中序递归
void inorder_2(struct TreeNode* root, int* res, int* resSize); 
//中序递归
int* inorderTraversal_1(struct TreeNode* root, int* returnSize); 

//后序非递归输出：返回数组
int* postorderTraversal(struct TreeNode* root, int* returnSize); 
//后序递归
void inorder_3(struct TreeNode* root, int* res, int* returnSize); 
//后序递归
int* postorderTraversal_1(struct TreeNode* root, int* returnSize);

//层序非递归
int* layerorderTraversal(struct TreeNode* root, int* returnSize);
//前中序遍历结果输出二叉树
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);
void shuchu(struct TreeNode* S);
