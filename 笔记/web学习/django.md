##### 1.安装

 pip install django

  python目录解释

  ```python
  -python.exe 解释python代码,解释器 - 高级语言转化为低级语言
  -Scripts
     -pip.exe - 安装其他组件的工具
     -django-admin.exe - 生成django项目基本文件结构
  -Lib
    -内置模块
    -site-package
       -flask
       - 第三方库
       -django - django源代码
       -opencv
  ```

##### 2. 创建项目

> django中创建默认目录和文件 django-admin.exe

###### 2.1 终端

- 进入创建项目的目录

- 执行命令创建项目

  ```python
  "django-admin路径" startproject
  可以给django-admin设置环境变量 直接输入django-admin即可
  将python39/script加入环境变量，也就是django-admin的上一级
  ```

  ![image-20231115131018663](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115131018663.png)

mytest为项目名称

###### 2.2pycharm创建

> 企业版pycharm支持

直接选择django 一定要选pip安装了django对应的python版本



说明

- 命令行创建项目标准。

- pycharm 在标准基础上加了东西

  -  创建了templates目录 删除
  - setting删除dirs内容 变成空列表

  

##### 3.默认项目文件

![image-20231115133135029](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115133135029.png)

##### 4.APP

![image-20231115133646970](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115133646970.png)

运行manage.py 建立app

![image-20231115134133647](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115134133647.png)

##### 5.运行

- 注册在setting文件加入

![image-20231115134346047](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115134346047.png)

-  编写url和视图函数对应关系

![image-20231115134640681](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115134640681.png)

- 编写视图函数index 函数要求有默认参数request

  ![image-20231115134821397](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115134821397.png)

- 启动

   命令行

   python manage.py runserver

   pycharm启动

![image-20231115135014225](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115135014225.png)

##### 6.优化

###### 返回html templates目录 模板

可以用request填充好html再给用户

return render(requset, "html文件");

> django app目录建立templates，输入的html文件默认在这个目录下检索。
>
> 根据app注册顺序，逐一去他们的template下找
>
> 可以在settiing dir设置查找路径。 但是默认是每一个app下的templates逐一查找，找不到就无法找到，不会在根目录，除非在setting设置了根目录的dir，优先在根找，然后再去各自目录找。

###### 静态文件

一般将

- 图片 

- css

- js

- 插件

  叫静态文件

  app下 /static/1.png

  /static css

  /static img

  /static js

  /static plugins

![image-20231115141353734](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115141353734.png)

这样写有路径提示

![image-20231115141602055](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115141602055.png)

会在这个目录下找



##### 7.模版语法

利用字典的形式，传递变量。html中变量的应用实际上是去html字典中找到对应键所对应的值。

例如 return (request,html,字典); 第三个参数为html字典,通过在html书写对应键，就可以得到字典中的键值。

h1关键字对应的值是列表。那么通过h1.0 , h1.1来访问

同时可以通过模版语法

> ```html
> {% for item in h1 %}
>    <span>{{ item }}</span>
> {% endfor %}
> ```

字典的遍历

![image-20231116175530938](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116175530938.png)

![image-20231116175538706](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116175538706.png)

![image-20231116175608542](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116175608542.png)

python字典的值可以是任意数据类型，但是字典的键必须是不可变数据类型。列表就不可，但元组就行。



if结构

![image-20231116180048487](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116180048487.png)

![image-20231116180111726](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116180111726.png)

![image-20231116180417835](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116180417835.png)

##### 8. 请求与响应

![image-20231116183523815](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116183523815.png)

![image-20231116183531443](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116183531443.png)

这里注意字典的三种遍历。另外还要注意收到的响应数据经过.json处理才能使用

重定向

redirect 后端返回一个新的请求地址，然后由前端发送新的请求，并不由后端负责请求，把html返回，而是前端请求，得到对应服务器的响应。

![image-20231117155934985](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231117155934985.png)

![image-20231117160350140](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231117160350140.png)

获取数据.

表单

![image-20231117160436187](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231117160436187.png)



403错误，表单中写![image-20231117160743321](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231117160743321.png)

![image-20231117160704447](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231117160704447.png)

![image-20231117160752678](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231117160752678.png)

代码结构优化，尽量减少if else 嵌套

![image-20231117161729882](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231117161729882.png)



##### 



##### 9. 数据库

pymysql 繁琐

django 可以用 orm 框架操作数据库

 ![image-20231123192054029](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123192054029.png)



ORM 将函数翻译成sql语句，再给到底层操作数据库，避免开发者写sql语句



###### 9.1 安装mysqlclient

 orm的底层，以前用的pymysql，mysqlclient目前支持比较好



