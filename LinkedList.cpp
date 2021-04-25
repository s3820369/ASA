
#include "LinkedList.h"
#include <stdexcept>

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

// void LinkedList::add_back(Tile* data){
//     Node* node = new Node();
//     node->tile = data;
//     node->next = nullptr;

//     if(head == nullptr){
//         head = node;
//     }else{
//         Node* current = head;
//         while(current->next != nullptr){
//             current = current->next;
//         }
//         current->next = node;
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

void LinkedList::remove_front(){
    if(head != nullptr){
        Node* toDelete = head;
        head = head->next;

        delete toDelete->tile;
        delete toDelete;
    }else{
        throw std::runtime_error("Nothing to remove");
    }

}

void LinkedList::clear(){
    while(head != nullptr){
        remove_front();
    }
}
