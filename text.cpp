#include "String.h" //includes iostream
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
    if(from.text_m)
        text_m = from.text_m;
    if(from.name)
        name = from.name;

}

//destructor, deletes dynamic memory and 
//the self made string class
Text::~Text()
{
    if(text_m)
        delete text_m;
    if(name)
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

//Destructor
Node::~Node()
{
    delete next;
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
    int array_size = 100;
    for(int i = 0; i != 100; i++)
    {
        array_list[array_size] = NULL;
    }

}

//destructor
Hashtable::~Hashtable()
{

}

//determine hash value of senders name to
//input into the hash table
int Hashtable::hash_function(char * name)
{
    int value = 0;
    for(int i = 0; i < strlen(name); i++)
        value = (value + (int)name[i] * 17);
    value = value % 3;
    cout << "This is value " << value << endl;
    return value;

}



