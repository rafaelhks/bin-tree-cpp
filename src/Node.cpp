#include "Node.h"
#include <iostream>

Node::Node(int v)
{
    value = v;
    rightNode = nullptr;
    leftNode = nullptr;
}

Node::~Node()
{
    delete(this);
}

bool Node::insertNode(Node* n){
    if(this->value < n->getValue()){
        if(rightNode == nullptr){
            cout<<"     - Node inserted on the right of "<<this->value<<" : "<<n->getValue()<<endl;
            this->rightNode = n;
            this->rightNode->setParent(this);
        }else{
            cout<<"     - Down right of "<<this->value<<" to node "<<this->getRightNode()->getValue()<<endl;
            this->rightNode->insertNode(n);
        }

        //this->balanco++;
        return true;
    }

    else if(this->value > n->getValue()){
        if(leftNode == nullptr){
            cout<<"     - Node inserted on the left of "<<this->value<<" : "<<n->getValue()<<endl;
            this->leftNode = n;
            this->leftNode->setParent(this);
        }else{
            cout<<"     - Down left of "<<this->value<<" to node "<<this->getLeftNode()->getValue()<<endl;
            this->leftNode->insertNode(n);
        }

        //this->balanco--;
        return true;
    }

    else{
        cout<<"\n     - O Could not insert Node on Tree."<<endl;
        return false;
    }
}

Node* Node::removeNode(int target){
    //Se for o Node a ser removido
    if(this->value == target){
        cout<<"\n     - Removed Node: "<<this->value<<endl;

        //Se não tiver filhos
        if(this->rightNode == nullptr && this->leftNode == nullptr){
            if(this->parent->getRightNode()->getValue() == this->value){
                this->parent->setRightNode(nullptr);
            }else if(this->parent->getLeftNode()->getValue() == this->value){
                this->parent->setLeftNode(nullptr);
            }
            return this;

        }

        //Se tiver só o filho direito
        if(this->rightNode && !this->leftNode){
            this->parent->setRightNode(this->rightNode);
            this->rightNode->setParent(this->parent);
        }

        //Se tiver só o filho esquerdo
        else if(!this->rightNode && this->leftNode){
            this->parent->setLeftNode(this->leftNode);
            this->leftNode->setParent(this->parent);
        }

        //Se tiver os dois filhos
        else if(this->rightNode && this->leftNode){

            //Raiz da sub-arvore esquerda
            Node* rootSub = this->leftNode;
            //Node mais à direita da sub-arvore esquerda
            while(rootSub->rightNode){
                rootSub = rootSub->rightNode;
            }
            this->parent->setLeftNode(rootSub);
            rootSub->setRightNode(this->rightNode);
            rootSub->setLeftNode(this->leftNode);

            //balancear os Nodes da subarvore
            //Node mais a direita ainda pode ter filhos na esquerda (setar como filho esquerda do parent dele)
            cout<<"     - New Node on the place of removed "<<target<<" :"<<rootSub->getValue()<<endl;
        }
        return this;
    }
    else if(this->value < target){
        if(this->rightNode){
            this->rightNode->removeNode(target);
        }
        else{
            cout<<"     - No nodes with the value "<<target<<" found on this tree!"<<endl;
            return nullptr;
        }
    }
    else if(this->value > target){
        if(this->leftNode){
            this->leftNode->removeNode(target);
        }
        else{
            cout<<"     - No nodes with the value "<<target<<" found on this tree!"<<endl;
            return nullptr;
        }
    }
}

//void Node::balancear(Node* r){
//
//}

void Node::setRightNode(Node* node){
    this->rightNode = node;
}

void Node::setLeftNode(Node* node){
    this->leftNode = node;
}

void Node::setParent(Node* p){
    this->parent = p;
}

int Node::getValue(){
    return value;
}

Node* Node::getParent(){
    return this->parent;
}

Node* Node::getRightNode(){
    return this->rightNode;
}

Node* Node::getLeftNode(){
    return this->leftNode;
}

void Node::printSubTree(){
    cout<<"Node: "<<this->value<<endl;
    if(this->leftNode!=nullptr){
        cout<<"\n   "<<this->value<<" -> Left: "<<this->leftNode->getValue()<<endl;
        this->leftNode->printSubTree();
    }
    if(this->rightNode!=nullptr){
        cout<<"\n   "<<this->value<<" -> Right: "<<this->rightNode->getValue()<<endl;
        this->rightNode->printSubTree();
    }

    if(this->rightNode==nullptr && this->leftNode==nullptr){
        cout<<"\n   "<<this->value<<" has no child nodes."<<endl;
    }

    cout<<endl;
}
//
//int Node::getBalanco(){
//    return this->balanco;
//}

