 /*
 * Given the pointer to the head node of a linked listand an integer to insert at a certain position,
 * create a new node with the given integer as its  attribute, insert this node at the desired position
 * and return the head node.
 *
 * 'position' j indicates inserting a node j connections away from the head.
 * The head pointer given may be null meaning that the initial list is empty.
 */


#include <iostream>
#include <vector>


class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data, SinglyLinkedListNode* next=nullptr) {
        this->data = node_data;
        this->next = next;
    }
};


class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};


void print_singly_linked_list(SinglyLinkedListNode* head) {

    if (head) {
        SinglyLinkedListNode* curr = head;

        while (curr) {
            std::cout << curr->data << "->";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }
}


SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
	/*
     * Inputs: 
	 * head: a SinglyLinkedListNode pointer to the head of the list
	 * The function accepts following parameters:
	 * data: an integer value to insert as data in your new node
	 * position: an integer position to insert the new node, zero based indexing
     * 
     * Returns:
     * SinglyLinkedListNode pointer: a reference to the head of the revised list
	 */

    SinglyLinkedListNode** p = &head;
    for (int i = 0; i < position; ++i)
        p = &(*p)->next;
    *p = new SinglyLinkedListNode{ data, *p };

    return head;
}


int main() {
 
    std::vector<int> list{ 1 ,2, 3 };
    int position{ 2 }, data{ 4 };

    SinglyLinkedList* llist{ new SinglyLinkedList() };
    print_singly_linked_list(llist->head);

    for (const auto& elem : list) {
        llist->insert_node(elem);
    }
    print_singly_linked_list(llist->head);

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);
    print_singly_linked_list(llist_head);

    llist_head = insertNodeAtPosition(llist->head, data, 0);
    print_singly_linked_list(llist_head);

    llist_head = insertNodeAtPosition(llist->head, data, -1);
    print_singly_linked_list(llist_head);

    return 0;
}