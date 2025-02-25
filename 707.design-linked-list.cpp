/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30204
 *
 * [707] 设计链表
 */

// @lcpr-template-start
using namespace std;
// @lcpr-template-end
// @lc code=start
class MyLinkedList
{
public:
  MyLinkedList() {}
  ~MyLinkedList()
  {
    Node* cur = dummyHead_;
    while (cur != nullptr) {
      dummyHead_ = cur->next;
      delete cur;
      cur = dummyHead_;
    }
  }

  int get(int index)
  {
    if (index < 0 || index >= size_) {
      return -1;
    }

    Node* current = dummyHead_->next;
    for (; index > 0; --index) {
      current = current->next;
    }
    return current->val;
  }

  void addAtHead(int val)
  {
    Node* newNode = new Node{ nullptr, val };
    newNode->next = dummyHead_->next;
    dummyHead_->next = newNode;
    ++size_;
  }

  void addAtTail(int val)
  {
    Node* newNode = new Node{ nullptr, val };
    Node* current = dummyHead_;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
    ++size_;
  }

  void addAtIndex(int index, int val)
  {
    if (index > size_ || index < 0) {
      return;
    }

    Node* current = dummyHead_;
    Node* newNode = new Node{ nullptr, val };
    for (; index > 0; --index) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    ++size_;
  }

  void deleteAtIndex(int index)
  {
    if (index >= size_ || index < 0) {
      return;
    }

    Node* current = dummyHead_;
    for (; index > 0; --index) {
      current = current->next;
    }

    Node* tmp = current->next;
    current->next = tmp->next;
    delete tmp;
    --size_;
  }

private:
  struct Node
  {
    Node* next;
    int val;
  };

  Node* dummyHead_ = new Node{ nullptr, 0 };
  int size_ = 0;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
