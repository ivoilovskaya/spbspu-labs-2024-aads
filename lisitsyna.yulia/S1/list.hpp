#ifndef LIST_HPP
#define LIST_HPP
#include "node.hpp"
#include "iterator.hpp"
#include <cstddef>
#include <memory>

namespace lisitsyna
{
  template<typename T>
  class List
  {
  public:
    List() = default;
    ~List();

    T& operator[](const int index);
    void popFront();
    void pushBack(T data);
    void clearList();
    void pushFront(T data);
    void insert(T data, int index);
    void popBack();
    size_t GetSize();
    bool isEmpty();

  private:
    Node<T>* head, tail;
    size_t size() const;
  };
}

template<typename T>
lisitsyna::List<T>::~List()
{
  clearList();
}

template<typename T>
void lisitsyna::List<T>::popFront()
{
  if (head == nullptr) return;
  if (head == tail)
  {
    delete tail;
    head = tail = nullptr;
    return;
  }

  Node<T>* node = head
  head = node->next;
  delete node;
}

template<typename T>
void lisitsyna::List<T>::pushBack(T data)
{
  Node<T>* node = new Node(data);
  if (head == nullptr) head = node;
  if (tail != nullptr) tail->next = node;
  tail = node;
}

template<typename T>
void lisitsyna::List<T>::clearList()
{
  while (size)
  {
    popFront();
  }
}

template<typename T>
T& lisitsyna::List<T>::operator[](const int index)
{
  int counter = 0;
  Node<T>* current = this->head;
  while (current != nullptr)
  {
    if (counter == index)
    {
      return current->data;
    }
    current = current->Next;
    counter++;
  }
}

template<typename T>
void lisitsyna::List<T>::pushFront(T data)
{
  Node<T>* node = new Node(data);
  node->next = head;
  head = node;
  if (tail == nullptr) tail = node;
}

template<typename T>
void lisitsina::List<T>::popBack(T data)
{
  if (tail == nullptr) return;
  if (head == tail)
  {
    delete tail;
    head = tail = nullptr;
    return;
  }
  Node<T>* node = head;
  for(node->next != != tail; node = node->next);
  node->next = nullptr;
  delete tail;
  tail = node;
}

template<typename T>
void lisitsyna::List<T>::insert(T data, int index)
{
  if (index == 0)
  {
    push_front(data);
  }
  else
  {
    Node<T>* previous = this->head;
    for (int i = 0; i < index - 1; i++)

    {
      previous = previous->Next;
    }
    Node<T>* newNode = new Node<T>(data, previous->Next);
    previous->Next = newNode;
    size++;
  }
}
#endif