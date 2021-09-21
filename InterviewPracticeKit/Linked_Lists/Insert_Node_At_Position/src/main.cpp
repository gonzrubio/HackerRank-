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
    // Can make template to sccept any data type
    // Need destructor and clean up memory??
private:
    SinglyLinkedListNode* m_head;
    SinglyLinkedListNode* m_tail;
    int m_size;

public:
    SinglyLinkedList() : m_head{ nullptr }, m_tail{ nullptr }, m_size{ 0 } 
    {
    }
    SinglyLinkedList(std::vector<int>& data) : m_head{ nullptr }, m_tail{ nullptr }, m_size{ 0 } {
        for (const auto& elem : data) {
            insert_node(elem);
        }
    }
    void insert_node(const int data) {
        // Insert node at the end of the linked list O(1)

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
    void insert_node_at(const int data, int position) {
        // Insert node at 'position' jumps from head O(1)

        // Bounds check
        if (position < 0 || position > m_size) {
            std::cout << "Specified position is out of bounds\n";
        }
        else {

            // Insert to an empty llist or to the end of the llist
            if (is_empty() || position == m_size) {
                insert_node(data);
            }
            else {

                // Loop until current position is the desired position (or until position is -1)
                SinglyLinkedListNode* curr = m_head;

                while (position-- + 1) {
                    if (position == -1) {

                        SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);

                        // Pointer assignment of current node and new node
                        new_node->m_next = curr;
                        curr = new_node;
                        print();

                    } else {
                        curr = curr->m_next;
                    }
                }
                m_size++;
            }
        }
    }
    bool is_empty() {
        return m_head ? false : true;
    }
    void print() {
        if (is_empty()) return;

        SinglyLinkedListNode* curr{ m_head };
        while (curr) {
            std::cout << curr->m_data << "->";
            curr = curr->m_next;
        }
        std::cout << "NULL\n";
    }
    int size() {
        return m_size;
    }
    // remove at O(1)
    // remove value O(n)
    // reverse O(n)
    // empty O(n)
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
    llist->print();

    llist->insert_node_at(0, 0);
    llist->print();

    llist->insert_node_at(1, llist->size());
    llist->print();

    llist->insert_node_at(100, 0);
    llist->print();

    llist->insert_node_at(100, 1);
    llist->insert_node_at(100, 2);
    llist->insert_node_at(900, 1);
    llist->print();

    //SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);
    //llist->size();
    //llist->print();

    return 0;
}