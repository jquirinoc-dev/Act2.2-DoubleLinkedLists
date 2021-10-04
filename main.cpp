#include <iostream>
#include "DoubleLinkedList.h"

int main(){
    DoubleLinkedList<int> myDoubleLinkedList;

    std::cout << "numElements: " << myDoubleLinkedList.getNumElements() << std::endl;
    std::cout << "Agregando 5 elementos al frente..." << std::endl;
    
    for (int i = 1; i < 6; i++){
        myDoubleLinkedList.addFirst(i);
    }

    std::cout << "numElements: " << myDoubleLinkedList.getNumElements() << std::endl;
    myDoubleLinkedList.printList();

    myDoubleLinkedList.clear();

    myDoubleLinkedList.printList();
}