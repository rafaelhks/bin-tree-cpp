#ifndef TREE_H
#define TREE_H
#include <vector>
#include "Node.h"

class Tree{
    public:
        void insertRoot(Node* n);
        Node* getRoot();
        //vector<Node*>* getNodes();
        Tree();
        virtual ~Tree();

    private:
        Node* root;
        //vector<Node*> nodes;
};

#endif // TREE_H
