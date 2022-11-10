#pragma once
typedef struct TreeNode {

	int val;
	struct TreeNode* left;
	struct TreeNode* right;

}TreeNode;

TreeNode* CreateLink();//����

//ǰ��ǵݹ��������������
int* preorderTraversal(struct TreeNode* root, int* returnSize);
//ǰ��ݹ�
void inorder_1(struct TreeNode* root, int* res, int* returnSize);
//ǰ��ݹ�
int* preorderTraversal_1(struct TreeNode* root, int* returnSize); 

//����ǵݹ��������������
int* inorderTraversal(struct TreeNode* root, int* returnSize);
//����ݹ�
void inorder_2(struct TreeNode* root, int* res, int* resSize); 
//����ݹ�
int* inorderTraversal_1(struct TreeNode* root, int* returnSize); 

//����ǵݹ��������������
int* postorderTraversal(struct TreeNode* root, int* returnSize); 
//����ݹ�
void inorder_3(struct TreeNode* root, int* res, int* returnSize); 
//����ݹ�
int* postorderTraversal_1(struct TreeNode* root, int* returnSize);

//����ǵݹ�
int* layerorderTraversal(struct TreeNode* root, int* returnSize);
//ǰ�������������������
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);
void shuchu(struct TreeNode* S);
