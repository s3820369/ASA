
#include <stdexcept>
#include <string>
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;
   length = 0;
}

LinkedList::~LinkedList() {
   clear();
}

int LinkedList::size() const {
   return length;
}

void LinkedList::push_front(Tile* data) {
   Node* node = new Node(data, head);
   head = node;
   ++length;
}

void LinkedList::push_back(Tile* data) {
   Node* node = new Node(data, nullptr);

   if(head == nullptr) {
      head = node;
   } else {
      Node* current = head;

      while(current->next != nullptr) {
         current = current->next;
      }
      current->next = node;
   }
   ++length;
}

Tile* LinkedList::at(int index) const {
   Tile* retTile = nullptr;

   if(index >= 0 && index < length) {
      int i = 0;
      Node* current = head;

      while(i < index) {
         current = current->next;
         ++i;
      }
      retTile = current->tile;
   }
   return retTile;
}

void LinkedList::insert(int index, Tile* data) {
   Node* current = nullptr;
   Node* prev = nullptr;
   int i = 0;

   if(index < 0 || index >= length)
     out_of_bounds(index);

   else if(index == 0)
      push_front(data);

   else if(index == length-1)
      push_back(data);

   else {
      current = head;

      while(i < index) {
         prev = current;
         current = current->next;
         ++i;
      }
      prev->next = new Node(data, current);
      ++length;
   }
}

void LinkedList::remove(int index) {
   if(index < 0 || index >= length)
      out_of_bounds(index);
      
   if(head != nullptr) {
      Node* current = head;
      Node* prev = nullptr;
      int i = 0;

      while(i != index) {
         prev = current;
         current = current->next;
         ++i;
      }

      if(index == 0)    head       = current->next;
      else              prev->next = current->next;

      delete current;
   }
   --length;
}

Tile* LinkedList::pop_front() {
   Tile* retTile = nullptr;

   if(head == nullptr)
      out_of_bounds(0);

   Node* toDelete = head;
   head = head->next;

   retTile = toDelete->tile;

   delete toDelete;

   --length;
   return retTile;

}
Tile* LinkedList::pop_back() {
   Tile* retTile = nullptr;

   if(head == nullptr)
      out_of_bounds(0);

   Node* current = head;
   Node* prev = nullptr;

   while(current->next != nullptr) {
      prev = current;
      current = current->next;
   }

   // If popping head
   if(prev == nullptr)  head       = nullptr; 
   else                 prev->next = nullptr;

   retTile = current->tile;
   delete current;

   --length;
    return retTile;
}

void LinkedList::clear() {
   while(head != nullptr) {
      pop_front();
   }
}

void LinkedList::out_of_bounds(int index) {
   throw std::range_error("Index " + std::to_string(index)
                           + " out of bounds for length: " + std::to_string(length));
}
