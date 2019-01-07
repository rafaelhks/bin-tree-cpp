#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
    public:
        Node* getParent();
        Node* getLeftNode();
        Node* getRightNode();
        int getValue();

        void setParent(Node* p);
        void setRightNode(Node* n);
        void setLeftNode(Node* n);
        void printSubTree();

        bool insertNode(Node* n);
        Node* removeNode(int v);

        Node(int value);
        virtual ~Node();

    private:
        int value;
        Node* parent;
        Node* leftNode;
        Node* rightNode;
};

#endif // NODE_H
