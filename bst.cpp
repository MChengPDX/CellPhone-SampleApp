#include"node.h"
#include<iostream>
using namespace std;

Bnode::Bnode(int n)
{
    height = 0;
    data = n;
    left = NULL;
    right = NULL;

}

Bnode::~Bnode()
{


}

Maze::Maze()
{
    root = NULL;
}

bool Maze::isEmpty()
{
    return root == NULL;
}

void Maze::makeEmpty()
{
    root = NULL;
}

void Maze::insert(int data)
{
    root = insert(data, root);
}

int Maze::height(Bnode * root)
{
     root == NULL ? -1 : root->height;
}

//return the max of x(left) and y(right)
int Maze::max(int x, int y)
{
    return x > y ? x : y;
}

Bnode * Maze:: insert(int data, Bnode * root)
{
    if(!root)
    {
        root = new Bnode(data);
    }
    else if(data < root->data)
    {
        root->left = insert(data, root->left);
        if(height(root->left)-height(root->right)==2)
            if(data < root->left->data)
                root = RLC(root);
            else
                root = DWLC(root);

    }
    else if(data >= root->data)
    {
        root->right = insert(data, root->right);
        if(height(root->right)-height(root->left)==2)
            if(data > root->right->data)
                root = RRC(root);
            else
                root = DWLC(root);
        }
    root->height = max(height(root->left), height(root->right));
    return root;


 }

Bnode * Maze::RLC(Bnode * root)
{
    Bnode * temp = root->left;
    root->left = temp -> right;
    root->height = max(height(root->left), height(root->right))+1;
    temp->height = max(height(temp->left), temp->height)+1;
    return temp;

}

Bnode * Maze::RRC(Bnode * root)
{
    Bnode * temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = max(height(root->left), height(root->right))+1;
    temp->height = max(height(temp->left), temp->height)+1;
    return temp;
}

Bnode * Maze::DWLC(Bnode * root)
{
    root->left = RLC(root->left);
    return RRC(root);
}


Bnode * Maze::DWRC(Bnode * root)
{
    root->right = RLC(root->right);
    return RRC(root);
}

int Maze::countBnodes(Bnode * root)
{
    if(!root)
        return 0;
    else
    {
        int l = 1;
        l += countBnodes(root->left);
        l += countBnodes(root->right);
        return l;
    }
}

void Maze::display_all()
{
    cout << "Displaying the whole tree " << endl;
    display_all(root);
}

void Maze::display_all(Bnode * root)
{
    if(!root)
    {
        return;
    }
    cout << root->data << endl;
    display_all(root->left);
    display_all(root->right);
}

void Maze::test()
{
    cout << "Display all left " << endl;
    display_all(root->left);
    cout << "Display all right" << endl;
    display_all(root->right);
    cout << "Current root " << root->data << endl;
}

void Maze::checkOrders()
{
    cout << "inorder successor is : ";
    inorder(root);
    cout << endl;

    cout <<"preorder succesor is : ";
    preorder(root);
    cout << endl;

    cout <<"postorder successor is : ";
    postorder(root);
    cout << endl;
}

void Maze::inorder(Bnode * root)
{
    if(!root)
    {
        inorder(root->left);
        cout << "The data " << root->data << endl;
        inorder(root->right);
    }

}

void Maze::preorder(Bnode * root)
{

}

void Maze::postorder(Bnode * root)
{
}

