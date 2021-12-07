//
// Created by Eric Trantham on 12/7/21.
//


#include <iostream>
#include "listtools.h"
using namespace std;
template<class T>
void headInsert(Node<T>*& head, const T& theData) {
    head = new Node<T>(theData, head);
}
template<class T>
void display(Node<T>*head) {
    Node<T>*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->getData()<<endl;
        temp = temp->getLink();
    }
}
template<class T>
void insert(Node<T>* afterMe, const T& theData) {
    afterMe->setLink(new Node<T>(theData, afterMe->getLink( )));
}
template<class T>
void deleteNode(Node<T>* before) {
    Node<T> *discard;
    discard = before->getLink( );
    before->setLink(discard->getLink( ));
    delete discard;
}
template<class T>
void deleteFirstNode(Node<T>*& head) {
    Node<T> *discard;
    discard = head;
    head = head->getLink( );
    delete discard;
}
template<class T>
Node<T>* search(Node<T>* head, const T& target) {
    Node<T>* here = head;
    if (here == NULL)  {
        return NULL;
    }
    else {
        while (here->getData( ) != target && here->getLink( ) != NULL)
            here = here->getLink( );
        if (here->getData( ) == target)
            return here;
        else
            return NULL;
    }
}

template<class T>
void MyList<T>::insertHead(T theData) {
    head = new Node<T>(theData, head);
}

template<class T>
void MyList<T>::deleteHead() {
    Node<T> *discard;
    discard = head;
    head = head->link;
    delete discard;

}

template<class T>
bool MyList<T>::search(T &target) {
    Node<T> * here = head;
    if(here == NULL)
    {
        return false;
    }
    else
    {
        while(here->data!= target && here->link != NULL)
        {
            here = here->link;
        }
        if(here->data == target)
            return here;
        else
            return false;
    }
}

template<class T>
void MyList<T>::display() {
    while (head != NULL) {
        cout << head->data << endl;
        head = head->link;
    }
}
