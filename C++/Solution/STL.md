### string

String -> int  `stoi(str)`

int -> string   `to_string(number)`

Char -> string  `string(1, 'a')`;

#### split

```c++
string str = "a b c"
istringstream in(str);
string word = "";
while (in >> word); 或者 for (string word; in >> word)
```



###  



### Vector

#### 清空

```c++
vector<int> vec = {1,2,3};
vec.clear();
cout << vec.size();    // 0
cout << vec.capacity(); // 3
```



### unordered_map

```c++
s[m] != 0 // 判断是否已经有元素，这里最好不要直接用，因如果second存储的是索引的话，可能存储的是0，但表示有元素，易错！
```



### unordered_set

```c++
unordered_set<int> s = {1, 2, 3};
s.find(x) != s.end(); //查找元素,返回迭代器，如果不等于end()，表示能找到这个元素
s.insert()

```

