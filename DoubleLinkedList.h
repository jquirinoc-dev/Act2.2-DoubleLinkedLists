#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

  #include <climits>
  #include "Node.h"
  #include "mergeSort.h"

  template <class T>
  class DoubleLinkedList {
      private:
        Node<T>* head;
        Node<T>* tail;
        int numElements;

      public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        int getNumElements();
        void printList();
        void addFirst(T value);
        void addLast(T value);
        void updateData(T val, T newVal);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);
        void clear();
        void sort();
        void duplicate();
        void removeDuplicates();
        DoubleLinkedList<T> getReversedSubList(int left, int right);
          
  };

  template<class T>
  DoubleLinkedList<T>::DoubleLinkedList() {
      std::cout << "--->Creando una lista vacia " << this << std::endl;
      head = NULL;
      tail = NULL;
      numElements = 0;
  }
  
  template<class T>
  DoubleLinkedList<T>::~DoubleLinkedList() {
    std::cout << "--->Liberando memoria de la lista " << this << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
  }
 
  template<class T>
  int DoubleLinkedList<T>::getNumElements() {
    return numElements;
  }
  template<class T>
  void DoubleLinkedList<T>::printList() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  template<class T>
  void DoubleLinkedList<T>::addFirst(T value) {
    Node<T> *newNode = new Node<T>(value);
    // Si la lista esta vacia 
    if (head == NULL) {
      head = newNode;
      tail = newNode;
    }
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    numElements++;
  }
  
  template<class T>
  void DoubleLinkedList<T>::addLast(T value) {
    // La lista esta vacia
    if (head == NULL) {
      addFirst(value);
    }
    else {
      Node<T> *newNode = new Node<T>(value);
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      numElements++;
    }    
  }

  template<class T>
  void DoubleLinkedList<T>::updateData(T val, T newVal) {

    Node<T> *p;
    p = head;
    if (p != NULL && p->data == val) {
      p->data = newVal;
    } else {
      while (p != NULL && p->data != newVal) {
        p = p->next;
      }
      if (p == NULL){
        std::cout << "Index fuera de rango." << std::endl;
      } else {
        p->data = newVal;
      }
    }
  }
  
  template<class T>
  bool DoubleLinkedList<T>::deleteData(T value) {
    Node<T> *p, *q;
    p = head;
    q = NULL;
    // Si la lista esta vacia 
    if (p == NULL) {
      return false;
    }
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value) {
        q = p;
        p = p->next;
      }
      // Si no existe value en la lista
      if (p == NULL)
        return false;
      // Si debe borrarse el primer elemento
      if (p->prev == NULL) {
        head = p->next;
        if (head != NULL)
          head->prev = NULL;
      }
      else if (p->next == NULL) { 
        // Si debe borrarse el último elemento
        q->next = NULL;
        tail = q;
      }
      else {
        // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }

  template<class T>
  bool DoubleLinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return false;
    }
    else if (position == 0) { // Si debe borrarse el primer elemento
      Node<T> *p = head;
      // Si la lista contiene solo un nodo
      if (head != NULL && head->next == NULL) {
        head = NULL;
        tail = NULL;  
      }
      else {
        head = p->next;
        head->prev = NULL;
      }
      delete p;
      numElements--;
      return true; 
    }
    else { 
      Node<T> *p = head, *q = NULL;
      int index = 0;
      while (index != position) {
        q = p;
        p = p->next;
        index++;
      }
      // Si debe borrarse el último elemento
      if (p->next == NULL) {
        q->next = NULL;
        tail = q;
      }
      else { // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }
  
  template<class T>
  T DoubleLinkedList<T>::getData(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return -1;
    }
    else {
      if (position == 0)
        return head->data;
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p->data;
        index++;
        p = p->next;
      }
      return -1;
    }
  }

  template<class T>
  void DoubleLinkedList<T>::clear(){
      Node<T> *ptr = head;
      
      while (ptr != NULL) {
          ptr = NULL;
          ptr = ptr->next;
    }
  }

  template<class T>
  void DoubleLinkedList<T>::sort() {

    Node<T> *current = NULL, *idx = NULL;
    T temp;

    if (this->head == NULL) {
      return;
    } else {
      for (current = head; current->next != NULL; current = current->next){
        for (idx = current; idx != NULL; idx = idx->next){
          if (current->data > idx->data) {
            temp = current->data;
            current->data = idx->data;
            idx->data = temp;
          }
        }
      }
    }

  }

  template<class T>
  void DoubleLinkedList<T>::duplicate() {
    
    int limit = getNumElements();

    for (int i = 0; i < limit; i++) {
      addLast(getData(i));
    }

  }

template <class T>
void DoubleLinkedList<T>::removeDuplicates() {

  if (this->head != nullptr) {

    Node<T> *current = this->head;
    Node<T> *temp = nullptr;
    Node<T> *target = nullptr;

    while (current != nullptr) {
      temp = current->next;
      while(temp != nullptr) {
        if (temp->data == current->data) {
          target = temp;
        }
        temp = temp->next;
        if (target != nullptr) {
          if (target->prev != nullptr) {
            target->prev->next = temp;
          }
          if (temp != nullptr) {
            temp->prev = target->prev;
          }
          if (target == this->tail) {
            this->tail = target->prev;
          }
          target->prev = nullptr;
          target->next = nullptr;
          target = nullptr;
        }
      }
      current = current->next;
    }

  }

}

  template <class T>
  DoubleLinkedList<T> DoubleLinkedList<T>::getReversedSubList(int left, int right) {

    DoubleLinkedList<T> newList;

    while (left != right + 1) {
      T value = getData(left);
      newList.addFirst(value);
      left++;
    }
    return newList;
  }
  
#endif // _DOUBLELINKEDLIST_H_