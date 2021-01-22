#include <iostream>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
using namespace std;

class BST
{
private:
	struct node
	{
		int key;
		string title;
		node* left;
		node* right;
	};
	node* root;
	void AddLeafPrivate(int d, int h, const string t, node* Ptr);
	void PrintInOrderPrivate(node* Ptr);
	node* ReturnNodePrivate(int d,int h, node* Ptr);
	node* MODPrivate(int d, int h, const string t, node* Ptr);
	int FindSmallestPrivate(node* Ptr);
	string ReturnTitlePrivate(int key, node* Ptr);
	void RemoveNodePrivate(int key, node* parent);
	void RemoveRootMatch();
	void RemoveMatch(node* parent, node* match, bool left);

public:
	BST();
	node* CreateLeaf(int key, const string t);
	void AddLeaf(int d, int h, const string t);
	void PrintInOrder();
	node* ReturnNode(int d, int h);
	node* MOD(int d, int h, const string t);
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	string ReturnTitle(int key);

	void RemoveNode(int key);
};
