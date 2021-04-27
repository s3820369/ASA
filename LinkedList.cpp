
#include "LinkedList.h"
#include <stdexcept>
#include <bits/stdc++.h>

LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
   clear();
}

int LinkedList::size(){
    
    int length = 0;

    Node* current = head;
    while(current != nullptr){
        ++length;
        current = current->next;
    }
    return length;
}

void LinkedList::push_front(Tile* data){
    Node* node = new Node();
    node->tile = data;
    node->next = head;
    head = node;
}

void LinkedList::push_back(Tile* data){
    Node* node = new Node();
    node->tile = data;
    node->next = nullptr;

    if(head == nullptr){
        head = node;
    }else{
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = node;
    }

}
Tile* LinkedList::at(int index){
    Tile* retCard = nullptr;

    if(index >= 0 && index < size()){

        int counter = 0;
        Node* current = head;

        while(counter<index){
            ++counter;
            current = current->next;
        }

        retCard = current->tile;

    }
    return retCard;
}

// void insertAt(Node** current, int data, int pos)
// {
//     int length =0;   
//     if (pos < 1 || pos > length + 1)
//         std::cout << "Invalid position!" << std::endl;
//     else {        
//         while (pos--) {
 
//             if (pos == 0) {
//                 Node* temp = at(data); 
//                 temp->next = *current;
//                 *current = temp;
//             }
//             else
//                current = &(*current)->next;
//         }
//         length++;
//     }
// }

void LinkedList::remove(int index){
    if(index >= 0 && index < size()){
        if(head != nullptr){
            int counter = 0;
            Node* current = head;
            
            Node* prev = nullptr;

            while(counter != index){
                ++counter;
                prev = current;
                current = current->next;
            }

            if(prev == nullptr){
                head = current->next;
            }else{
                prev->next = current->next;
            }

            delete current->tile;
            delete current;
        }
    }
}

void LinkedList::pop_front(){
    if(head != nullptr){
        Node* toDelete = head;
        head = head->next;

        delete toDelete->tile;
        delete toDelete;
    }else{
        throw std::runtime_error("Nothing to remove");
    }

}
void LinkedList::pop_back(){
    
    if(head != nullptr){
        Node* current = head;
        //pre should point to node before current;
        Node* prev = nullptr;

        while(current->next != nullptr){
            prev = current;
            current = current->next;
        }

        if(prev == nullptr){
            head = nullptr;
        }else{
            prev->next = nullptr;
        }

        delete current->tile;
        delete current;
    }
    
}

void LinkedList::clear(){
    while(head != nullptr){
        pop_front();
    }
}
