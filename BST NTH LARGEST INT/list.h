#ifndef LIST_H
#define LIST_H

class NodeList
{
    public:
        int data;
        NodeList* next;

        void addNodeEnd(Node* headNode, int newData)
        {
            //prep new node
            Node* newNode = new Node();
            newNode->data = newData;
            newNode->next = NULL;

            //if empty, make head
            if (!headNode){
                headNode = newNode;
                return;
            }

            //find last
            Node* last = headNode;
            while (last->next!=NULL){
                last = last->next;
            }
            
            //insert after last
            last->next = newNode;
        }
};

#endif