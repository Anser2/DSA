#include <iostream>
using namespace std;

// Define the ListNode structure
struct ListNode {
    int data;           // Data stored in the node
    ListNode* next;     // Pointer to the next node
    ListNode* previous; // Pointer to the previous node
};

// Function to reverse a doubly linked list
ListNode* reversingDoublyLinkedList(ListNode* head) {
    if (head == nullptr) {
        return nullptr; // Empty list, nothing to reverse
    }
    ListNode* current = head;
    ListNode* temp = nullptr;
    // Traverse the list and swap next and previous pointers for each node
    while (current != nullptr) {
        temp = current->previous;       // Store the previous pointer in a temporary variable
        current->previous = current->next; // Swap previous and next pointers
        current->next = temp;           // Assign the stored previous pointer to next
        current = current->previous;    // Move to the next node (which is now in previous)
    }
    // After the loop, temp points to the new head (last node of the original list)
    if (temp != nullptr) {
        head = temp->previous; // Update the head to point to the new first node
    }
    return head;
}

// Function to search and replace nodes
ListNode* searchAndReplace(ListNode* head) {
    if (head == nullptr) {
        cout << "The list is empty!" << endl;
        return head;
    }
    int a, b;
    cout << "Enter the first value to search: ";
    cin >> a;
    cout << "Enter the second value to search: ";
    cin >> b;
    ListNode* current = head;
    ListNode* nodeA = nullptr; // Node containing value 'a'
    ListNode* nodeB = nullptr; // Node containing value 'b'

    // Step 1: Find the node with value 'a'
    while (current != nullptr && current->data != a) {
        current = current->next;
    }
    if (current != nullptr) {
        nodeA = current;
    }

    // Step 2: Find the node with value 'b'
    current = head; // Reset current to start from the head again
    while (current != nullptr && current->data != b) {
        current = current->next;
    }
    if (current != nullptr) {
        nodeB = current;
    }

    // Step 3: Check if both nodes were found
    if (nodeA == nullptr || nodeB == nullptr) {
        cout << "One or both values not found in the list." << endl;
        return head;
    }

    // Step 4: Handle edge case where nodeA and nodeB are the same
    if (nodeA == nodeB) {
        cout << "Both values refer to the same node. No swap needed." << endl;
        return head;
    }

    // Step 5: Swap the nodes
    // Update previous pointers
    if (nodeA->previous != nullptr) {
        nodeA->previous->next = nodeB;
    } else {
        head = nodeB; // If nodeA was the head, update head
    }
    if (nodeB->previous != nullptr) {
        nodeB->previous->next = nodeA;
    } else {
        head = nodeA; // If nodeB was the head, update head
    }

    // Update next pointers
    if (nodeA->next != nullptr) {
        nodeA->next->previous = nodeB;
    }
    if (nodeB->next != nullptr) {
        nodeB->next->previous = nodeA;
    }

    // Swap the previous and next pointers of nodeA and nodeB
    ListNode* tempNext = nodeA->next;
    ListNode* tempPrev = nodeA->previous;
    nodeA->next = nodeB->next;
    nodeA->previous = nodeB->previous;
    nodeB->next = tempNext;
    nodeB->previous = tempPrev;

    return head;
}

// Helper function to print the list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Helper function to create a new node
ListNode* createNode(int data) {
    ListNode* newNode = new ListNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->previous = nullptr;
    return newNode;
}

int main() {
    // Create a sample doubly linked list: 1 <-> 2 <-> 6 <-> 7 <-> 4
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->previous = head;
    ListNode* temp = head->next; // Use a temporary pointer for chaining
    temp->next = createNode(6);
    temp->next->previous = temp;
    temp = temp->next;
    temp->next = createNode(7);
    temp->next->previous = temp;
    temp = temp->next;
    temp->next = createNode(4);
    temp->next->previous = temp;

    cout << "Original list: ";
    printList(head);

    // Call the searchAndReplace function and update the head
    head = searchAndReplace(head);

    // Print the list after swapping
    cout << "List after swapping: ";
    printList(head);

    // Reverse the list
    head = reversingDoublyLinkedList(head);
    cout << "Reversed list: ";
    printList(head);

    // Clean up memory (optional, but good practice)
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}