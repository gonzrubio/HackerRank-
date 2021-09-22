#include <iostream>


//struct SinglyLinkedListNode {
//    int m_data;
//    SinglyLinkedListNode* m_next;
//
//    SinglyLinkedListNode(const int data) : m_data{ data }, m_next{ nullptr }
//    {
//    }
//};
//
//
//class SinglyLinkedList {
//    // Can make template to sccept any data type
//    // Need destructor and clean up memory??
//private:
//    SinglyLinkedListNode* m_head;
//    SinglyLinkedListNode* m_tail;
//    int m_size;
//
//public:
//    SinglyLinkedList() : m_head{ nullptr }, m_tail{ nullptr }, m_size{ 0 } 
//    {
//    }
//    SinglyLinkedList(std::vector<int>& data) : m_head{ nullptr }, m_tail{ nullptr }, m_size{ 0 } {
//        for (const auto& elem : data) {
//            insert_node(elem);
//        }
//    }
//    void insert_node(const int data) {
//        // Insert node at the end of the linked list O(1)
//
//        SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
//        
//        if (is_empty()) {  
//            m_head = new_node;
//        }
//        else{
//            m_tail->m_next = new_node;
//        }
//        m_tail = new_node;
//        m_size++;
//    }
//    void insert_node_at(const int data, int position) {
//        // Insert node at 'position' jumps from head O(1)
//
//        // Bounds check
//        if (position < 0 || position > m_size) {
//            std::cout << "Specified position is out of bounds\n";
//        }
//        else {
//            // Loop until current position is the desired position (or until position is -1)
//            SinglyLinkedListNode* curr = m_head;
//
//            while (position-- + 1) {
//                if (position == -1) {
//
//                    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
//
//                    // Pointer assignment of current node and new node
//                    new_node->m_next = curr;
//                    curr = new_node;
//                }
//                else {
//                    curr = curr->m_next;
//                }
//            }
//            m_size++;
//        }
//    }
//    bool is_empty() const {
//        return m_head ? false : true;
//    }
//    void print() const {
//
//        if (!is_empty()) {
//            SinglyLinkedListNode* curr{ m_head };
//
//            while (curr) {
//                std::cout << curr->m_data << "->";
//                curr = curr->m_next;
//            }
//            std::cout << "NULL\n";        
//        }
//    SinglyLinkedListNode** p = &head;
//    for (int i = 0; i < position; ++i)
//        p = &(*p)->next;
//    *p = new SinglyLinkedListNode{ data, *p };
// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/forum/comments/221112
//    }
//    int size() const {
//        return m_size;
//    }
//    // remove at O(1)
//    // remove value O(n)
//    // reverse O(n)
//    // empty O(n)
// ~LinkedList() {  // Ask on stack overflow / code review if this is right. google destrutor linked list and why use it?
// https://www.google.com/search?q=delete+memory+linked+list+class&rlz=1C1RXQR_enCA953CA953&sxsrf=AOaemvL_GrO5qgzTHWEVH2Zx30Rgh9VN9g%3A1632331656143&ei=iGdLYb2gCNvL0PEPy4qekAM&oq=delete+memory+linked+list+class&gs_lcp=Cgdnd3Mtd2l6EAM6BwgAEEcQsANKBAhBGABQvFFYtWFg4m5oAnACeACAAWiIAcYEkgEDNi4xmAEAoAEByAEIwAEB&sclient=gws-wiz&ved=0ahUKEwi9hJSkjZPzAhXbJTQIHUuFBzIQ4dUDCA8&uact=5
// https://stackoverflow.com/questions/21237676/delete-a-linked-list-before-closing-a-c-program
//        while (LinkedList* head = next) {
//            next = head->next;
//            head->next = nullptr;
//            delete head;
//        }
//    }
//};



int main() {

}