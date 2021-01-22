#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cstring>

#include "BST.h"
using namespace std;
extern ofstream f2;

BST::BST()
{
	root = NULL;
}

BST::node* BST::CreateLeaf(int key, const string t)
{
	node* n = new node;
	n -> key = key;
	n -> title = t;
	n -> left = NULL;
	n -> right = NULL;
	return n;
}

void BST::AddLeaf(int d, int h, const string t)
{
	AddLeafPrivate(d, h, t, root);
}

void BST::AddLeafPrivate(int d, int h, const string t, node* Ptr)
{
	int CompactData = d * 100 + h;
	if(root == NULL)
	{
		root = CreateLeaf(CompactData, t);
	}
	else if(CompactData < Ptr -> key)
	{
		if(Ptr -> left != NULL)
		{
			AddLeafPrivate(d, h, t, Ptr -> left);
		}
		else
		{
			Ptr -> left = CreateLeaf(CompactData, t);
		}
	}
	else if(CompactData > Ptr -> key)
	{
		if(Ptr -> right != NULL)
		{
			AddLeafPrivate(d, h, t, Ptr -> right);
		}
		else
		{
			Ptr -> right = CreateLeaf(CompactData, t);
		}
	}
	else
	{
		cout << "Conflict " << d <<  " " << h << endl;
		f2 << "Conflict " << d <<  " " << h << endl;
	}
}

void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr)
{
	if(root != NULL)
	{
		if(Ptr -> left != NULL)
		{
			PrintInOrderPrivate(Ptr -> left);
		}
		cout << Ptr -> title << " " << (Ptr -> key) / 100 << " " << (Ptr -> key) % 100 << endl;
		f2 << Ptr -> title << " " << (Ptr -> key) / 100 << " " << (Ptr -> key) % 100 << endl;
		if(Ptr -> right != NULL)
		{
			PrintInOrderPrivate(Ptr -> right);
		}
	}
	else
	{
		cout << "Empty Planner" << endl;
		f2 << "Empty Planner" << endl;
	}
}

BST::node* BST::ReturnNode(int d, int h)
{
	return ReturnNodePrivate(d, h, root);
}

BST::node* BST::ReturnNodePrivate(int d, int h, node* Ptr)
{
	int CompactData = d * 100 + h;
	if(Ptr != NULL)
	{
		if(Ptr -> key == CompactData)
		{
			cout << Ptr -> title << endl;
			f2 << Ptr -> title << endl;
			return Ptr;
		}
		else
		{
			if(CompactData < Ptr -> key)
			{
				return ReturnNodePrivate(d, h, Ptr -> left);
			}
			else
			{
				return ReturnNodePrivate(d, h, Ptr -> right);
			}
		}
	}
	else
	{
		cout << "Empty " << CompactData / 100 << " " << CompactData % 100 << endl;
		f2 << "Empty " << CompactData / 100 << " " << CompactData % 100 << endl;
		return NULL;
	}
}

string BST::ReturnTitle(int key)
{
	return ReturnTitlePrivate(key, root);
}

string BST::ReturnTitlePrivate(int key, node* Ptr)
{
	if(Ptr != NULL)
	{
		if(Ptr -> key == key)
		{
			return Ptr -> title;
		}
		else
		{
			if(key < Ptr -> key)
			{
				return ReturnTitlePrivate(key, Ptr -> left);
			}
			else
			{
				return ReturnTitlePrivate(key, Ptr -> right);
			}
		}
	}
	else
	{
		//cout << "Empty " << key / 100 << " " << key % 100 << endl;
		//f2 << "Empty " << key / 100 << " " << key % 100 << endl;
		return NULL;
	}
}

BST::node* BST::MOD(int d, int h, const string t)
{
	return MODPrivate(d, h, t, root);
}

BST::node* BST::MODPrivate(int d, int h, const string t, node* Ptr)
{
	int CompactData = d * 100 + h;
	if(Ptr != NULL)
	{
		if(Ptr -> key == CompactData)
		{
			Ptr -> title = t;
			//cout << "t  = " << t << endl;
			return Ptr;
		}
		else
		{
			if(CompactData < Ptr -> key)
			{
				return MODPrivate(d, h, t, Ptr -> left);
			}
			else
			{
				return MODPrivate(d, h, t, Ptr -> right);
			}
		}
	}
	else
	{
		cout << "Empty " << CompactData / 100 << " " << CompactData % 100 << endl;
		f2 << "Empty " << CompactData / 100 << " " << CompactData % 100 << endl;
		return NULL;
	}
}

int BST::ReturnRootKey()
{
	if(root != NULL)
	{
		return root -> key;
	}
	else
	{
		return -1000; // As an example
	}
}


