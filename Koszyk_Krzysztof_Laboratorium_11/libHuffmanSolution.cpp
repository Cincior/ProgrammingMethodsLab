#include "libHuffmanSolution.h"

void f_createTree(priority_queue<Node*, vector<Node*>, CompareNode> &nodesQueue)
{
	while (nodesQueue.size() > 1)
	{
		Node* firstNode = nodesQueue.top();
		nodesQueue.pop();
		Node* secondNode = nodesQueue.top();
		nodesQueue.pop();

		Node* newNode = new Node;
		newNode->occurrences = firstNode->occurrences + secondNode->occurrences;
		newNode->left = firstNode;
		newNode->right = secondNode;
		nodesQueue.push(newNode);
	}
}

void f_printPrefixCode(Node* node, string code)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->letter != '0')
	{
		cout << node->letter << ": " << code << "\n";
	}
	f_printPrefixCode(node->left, code + "0");
	f_printPrefixCode(node->right, code + "1");
}

void printTree(Node* node, string indent, bool last)
{
	if (node != nullptr)
	{
		cout << indent;
		if (last)
		{
			cout << "\\-";
			indent += "  ";
		}
		else
		{
			cout << "|-";
			indent += "| ";
		}
		cout << node->letter << ": " << node->occurrences << endl;
		printTree(node->left, indent, false);
		printTree(node->right, indent, true);
	}
}
