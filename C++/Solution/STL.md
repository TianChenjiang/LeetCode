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

#### 排序

```c++
sort(v.begin(), v.end()); //顺序
sort(v.begin(), v.end(), greater<int>()); //逆序
//自定义
struct Point {
  int x, y;
};
bool comparePoint(Point a, Point b) {
  return (a.x < b.x);
}
sort(v.begin(), v.end(), comparePoint);
```

注意用accumulate的时候，v.begin. v.begin()+2，是前闭后开的

#### 删除

```c++
for (auto it = vec.begin(); it != vec.end();) {
  if (*it == value) {
    it = vec.erase(it); //erase后，迭代器会指向下一个元素
  } else it++;
}
```





### unordered_map

```c++
s[m] != 0; // 判断是否已经有元素，这里最好不要直接用，因如果second存储的是索引的话，可能存储的是0，但表示有元素，易错！
count(key); // 判断是否有key存在，也可以用find(key) != m.end()
```

 求最大值：

```c++
unordered_map<char, int> m;
char chr = max_element(m.begin(), m.end(), cmp)->first; //这里如果不写cmp的话，好像默认是用key来排序

bool cmp(pair<char,int> p1, pair<char,int> p2) {
  return p1.second > p2.second;
}
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

push 插入元素到**队尾**

top pop 访问和弹出**队头**元素

找第k大的元素，可以维护一个K大小的小根堆，堆顶（队头）也就是第K大

```c++
for (int num : nums) {
  q.push(num);
  if (q.size() > K) {
    q.pop();
  }
}
```





### multiset

这个是允许重复元素的set，一种基于红黑树的数据结构，可以自动对元素进行排序（默认升序），又允许有重复值

`erase`如果删除元素，是默认把所有等于该元素的值删除掉；可以通过find找到确定的iterator再删除

// 和小根堆效果一样

```c++
for (int num : nums) {
  st.insert(num);
  if (st.size() > k) st.erase(st.begin());
}
```







### 迭代器知识

it.begin() 返回一个迭代器，指向第一个元素

it.end() 指向最后一个元素的下一个元素

it.rbegin() 指向最后一个元素

it.rend() 指向第一个元素的前一个位置