###### 9.2 操作

- 创建 修改 删除 表         无法创建数据库
- 操作数据 

> 1. 建库
>
>    ![image-20231123193311133](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123193311133.png)
>
> 2. Django链接
>
>    在settings.py文件中配置和修改
>
>    

![image-20231123193912368](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123193912368.png)

3. 基于django创建表 操作表

   models.py

   ![](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123194749847.png)

执行命令

![image-20231123194848802](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123194848802.png)

```python
python3.9 manage.py makemigrations
python3.9 manage.py migrate

app已经注册的前提下.
```

如果新加一列，1.输入值来填充其他的数据    2. 退出，让设置默认值

![image-20231123201147850](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123201147850.png)



表中新增一列需要注意数据填充，三个方式解决.

1. 新增列给加default给原来数据填充
2. 或者不写这个系统提示请求默认值你再输入.

   3.null = true 允许为空



*** 增删改查

增加数据

![image-20231123203900863](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123203900863.png)

删除数据

![image-20231123204152759](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123204152759.png)

搜索数据

![image-20231123204857457](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123204857457.png)

![image-20231123205100640](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123205100640.png)

更新数据

![image-20231123205536362](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231123205536362.png)



##### 10. 表单

![image-20231126122033812](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231126122033812.png)

> 表单提交
>
> 在django要加{% csrf_token %}
>
> method = "post"/"get"  action = "请求地址" , 如果action不写，可以认为发送到本地址. 另外如果发到localhost只用写后面的路径
>
> 里面的input 起名字name,然后input里面的内容会变成以name为名字的变量传递, 以method方法传递给后端。 给标签设置name后,会自动生成 name为名字 value为值的变量传递给后端。

![image-20231126122913922](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231126122913922.png)

获取post数据

重定向

![image-20231126123200851](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231126123200851.png)

如果仅仅是return html 不会发生渲染,但是需要的是渲染后的页面，所以要重定向而不是直接返回html.

键值传参

![image-20231126124248246](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231126124248246.png)

> 对于字典的获取 items
>
> items.['key']
>
> 或者items.get("key")
>
> 都可以
>
> 但是不能通过 . 访问



##### 项目

删除temlates， 修改setting dir

创建app

注册app

设计表结构 django

```python
from django.db import models

# Create your models here.
class Department(models.Model):
    """ 部门表 """
    # verbose_name 是提示自己的
    # id 自增自动创建
    # id = models.BigAutoField(verbose_name='ID',primary_key=True)

    title = models.CharField(verbose_name='部门名', max_length=32)


class UserInfo(models.Model):
    """ 员工表 """
    name = models.CharField(verbose_name='姓名', max_length=16)
    password = models.CharField(verbose_name='密码', max_length=64)
    age = models.IntegerField(verbose_name='年龄')

    # 后面实际是调用了DecimalField的构造函数,ctrl + 点击可以去看具体参数
    account = models.DecimalField(verbose_name='账户余额', max_digits=10, decimal_places=2,default=0)
    # 数字总共10, 小数2, 默认值0
    create_time = models.DateTimeField(verbose_name='入职时间')
    # yyyy-mm-dd

    # 部门名称 or id ?
    """
        ID 数据库范式,理论,开发标准
        存储开销低
        
        
        一些比较大的公司
        直接存名称 ,!!!! 空间换时间 !!!!
        连表操作耗时
        
        下面演示如何存id呢? 外键约束?
        如果存了100000呢？ 但是对应的部门并不存在.  
        这样的数据不能让其插入,加入外键约束,他就只能是部门表已存在的id
        !!! 直接报错 !!! .   
    """

    # 无约束
    # depart_id = models.BigIntegerField(verbose_name='部门ID')

    # 级联删除
    # depart = models.ForeignKey(to="Department" ,to_field="id" ,on_delete=models.CASCADE)

    # 置空
    # depart = models.ForeignKey(to="Department" ,to_field="id",null=True, blank=True,on_delete=models.SET_NULL)

    # 表示了要与哪个表关联, Department, 与哪个列关联 to_field id
    # django
    # - 写的depart
    # - 生成数据列 depart_id 自动生成这一列
    # - depart + _ + to_field 这一列
    # 如果某个部门被删除,如何处理???
    """
    外键 : 必须是唯一性索引, 一般是关联主键, 但是外键可以为空. 按照depart_id 与depart表的id行匹配连接上,然后就可以使用他的列.
        部门删除 - 
        1. 关联的用户 删除  级联删除 ondelete = models.CASECADE 级联删除
        2. 置空 null 
    """

男 女 没必要搞外键,但是部门会动态修改
    example:
    比如 在userinfo里面我们存的部门id,然后部门id不变的情况下,我们修改了部门表中id为1的部门名称,那么部门名称就会发生改变.
    如果存的是部门名称,那么某一个部门的名称发生了改变,那么所有的都要去手动更改,效率低下.
    
```

