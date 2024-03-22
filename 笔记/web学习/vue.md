nodejs版本

node -v

##### 创建vue 项目

![image-20231115154503649](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115154503649.png)

进入目录并创建

> npm init vue@latest

![image-20231115154649784](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115154649784.png)

项目名称不要大写字母

![image-20231115154742328](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115154742328.png)

即可运行







vue create 项目名称

创建完成，然后npm install bootstrap

可以替代上面，上面如果出错，用这个方法



##### 目录结构

![image-20231115155207511](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115155207511.png)

所以代码都在index.html中运行



##### 模板语法

![image-20231115160143799](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115160143799.png)

{{单一表达式, 支持三目运算符}} {{里的内容可以合法写在return后，是一个值}}

理解return可以，那么{{}}就可以放

一般不要在{{}}中做逻辑判断，尽量在js中完成。

如果返回一个html标签，只是字符串，要用<p v-html>{{msg}}</p> msg 是html标签.

##### 属性绑定

![image-20231115161051222](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115161051222.png)

在属性上用双括号是不生效的

利用v-bind成功让属性部分变成变量显示

![image-20231115161230256](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115161230256.png)

![image-20231115162247886](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115162247886.png)

如果bind的为null那么这个属性被移除

或者直接:不用v-bind

![image-20231115162450519](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115162450519.png)

直接v-bind="字典" 字典自动生成属性，值



##### 条件渲染

类似js的if else

![image-20231115163110917](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115163110917.png)

当v-if = "表达式或变量" 如果其值为0就不显示 为1显示

v-else 只有v-if为false才显示他

![image-20231115163302969](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115163302969.png)

v-show同理

![image-20231115163537954](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115163537954.png)

##### 列表渲染

![image-20231115163917771](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115163917771.png)

![image-20231115165215229](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115165215229.png)

:key="item" 和前面一致不然会报错.

（item,index）in ...  index是迭代项数下标

in --- of

顺序固定  

遍历字典，同时想要key和value和index时

(value, key, index)

  value - 对象的值

  key - 代表关键字

  index - 下标

遍历列表，每一项是一个字典



key的管理

如果不绑定key那么执行v-for所有都要渲染，很浪费时间。效率低下。

如果绑定了key，执行v-for时，vue会看key是否变化。 根据key，如果内容一样，标签类型一样，就可以完成复用不会再次渲染。所有我们找到key与内容一一对应的，那么创建的后key和内容的对应关系不会随着元素的插入删除改变，那么就可以只对更新部分进行渲染，提高了效率。



##### 事件处理

v-on:事件="函数名"

@事件="函数名"

变量内联处理

![image-20231115193049357](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115193049357.png)

方法内联处理

所有data里面的数据都可以用this读取

![image-20231115193934155](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231115193934155.png)

> methods里面写事件，去掉s无效，同时在data里的数据可以通过this访问，页面的数据和数据是动态绑定的，数据改变页面的数据就发生了变化。

##### 事件参数

事件参数e，是一个对象，可以获取原对象，然后对原对象操作

![image-20231116184502138](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116184502138.png)

##### 传递参数

![image-20231116184633885](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116184633885.png)

![image-20231116184903281](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116184903281.png)

如果有了传递参数，还想用event。

则写函数(传递参数，$event)

如果只要event无需写，直接在js添加一个参数，就是event

##### 事件修饰符

对于事件触发的修饰，对于一些在事件内部处理prevent，stop。但是事件内部更多去逻辑处理，所以在v-on引入修饰符，让代码简化。

比如取消a标签的跳转

> 阻止默认事件

e.preventDefault()；取消标签的默认事件，但是写在js中，其实和逻辑处理关系不大，

所以引入修饰符，在v-on声明。

@click.prevent="" 就完成了这个功能

> 事件冒泡

e.stopPropagation 子事件的触发不会让父亲事件再触发

比如父亲是一个点击，儿子也是一个点击，如果点击儿子，那么父亲和儿子都会执行。

加入@click.stop 当儿子执行，其父亲对应的click事件不会发生。

##### 数组变化检测

![image-20231116191026660](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116191026660.png)

![image-20231116191039004](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116191039004.png)

![image-20231116191115259](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116191115259.png)

替换一个数组的方法，是把原数组和旧数组生成一个新数组，但是不会把原数组改变。

变更方法是直接在原数组上进行了操作，原数组直接会发生改变。

所以替换方法需要重新赋值给原数组，页面才会发生相应的更新

##### 计算属性

对模版语法的改进，模版语法只适合简单的处理。

![image-20231116191915010](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116191915010.png)

将需要复杂逻辑的变量放到computed里面，然后return随时更新该变量。

为什么不用method代替.

![image-20231116192141170](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116192141170.png)

