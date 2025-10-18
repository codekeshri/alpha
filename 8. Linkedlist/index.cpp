#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverse(ListNode* head) {
    ListNode *prev = nullptr, *curr = head, *next = nullptr;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

//   bool isPalindrome(ListNode* head) {
//     ListNode *fast = head, *slow = head, *t = head;
//     if (!head || !head->next) return true;
//     int count = 0;
//     while (t) {
//       count++;
//       t = t->next;
//     }
//     while (fast->next->next) {
//       fast = fast->next->next;
//       slow = slow->next;
//     }
//     cout << slow->val << " " << fast->val << endl;
//     ListNode* temp = reverse(slow->next);
//     cout << temp->val << " reverse head " << endl;
//     ListNode* tail = head;
//     while (temp == slow) {
//       if (tail->val != temp->val) return false;
//       tail = tail->next;
//       temp = temp->next;
//     }
//     return true;
//   }
// };

 bool isPalindrome(ListNode* head) {
        stack<int>st;
        int count = 0;
        ListNode* tail = head;
        
        while(tail != nullptr){
            count++;
            tail = tail->next;
        }

        int c = 0;
        tail = head;
        while(tail && c != count/2){
            st.push(tail->val);
            tail = tail->next;
        }

        if(count%2 != 0)st.pop();

        while(tail != nullptr){
            tail = tail->next;
            if(tail->val != st.top())return false;
            st.pop();
        }
        return true;
    }
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
  Solution sol;
  vector<int> vals = {1, 2};
  ListNode* head = createList(vals);
  printList(head);
  bool ans = sol.isPalindrome(head);
  cout << (ans ? "True" : "False") << endl;

  return 0;
}
