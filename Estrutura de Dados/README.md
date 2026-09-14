# Estrutura de Dados (Data Structures)

Classic data structures implemented in C++ (most of them as templates). Each folder is a standalone program whose `main` exercises the structure.

| Folder | Structure |
| --- | --- |
| [LES](LES) | Sorted static sequential list with binary search. |
| [LDS](LDS) | Sorted, resizable dynamic sequential list (template). |
| [LinkedList](LinkedList) | Sorted singly linked list of integers. |
| [LDE](LDE) | Generic sorted singly linked list with a configurable comparator (`lde.hpp`), used to build a hash table with separate chaining (`main.cpp`). |
| [DoubleLinkedList](DoubleLinkedList) | Sorted doubly linked list with copy constructor and assignment operator. |
| [LinkedStack](LinkedStack) | Generic linked stack, applied to checking balanced brackets. |
| [LinkedQueue](LinkedQueue) | Generic linked FIFO queue with copy constructor and assignment operator. |
| [Heap](Heap) | Max-heap on `std::vector`: O(n) build, insertion and removal of the maximum. |
| [Tree_2](Tree_2) | Binary search tree: insertion, search, removal and in-order traversal. |
| [Tree_3](Tree_3) | In-order traversal without recursion or a stack (Morris traversal). |
| [Tree](Tree) | AVL tree: insertion, removal, rotations and printing. |
| [BalancedTree](BalancedTree) | Same AVL implementation as `Tree` (kept as its own exercise). |
| [Oop](Oop) | C++ polymorphism warm-up: areas of geometric shapes through a virtual method. |

Some exercises started from an instructor-provided skeleton (for example, the BST base and printing code in `Tree`); this is noted in each file's header.

## Building

```bash
g++ -std=c++17 -Wall -Wextra Heap/main.cpp -o heap && ./heap
```
