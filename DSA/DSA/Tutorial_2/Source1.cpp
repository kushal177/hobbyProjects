//A single linked-list program
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

static int const TRAIN_PROGRAM_1 = 0;// to find cyclic single linked list 
static int const TRAIN_PROGRAM_2 = 0;// to reverse a single linked list
static int const TRAIN_PROGRAM_3 = 1;// find all the leaf nodes of a binary tree




///////////////////////////////////////////////////////////////////////////////
struct Node
{
	int data;
	Node* next;
};
Node* head = NULL;
int count = 0;

bool insertElem(int item, Node** headNode, bool flag)
{
	if (*headNode == NULL)
	{
		*headNode = new Node;
		(*headNode)->data = item;
		(*headNode)->next = NULL;
	}
	else
	{
		Node* curNode = *headNode;
		if (false == flag)
		{
			while (NULL != curNode->next)
			{
				curNode = curNode->next;
			}
			/*Node* newNode = new Node;
			newNode->data = item;
			newNode->next = NULL;
			curNode->next = newNode;*/
		}
		else
		{
			while ((NULL != curNode->next))
			{
				if (item == curNode->data)
				{
					return true;
				}
				curNode = curNode->next;
			}

		}
		Node* newNode = new Node;
		newNode->data = item;
		newNode->next = NULL;
		curNode->next = newNode;
	}
	return false;
}

Node* createSinglyLinkedList(std::vector<int>& arrVec, Node* headNode)
{
	//insert the elements
	std::vector<int>::iterator iter = arrVec.begin();
	for (; iter != arrVec.end(); ++iter)
	{
		insertElem(*iter, &headNode, false);
	}
	return head;
}

int countNodes(Node* my_head)
{
	int count = 0;
	Node* curNode = my_head;
	while (NULL != (curNode = curNode->next))count++;
	return count;
}

void createCyclic(Node* listhead, int n1, int n2)
{
	Node* curNode = listhead;
	Node* nodeN1 = listhead;
	Node* nodeN2 = listhead;
	int count = 0;
	int offset = n2 - n1;
	while (count<n2)
	{
		if (count >= offset)//start the node after the offset.
		{
			nodeN1 = nodeN1->next;
		}

		nodeN2 = nodeN2->next;
		count++;
	}
	nodeN2->next = nodeN1;
}

void printList(Node* listhead, int listSz)
{
	int count = 0;
	Node* curNode = listhead;
	std::cout << std::endl <<"Data: " << std:: endl;
	if (listSz != -1)
	{

		while (count <= listSz)
		{
			std::cout << curNode->data << "  ";
			curNode = curNode->next;
			count++;
		}
	}
	else
	{
		while (curNode != NULL)
		{
			std::cout << curNode->data << "  ";
			curNode = curNode->next;
		}
	}
	std::cout << std::endl;
}

bool has_cyclic(Node* listhead)
{
	Node* curNode = listhead;
	Node* iterNode = listhead;
	bool is_cyclic = false;
	Node* countNodeList = NULL;
	int count = 0;
	while ((NULL != curNode->next) && (is_cyclic == false))
	{
		long addr = (int)curNode->next;
		std::cout << "Ref data: " << curNode->data << std::endl;
		is_cyclic = insertElem(addr, &countNodeList, true);
		std::cout << "cyclic flag: " << is_cyclic << std::endl;
		count++;
		if (true == is_cyclic)
		{
			return is_cyclic;
		}
		curNode = curNode->next;
	}
	return is_cyclic;
}

void reverseNode(Node* n1, Node** n2, Node** tmpNode)
{
	*n2 = *tmpNode;
	(*tmpNode) = (*n2)->next;
	(*n2)->next = n1;
}

void reverseHeadNode(Node* n1, Node** n2, Node** tmpNode)
{
	*n2 = n1->next;
	n1->next = NULL;
	(*tmpNode) = (*n2)->next;
	(*n2)->next = n1;
}

Node* reverseList(Node* listhead)
{

	Node* curNode = listhead;
	Node* nxtNode = listhead;
	Node* nxtnxtNode = listhead;
	//reverse Head node
	reverseHeadNode(curNode, &nxtNode, &nxtnxtNode);
	curNode = nxtNode;
	nxtNode = nxtnxtNode;
	while (NULL != nxtNode)
	{
		reverseNode(curNode, &nxtNode, &nxtnxtNode);
		curNode = nxtNode;
		nxtNode = nxtnxtNode;
	}
	return curNode;
}
///////////////////////////////////////////////////////////////////////////////
//////// program to find the leaf nodes in a given binary tree
struct BinaryNode
{
	int data;
	BinaryNode* left;
	BinaryNode* right;
};

bool traverseAndCreateR(BinaryNode** node)
{
	bool flag = false;
	if (NULL == *node)
	{
		*node = new BinaryNode;
		(*node)->left = NULL;
		(*node)->right = NULL;
		(*node)->data = INT_MIN;
		flag = true;
	}
	return flag;
	
}

bool traverseAndCreateL(BinaryNode** node)
{
	bool flag = false;
	if (NULL == *node)
	{
		*node = new BinaryNode;
		(*node)->left = NULL;
		(*node)->right = NULL;
		(*node)->data = INT_MIN;
		flag = true;
	}
	/*else
	{
		(*node) = (*node)->left;
	}*/

	return flag;
	
}


