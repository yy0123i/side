##### 3.BootStrap

已经写好的CSS样式，

1. 下载BootStrap本质是下载Style文件

##### 栅格系统

https://v3.bootcss.com/css/#grid

一行划分为12个格子

```html
<div class="col-xs-k">
    k为占几个格子
</div>
```

分类

   响应式 根据页面宽度不同 做不同改变

```html
.col-sm- 750 当页面宽度<750变成上下摆放
.col-md- 970
.col-lg- 1170
```



   非响应

```html
<div class="col-xs-k">    
k为占几个格子</div>
```



列偏移

```html
    <div class="col-xs-offset-3 col-xs-6" style="background-color: red;">1</div>
```



空白样式直接引入class = container即可

-fluid 平铺



boostrap ----- clearfix自动清除浮动

##### 面板元素



拷贝某个元素

copy otherhtml

定位元素然后拷贝就可以用别人的了



登录实例

![image-20231101195529026](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231101195529026.png)



表单

box-shadow 设置阴影

5px 5px 20px #aaa



##### 后台页面

![image-20231102194344146](C:\Users\Haon\AppData\Roaming\Typora\typora-user-images\image-20231102194344146.png)

##### 图标使用

- boostrap提供

- font awesome组件 类似于bootstrap引入插件和css

  style = "color ---"换颜色 font-size 变大小

##### 行块级标签

块级可以设置宽高，行级设置无效



块级可设置margin和padding



行内元素margin和padding只在水平方向有效，垂直方向无效



设置 行内元素居中，例如scan文本 设置父亲div text-align

行内元素垂直居中 行内元素设置垂直居中，设置外层行高为行内元素的高度即可。

height:30px;  line-height:30px 







