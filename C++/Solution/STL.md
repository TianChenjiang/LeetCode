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
或者   
string t = "";
while(getline(in, t, ',')) v.push_back(t)
ps: 两种方法有个区别，对于"a "来说，第一种方法会把末尾的空格略去，第二种方法会保留【LeetCode58】
```

#### 字符串的类栈函数

```c++
string str;
//取栈顶元素
str.back();
//弹出栈顶元素
str.pop_back();
//插入元素
str.push_back();
```



### array

动态创建数组

```c++
int *p = new int[len];
// int *p = new int[len](); 多加个括号表示初始化为0
int **p = new int*[row];
for (int i = 0; i < row; i++) {
  p[i] = new int[col];
}
```

释放

```c++
delete[] p;

//二维
for (int i = 0; i < row; i++) {
  delete[] p[i];
}
delete[] p;
```



### vector

`push_back()`是深度拷贝 

#### 一维数组初始化

```c++
vector<int> vec(100, -1);
vector<int> vec2(vec);
```

#### 二维数组初始化

```c++
vector<vector<int>> vec;
vec.resize(100, vector<int>(100, 0));
```

#### 复制

```c++
vector<int> vec2(vec1);
```

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

##### 二次排序

```c++
bool cmp(vector<int> v1, vector<int> v2)  {
  if (v1[0] == v2[0]) return v1[1] > v2[1]; //降序
  return v1[0] < v2[0]; //升序
}
```





#### 删除

```c++
for (auto it = vec.begin(); it != vec.end();) {
  if (*it == value) {
    it = vec.erase(it); //erase后，迭代器会指向下一个元素
  } else it++;
}
```





### map

```c++
//排序 如果针对value进行排序，需要把map的pair放入vector，然后再对vector排序
map<char, int> m;
vector<pair<char,int>> vec;
for (auto [c, freq] : m) {
  vec.push_back(make_pair(c, freq));
}
sort(vec.begin(), vec.end(), [&] (pair<char,int> p1, pair<char,int> p2)->bool {
		return p1.second > p2.second});
```

补充：

一般会用到的写法：

```c++
sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
   return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
 });
```



lamda语法：`[] (A x, A y) -> bool {return x < y;}`

`[ capture list ] ( parameter list) -> return type { function body; };`

`[捕获列表]( 参数列表 ) -> 返回值类型{函数体}`

注意：[]表示哪些参数需要传入，空的话表示不需要传入任何参数，常见的有&和=

补充捕获列表：

> - [] 不捕获任何变量。
> - [&] 捕获外部作用域中所有变量，并作为引用在函数体中使用（按引用捕获）。
> - [=] 捕获外部作用域中所有变量，并作为副本在函数体中使用（按值捕获）。
> - [=，&foo] 按值捕获外部作用域中所有变量，并按引用捕获 foo 变量。
> - [bar] 按值捕获 bar 变量，同时不捕获其他变量。
> - [this] 捕获当前类中的 this 指针，让 lambda 表达式拥有和当前类成员函数同样的访问权限。如果已经使用了 & 或者 =，就默认添加此选项。捕获 this 的目的是可以在 lamda 中使用当前类的成员函数和成员变量。





### unordered_map

```c++
s[m] != 0; // 判断是否已经有元素，这里最好不要直接用，因如果second存储的是索引的话，可能存储的是0，但表示有元素，易错！
count(key); // 判断是否有key存在，也可以用find(key) != m.end()
```

 遍历：

```c++
for (auto mm : m) {
  cout << mm.first << mm.second << endl;
}

for (auto [num, freq] : m) {
  cout << num << freq << endl;
}
```



求最大值：

```c++
unordered_map<char, int> m;
char chr = max_element(m.begin(), m.end(), cmp)->first; //这里如果不写cmp的话，好像默认是用key来排序

bool cmp(pair<char,int> p1, pair<char,int> p2) {
  return p1.second > p2.second;
}
```

清除元素：

```c++
st.erase(num);
```

`lower_bound`  返回一个迭代器，指向 >= key的第一个元素

 `upper_bound`返回一个迭代器，指向>key的第一个元素

ps：这两个属于std::map::lower_bound

用法：

```c++
map<int, int> m;
map<int, int>::iterator it = m.lower_bound(3);
```

如果需要排序，可以用vector存储key，然后再对vector排序

```c++
sort(vec.begin(), vec.end(), [&] (string a, string b) -> bool {
            return (m[a] == m[b]) ? a < b : m[a] > m[b];
});
```





### set

基于平衡树实现，key以一定的顺序排列

```c++
s.insert(num);
```



### unordered_set

基于hash table实现，可以以任何顺序排列，key被hash为indices，所以插入是随机的

```c++
unordered_set<int> s = {1, 2, 3};
s.find(x) != s.end(); //查找元素,返回迭代器，如果不等于end()，表示能找到这个元素
s.insert(num)
if (s.count(num)) //是否存在该元素
```





### queue

初始化

```c++
queue<TreeNode*> q({root});
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

内部是平衡二叉树，插入元素会自动调整，保证root-val > root-left->val

也保证根节点左右子树高度相等，这样二叉树高度最小，检索速度最快

<img src="../../../../学习/笔记合集/img/image-20210417141023244.png" alt="image-20210417141023244" style="zoom:33%;" />

这个是允许重复元素的set，一种基于红黑树的数据结构，可以自动对元素进行排序（默认升序），又允许有重复值

`erase`如果删除元素，是默认把所有等于该元素的值删除掉；可以通过find找到确定的iterator再删除

// 和小根堆效果一样

```c++
for (int num : nums) {
  st.insert(num);
  if (st.size() > k) st.erase(st.begin());
}
```



### list

链表

- `push_back()`
- `erase`



### 迭代器知识

it.begin() 返回一个迭代器，指向第一个元素

it.end() 指向最后一个元素的下一个元素

it.rbegin() 指向最后一个元素

it.rend() 指向第一个元素的前一个位置





在递增序列中：

lower_bound: 返回[first, last)中第一个>=val 的位置

upper_bound: 返回[first, last)中第一个val的位置

```c++
int a[15];
int lb = lower_bound(a, a + n + 1, 2) - a; //在[a,a+n+1)中找出大于等于2的位置，这个位置是从0开始
int ub = upper_bound(a, a + n + 1, 2) - a; //在[a,a+n+1)中找出大于2的位置，这个位置是从0开始
```





内部有序的数据结构：

下面三种都基于红黑树实现

- set

  - 也可以更改默认排序方式

  - ```c++
    // 从大到小排序的比较器函数对象
    struct Compartor
    {
        bool operator()(const int lhs,const int rhs) const
        {
            return rhs < lhs;
        }
    };
    // 声明使用自定义比较器的set
    set<int,Compartor> s;
    // 按照从小到大的顺序插入
    for (int i = 0; i < 10; i++){
        s.insert(i);
    }
    ```

  - 

- multiset

- map





### 智能指针

https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-unique-ptr-instances?view=msvc-160

一个智能指针用来表示一个单例

指针不能被复制，只能被move

<img src="https://tva1.sinaimg.cn/large/008i3skNly1gq0npc30fjj31720fewgs.jpg" alt="image-20210429154112439" style="zoom:33%;" />

