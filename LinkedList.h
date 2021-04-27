
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   int size();
   void clear();
   void push_front(Tile* data);
   void push_back(Tile* data);
   Tile* at(int index);
   void insertAt(Node** current, int pos, int data);
   void remove(int index);
   void pop_front();
   void pop_back();

private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
