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

//1. 二叉树T的非叶子结点个数
int leafTreeNodesum(struct TreeNode* root);

//2. 如何打印输出二叉树第3层结点(假设树根为第1层)
int* PTreeNodeLevel(struct TreeNode* root, int val, int* returnSize);
void PTreeNodeLevel_1(struct TreeNode* root, int val, int* res, int* returnSize);

//3. 求二叉树中度为2的结点的个数

int Tree_three(struct TreeNode* root);

//  4. 求二叉树中结点总数
int TreeNodesum(struct TreeNode* root);

// 5. 求二叉树中叶子结点总数
int LTsum(struct TreeNode* root);

//6. 遍历二叉树时显示每个结点的层号
void Tree_six(struct TreeNode* root);

// 7. 求二叉树的深度。
int deepTree(struct TreeNode* root);

void Output(struct TreeNode* S);
void Printarray(int* nums, int numsSize);
