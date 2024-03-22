##### numpy

```python
np.array([2,3,4]);
import math
import sys
import numpy as np

"""
数组创建
所有元素类型都相同的列表
"""
# np.array([]) 参数为一个python列表
# a = np.array([2, 4, 6])
# a.dtype -> 查看元素类型

# print(np.array([[1, 2, 3], [4, 5, 6]]))

# 显式确定类型
# a = np.array([[1, 2, 4], [4, 5, 6]], dtype=float)
# print(a)

# 默认给float类型
# a = np.zeros((3, 4),dtype=int)
# print(a)

# 初始化 默认float类型
# a = np.ones((4, 5))
# print(a)

# 默认值是取决于内存那个区域的原始残留数据,相当于没有初始化的数组
# a = np.empty((2, 3))
# print(a)

# 创建从 10开始加到20, 每次加5, 不包括end
# start = 10
# end = 20
# walk = 5
# print(np.arange(start, end, walk))
# 同理
# print(np.arange(10, 20, 0.5))

# 上面步长由于精度问题无法预测元素的数量，如果想要精确元素的数量，用lin-space
# start = 0
# end = 10
# size = 10
# print(np.linspace(start, end, size))

# sinx 0 - 2 * pi , 取100个点
# start = 0
# end = 2 * math.pi
# size = 100
# x = np.linspace(start, end, size)
# y = np.sin(x)
# 这样x与y的维度完全一样，通过linspace生成固定个数的点，然后可以进行绘图.


## 3维度
# print(np.arange(24).reshape(2, 3, 4))
# 最后一个轴从左到右，其余从上到下

# 禁止打印省略
# np.set_printoptions(threshold=sys.maxsize)
# print(np.arange(10000).reshape(400, 25))

# a = np.arange(2, 5)
# b = np.arange(1, 4)
# print(a)
# print(b)
# print(a / b)   # 逐项相除
# print(a * b)   # 逐项相乘
# print(a ** b)  # a的b次方

# print(np.arange(33, 69).dtype)
# print(a < 55)           # 布尔类型的数组


# random类 random方法 2行3列
# print(np.random.random((2, 3)))
# a = np.arange(0, 10).reshape((2, 5))
# print(a.max())
# print(a.min())
# print(a.sum())
# 指定axis 只在axis轴上操作
# axios=0 columns
# axios=1 rows

# print(np.exp(np.array([2, 3, 4]))) # 对每个元素求e

# 索引 切片 迭代

# a = np.arange(10) ** 3
# print(a[0])    # 可以通过索引访问
# print(a[1:5])  # 截取索引为1-5的元素，索引从0开始
# print(a[-5:-1])
# print(a[::-1])  # start:end:walk start缺省为0,end缺省为最后一个元素,并不是-1
# print(a[:-1:])  # 因为end最后取不到,所以如果想取到最后一个元素只需要缺省即可
# print(a[4::1])  # such as this
# for i in a:
#     print(i ** (1/3.))


row = 3
col = 4


def f(x, y):
    return 10 * x + y


# # lambda input,output
# b = np.fromfunction(lambda x, y: 10 * x + y, (row, col), dtype=int)
# print(b)
# x , y is i , j    i = 0 ~ 2 j = 0 ~ 3
# print(b[2, 3]) # 矩阵通过逗号的形式访问
# b[哪些行,哪些列]
# print(b[0:2, 1:3])
# 缺省的就认为取完
# b[-1] # 缺省列,就认为取所有列
# ... == : 都代表取编所有
# print(b[1, ...])
# b = np.arange(20).reshape(4,5)
# for row in b:
#     print(row)

# b.flat 对 b的每一个元素进行遍历
# for element in b.flat:
#     print(element)

# a = np.zeros((3, 4))[1:3,1:3]# 进行转至
# a[:,:] = 2
# a[1,...] = 3
# print(a)
# # 将数组拉成一维度,按列拉
# print(a.ravel())


# reshape -1 会自动计算
# a = np.zeros((4,5)).reshape(-1,10)
# print(a)

# 向下取整
# print(np.floor([2.4, 5.6, 5.9]))
# print(type(np.floor([3.4, 5.6, 5.6])))

# b = np.array([1, 2, 3, 4])
# b = b.reshape(2, 2)
# c = np.array([3, 4, 5, 6])
# c = c.reshape(2, 2)
# # v竖向 h横向
# print(np.vstack((b, c)))
# print(np.hstack((b, c)))

# 按列切割
# d = np.arange(0,10).reshape(2,5)
# print(d)
# 按纵向分成五等分
# print(np.hsplit(d, 5))
# 按纵向切 在索引0 和 2 的前面切一刀,但是注意0的前面是空数组，最后的后面也是一个空数组.
# print(np.hsplit(d, (0, 2)))
# d = np.arange(0,10).reshape(5,2)
# print(d)
# print(np.vsplit(d, 5))
# print(np.vsplit(d, (1, 3)))

# 合并 有相同维度 shape相同
# shape 相同,按h是横向放,v是竖着放
# a = np.array([[2, 3], [4, 5]])
# b = np.array([[3, 4], [5, 6]])
# c = np.hstack((a, b))
# c = np.vstack((a, b))
# print(c)

# np的赋值只是起了个别名
# a = np.arange(12)
# b = a
# b[1] = 99999
# print(a)

# python也是如此
# a = [1, 2, 3]
# b = a
# b[2] = 999

# 同样的别名
# a = [[1, 2, 3], [4, 5, 6]]
# b = a
# b[1][1] = 999
# print(a)

# 总结 python 将可变对象作为引用传递
# python的可变对象有
"""
可变 list dict set
不可变 int string tuple bool ....
"""
# 可变对象只是引用传递
# c = {'你好':123,'不好':456}
# d = c
# d['你好'] = 99999
# print(c['你好'])

# np 给出的解决方案 view
# a = np.arange(0, 10)
# b = a.view()
# b[1] = 999
# print(a is b)
# a 与 b 还是同时改变，不过此时不是引用关系，而是为b也开了空间，只是随着a的数据变而已
# b = b.reshape(2,5)
# print(a)
# b[0, 1] = 10086
# print(b)
# print(a)
# b 的形状可以改变，但是a不随他变，只是对应位置的数据随他变.但是引用类型就不一样.

# 引入view更好地理解切片,切片返回的是原来的一个视图,切片对应的位置改变,原来的也会变
# a = np.arange(20).reshape(5,4)
# print(a)
# b = a[2:4,...]
# b[:,:] = 999
# print(a)

# 深拷贝 改变 b a不变
# a = [1, 2, 3]
# b = a.copy()
# b[2] = 8
# print(a)

# 二维数组依旧不行,用deepcopy
# copy是浅拷贝,只是把变量本身给新建空间存储,但是内部是可变变量,那么他的拷贝依旧会面临引用拷贝,也就是同一份数据
# deepcopy 解决的是内部的值都重新开辟了空间.
# a = [[1, 2, 3] ,[4, 5, 6]]
# b = copy.deepcopy(a)
# b[1][1] = 999
# print(a)

# 可以看到在np中 copy就是对所有进行了深拷贝
# b = np.arange((30)).reshape(5,6)
# a = b.copy()
# a[1,1] = 999
# print(b)
#


# # np里面的copy是深拷贝，也就是变量本身新开辟空间，里面的赋值也全是新开辟空间. 不同于python
# a = np.arange(100000)
# b = a[0:200].copy()
# del a
# # a不再使用释放内存
# print(b)

# 广播机制
# 当两个matrix形状不同时,利用广播机制进行传递.
# b = np.arange(100).reshape(20,5)
# b = b + 2
# print(b)

"""
如果满足以下条件之一，那么数组被称为可广播的。

数组拥有相同形状。数组拥有相同的维数，且某一个或多个维度长度为 1  数组拥有极少的维度，可以在其前面追加长度为 1 的维度，使上述条件成立
广播的规则:

规则 1 如果两个数组的维度数不相同，那么小维度数组的形状将会在最左边补 1
规则 2 如果两个数组的形状在任何一个维度上都不匹配，那么数组的形状会沿着维度 为 1 的维度扩展以匹配另外一个数组的形状
规则 3 如果两个数组的形状在任何一个维度上都不匹配并且没有任何一个维度等于 1， 那么会引发异常


根据维数小的左侧补1,然后1可以变成n与某列匹配,当所有维度都匹配就广播成功.
从后开始匹配. 如果没有1并且有的列没匹配，那么就抛出异常.
"""
# a = np.arange(160).reshape(2,2,40)
# b = np.arange(40)
# print((a + b).shape)


```

>  ----- 花式索引