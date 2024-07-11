#include "StatesTree.h"

Node::Node(double p, double w, double maxP, double b , Node* l, Node* r, bool promising, int position, int depth, Node* up) : profit(p), weight(w), maxProfit(maxP), bound(b), left(l), right(r), promising(promising), position(position), depth(depth), up(up)
{

}

double f_getBound(vector<Item> items, double W, Node* node, int lvl)
{
    int k = f_getK(items, W);
    int j = lvl + 1;
    double totW = f_getTotW(j, k, items, node, W);

    double sumP = 0;
    for (j; j <= k - 1; j++)
    {
        sumP += items[j].P;
    }
    double bound = 0;
    if (k >= items.size())
    {
        bound = (node->profit + sumP) + (W - totW) * 0;
    }
    else
    {
        bound = (node->profit + sumP) + (W - totW) * (items[k].P / items[k].W);
    }

    return bound;
}

int f_getK(vector<Item> remainingItems, double W)
{
    int index = 0;
    double sum = 0;
    while (sum <= W)
    {
        if (index == remainingItems.size())
        {
            index++;
            break;
        }
        sum += remainingItems[index].W;
        index++;

    }
    return index - 1;
}


double f_getTotW(int j, int k, vector<Item> items, Node* node, double W)
{
    double sum = 0;

    for (j; j <= k - 1; j++)
    {
        sum += items[j].W;
    }

    sum += node->weight;
    return sum;
}


Node* f_createLeftNode(int lvl, Node* previousNode, vector<Item> items, double W, double* maxProfitOverall, vector<int>* positions, Node*& answer)
{
    if (!previousNode->promising)
    {
        return nullptr;
    }

    Node* nodeLeft = new Node();
    nodeLeft->up = previousNode;
    nodeLeft->weight = items[lvl].W + previousNode->weight;

    if (nodeLeft->weight >= W) //nieobiecujacy
    {
        nodeLeft->promising = false;
    }

    nodeLeft->profit = items[lvl].P + previousNode->profit;

    if (*maxProfitOverall < nodeLeft->profit && nodeLeft->promising)
    {
        *maxProfitOverall = nodeLeft->profit;
        nodeLeft->maxProfit = *maxProfitOverall;
    }
    else
    {
        nodeLeft->maxProfit = *maxProfitOverall;
    }

    double bound = f_getBound(items, W, nodeLeft, lvl);

    if (bound <= nodeLeft->maxProfit) // nieobiecuj¹cy
    {
        nodeLeft->promising = false;
    }

    nodeLeft->bound = bound;
    nodeLeft->depth = lvl;
    nodeLeft->position = (*positions)[lvl];
    (*positions)[lvl]++;

    if (*maxProfitOverall == nodeLeft->profit)
    {
        answer = nodeLeft;
    }

    return nodeLeft;
}

Node* f_createRightNode(int lvl, Node* previousNode, vector<Item> itemsCopy, double W, double* maxProfitOverall, vector<int>* positions)
{
    if (!previousNode->promising)
    {
        return nullptr;
    }

    Node* nodeRight = new Node();
    nodeRight->up = previousNode;
    nodeRight->profit = previousNode->profit;
    nodeRight->weight = previousNode->weight;
    nodeRight->maxProfit = *maxProfitOverall;
    double boundRight = f_getBound(itemsCopy, W, nodeRight, lvl);
    nodeRight->bound = boundRight;

    if (nodeRight->weight >= W) //nieobiecujacy
    {
        nodeRight->promising = false;
    }

    if (boundRight <= nodeRight->maxProfit) // nieobiecuj¹cy
    {
        nodeRight->promising = false;
    }

    nodeRight->position = (*positions)[lvl];
    (*positions)[lvl]++;
    return nodeRight;
}


void f_createTree(int depth, int lvl, Node* previousNode, vector<Item> items, double W, Node*& answer)
{
    static double maxProfitOverall = 0;
    static vector<int> positions(depth, 1); // pozycje na danej glebokosci 
    
    if (lvl >= depth || previousNode == nullptr) //nieobiecuj¹cy
    {
        return;
    }

    Node* nodeLeft = f_createLeftNode(lvl, previousNode, items, W, &maxProfitOverall, &positions, answer);
    previousNode->left = nodeLeft;
    f_createTree(depth, lvl + 1, previousNode->left, items, W, answer);

    vector<Item> itemsCopy;
    itemsCopy.clear();
    itemsCopy = f_createItemsCopy(items, lvl);
    
    Node* nodeRight = f_createRightNode(lvl, previousNode, itemsCopy, W, &maxProfitOverall, &positions);
    previousNode->right = nodeRight;
    f_createTree(depth, lvl + 1, previousNode->right, itemsCopy, W, answer);

}

vector<Item> f_createItemsCopy(vector<Item> items, int lvl)
{
    vector<Item> itemsCopy;

    Item i1;
    i1.P = 0;
    i1.W = 0;

    itemsCopy.push_back(i1);
    for (int i = 1; i < items.size(); i++)
    {
        Item i1;
        i1.P = items[i].P;
        i1.W = items[i].W;
        i1.ratioPW = items[i].ratioPW;
        itemsCopy.push_back(i1);
        if (i == lvl)
        {
            itemsCopy[i].W = 0;
        }
    }
    return itemsCopy;
}

void printTree(Node* node, string indent, bool last, int index, int n, ofstream& fileWrite)
{
    if (node != nullptr)
    {
        fileWrite << indent;
        if (last) 
        {
            fileWrite << "\\-";
            indent += "  ";
        }
        else 
        {
            fileWrite << "|-";
            indent += "| ";
        }
        fileWrite << "index: " << index << "; pozycja: " << node->position << "; p: " << node->profit << "; w: " << node->weight << "; maxP: " << node->maxProfit << "; b: " << node->bound << "; Czy obiecujacy: " << node->promising << endl;
        printTree(node->left, indent, false, index + 1, n, fileWrite);
        printTree(node->right, indent, true, index + 1, n, fileWrite);
    }
}

void f_printTree(Node* previousNode, int n) 
{
    ofstream fileWrite = f_openFileToWrite("output");
    printTree(previousNode, "", true, 0, n, fileWrite);
}

Node* f_initializeRoot(vector<Item> items, double W)
{
    // jeœli nie: w >= W to obiecuj¹cy - w pierwszym zawsze spelnia bo przy pobieraniu danej W > 0

    Node* newNode = new Node(0, 0, 0);
    newNode->bound = f_getBound(items, W, newNode, 0);
    return newNode;
}



