#pragma once

#include <list>
#include <cassert>

struct Node {
    int data;
    Node* next;
};

bool hasLoop(Node* head) {
    if (!head) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;            // Move slow pointer by 1 step
      fast = fast->next->next;      // Move fast pointer by 2 steps

      if (slow == fast) {
        return true;              // Loop detected
      }
    }

    return false;                     // No loop detected
}

// Example usage
int main() {
    // Create a linked list with a loop
    Node* head = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    Node* third = new Node{3, nullptr};
    Node* fourth = new Node{4, nullptr};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;  // Create a loop

    if (hasLoop(head)) {
        std::cout << "Loop detected in the linked list.\n";
    } else {
        std::cout << "No loop detected in the linked list.\n";
    }

    return 0;
}
