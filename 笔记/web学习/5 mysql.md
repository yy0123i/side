##### Mysql

```html
静态页面 数据静态 前端
动态页面 数据动态 配合后端 
```

静态

页面无论是响应还是什么，不会改变

动态页面，根据数据的改变，实时更新。



前端{{titile}}

后端return (titile="....")；补充占位符

循环占位符号

{% for item in data_list %}

{% endfor %}



![image-20231109210834319](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109210834319.png)





![image-20231109211934953](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109211934953.png)



##### 安装Mysql 

Mysql是一个软件

###### 下载mysql

![image-20231109214021139](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109214021139.png)

下载64位，第二个

##### 先安装补丁

![image-20231109214231159](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109214231159.png)

##### 在安装mysql

解压到任意目录

路径建议不要有中文！

![image-20231109215911262](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109215911262.png)

##### 创建配置文件  在mysql的安装目录下

![image-20231109220228122](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109220228122.png)

![image-20231109220424472](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109220424472.png)



##### 初始化

打开cmd，管理员身份

输入初始化命令  

"你的mysql路径 \ 分割    + \ bin \ mysqld.exe" --initialize-insecure

![image-20231109221646661](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109221646661.png)



##### 启动mysql

临时启动

![image-20231109222923123](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109222923123.png)

关掉窗体就结束启动



制作成windows服务，基于服务启动关闭 

如何制作服务

```html
“----bin/--mysqld.exe” --install mysql57
就是把这条指令变成一个服务，一直开启。
```

![image-20231109223325915](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109223325915.png)

![image-20231109223618812](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231109223618812.png)

还可以在服务界面里面找到这个服务进行启动!

![image-20231110193703532](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231110193703532.png)



##### 用工具发送指令

"mysql.exe" -h 127.0.0.1 -P 3306 -u  root -p 

可以省略为

-u root -p 默认3306

输入密码

//连接哪台电脑

ini配置文件里面写的3306 ！

每次都要输入路径，把路径添加到系统的环境变量中

可直接写 mysql -u root -p

![image-20231110194703743](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231110194703743.png)

如果输入一个指令，他就在这些路径下检索该文件，并运行。 mysql.exe 在该路径下，所以成功执行。

![image-20231110194959058](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231110194959058.png)

![image-20231110195119104](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231110195119104.png)

![image-20231110195550143](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231110195550143.png)

##### 查看已有文件夹 数据库

show databases;

##### 关闭连接

exit;



##### 忘记密码如下操作

修改配置文件（以无账号模式）

![image-20231110202925519](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231110202925519.png)



![image-20231110202948214](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231110202948214.png)

![image-20231110203208700](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231110203208700.png)

这样就可以把以前的密码改掉

然后再改成需要账号模式即可，完成整套修改密码的过程



##### mysql指令集

- show databases;

- 创建数据库

  create database 数据库名字 DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

  会按照gbk存取，一般开发用utf-8

![image-20231110204547893](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231110204547893.png)

- 删除数据库 

  drop database sidedata;

- 进入数据库(进入文件夹，才能操作其中的文件

  use 数据库名

- 查看所有文件 show tables;

- 创建表 

  create table 表名（

  列名 类型,

  列名 类型

)default charset=utf8;

- not null 某一列不允许为空 null 允许为空
- age int default 3 ---插入数据age没写默认为3
- id int primary key, --- 设置主键，该列不能为空，且不能重复。

主键用于表示行的数据编号，唯一标识某一行。

设置自增自减，

###### id int not null auto_increament primary key ,

######  id主键的一般写法

- desc 表名 ; 查看表结构

mysql 数据类型

- int  

- tinyint 

  ```pascal
  有符号 -128 - 127
  无符号 0 - 255
  ```

  ```sql
  age tinyint 默认有符号
  age tinyint unsigned 无符号
  insert into tb3(age) values(-10); 会报错，设置无符号
  ```

- bigint

insert into tb3(age) values(10),(20),(30); 批量插入

查询数据

select * from tables 

django

数据库配置

![image-20240103151630712](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20240103151630712.png)
