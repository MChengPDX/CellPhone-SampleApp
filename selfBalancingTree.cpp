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

Maze::~Maze()
{

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



Bnode * Maze::advance_r(Bnode * current)
{
    if(current->right == NULL)
    {
        Bnode * dead;
        dead->data = 500;
        cout << "Can't go left, you reached a dead end and fell off the cliff" << endl;
        return dead;
    }
    cout <<"You are current at " << current->data << endl;
    current = current->right;
    cout <<"After moving left, you are at " << current->data << endl;
    return current;
}

Bnode * Maze::advance_l(Bnode * current)
{
    if(current->left == NULL)
    {
        Bnode * dead;
        dead->data = 500;
        cout << "Can't go left, you reached a dead end and fell off the cliff" << endl;
        return dead;
    }
    cout << "You are current at " << current->data << endl;
    current = current->left;
    cout <<"After moving right, you are at " << current->data << endl;
    return current;
}

void Maze::move()
{
    Bnode * current = root;
    int value = 0;
    bool done = false;
    while(!done)
    {
        cout << "This is currently current " << current -> data << endl;
        cout << "Enter what direction to go, 1 for LEFT and 2 for RIGHT." << endl;
        cin >> value;
        cout << "This is again current " << current -> data << endl;
        current = advance(value, current);
        if(current->data == 100)
        {
            cout << "You win! " << endl;
            done = true;
            return;
        }
        else
            continue;

    }
}

Bnode * Maze::advance(int value, Bnode * current)
{
    if(value == 1)
    {
       current =  advance_l(current);
       return current;
    }
    if(value == 2)
    {
        current = advance_r(current);
        return current;
    }
    else
    {
        cout << "Invalid" << endl;
        return 0;
    }

}
