#include <iostream>
#include <array>

/*
    Given a single linked list of integers (l) and an integer (k),
    remove all elements of the list (l) equal to integer (k).

    ie. l = [3, 1, 2, 3, 4, 5] and k = 3 -> removeKFromList(l, k) = [1, 2, 4, 5]
    ie. l = [1, 2, 3, 4, 5, 6, 7] and k = 10 -> removeKFromList(l, k) = [1, 2, 3, 4, 5, 6, 7]

    Note: Solve in O(n) time using O(1) additional space where n is the number of elements.
*/

struct ListNode
{
    int value ;       // integer in a given node.
    ListNode *next ;  // Pointer to the next node.
};

ListNode* arrayToList(const int *arr, const int len)
{
    std::cout << "Input array: [ " ;
    for (int element{0} ; element < len ; ++element)
    {
        std::cout << arr[element] << " " ;
    }
    std::cout << "]\n" ;

    ListNode *root{ nullptr } ;          // Head (root). Pointer to first elemeent in list.
    for (int element{0} ; element < len ; ++element)
    {
        ListNode *newOne{ new ListNode} ; // Dynamically allocate node.
        newOne->value = arr[element] ;    // Follow pointer and access member.
        newOne->next = root ;             // Make new entry point to next node (where root was pointing).
        root = newOne ;                   // Make root point to this new entry (prepending).
    }
    return root ;
}

void printList(ListNode *root)
{
    // Reverse printing (traversal) ;
    //std::cout << "Linked list: " ;
    /*for (ListNode *curr{root} ; curr != nullptr ; curr = curr->next)
    {
        std::cout << curr->value << "->" ;
    }
    std::cout << "nullptr\n" ;*/

    // Same order as input with recursive aproach.
    if (root)
    {
        printList(root->next) ;
        std::cout << root->value << "->" ;
    }
}

ListNode* removeKFromList(ListNode *l, const int k)
{
    // Write algrithm here
    if (l == nullptr) return nullptr;
    l->next = removeKFromList(l->next, k);
    if (l->value == k) return l->next;

    return l ;
}

int main()
{
    // Input array and element to remove.
    constexpr int k{3} ;
    int arr[] {3, 1, 2, 3, 4, 5} ;
    int len{ sizeof(arr)/sizeof(arr[0]) } ;

    // Pointer to root (head) of linked list.
    ListNode *l = arrayToList(arr,len) ;

    // Input singly linked list
    std::cout << "Input Linked list: " ;
    printList(l) ;
    std::cout << "nullptr\n" ;

    // Remove k from l.
    removeKFromList(l,k) ;

    // output singly linked list
    std::cout << "Output Linked list: " ;
    printList(l) ;
    std::cout << "nullptr\n" ;

    return 0;
}
