#ifndef DEQUE_H
#define DEQUE_H

class Node{
    private:
    char str;
    Node* prev;
    Node* next;
    friend class LinkedList;
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    const char& front() const;
    const char& back() const;
    void addFront(const char& e);
    void addBack(const char& e);
    void removeFront();
    void removeBack();
private:
    Node* header;
    Node* trailer;
protected:
    void add(Node* v, const char& e);
    void remove (Node* v);
};

class Deque{
public:
    int size() const;
    bool empty() const;
    const char& front();
    const char& back();

    void insertFront(const char& e);
    void insertBack(const char& e);
    void removeFront();
    void removeBack();
private:
    LinkedList D;
    int n = 0;
    friend class NotationConverter;
};

#endif
