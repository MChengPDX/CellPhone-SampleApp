




class Bnode
{
    public:
        int height, data;
        Bnode * left;
        Bnode * right;
        Bnode(int n);
        ~Bnode();

};


class Maze
{
    private:
        Bnode * root;
    public:
        Maze();
        ~Maze();
        void remove_all(Bnode * root);
        void display_all();
        void display_all(Bnode * root);
        void insert(int data);
        int height(Bnode * root);
        int max (int a, int b);
        Bnode * insert(int data, Bnode * root);
        // Rotate tree node with left child 
        Bnode * RLC(Bnode * root);
        // Rotate with right child
        Bnode * RRC(Bnode * root);
        // Double rotate the binary tree node
        // first left child with its right child
        // then the node to rotate with  the new left child
        Bnode * DWLC(Bnode * root);
        //Doing the opposite of DWLC
        Bnode * DWRC(Bnode * root);
        int countBnodes();
        int countBnodes(Bnode * root);

        void test();
        void display_left(Bnode * root);
        void display_right(Bnode * root);

        void checkOrders();
        void inorder(Bnode * root);
        void preorder(Bnode * root);
        void postorder(Bnode * root);
       
        Bnode * advance_l(Bnode * root);
        Bnode * advance_r(Bnode * root);
        void move();
        Bnode * advance(int value, Bnode * current); 

};
