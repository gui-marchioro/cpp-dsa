# Frequency Map

Useful technique used in string manipulation, which basically will count the occurrence of certain characters or substrings.

To do that it is very simple:

- Initialize a hashmap
- Add occurrences of chars/substrings and count them

e.g.

~~~python
{
    "a": 4,
    "b": 2
}
~~~

This algorithm can be used to solve different problems such:

- Anagram (different words that have the same set of characters)
- Palindrome (symetric words)
- Compression
- Crypto
- Sliding Window

e.g. Implementation
~~~python
def frequency_map(s: str) -> dict:
    freq = {}
    for ch in s:
        if ch in freq:
            freq[ch] += 1
        else:
            freq[ch] = 1
    return freq
~~~
