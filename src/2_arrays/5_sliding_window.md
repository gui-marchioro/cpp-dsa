# Sliding Window

- Generally related to programs that ask you to find certain sub-arrays inside the array.
- The algorithm have the following format:  
    - while
        - r++ -> this will expand the window
        - while
            - l++ -> this will reduce the window
    - The while condition on which it will say when to grow or shrink the window generally has a certain counter or hashmap related to help evaluate the condition.

- e.g.

~~~python
def maximumLengthSubstring(self, s: str) -> int:
    l, r = 0, 0
    _max = 1
    counter = {}

    counter[s[0]] = 1

    while r < len(s) -1:
        r+=1
        if counter.get(s[r]):
            counter[s[r]] += 1
        else:
            counter[s[r]] = 1

        while counter[s[r]] == 3:
            counter[s[l]] -= 1
            l += 1
        _max = max(_max, r-l+1)
    
    return _max
~~~

