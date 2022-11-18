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

//1. ������T�ķ�Ҷ�ӽ�����
int leafTreeNodesum(struct TreeNode* root);

//2. ��δ�ӡ�����������3����(��������Ϊ��1��)
int* PTreeNodeLevel(struct TreeNode* root, int val, int* returnSize);
void PTreeNodeLevel_1(struct TreeNode* root, int val, int* res, int* returnSize);

//3. ��������ж�Ϊ2�Ľ��ĸ���

int Tree_three(struct TreeNode* root);

//  4. ��������н������
int TreeNodesum(struct TreeNode* root);

// 5. ���������Ҷ�ӽ������
int LTsum(struct TreeNode* root);

//6. ����������ʱ��ʾÿ�����Ĳ��
void Tree_six(struct TreeNode* root);

// 7. �����������ȡ�
int deepTree(struct TreeNode* root);

void Output(struct TreeNode* S);
void Printarray(int* nums, int numsSize);
