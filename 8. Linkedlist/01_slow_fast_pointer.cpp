#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* createList(vector<int> vals) {
  if (vals.empty()) return nullptr;
  ListNode* head = new ListNode(vals[0]);
  ListNode* curr = head;
  for (int i = 1; i < vals.size(); ++i) {
    curr->next = new ListNode(vals[i]);
    curr = curr->next;
  }
  return head;
}

void printList(ListNode* head) {
  while (head) {
    cout << head->val;
    if (head->next) cout << " ";
    head = head->next;
  }
  cout << endl;
}



int main() {
  vector<int> vals = {1, 2};
  ListNode* head = createList(vals);
  printList(head);

  return 0;
}
