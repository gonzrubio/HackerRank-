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


struct SinglyLinkedListNode {
    int m_data;
    SinglyLinkedListNode* m_next;

    SinglyLinkedListNode(const int data) : m_data{ data }, m_next{ nullptr }
    {
    }
};


class SinglyLinkedList {
private:
    SinglyLinkedListNode* m_head;
    SinglyLinkedListNode* m_tail;
    int m_size;

public:
    SinglyLinkedList() : m_head{ nullptr }, m_tail{ nullptr }, m_size{ 0 } 
    {
    }
    void insert_node(const int data) {
        // Insert node at the end of the linked list O(1).

        SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
        
        if (is_empty()) {  
            m_head = new_node;
        }
        else{
            m_tail->m_next = new_node;
        }
        m_tail = new_node;
        m_size++;
    }
    // void insert_node_at(const int data, const int position) {
    // O(1)
    // }
    // remove at O(1)
    // remove value O(n)
    bool is_empty() {
        return m_head ? false : true;
    }
    int size() {
        return m_size;
    }
    void print() {
        if (is_empty()) return; // need this here or handles empty lists automatically?
        SinglyLinkedListNode* curr{ m_head };
        while (curr) { // I think this handles the empty case.
            std::cout << curr->m_data << "->";
            curr = curr->m_next;
        }
        std::cout << "NULL\n";
    }
};


// SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
// 	/*
//      * Inputs: 
// 	 * head: a SinglyLinkedListNode pointer to the head of the list
// 	 * The function accepts following parameters:
// 	 * data: an integer value to insert as data in your new node
// 	 * position: an integer position to insert the new node, zero based indexing
//      * 
//      * Returns:
//      * SinglyLinkedListNode pointer: a reference to the head of the revised list
// 	 */
//     return head;
// }


int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    std::cout << llist->is_empty() << '\n';
    std::cout << llist->size() << '\n';
    llist->print();

    std::vector<int> nodes{ 1, 2, 3};
    for (std::size_t i = 0; i < nodes.size(); i++) {
        llist->insert_node(nodes[i]);
    }

    std::cout << llist->is_empty() << '\n';
    std::cout << llist->size() << '\n';
    llist->print();


    // SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);
    // llist->size();
    // llist->print();

    return 0;
}