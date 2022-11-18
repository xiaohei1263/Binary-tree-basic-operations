#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"func.h"
/*定义出二叉树的物理结构；创建二叉树；销毁二叉树；
  二叉树的先序遍历；二叉树的中序遍历；二叉树的后序遍历；二叉树的层序遍历；

  从以下几个题目选择一个并编程实现：
  1. 如何求二叉树T的非叶子结点个数
  2. 如何打印输出二叉树第4层结点(假设树根为第1层)
  3. 求二叉树中度为2的结点的个数
  4. 求二叉树中结点总数
  5. 求二叉树中叶子结点总数
  6. 遍历二叉树时显示每个结点的层号
  7. 求二叉树的深度。
  最后编写主函数调用这些函数验证所编写函数的正确性。
*/

int main(){
	TreeNode* S;
	printf("请输入第一个节点的数据:\n");
	//测试数据1 2 4 -1 7 -1 -1 -1 3 5 -1 -1 6 8 -1 -1 -1
	S = CreateLink();
	printf("\n");
	Output(S);
	
	return 0;
}

void Output(struct TreeNode* S) {
	int n = 0;
	int* array = (int*)malloc(sizeof(int) * 100);

	printf("前序递归输出");
	Printarray(preorderTraversal_1(S, &n), n);
	printf("\n");

	printf("前非递归输出");
	Printarray(preorderTraversal(S, &n), n);
	printf("\n");

	printf("中序递归输出");
	Printarray(inorderTraversal_1(S, &n), n);
	printf("\n");

	printf("中非递归输出");
	Printarray(inorderTraversal(S, &n), n);
	printf("\n");

	printf("后序递归输出");
	Printarray(postorderTraversal_1(S, &n),n);
	printf("\n");

	printf("后非递归输出");
	Printarray(postorderTraversal(S, &n), n);
	printf("\n");

	printf("非递归层输出");
	Printarray(layerorderTraversal(S, &n), n);
	printf("\n");

	printf("非叶子节点个数为%d", leafTreeNodesum(S));
	printf("\n");

	printf("层序输出第4层元素");
	Printarray(PTreeNodeLevel(S, 4, &n), n);
	printf("\n");

	printf("中度为2的节点个数为%d", Tree_three(S));
	printf("\n");

	printf("二叉树的节点个数为%d", TreeNodesum(S));
	printf("\n");

	printf("叶子节点的个数为%d", LTsum(S));
	printf("\n");

	printf("层序遍历带层数号");
	Tree_six(S);

	printf("二叉树的深度为%d", deepTree(S));
	printf("\n");
}

void Printarray(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; ++i) {
		printf("%2d", nums[i]);
	}
}

TreeNode* CreateLink(){
	int val;
	int temp;
	TreeNode* T;
	scanf_s("%d", &val);
	temp = getchar();
	if (val == -1)
		return NULL;
	else {
		T = (TreeNode*)malloc(sizeof(TreeNode));
		T->val = val;
		printf("请输入%d的左子树: ", val);
		T->left = CreateLink();
		printf("请输入%d的右子树: ", val);
		T->right = CreateLink();
		return T;
	}
}

void inorder_1(struct TreeNode* root, int* res, int* returnSize) {
	if (!root)
		return;
	res[(*returnSize)++] = root->val;
	inorder_1(root->left, res, returnSize);
	inorder_1(root->right, res, returnSize);
}
int* preorderTraversal_1(struct TreeNode* root, int* returnSize) {//前序递归输出
	*returnSize = 0;
	int* res = (int*)malloc(sizeof(int) * 100);
	inorder_1(root, res, returnSize);
	return res;
}

void inorder_2(struct TreeNode* root, int* res, int* resSize) {
	if (!root) {
		return;
	}
	inorder_2(root->left, res, resSize);
	res[(*resSize)++] = root->val;
	inorder_2(root->right, res, resSize);
}
int* inorderTraversal_1(struct TreeNode* root, int* returnSize) {//中序递归输出
	int* res = (int*)malloc(sizeof(int) * 501);
	*returnSize = 0;
	inorder_2(root, res, returnSize);
	return res;
}