int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
	if(root == NULL)
	{
		cout << "The tree is empty" << endl;
		f2 << "The tree is empty" << endl;
		return -1000;
	}
	else
	{
		if(Ptr -> left != NULL)
		{
			return FindSmallestPrivate(Ptr -> left);
		}
		else
		{
			return Ptr -> key;
		}
	}
}

void BST::RemoveNode(int key)
{
	RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent)
{
	if(root != NULL)
	{
		if(root -> key == key)
		{
			RemoveRootMatch();
		}
		else
		{
			if((key < parent -> key) && (parent -> left != NULL))
			{
				parent -> left -> key == key ?
						RemoveMatch(parent, parent -> left, true) :
						RemoveNodePrivate(key, parent -> left);
			}
			else if((key > parent -> key) && (parent -> right != NULL))
			{
				parent -> right -> key == key ?
						RemoveMatch(parent, parent -> right, false) :
						RemoveNodePrivate(key, parent -> right);
			}
			else
			{
				cout << "Empty " << key / 100 << " " << key % 100 << endl;
				f2 << "Empty " << key / 100 << " " << key % 100 << endl;
			}
		}
	}
	else
	{
		cout << "Empty " << key / 100 << " " << key % 100 << endl;
		f2 << "Empty " << key / 100 << " " << key % 100 << endl;
	}
}

void BST::RemoveRootMatch()
{
	if(root != NULL)
	{
		node* delPtr = root;
		int rootKey = root -> key;
		int smallestInRightSubtree;
		// case 0 - 0 children
		if((root -> left == NULL) && (root -> right == NULL))
		{
			root = NULL;
			delete delPtr;
		}
		// case 1 - 1 children
		else if((root -> left == NULL) && (root -> right != NULL))
		{
			root = root -> right;
			delPtr -> right = NULL;
			delete delPtr;
			//cout << "The root node with key " << rootKey << " was deleted" << " The new root contains key " << root -> key << endl;
			//f2 << "The root node with key " << rootKey << " was deleted" << " The new root contains key " << root -> key << endl;
		}
		else if((root -> left != NULL) && (root -> right == NULL))
		{
			root = root -> left;
			delPtr -> left = NULL;
			delete delPtr;
			//cout << "The root node with key " << rootKey << " was deleted" << " The new root contains key " << root -> key << endl;
			//f2 << "The root node with key " << rootKey << " was deleted" << " The new root contains key " << root -> key << endl;
		}
		// case 2 - 2 children
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(root -> right);
			string Title_temp = ReturnTitle(smallestInRightSubtree);
			RemoveNodePrivate(smallestInRightSubtree, root);
			root -> key = smallestInRightSubtree;
			//cout << "I am here" << endl;
			root -> title = Title_temp;
			//cout << "The root key containing key " << rootKey << " was overwritten with key " << root -> key << endl;
			//f2 << "The root key containing key " << rootKey << " was overwritten with key " << root -> key << endl;
		}
	}
	else
	{
		cout << "Cannot remove root. The tree is empty" << endl;
		f2 << "Cannot remove root. The tree is empty" << endl;
	}
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
	if(root != NULL)
	{
		node* delPtr;
		int matchKey = match -> key;
		int smallestInRightSubtree;
		// case 0 - 0 children
		if((match -> left == NULL) && (match -> right == NULL))
		{
			delPtr = match;
			left == true ? parent -> left = NULL : parent -> right = NULL;
			delete delPtr;
			//cout << "The node contain key " << matchKey << " was removed" << endl;
			//f2 << "The node contain key " << matchKey << " was removed" << endl;
		}
		// case 1 - 1 children
		else if((match -> left == NULL) && (match -> right != NULL))
		{
			left == true ? parent -> left = match -> right : parent -> right = match -> right;
			match -> right = NULL;
			delPtr = match;
			delete delPtr;
			//cout << "The node containing key " << matchKey << " was removed" << endl;
			//f2 << "The node containing key " << matchKey << " was removed" << endl;
		}else if((match -> left != NULL) && (match -> right == NULL))
		{
			left == true ? parent -> left = match -> left : parent -> right = match -> left;
			match -> left = NULL;
			delPtr = match;
			delete delPtr;
			//cout << "The node containing key " << matchKey << " was removed" << endl;
			//f2 << "The node containing key " << matchKey << " was removed" << endl;
		}
		// case 2 - 2 children
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(match -> right);
			string Title_temp = ReturnTitle(smallestInRightSubtree);
			RemoveNodePrivate(smallestInRightSubtree, match);
			match -> key = smallestInRightSubtree;
			//cout << "I am here" << endl;
			match -> title = Title_temp;
		}
	}
	else
	{
		cout << "cannot remove match. The tree is empty" << endl;
		f2 << "cannot remove match. The tree is empty" << endl;
	}
}
