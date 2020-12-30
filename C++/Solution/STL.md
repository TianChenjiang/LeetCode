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



### priority_queue

```c++
priority_queue<int, vector<int>, less<int>> q; // 降序队列，从队头到队尾递减 大顶堆 默认是大顶堆
priority_queue<int, vector<int>, greater<int>> q; //升序队列 小顶堆

//重载操作符 < 
bool operator<(Node a, Node b) {
  if (a.x > b.x) return a.y > b.y;
  return a.x > b.x;
}

//自定义排序
struct cmp {
  bool operator() (Node a, Node b){ 
    if(a.x == b.x)  return a.y >= b.y;
    else return a.x > b.x;
  }
}

//注意：正好是反着的，小顶堆是>,大顶堆是<
//小顶堆
struct cmp1{
	    bool  operator ()  (int  a , int  b){
	   	      return a > b;
	   } 
}; 

//大顶堆
struct cmp2{
	   bool operator ()( int s , int d){
	   	   return s < d;
	   }
};
```

push 插入元素到队尾

top pop 访问和弹出队头元素









