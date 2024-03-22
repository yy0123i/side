##### mysql

######  数据类型

- decimal

​     利用decimal(n,m) n是总位数，m是小数点后位数代替 double 和 float 不用考虑精度问题。

- char   n <= 255

  char(n) 固定用n个字符  

  ```python
  死板,浪费空间
  速度快-查询速度 类似数组查找
  ```

- varchar  65535字节 按编码方式来看一个字符占几个字节 

  varchar(n)  真实数据多长就按多长存储，在n个字符以下

  ```python
  灵活,节省内存
  挨着放变长数据，要依次遍历才能找到
  ```

- text

  ```py
  容纳65535个字符 文章 新闻
  ```

- mediumtext

- longtext

- datetime

  ```python
  yyyy-mm-dd hh:mm:ss
  ```

- date

  ```python
  yyyy-mm-dd
  ```

###### 操作

新增数据

- insert into 表名 (列名) values(，，，),(，，，);

删除数据

- delete from 表名; 删除表所有数据
- where 只删除符合条件的数据

 ![image-20231114192623838](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114192623838.png)

修改数据

 ```sql
 update 表名 set 列=值,列=值 where 条件;
 ```

![image-20231114192841754](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114192841754.png

![image-20231114192858091](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114192858091.png)

查询数据

```sql
select * from 表名称;
select 列名 from 表名称; 
+ where 条件
```

![image-20231114193012742](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114193012742.png)

![image-20231114193109533](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114193109533.png)

##### 项目步骤

###### 表和库

uft8数据库创建

![image-20231114194025385](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114194025385.png)

数据表创建

![image-20231114194046704](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114194046704.png)

###### 数据操作

![image-20231114194332387](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114194332387.png)

安装模块

![image-20231114205302384](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114205302384.png)

![image-20231114210911636](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114210911636.png)

关于动态参数的注意

![image-20231114211859485](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114211859485.png)

查询要有fetchall()

![image-20231114212403673](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114212403673.png)

%s   以列表传 无论什么型都是%s，没有%d

%(名字)s 以字典传

数据库返回的数据是列表，列表的每一项是一个字典，一个字典是表的一行s

fetchone()只取拿到的一条，只拿其中一条



删除数据

![image-20231114213135937](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114213135937.png)

修改数据

![image-20231114213302998](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114213302998.png)

##### Flask提交

![image-20231114215430397](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231114215430397.png)

##### springboot mysql映射

@Data @tablename对应表 @TableId对应主键 @TableField对应普通列

![image-20231118212600462](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231118212600462.png)

##### 自增列在springboot的设置

```
@TableId(value = "id",type= IdType.AUTO)
```