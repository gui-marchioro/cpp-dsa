# Binary numbers

~~~
2^   7 6 5 4 3 2 1 0
    64 32 16 8 4 2 1
1 ->               1
     - - - - - - - -
3 ->             1 1
     - - - - - - - -
5 ->           1 0 1
     - - - - - - - -
~~~

- Bit 0 (2^0) is normally referred as parity bit, since all other bits are multiples of 2 (even numbers)
- When representing signed numbers, the last bit is the responsible of giving the sign to the number

## Left and Right Shift

- Binary shifting operation, generally represented by `>>` or `<<` in programming languages

- Right shift e.g.
~~~
5 ->                  1 0 1|
            - - - - - - - -|

5 >> 1 ->               1 0|1
            - - - - - - - -|
result:
2      ->               1 0|
            - - - - - - - -|
~~~

- Each bit we right shift has the effect of divinding by 2 (with some rounding error if a parity bit was present like what was shown in the last e.g.)

- Left shift e.g.
~~~
5 ->                  1 0 1|
            - - - - - - - -|

5 << 1 ->           1 0 1 0|
= 10        - - - - - - - -|

5 << 2 ->         1 0 1 0 0|
= 20        - - - - - - - -|
~~~

- Each bit we left shift has the effect of multuplying by 2 (only exception is if an overflow from the data type happens)

## AND, OR, NOT, XOR

- Binary operators that will compare binary numbers and give a result based in the operation choosen

### AND
- Only keeps an "1" if both compared bits are "1", else the result is "0"
~~~
5 & 12 ->       - - - - - 1 0 1
                - - - - 1 1 0 0
                _______________
= 4             - - - - 0 1 0 0
~~~
- `& 1` operation can be used to find if a number is odd or even
~~~
5 & 1 ->        - - - - - 1 0 1
                - - - - - - - 1
                _______________
= 1 -> ODD      - - - - - 0 0 1

2 & 1 ->        - - - - - 0 1 0
                - - - - - - - 1
                _______________
= 0 -> EVEN     - - - - - 0 0 0
~~~

### OR
- Only keeps a "0" if both compared bits are "0", else the result is "1"
~~~
5 | 12 ->       - - - - - 1 0 1
                - - - - 1 1 0 0
                _______________
= 13            - - - - 1 1 0 1
~~~

### XOR
- Results in "1" if compared bits are different, "0" otherwise
~~~
5 ^ 12 ->       - - - - - 1 0 1
                - - - - 1 1 0 0
                _______________
= 9             - - - - 1 0 0 1
~~~

### NOT
- Results in the complimentary number which summed by the original number equals -1
~~~
~5 ->           0 1 0 1
                _______
= -6            1 0 1 1
~~~