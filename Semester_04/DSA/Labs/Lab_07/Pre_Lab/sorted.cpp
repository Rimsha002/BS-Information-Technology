// template<typename T>
// void DoublyLinkedList<T>::sort() {
//     if (!head || !head->next) return; // If list is empty or has one element, no need to sort

//     DNode<T>* sortedTail = nullptr;

//     while (sortedTail != tail) {
//         DNode<T>* smallest = head;
//         DNode<T>* current = head;

//         while (current != sortedTail) {
//             if (current->data < smallest->data)
//                 smallest = current;
//             current = current->next;
//         }

//         if (smallest != head) {
//             // Update links to place smallest node at the head
//             if (smallest->prev) smallest->prev->next = smallest->next;
//             if (smallest->next) smallest->next->prev = smallest->prev;
//             if (smallest == tail) tail = smallest->prev;

//             smallest->next = head;
//             head->prev = smallest;
//             smallest->prev = nullptr;
//             head = smallest;
//         }
//         sortedTail = smallest;
//     }
// }



// Reverse
// template<typename T>
// void DoublyLinkedList<T>::reverse() {
//     DNode<T>* current = head;
//     DNode<T>* temp = nullptr;

//     while (current) {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev;
//     }

//     if (temp) head = temp->prev;  // Update head pointer to the new first node
// }
