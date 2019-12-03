#### 子集树

> 从n个元素的集合S中找出S满足某种性质的子集
>
> 可以用剪枝的技巧



##### 0-1背包

```c++
void backtrack(int t) {
if (t > n)
 output(x);
else
 for (int i = 0; i < l; i++) {
  x[t] = i;
  if (constraint(t) && bound(t))
   backtrack(t + 1);
 }
}
```





#### 排列树

> 求所给问题的确定n个元素满足某种性质的排列

##### 旅行家问题

```c++
void backtrack(int t) {
if (t > n)
 output(x);
else
 for (int i = t; i < n; i++) {
  swap(x[t], x[i]);
  if (constraint(t) && bound(t))
   backtrack(t + 1);
  swap(x[t], x[i]);
 }
}
```



#### 经典例题

[八皇后问题](https://www.2cto.com/kf/201405/302318.html)