多次使用计算属性，第一次使用会将结果缓存，如果依赖元素都没变，就不会重新计算。

但是method使用几次，就执行了几次

在实际写代码中，遇到data属性的引用一定要写this，否则会认为没有定义

##### Class绑定

为了class绑定的方便，给class提供了数组和字典的额外形式，其他都是字符串的绑定。

> 字符串拼接，容易出错 :class = "string" 对string调整比较复杂

> 表达式可以使对象或者数组，:class="{'active' : isactive , 'bond' : isbond }"
>
> 如果某个键的值为真，那么这个键就被添加到class，这就是字典动态添加和删除类的思想

![image-20231116201518800](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116201518800.png)

然后放到class的位置 :class="classObject"

数组绑定

![image-20231116201804861](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116201804861.png)

本质就是把几个类放进数组，然后一 一给class,根据数组元素对字符串进行了处理。

![image-20231116202000563](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116202000563.png)

![image-20231116202129611](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231116202129611.png)

只能数组嵌套对象，反之不行 了解即可，代码可读性差

##### Style绑定





##### 路由配置

npm install --save vue-router@4   -vue3需要router4版本

```vue
router - 不用a标签
<router-link to="/home">首页</router-link> --- a 标签
<router-link to="/blog">博客</router-link>
<router-view>routerlink切换之后的东西放在router-view</router-view>
```

```vue
src 创建router.js
import { createRouter ,createWebHashHistory} from "vue-router"; //创建路由
import Home from "./...."
import Blog from "./...."
const router= createRouter({
        history:createWebHashHistory(),
        routes:[
      {
           path:"/",
           component:Home
      },
      {
           path:"/blog",
           componet:Blog
      }
      ]

});
暴露出去;;; export defalut router;


main.js
import router form "./router.js"

const app = createApp(App)
app.use(router)
app.mount("#app")
```

##### 路由传参

要在接收方写

![image-20231119153531044](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231119153531044.png)

动态路由params传参注意两点，name是必须写的，params也是必须写，另外params必须是路径动态位的变量，

比如hello这一页面他的路径是    /hello/:id,在动态位置id是变量，那么params有且只有id才可以。



##### 组件引用

主要是在要引入的界面加入

第一步引入

第二步注入

![image-20231117205314469](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231117205314469.png)

![image-20231117205526091](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231117205526091.png)

##### 表单输入绑定

v-model="变量名"

输入的值，就跑到了变量上，在data定义变量，然后利用v-model="变量",这样就实现了变量与输入值的绑定，其实就是和组件的value属性进行了绑定。

.lazy 是失去焦点，才进行值的改变，不会输入的时候实时改变

.number 只接受数字类型

.trim 去掉首尾空格



##### 模版引用

在vue中对特定元素进行操作，在特定元素用ref定义一个名字，然后在javascript中利用this.$refs.名字.元素属性 进行元素操作，这样就不需要在jquery的情况下，实现对元素dom操作

innerHTML 修改内容

value 如input的输入内容

其他封装的操作可以利用

![image-20231118200323505](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231118200323505.png)

一般必须操作dom用ref即可

![image-20231118200345038](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231118200345038.png)



##### 侦听器

只能对可变数据侦听，不能对死数据监听。

watch:{

新数据和旧数据作为参数会送入这个函数。

 message --与属性名一致(newValue, oldValue){  

}

}



##### 组件全局注册

![image-20231118202107573](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231118202107573.png)

---- 组件引入部分  局部注册

>  全局注册方法
>
> main.js 中注册完，可以再任意组件中使用该组件,直接可以显示

![image-20231118202348829](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231118202348829.png)

![image-20231118202445120](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231118202445120.png)

第一个字符串是给他起的名字。

全局注册在项目打包时，相当于在每一个组件js都引入了，空间会大

可维护性差

##### 组件传递数据

组件被封装了，但是props为封装组件之间提供了数据传递的方法。

![image-20231118203240584](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231118203240584.png)

父级向子级传递，并在子级显示

同时可以动态数据的传递

![image-20231118203440991](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231118203440991.png)

> props传递 只能父到子，不能反过来。



##### axios

npm install axios

直接在用的文件import axios from axios

组件引用

mounted是页面加载就发出请求

下面是标准的get和post请求示例

![image-20231118211700245](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231118211700245.png)

![image-20231118221002627](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231118221002627.png)

##### @RequestBody

Post请求

参数写出Map,这个注解会把前端传过来的json映射为map，然后直接可以对map进行操作。

![image-20231119111607489](C:\Users\86186\AppData\Roaming\Typora\typora-user-images\image-20231119111607489.png)

- @RequestParam 一般在前端请求路径上 用 **?和&** 或者 表单请求

