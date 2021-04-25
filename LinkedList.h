
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   int size();
   void clear();
   void add_back(Tile* data);
   void remove(int index);
   void remove_front();

private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
