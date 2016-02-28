#include "text.h" //includes iostream
#include<cstring>
using namespace std;


//Class Text implementation

//defualt constructor
Text::Text()
{
    text_m = NULL;
    name = NULL;
}

//copy constructor
Text::Text(const Text & from)
{
    text_m = from.text_m;
    name = new char [(strlen(from.name)+1)];
    strcpy(name, from.name);

}

//assignment operators 
Text::Text(String t, char * n)
{
    text_m = t;
    name = new char [(strlen(n)+1)];
    strcpy(name, n);

}

//destructor, deletes dynamic memory and 
//the self made string class
Text::~Text()
{
        delete [] name;
}

//display content of text message, by sender and the sender message
void Text::display_item()
{
    cout << "Sender Name : " << name << endl;
    cout << "Message --------------------" << endl;
    cout << text_m << endl;

}

//Class Node implementation

//constructor
Node::Node()
{
    next = NULL;
}


//using the copy constructor from parent class
Node::Node(const Text & from):Text(from)
{

}

//assignement constructor
Node::Node(char * n, String t):Text(t, n)
{

}

//Destructor
Node::~Node()
{
}

//Return next value
Node *& Node::get_next()
{
    return next;
}

//Class Hashtable implementation

//constructor
Hashtable::Hashtable()
{
    array_size = 10;
    //was segfualting till I added this.
    array_list = new Node * [array_size];
    for(int i = 0; i != 10; i++)
    {
        array_list[array_size] = NULL;
    }

}

//destructor
Hashtable::~Hashtable()
{
    remove_all();

}

//remove all
int Hashtable::remove_all()
{
    for(int i = 0; i < array_size; i++)
    {
        if(array_list[i] == NULL)
        {
            cout << "No element to be deleted" << endl;
            return 0;
        }
        Node * temp = array_list[i];
        while(temp != NULL)
        {
            Node * current = temp->get_next();
            delete temp;
            temp = current;

        }
        array_list[i] = NULL;
    }
    delete [] array_list;

    
}

//determine hash value of senders name to
//input into the hash table
int Hashtable::hash_function(char * name)
{
    int value = 0;
    for(int i = 0; i < strlen(name); i++)
        value = (value + (int)name[i] * 17);
    value = value % 3;
    return value;

}

//inserting into a hash table
int Hashtable::insert(char * name, String text_m)
{
    int hash_value = hash_function(name);
    Node * temp = new Node(name, text_m);
    if(array_list[hash_value] == NULL)
    {
        array_list[hash_value] = temp;
        temp->get_next() = NULL;
        return 1;
    }
    else
    {
        Node * hold = array_list[hash_value]->get_next();
        array_list[hash_value]->get_next() = temp;
        temp->get_next() = hold;
        return 1;
    }

}

int Hashtable::find_one(char * name)
{
    int search_value = hash_function(name);
    Node * temp = array_list[search_value];
    if(temp == NULL)
    {
        cout << "Not found." << endl;
        return 0;
    }
    else
    {
        while(temp!=NULL)
        {
            temp->display_item();
            temp = temp->get_next();
        }
        return 1;
    }
}

int Hashtable::display_all()
{
    cout << "This is array size " << array_size << endl;
    for(int i = 0; i < array_size; i++)
    {
        Node * temp = array_list[i];
        while(temp!=NULL)
        {
            temp->display_item();
            temp = temp -> get_next();
        }
    }
    return 1;
}
