##### 引入jQuery

引入可以利用bootstrap写好的 javascript库

jQuery是bootstrap写好的一些关于javascript的依赖

jQuery是javascript的类库，javascript是一门语言。

```html
<script src="static/js/jquery-3.7.1.min.js"> </script> 引入js类库，jquery是javascript写的。
<script src="static/plugins/bootstrap-3.4.1/js/bootstrap.min.js"></script>   bootstrap引入js导入
```

模态框的使用

##### JS

- JavaScript 浏览器是解释器
- DOM和BOM

   ```html
   编程语言的内置模块
   python的re，random，time，json模块
   ```

- jQuery

  ```html
  编程语言javascript的第三方模块
  如requests openpyxl opencv
  ```

confirm alert 都是弹框

按钮加入onclick=对应函数

- 当前html

  script可以放在body的尾部（推荐）和head里

  放在上面把js的某些东西执行完，才会加载页面。

- 其他文件

  static/(javascriptfile) 里面写function 或语句。

  html引入，

  ```html
  <script src = "...."></script>
  ```



##### 注释

javascript //  /* */

html <!-->

css /* */   <style代码块中>

##### 语法

###### 1.变量

```javascript
let name ; var name = "号前";
console.log(name); //在网页看；
```

2.字符串

```javascript
// 
var name = "12345";
var name = String("高倩");

//常见功能
var name = "中国联通";
var v1 = name.length;
var v2 = name[0]; // name.charAt(0)
var v3 = name.trim();去除空白
var v4 = name.substring(1,2);//  前取后不取
```

html中找标签内容

DOM,document 找id

```javascript
var TAG = document.getElementById("id号");
var st = TAG.innerText;
数字跑马灯

更新标签值
TAG.innetText= newText;

如何定时执行
//JavaScript定时器
setInterval(show, 1000);
```



##### 数组

``` 
var v1 = [11,22,33,44];
var v2 = Array([11,22,33,44]);

1.获取值
v1[1]
v1[0] = "钱"

2.添加删除
v1.push("联通");    尾部
v1.unshift("联通"); 头部
v1.splice(索引,0,元素); 指定位置插入

v1.pop();
v1.shift();
v1.splice(2, 1)；索引为2的元素删除
v.splice第二个参数 0 表示保留原位置，1表示删除原位置。
```

```javascript
for(var item in v1)
    {
        // item = 0,1, 2
        data = v1[item];
        // item 不是元素，而是索引！！！
    }
for(var i = 0; i < v1.length; i ++ ){
    
}
break , continue;


```

![image-20231103191703114](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231103191703114.png)

##### 字典

```javascript
info = {
    "name":"高清",
    "age":18
}
info = {
    name:"高清",
    age:18
}

info.age
info.name
info["age"]
info["name"]

delete info["age"];

循环
for(var key in info)
    {
        key --->= name/age;
        // key是键值！！！
        data=info[key];
    }
```

![image-20231103192943810](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231103192943810.png)

![image-20231103193445272](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231103193445272.png)

##### 条件语句

```javascript
if ( 条件 )
    {
        
    }
else
    {
        
    }
if (条件){
    
}
else if(条件)
{
        
}
else
{
        
 }
```

##### 函数

```javascript
function func(){
    .....
    
}
func();


```

##### DOM

```javascript
理解为模块，可以操作html标签
var bodyTag = document.getElementById("ID号");
//获取标签文本
innerText

//设置
innerText =....

//创建标签
t = document.createElement("div");
//写内容
t.innerText;
//加子标签
t.appendChild("id");
```

##### 事件绑定

```javascript
onclick
ondblclick双击
input标签，获取内容
tag.innerText内部文本
标签本身的内容，tag.value; input的内容；
tag.vallue=""；text内容清空；；；；
```

DOM还有其他操作！！ jquery类库封装好，可以实现，dom本身繁琐。

##### 编码

```javascript
文件存储
底层是0101010101001010101010.
根据编码规则转换为字符
- utf-8 编码，动态压缩，不是固定字节，但是也包括了所有明文
(中文一般用3个字节)
- unicode, ucs2/ucs4 包括发现的所有明文空间大。
- gb2312 , gbk ，中文和亚洲一些国家 (中文 2字节)
- ascii编码 256种对应关系

python解释器 默认utf-8 
如果代码文件保存为gbk编码
就将python解释器改为gbk模式，

```

- 字符串格式化

```python
v1 = "我是{},锦娘{}".format("问我"，444); #推荐
v2= "我是%s,锦娘%d岁" %("试试"，33);

v3=f"我是{name}锦娘{age}岁”
```

```python
bool flase:---> 
    none,空，0
-可变
list dict set
-其余不可变
实际开辟了新的空间
-可哈希不可哈希
-- 字典键元素的集合，必须是可哈希类型。
list dict set 不能作为键
可变元素，作为键值，list例如加入内容，hash值发生改变，会给底层造成麻烦。对于可变的一般不hash

-str
split upper lower startswith strip join
不可变类型，变了实际是建了一个新的字符串
-list
append,insert,remove,pop
可变类型，功能大多对原始数据修改。
-dict
 -独有
    get/keys/items/values
```

```python
v1 = 99 and 88
v1整体取决于哪个就是哪个
v2 =[] or 10
v2 =10; 因为整体取决于10
v3 = "联通" or []; --> 联通
```

```python
传参
*args,**kwargs,参数默认值，关键字，位置
函数作用域
  全局变量，局部变量
  全局变量(大写)
  局部变量(小写)
  -局部变量用global关键字，作用
   引用全局，而不是内部新建
内置函数


文件 with 防止关闭文件
类似C
r/rb //文件不存在报错
w/wb //新建
a/ab //新建
```

##### jquery

javascript第三方模块。

上面由bootstrap如何导入jquery



如何找标签

直接法

![image-20231106213457153](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231106213457153.png)

```python
样式选择器 class = "c1"
$(".c1")
标签选择器
$("h1")
层级选择器
$(".c1 .c2 a") c1类下的c2类下的a标签
c1下面的所有c2标签中的所有a标签
```

![image-20231106214425162](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231106214425162.png)

```python
多选择器
$("#c3,#c2") 会同时选择c3和c2

属性选择器
$("input(name='n1')")
找到input标签，属性name等于n1的那个

```

间接法

```python
找上一个兄弟
<div>
     <div></div>
    <div class="c1"></div>
    <div></div>
</div>
$("#c1").prev().next()
prev找上一个兄弟，next找下一个兄弟
.siblings() //找所有兄弟

找父关系
.parent
.children() //所有孩子
.children(".p10") //选所有的儿子
.find(".p10") //在所有的子孙中找p10
.find("div")
```

##### 菜单切换

.removClass

.hasClass

.addClass

![image-20231106221542872](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231106221542872.png)

cursor：pointer 变手



##### 值操作

获取值 对于文本

$("#id").text();

设置文本值

$("#id").text("要设置的值");

设置input value属性

....val 与text同理。



创建新元素。

var new = $("<元素标签名>").属性("值");

添加新元素

$.....    .append(new)



##### 事件绑定

$("").click(function() {

 函数内容

$(this)表示当前点击的某一个标签

})



![image-20231108125017663](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231108125017663.png)

外面套的function当页面框架加载完就执行，不会等到所有资源全出来才会生效。



datetimepicker插件，可以弹出时间选择。

