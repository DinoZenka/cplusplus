
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
public:
  struct Node {
    T value;
    Node* next = nullptr;
  };

  ~LinkedList()
  {
      
      while(head!=nullptr)
      {
        Node *tmp = head;
        head = tmp->next;
        delete tmp;
      }
  }

  void PushFront(const T& value)
  {
    if(head == nullptr)
    {
      Node *tmp = new Node;
      tmp->value = value;
      tmp->next = nullptr;
      head = tmp;
    }
    else
    {
      Node *tmp = new Node;
      tmp->value = value;
      tmp->next = head;
      head = tmp;
    }
  }

  void InsertAfter(Node* node, const T& value)
  {
      if(!node)
        PushFront(value);
      else
      {
        Node *tmp = new Node;
        tmp->value = value;
        tmp->next = node->next;
        node->next = tmp;
      }
  }
  void RemoveAfter(Node* node)
  {
      Node *tmp;
      if(!node)
        PopFront();
      else if(node->next)
      {
        if(node->next->next)
        {
          tmp = node->next;
          node->next = tmp->next;
          delete tmp;
        }
      else
      {
        tmp = node->next;
        node->next = nullptr;
        delete tmp;
      }  
      }     
      else    
        return;
  }
  
  void PopFront()
  {
  
    if(head == nullptr) return;
    else  if(head->next == nullptr)
    {
      Node *tmp = head;
      delete tmp;
      head = nullptr;
    }
    else
    {
      Node *tmp = head;
      head = tmp->next;
      delete tmp;
    }
    
  }

  Node* GetHead() { return head; }
  const Node* GetHead() const { return head; }

private:
  Node* head = nullptr;
};

int main() {
  
  LinkedList<int> ls;      
  ls.PopFront();
  LinkedList<int>::Node *node = nullptr;
  ls.RemoveAfter(node);
  ls.PushFront(1);
  ls.PushFront(2);

  LinkedList<int>::Node *node2 = ls.GetHead();
  ls.RemoveAfter(node2);
  cout<<ls.GetHead()->value<<endl;
  

  return 0;
}
