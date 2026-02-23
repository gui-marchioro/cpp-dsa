# Queues

- Data strcuture that follows the **FIFO** (first-in, first-out) paradigm
- It is implemented using a linked list as its foundation
- It should have a reference to the first and the last item in the linked list
- This will ease insertion next to the last item, and poping the first item of the list
- Inside each element, only a reference to the next node is needed
- Considering the following queue:

    | #0 | -> | #1 | -> | #2 |

    - **#0** was the **first** element added, so it should be the **first** to leave the queue
    - **#2** was the **last** element added, so it should be the **last** to leave the queue

## Dequeue

- Different from a classic queue it is possible to add or remove elements in the first or the last item of the list (thus, not FIFO)
- It is implemented using a double linked list as its foundation
- e.g.:

    | #0 | <=> | #1 | <=> | #2 |
