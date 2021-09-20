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
    int m_data;
    SinglyLinkedList* m_next;
    
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
    SinglyLinkedList() : m_head{nullptr}, m_tail{ nullptr } {
    }
    void insert_node(const int data) {
        SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
        if (m_head) {
            m_head = new_node;
        }
        m_tail = new_node;
    }
    void insert_node_at(const int data, const int position) {

    }
    int size() {
        return m_size;
    }
    void print() {
        std::cout << m_head->data << "->";

    }
};


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
    return head;
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    std::vector<int> nodes{ 1, 2, 3};
    for (int i = 0; i < nodes.size(); i++) {
        llist->insert_node(nodes[i]);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist_head);

    fout.close();

    return 0;
}