void insertBinElem(int data, BinaryNode** binHead)
{
	// use random function to generate a random number and 
	// find if the number is even or odd
	// if odd, traverse to the left child
	// if even, traverse to the right child


	if (*binHead == NULL)
	{
		*binHead = new BinaryNode;
		(*binHead)->data = data;
		(*binHead)->left = NULL;
		(*binHead)->right = NULL;
		std::cout << " Head data: " << (*binHead)->data << std::endl;
	}
	else
	{
		bool exitFlag = false;
		BinaryNode* temp = *binHead;
		//BinaryNode* prevTmp = NULL;
		while (false == exitFlag)
		{
			int v2 = rand() % 100 + 1;
			//prevTmp = temp;
			if (0 == v2 % 2)
			{
				//traverse right
				exitFlag = traverseAndCreateR(&temp->right);
				std::cout << "Right ";
				temp = temp->right;
			}
			else
			{
				//traverse left
				exitFlag = traverseAndCreateL(&temp->left);
				std::cout << "Left ";
				temp = temp->left;
			}
		}
		temp->data = data;
		std::cout << "data: " << temp->data << std::endl;
	}




}

BinaryNode* createBinTree(std::vector<int> arrVec, BinaryNode* binNodeHead)
{
	//insert the elements

	std::vector<int>::iterator iter = arrVec.begin();
	for (; iter != arrVec.end(); ++iter)
	{
		insertBinElem(*iter, &binNodeHead);
	}
	return binNodeHead;
}

int height(BinaryNode* binNodeHead)
{
	// traverse through all the paths and update the maximum path
	if (binNodeHead == NULL)
		return 0;

	// find the height of each subtree
	int lh = height(binNodeHead->left);
	int rh = height(binNodeHead->right);

	return 1 + std::max(lh, rh);
}

void printBottomLeafNodes(BinaryNode* binNodeHead,int level, int maxhtnode)
{
	//int ht = 0;
	if (binNodeHead == NULL)
	{
		return;
	}
	else if ((binNodeHead->left == NULL) && (binNodeHead->right == NULL))
	{
		if (level == maxhtnode)
		{
			std::cout << "Bottom leaf node: " << binNodeHead->data << std::endl;
		}
		return;
	}

	printBottomLeafNodes(binNodeHead->left,level+1, maxhtnode);
	printBottomLeafNodes(binNodeHead->right, level+1, maxhtnode);

	

	

	//return 1+ht;
}

void printLeafNodes(BinaryNode* binNodeHead)
{
	BinaryNode* temp = binNodeHead;

	// find the height of the binary tree
	int ht = height(binNodeHead);
	////print right leaf nodes
	std::cout << "Right leafy nodes: " << std::endl;
	while (temp->right != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->right;
	}
	std::cout << temp->data << std::endl;
	//print left leaf nodes
	temp = binNodeHead->left;
	while (temp->left != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->left;
	}
	std::cout << temp->data << std::endl;


	// print all the nodes at the bottom most height
	printBottomLeafNodes(binNodeHead,0, ht - 1);

}

int main()
{
	

	//check if the list is cyclic
	if (TRAIN_PROGRAM_1)
	{
		std::vector<int> arrVec = { 1, 30, 6, 8, 3, 44, 22, 3, 1, 66, 54, 32, 78 };
		//create a linked list
		Node* listhead = createSinglyLinkedList(arrVec, head);
		//count the number of nodes in the list;
		int listSz = countNodes(listhead);

		//createSinglyLinkedList cyclic at Nth node
		int n1 = listSz - 6;
		int n2 = listSz - 3;
		printList(listhead, listSz);
		createCyclic(listhead, n1,n2);
		printList(listhead, listSz);
		bool is_cyclic = has_cyclic(listhead);
		if (true == is_cyclic)
		{
			std::cout << "Linked list is cyclic\n";
		}
		else
		{
			std::cout << "Linked list is Not cyclic\n";
		}
	}

	//reverse the linked list.
	if (TRAIN_PROGRAM_2)
	{
		std::vector<int> arrVec = { 1, 30, 6, 8, 3, 44, 22, 3, 1, 66, 54, 32, 78 };
		//create a linked list
		Node* listhead = createSinglyLinkedList(arrVec, head);
		//count the number of nodes in the list;
		int listSz = countNodes(listhead);

		//create cyclic at Nth node
		int n1 = listSz - 6;
		int n2 = listSz - 3;
		printList(listhead, listSz);
		listhead = reverseList(listhead);
		printList(listhead, -1);
	}

	// program to find the outer leaf nodes in a given binary tree
	if (TRAIN_PROGRAM_3)
	{
		std::vector<int> arrVec = { 1, 30, 6, 8, 3, 44, 22, 3, 1, 66, 54, 32, 78,
			                        5, 4, 33, 2, 10, 75, 77, 83, 7, 9, 54, 63, 99 };

		for (const int& i : arrVec) // access by const reference
			std::cout << i << ' ';
		std::cout << endl;
		// create a binary tree with numbers
		BinaryNode* binTreeHead = NULL;
		binTreeHead = createBinTree(arrVec, binTreeHead);

		//print out all the outer leaf nodes
		printLeafNodes(binTreeHead);


	}

	return 0;
	
}
