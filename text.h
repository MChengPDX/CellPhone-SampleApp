#include "string.h"
#include <iostream>

class Text
{
    private:
        String text_m;
        char * name;


    public:
        Text();
        Text(const Text & from);
        Text(String T, char * n);
        ~Text();
        void display_item();


};

class Node : public Text
{
    private:
        Node * next;

    public:
        Node();
        ~Node();
        
        Node *& get_next();

};

class Hashtable
{
    private:
        Node ** array_list;
        int array_size;

    public:
        Hashtable();
        ~Hashtable();

        int hash_function(char * name);
        int insert(char * name, String text_m);
        int remove(char * name);
        int remove_all();
        int find_one(char * name);
        int display_all();

};

