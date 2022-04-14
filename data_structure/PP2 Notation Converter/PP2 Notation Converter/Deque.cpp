#include "Deque.hpp"

LinkedList::LinkedList(){
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

LinkedList::~LinkedList(){
    while(!empty()) removeFront();
    delete header;
    delete trailer;
}

bool LinkedList::empty() const{
    return (header->next == trailer);
}

const char& LinkedList::front() const{
    return header->next->str;
}

const char& LinkedList::back() const{
    return trailer->prev->str;
}

void LinkedList::add(Node* v, const char& e){
    Node* u = new Node;
    u->str = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

void LinkedList::addFront(const char& e){
    add(header->next, e);
}

void LinkedList::addBack(const char& e){
    add(trailer, e);
}

void LinkedList::remove(Node* v){
    Node* u = v->prev;
    Node* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void LinkedList::removeFront(){
    remove(header->next);
}

void LinkedList::removeBack(){
    remove(trailer->prev);
}

bool Deque::empty() const{
    return D.empty();
}

const char& Deque::front(){
    return D.front();
}

const char& Deque::back(){
    return D.back();
}

int Deque::size()const{
    return n;
}

void Deque::insertFront(const char& e){
    D.addFront(e);
    n++;
}

void Deque::insertBack(const char& e){
    D.addBack(e);
    n++;
}

void Deque::removeFront(){
    D.removeFront();
    n--;
}

void Deque::removeBack(){
    D.removeBack();
    n--;
}
