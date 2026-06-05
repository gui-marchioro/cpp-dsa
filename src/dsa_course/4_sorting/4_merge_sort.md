# Merge Sort

- Often used for sorting linked lists
- This is not a rule, but in general quick sort is used for arrays, and merge sort is used for linked lists
- Time Complexity: O(n logn)
- Space complexity: O(n)

## Algorithm

- Divide and conquer, fast and slow pointer
- 1st step is to divide the list until reduce it to a node
- 2nd merge sort

## Example

- Find the middle of the list by using fast and slow pointer
~~~
  sf
| 9 | -> | 3 | -> | 1 | -> | 7 |
           s        f
| 9 | -> | 3 | -> | 1 | -> | 7 |
           s                 f
| 9 | -> | 3 | -> | 1 | -> | 7 |
~~~
- Divide the list
~~~
  sf                sf
| 9 | -> | 3 |    | 1 | -> | 7 |
  s        f        s        f
| 9 | -> | 3 |    | 1 | -> | 7 |
~~~
- Divide the list
~~~
| 9 |    | 3 |    | 1 |    | 7 |
~~~
- Merge sort
~~~
| 9 |    | 3 |    | 1 |    | 7 |
| 3 | -> | 9 |    | 7 | -> | 1 |
~~~
- Merge remaining lists
~~~
| 1 | -> | 3 | -> | 7 | -> | 9 |
~~~

## Sample Implementation

~~~python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def findMiddle(head):
    slow = head
    fast = head.next
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow


def mergeTwoLists(l1, l2):
    head = ListNode()
    tail = head

    while l1 and l2:
        if l1.val < l2.val:
            tail.next = l1
            l1 = l1.next
        else:
            tail.next = l2
            l2 = l2.next
        tail = tail.next

    tail.next = l1 or l2
    return head.next


def mergesort(head):
    if not head or not head.next:
        return head

    middle = findMiddle(head)
    after_middle = middle.next
    middle.next = None

    left = mergesort(head)
    right = mergesort(after_middle)

    return mergeTwoLists(left, right)
~~~