void inorder_3(struct TreeNode* root, int* res, int* returnSize) {//后序递归
	if (!root)
		return;
	inorder_3(root->left, res, returnSize);
	inorder_3(root->right, res, returnSize);
	res[(*returnSize)++] = root->val;
}
int* postorderTraversal_1(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	int* res = (int*)malloc(sizeof(int) * 100);
	inorder_3(root, res, returnSize);
	return res;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {//前序非递归输出
	*returnSize = 0;
	int* res = (int*)malloc(sizeof(int) * 501);
	struct TreeNode** stk = (TreeNode**)malloc(sizeof(int) * 501);
	struct TreeNode* node = root;
	int top = 0;
	while (top > 0 || node != NULL) {
		while (node != NULL) {
			res[(*returnSize)++] = node->val;
			stk[top++] = node;
			node = node->left;
		}
		node = stk[--top];
		node = node->right;
	}
	return res;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {//中序非递归输出
	*returnSize = 0;
	int size = 0;
	int* res = (int*)malloc(sizeof(int) * 501);//输出数组
	struct TreeNode** stk = (TreeNode**)malloc(sizeof(struct TreeNode*) * 501);
	struct TreeNode* node = root;
	int top = 0;
	while (node != NULL || top > 0) {
		while (node != NULL) {
			stk[top++] = node;
			node = node->left;
		}
		node = stk[--top];
		res[size++] = node->val;
		node = node->right;
	}
	*returnSize = size;
	return res;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize) {//后序非递归输出
    int *res = (int*)malloc(sizeof(int) * 2001);
    *returnSize = 0;
    if (root == NULL) {
        return res;
    }
    struct TreeNode **stk = (TreeNode**)malloc(sizeof(struct TreeNode *) * 501);
    int top = 0;
    struct TreeNode *prev = NULL;
    while (root != NULL || top > 0) {
        while (root != NULL) {
            stk[top++] = root;
            root = root->left;
        }
        root = stk[--top];
        if (root->right == NULL || root->right == prev) {
            res[(*returnSize)++] = root->val;
            prev = root;
            root = NULL;
        } else {
            stk[top++] = root;
            root = root->right;
        }
    }
    return res;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {//前中序遍历结果输出二叉树
	if (preorderSize == 0 || inorderSize == 0)
		return NULL;
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	int index;
	root->val = preorder[0];
	for (index = 0; index < inorderSize; index++)
		if (inorder[index] == preorder[0])
			break;
	root->left = buildTree(preorder + 1, index, inorder, index);
	root->right = buildTree(preorder + index + 1, preorderSize - index - 1, inorder + index + 1, preorderSize - index - 1);
	return root;
}

int* layerorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	int* res = (int*)malloc(sizeof(int) * 501);
	struct TreeNode** queue = (TreeNode**)malloc(sizeof(int) * 501);
	struct TreeNode* node = root;
	int rear = 0;
	int front = 0;
	queue[rear++] = node;
	while (rear != front) {
		struct TreeNode* curr = queue[front];
		res[(*returnSize)++] = queue[front++]->val;
		if (curr->left != NULL) {
			queue[rear++] = curr->left;
		}
		if (curr->right != NULL) {
			queue[rear++] = curr->right;
		}
	}
	return res;
}


int leafTreeNodesum(struct TreeNode* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return 0;
	else 
		return leafTreeNodesum(root->left) + leafTreeNodesum(root->right) + 1;
}


void PTreeNodeLevel_1(struct TreeNode* root,int val, int* res, int* returnSize) {
	if (val == 1) {
		res[(*returnSize)++] = root->val;
		return;
	}
	if (root->left != NULL)
		PTreeNodeLevel_1(root->left, val - 1, res, returnSize);
	if (root->right != NULL)
		PTreeNodeLevel_1(root->right, val - 1, res, returnSize);
}

int* PTreeNodeLevel(struct TreeNode* root, int val, int* returnSize) {
	*returnSize = 0;
	int* res = (int*)malloc(sizeof(int) * 100);
	PTreeNodeLevel_1(root, val, res, returnSize);
	return res;
}

int TreeNodesum(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	else {
		return TreeNodesum(root->left) + TreeNodesum(root->right) + 1;
	}
}

int LTsum(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	int numLeft = LTsum(root->left);
	int numRight = LTsum(root->right);
	return (numLeft + numRight);
}

int deepTree(struct TreeNode* root) {
	if (root == NULL) return 0;
	return fmax(deepTree(root->left), deepTree(root->right)) + 1;
	
}

void Tree_six(struct TreeNode* root) {
	int i = 1;
	int n = 0;
	int size = deepTree(root);
	for (int i = 1; i <= size; i++) {
		printf("第%d层", i);
		Printarray(PTreeNodeLevel(root, i, &n), n);
		printf("\n");
	}
	
}

int Tree_three(struct TreeNode* root) {
	if (!root)
		return 0;
	else if (root->left && root->right)
		return Tree_three(root->left) + Tree_three(root->right) + 1;
	else
		return Tree_three(root->left) + Tree_three(root->right);
}