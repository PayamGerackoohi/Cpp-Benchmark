[Holiday Season](https://www.hackerearth.com/problem/algorithm/holiday-season-ab957deb/)

It's a holiday season for all school students around the world! Unfortunately, Mahamba is busy preparing for International Olympiad in Informatics, which will be held in Tehran, Iran. He is now facing a new challenge from his teacher Aceka, and it goes something like this:

You have a string x of length N, which consists of small English letters. You have to find the number of indexes a, b, c and d such that $1 \le a < b < c < d \le N$ and $x_a=x_c$, as well as $x_b=x_d$.

He is baffled and definitely needs some help. So, you, the best programmer in Lalalandia, decided to give him a hand!

## Input format

The first line contains the number N - the length of a string x. The second line contains the string x itself.

## Output format

The first and only line should contain the answer to the problem.

## Constraints
$1 \le N \le 2000$

The string x only contains small English letters.

| Sample Input | Sample Output |
| ------------ | ------------- |
| 5<br>ababa | 2 |

Time Limit: 2
Memory Limit: 256
Source Limit: -

## Explanation
There are only 2 variants: (a=1, b=2, c=3, d=4) and (a=2 ,b=3 ,c=4, d=5)
