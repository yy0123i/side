##### 类

isinstance(b,B); b是否为B的类，或子类

issubclass(A,B); A类是否为B的子类

###### 多重继承

​      class C(A,B) 对于同名属性，左侧覆盖右侧

​      只有C中无，A中无，找B

###### self 

​     实例对象本身

>方法是公共的,但是每一个实例有自己的属性,self就是实力本身,通过self来明确当前操作的实例,以确保共享方法对具体实例的属性进行操作

![image-20231123163040738](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123163040738.png)

只是在类中创建的局部变量x,不会对类和实例的x造成影响,如果要改变实例的属性,需要self.属性进行绑定.

###### 组合

​       ![image-20231123161627714](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123161627714.png)

###### 类与字典

![image-20231123163512034](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123163512034.png)

通过空类，本质是一个字典，但是可以通过类动态创建属性，简化字典操作，当作字典使用.

###### 构造函数

```python
__init(self,x , y)
 self.x = x;
 self.y = y;
self 的理解在上面;
类的方法第一个参数默认为self,用于绑定实例对象,这样才能对实例对象的属性进行操作.

一个类的属性，如果没有构造函数，那么在实例内省其中没有该属性，但是可以访问，实际上是对类的属性的访问，而通过构造函数，就真正的创建了属性，这个属性属于实例对象.
```

###### 重写

> 子类对父类的重写 可以看多重继承的规则

![image-20231123164428705](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123164428705.png)

​     子类通过C.父类构造函数，可以省去self.父类属性=值的操作，由父类构造函数完成，那么在自身构造函数只需要完成自身新添加属性的初始化.

![image-20231123170646281](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123170646281.png)

![image-20231123170946337](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123170946337.png)

![image-20231123170959586](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123170959586.png)

###### super

> 解决菱形继承问题，按照MRO顺序，一般调用基类的构造函数利用
>
> super.init 即可
>
> C.MRO 查看解析顺序

```python
super - 
super 会被设定一个顺序，它是按照mro顺序去调用函数的，如果当前类调用了super则会在上一级super中找该函数。 super顺序也就是多继承顺序. 
super 会看self是谁执行谁的super结构，然后再去看当前处于哪个类，.super则是在self的super结构的当前类的上一个类中去寻找函数进行调用.
```

![image-20231123184214459](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123184214459.png)

![image-20231123184518148](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123184518148.png)

集合菱形继承更能够深刻理解

###### 设计模式

就是在已经写好的类再继承一个新类，为其添加新的方法。

###### 多态

```python
len 就是一个多态
1.
class Shape:
    def __init__(self):
       print("这是基类");
        
class Circle(Shape):
    def _init_(self):
        super()._init_();
    def mj(radius):
        return ....;

class Shape_zfx(Shape):
    def __init__(self):
        super().init()
    def mj(radius):
        return ....;
    
shape_Zfx.mj != circle_zfx.mj 
同一个基类，但是子类同名函数的不同状态叫做多态.


2.
另一种
class dog:
    say---
class cat:
    say---
    
def animal(x):
    x.say();
不同对象就完成了不同的操作，这也是多态.
```

###### 鸭子类型

主要满足多态函数中被调用的函数，就可以作为参数.



##### 私有变量

> __变量名 

```python
class c:
    def __init__(self,x):
        self.__x = x;       
// x为私有变量，但不同于其他语言，仍然可以被访问
```

> 访问方法： 实例名._类名__私有变量名

![image-20231123114145893](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123114145893.png)

函数加上__在外层也无法直接访问

> 编码规则，但是python不会给出具体限制
>
> _开头 仅供内部使用的变量 
>
> 结尾_  class_ 防止关键字冲突

```python
普通类

动态添加属性
c.a = 3;
c.__dict__ //访问c的属性
c.__dict__['z'] = 666;
相当于给c实例添加了z属性
```

```python
加入slots

class C:
  __slots__ = ["x","y"];
  def __init__(self,x):
        self.x = x;
c = C(250);
只能访问slot举出的属性，如果添加就会报错
```

> slots在子类不会被继承，只会对自身类作出限制 子类有继承的solts
>
> 但是不会生效

##### 魔法

> 在类实例时，自动调用的方法

```python
1. __new__(cls,)   //类实例创建 return self
一个类首先执行自己的new方法,new方法通过super执行父类的new方法返回一个实例化对象。这个实例化对象就是这个类的实例,然后再执行这个类的构造函数。通过当前类的new向父类new传递参数,返回的实例对象,可以实现对于str,int构造之前的预处理。

可以发现__new__方法是传入类(cls)，而__init__方法传入类的实例化对象(self)，而有意思的是，__new__方法返回的值就是一个实例化对象（ps:如果__new__方法返回None，则__init__方法不会被执行，并且返回值只能调用父类中的__new__方法，而不能调用毫无关系的类的__new__方法）


2. __init__(self, ); //类实例自动调用 

3.__del__(self) ; // 类销毁时自动调用
```

![image-20231130185016567](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231130185016567.png)

##### 运算魔法

![image-20231130185423028](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231130185423028.png)

> s1 + s2 = 
>
> s1.add_(s2)
>
> 调用的是s1的add函数
>
> 当参与运算时,会调用的方法。
>
> __add__(self,other)
>
> 两个参数

##### 闭包

> 外层函数的变量
>
> 嵌套函数，外层的变量会被保留下来，即使函数执行结束.

> 作用域
>
> 当前作用域局部变量->外层作用域变量->当前模块中的全局变量->python内置变量（这里可以看到当前作用域的变量的执行优先级别最高）

![image-20231130175941070](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231130175941070.png)

> 对于不同的闭包,所存储的值是独立的
>
> ![image-20231130182723123](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231130182723123.png)