manage.py 执行 , 生成表结构。

makemigrations

migrate



建立templates, 引入bootstrap 的plugins

书写项目

> 部门列表
>
> 







##### 模版的继承

模版书写

navbar.html

可以在模版中写多个block,只要使用时书写对应的block填充对应部分即可.

![image-20231130210530342](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231130210530342.png)

模版使用

index.html

![image-20231130210514785](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231130210514785.png)



##### 动态url

符合depart/<int:id>/delete的链接都会映射到函数depart_delete

![image-20231130210711677](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231130210711677.png)

在view中

![image-20231130210953433](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231130210953433.png)

参数名称要和路径的id一致才可以使用,比如id改成uid就会报错!



end - 2023-11-30

##### 11. Modelform

> 原始方法
>
> 
>
> ![image-20231202204702480](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231202204702480.png)
>
> - 需要数据验证
> - 需要错误提醒
> - 页面每一个字段都要重新书写获取 形式繁琐
> - 关联的数据手动获取并在前端展示

##### Django组件

###### Form

![image-20231202210138877](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231202210138877.png)

  ![image-20231202210127505](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231202210127505.png)

###### ModelForm

##### models.py

![image-20231202210400271](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231202210400271.png)

也可以加入自定义字段

![image-20231202210518010](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231202210518010.png)

![image-20231202210901121](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231202210901121.png)

可以显示数据库定义的verbar_name

通过form.name.label

对于选择select 

![image-20231202211146882](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231202211146882.png)

写上choice属性就可以显示了!

部门类不显示的问题

![image-20231202211438704](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231202211438704.png)

输出对象时候如果想要定制内容就写上__str

在python的底层对于选择框是

list = Department.obj.all()

 for item in list

   print(item) 

item是一个department类，如果直接输出是不行的，所以要定制.

完成了样式的添加

![image-20231202212151948](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231202212151948.png)

遍历方法

![image-20231206193235671](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231206193235671.png)

固定写法

![image-20231206201133372](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231206201133372.png)

可以实现属性的添加.



##### 添加报错

html部分

##### ![image-20231206203508219](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231206203508219.png)

views部分

![image-20231206203524953](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231206203524953.png)

setting 部分

![image-20231206203744901](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231206203744901.png)

##### 编辑

*![image-20231207210243864](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231207210243864.png)**

> Myform(instance = data) 把搜索到的数据填入Myform 
>
> Myform(instance = data, data = req.POST)  
>
> form.save() 在instance那一行填入data,如果没有instance 则创建一行

instance设置后,form就等价于那一行，通过data可以修改这一行的数据.

显示choice列的办法

![image-20231207220843808](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231207220843808.png)

##### 12.百度云盘的解决方案   速度太慢最终选择阿里云

```
from bypy import ByPy
bp = ByPy()
# 上传
# bp.upload(r"C:\Users\86186\Desktop\ssl\")
# 本地目录 云盘目录
bp.upload(localpath=r"C:\Users\86186\Desktop\ssl.txt", remotepath=r"/hello/")
print(bp.list())
# 下载云盘文件 云盘目录 本地目录 
bp.download(r"/hello/ssl.txt", r'C:\Users\86186\Desktop\新建文件夹')
```

> upload目录可以固定存储到百度云盘的某个位置上,可以作出用户名区分建立不同的文件 
>
> 本地文件路径是否可以通过选择的方式获取呢？
>
> download 目录通过用户名文件名生成下载路径
>
> 然后把百度云盘的文件下载到本地 本地的路径是否可以通过选择进行建立？
>
> 实验数据用户选择本地数据进行实验，那么和这里不是一套系统，就是简单的csv读取
>
> 文件系统就这样解决

[用Python自动上传文件到百度网盘原来这么简单 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/622230203#:~:text=用Python自动上传文件到百度网盘原来这么简单 1 首先试一下显示在云盘（程序的）根目录下文件列表，cmd%2F终端里输入： bypy list 会出现这样的界面 点击终端上方出现的蓝色链接 复制授权码，在终端输入并回车：,print(bp.list()) 效果如下： 打开百度网盘测试一下： 成功咧，真简单咧。 3 你可以选择把整个文件夹统统同步到百度网盘，比如我这里有个文件夹要全部推送到百度网盘： 那么我们只需要这么写%3A )
