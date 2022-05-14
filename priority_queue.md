# Priority Queue Notebook
---

## 什么是优先队列
一、优先队列

* 与队列具有类似的特性，即只能从队尾插入元素，从队首删除元素。
* 此外，优先队列中的最大元素总是位于队首，所以在进行出队时，总是将当前队列中的最大元素出队



二、优先队列的使用
 
1、首先要添加头文件
```cpp 
#include<queue>
```

2、优先队列的声明  

```cpp
priority_queue<type,container,function>
```  

其中第一个参数不可以省略，后两个参数可以省略。 

```
type:数据类型  
container:实现优先队列的底层容器，要求必须是以数组形式实现的容器  
function:元素之间的比较方式priority_queue<int> q;//定义一个优先队列，按照元素从大到小的顺序出队  
```

```cpp
//等同于
 priority_queue<int,vector<int>, less<int> >q;
//另外一种按元素从小到大顺序出队
priority_queue<int,vector<int>, greater<int> >q;
```  


3、基本操作
```cpp
q.top()    //访问队首元素
q.empty() //判断队列是否为空
q.push()   //插入元素到队尾
q.pop()    //出队队首元素
q.size()   //返回队列中元素的个数

示例代码priority_queue<int> q;
//将元素入队
q.push(1);
q.push(2);
q.push(3);
while(!q.empty()){
     cout<<q.top()<<endl;//输出队首元素
     q.pop();//出队
}
//从大到小依次输出3 2 1
```


## sort 方法
```cpp
sort(start,end,cmp)
```

> start: 表示排序数组起始的位置  
> end: 表示排序数组结束的位置  
> cmp: 用于排序的方法，可以不填，不填默认升序

```cpp
bool cmp(int x, int y)
{
    return x<y;    
    /*
        可以这样理解，sort第三个参数默认升序，
        这个地方是个bool函数。
        如果返回值结果为假，那么函数会互换他们的位置
        如果返回结果为真，就保持原来的位置不变 。
        如果x<y成立，那么就保持不变，否则就交换位置。 
    */ 
} 
```

```cpp
// 将 nums2 的值和对应索引push back 数组内
for(int i=0;i<n;i++){
    newnums2.push_back(pair<int,int>(nums2[i],i));
}

// sort 函数可以穿入 sort标志。按 first 进行排序
sort(newnums2.begin(),newnums2.end(),[](const pair<int,int>& a1,const pair<int,int>& a2){
    return a1.first<=a2.first;
});
```


## c++的 lambda 匿名函数写法

基本lambda语法

基本形式如下：

```cpp
[capture](parameters)->return-type {body}
```

> []叫做捕获说明符，表示一个lambda表达式的开始。接下来是参数列表，即这个匿名的lambda函数的参数，->return-type表示返回类型，如果没有返回类型，则可以省略这部分。最后就是函数体部分了。

我们可以这样输出"hello,world"

```cpp
auto func = [] () { cout << "hello,world"; };

func(); // now call the function
```

lambda函数能够捕获lambda函数外的具有自动存储时期的变量。函数体与这些变量的集合合起来叫闭包。

```cpp
[] 不截取任何变量
[&} 截取外部作用域中所有变量，并作为引用在函数体中使用
[=] 截取外部作用域中所有变量，并拷贝一份在函数体中使用
[=, &foo] 截取外部作用域中所有变量，并拷贝一份在函数体中使用，但是对foo变量使用引用
[bar] 截取bar变量并且拷贝一份在函数体重使用，同时不截取其他变量
[x, &y] x按值传递，y按引用传递
[this] 截取当前类中的this指针。如果已经使用了&或者=就默认添加此选项。
```




