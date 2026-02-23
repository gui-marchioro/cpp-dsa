# Stack

- Data strcuture that follows the **LIFO** (last-in, first-out) paradigm
- If the size is known upfront it could be implemented using an array
- But generally it is implemented using a linked list
- It should have a reference to the last item in the linked list
- This will ease insertion and removal in the end of the list
- Inside each element, only a reference to the previous node is needed
- Considering the following stack:

    | #0 | <- | #1 | <- | #2 |

    - **#0** was the **first** element added, so it should be the **last** to leave the queue
    - **#2** was the **last** element added, so it should be the **first** to leave the queue