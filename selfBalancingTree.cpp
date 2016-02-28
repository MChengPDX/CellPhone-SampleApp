
#include"node.h"
#include<iostream>
using namespace std;



//Bnode Class Implementation

//Bnode constructor
Bnode::Bnode(int n)
{
    height = 0;
    data = n;
    get_left() = NULL;
    get_right() = NULL;
    prev = NULL;

}

//Bnode destructor
Bnode::~Bnode()
{


}

int Bnode::set_height(int value)
{
    height = value;
}

int Bnode::set_data(int value)
{
    data = value;
}


int Bnode::get_data()
{
    return data;
}

int Bnode::get_height()
{

    return height; 
}

Bnode *& Bnode::get_left()
{
    return left;
}

Bnode *& Bnode::get_right()
{
    return right;
}

Bnode *& Bnode::get_prev()
{
    return prev;
}

//Maze Class Implementation


//Maze Constructor
Maze::Maze()
{
    root = NULL;
}

Maze::~Maze()
{
    remove_all();

}

void Maze::remove_all()
{
    remove_all(root);
}

void Maze::remove_all(Bnode * root)
{
    if(!root)
        return ;
    if(root->get_left() != NULL)
        remove_all(root->get_left());
    if(root->get_right() != NULL)
        remove_all(root->get_right());
    delete root;

}

void Maze::insert(int data)
{
    root = insert(data, root);
}

int Maze::height(Bnode * root)
{
     root == NULL ? -1 : root->get_height();
}

//return the max of x(get_left()) and y(get_right())
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
    else if(data < root->get_data())
    {
        root->get_left() = insert(data, root->get_left());
        if(height(root->get_left())-height(root->get_right())==2)
            if(data < root->get_left()->get_data())
                root = RLC(root);
            else
                root = DWLC(root);

    }
    else if(data >= root->get_data())
    {
        root->get_right() = insert(data, root->get_right());
        if(height(root->get_right())-height(root->get_left())==2)
            if(data > root->get_right()->get_data())
                root = RRC(root);
            else
                root = DWLC(root);
        }
    int value = max(height(root->get_left()), height(root->get_right()));
    root->set_height(value);
    return root;


 }

Bnode * Maze::RLC(Bnode * root)
{
    Bnode * temp = root->get_left();
    root->get_left() = temp -> get_right();
    int value =0;
    value = max(height(root->get_left()), height(root->get_right()))+1;
    root->set_height(value);
    int value2 =0;
    value2 = max(height(temp->get_left()), temp->get_height())+1;
    temp->set_height(value);
    return temp;

}

Bnode * Maze::RRC(Bnode * root)
{
    int v1 = 0;
    int v2 = 0;
    Bnode * temp = root->get_right();
    root->get_right() = temp->get_left();
    temp->get_left() = root;
    v1= max(height(root->get_left()), height(root->get_right()))+1;
    root->set_height(v1);
    v2 = max(height(temp->get_left()), temp->get_height())+1;
    temp->set_height(v2);
    return temp;
}

Bnode * Maze::DWLC(Bnode * root)
{
    root->get_left() = RLC(root->get_left());
    return RRC(root);
}


Bnode * Maze::DWRC(Bnode * root)
{
    root->get_right() = RLC(root->get_right());
    return RRC(root);
}

int Maze::countBnodes(Bnode * root)
{
    if(!root)
        return 0;
    else
    {
        int l = 1;
        l += countBnodes(root->get_left());
        l += countBnodes(root->get_right());
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
    cout << root->get_data() << endl;
    display_all(root->get_left());
    display_all(root->get_right());
}

void Maze::test()
{
    cout << "Display all get_left() " << endl;
    display_all(root->get_left());
    cout << "Display all get_right()" << endl;
    display_all(root->get_right());
    cout << "Current root " << root->get_data() << endl;
}


Bnode * Maze::go_back(Bnode * current)
{
    if(current->get_prev() == NULL)
    {
        cout << "Can't go back " << endl;
        return current;
    }
    cout << "You are currently at " << current->get_data() << endl;
    current = current->get_prev();
    cout << "After moving previously, you are at " << current->get_data() << endl;
    return current;

}

Bnode * Maze::advance_r(Bnode * current)
{
    if(current->get_right() == NULL)
    {
        cout << "Can't go left, you reached a dead" << endl;
        return current;
    }
    cout <<"You are current at " << current->get_data() << endl;
    current = current->get_right();
    cout <<"After moving left, you are at " << current->get_data() << endl;
    return current;
}

Bnode * Maze::advance_l(Bnode * current)
{
    if(current->get_left() == NULL)
    {
        cout << "Can't go left, you reached a dead end" << endl;
        return current;
    }
    cout << "You are current at " << current->get_data() << endl;
    current = current->get_left();
    cout <<"After moving get_right(), you are at " << current->get_data() << endl;
    return current;
}

void Maze::move()
{
    Bnode * current = root;
    int value = 0;
    bool done = false;
    while(!done)
    {
        cout << "This is currently current " << current -> get_data() << endl;
        cout << "Enter what direction to go, 1 for going left and 2 for going right and 3 for going back." << endl;
        cin >> value;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "This is again current " << current -> get_data() << endl;
        current = advance(value, current);
        if(current->get_data() == 100)
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
    if(value == 3)
    {
        current = go_back(current);
        return current;
    }
    else
    {
        cout << "Invalid" << endl;
        return current;
    }
}

//setting previous pointers

void Maze::set_previous()
{
    root->get_prev() = NULL;
    set_previous(root->get_left(), root);
    set_previous(root->get_right(), root);
}

void Maze::set_previous(Bnode * ptr, Bnode *p_ptr)
{
    if(!ptr)
        return;
    if(!p_ptr)
        return;
    
    ptr->get_prev() = p_ptr;
    cout << "This is ptr " << ptr-> get_data() << endl;
    cout << "This is p_h " << p_ptr-> get_data() << endl;
    set_previous(ptr->get_left(),p_ptr->get_left());
    set_previous(ptr->get_right(), p_ptr->get_right());

    if(ptr->get_left() == NULL)
    {
        ptr->get_prev() = p_ptr;
        return set_previous(ptr->get_left(), p_ptr->get_left());
    }
    if(ptr->get_right() == NULL)
    {
        ptr->get_prev() = p_ptr;
        return set_previous(ptr->get_right(), p_ptr->get_right());
    }

}

