[Maximum Borders](https://www.hackerearth.com/problem/algorithm/maximum-border-9767e14c/)

You are given a table with `n` rows and `m` columns. Each cell is colored with white or black. Considering the shapes created by black cells, what is the maximum border of these shapes? Border of a shape means the maximum number of consecutive black cells in any row or column without any white cell in between.

A shape is a set of connected cells. Two cells are connected if they share an edge. Note that no shape has a hole in it.

Input format

The first line contains `t` denoting the number of test cases.
The first line of each test case contains integers `n`, `m` denoting the number of rows and columns of the matrix. Here, `'#'` represents a black cell and `'.'` represents a white cell. 
Each of the next `n` lines contains  integers.
Output format

Print the maximum border of the shapes.

| Sample Input | Sample Output |
|-|-|
| 10<br>2 15<br>.....####......<br>.....#.........<br> | 4 |
| 7 9<br>...###...<br>...###...<br>..#......<br>.####....<br>..#......<br>...#####.<br>.........<br> | 5 |
| 18 11<br>.#########.<br>########...<br>.........#.<br>####.......<br>.....#####.<br>.....##....<br>....#####..<br>.....####..<br>..###......<br>......#....<br>....#####..<br>...####....<br>##.........<br>#####......<br>....#####..<br>....##.....<br>.#######...<br>.#.........<br> | 9 |
| 1 15<br>.....######....<br> | 6 |
| 5 11<br>..#####....<br>.#######...<br>......#....<br>....#####..<br>...#####...<br> | 7 |
| 8 13<br>.....######..<br>......##.....<br>########.....<br>...#.........<br>.............<br>#######......<br>..######.....<br>####.........<br> | 8 |
| 7 5<br>.....<br>..##.<br>###..<br>..##.<br>.....<br>..#..<br>.#...<br> | 3 |
| 14 2<br>..<br>#.<br>..<br>#.<br>..<br>#.<br>..<br>..<br>#.<br>..<br>..<br>..<br>#.<br>..<br> | 1 |
| 7 15<br>.###########...<br>##############.<br>...####........<br>...##########..<br>.......#.......<br>.....#########.<br>.#######.......<br> | 14 |
| 12 6<br>#####.<br>###...<br>#.....<br>##....<br>###...<br>......<br>.##...<br>..##..<br>...#..<br>..#...<br>#####.<br>####..<br> | 5 |

Time Limit: 1
Memory Limit: 256
Source Limit: -
