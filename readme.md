### Linux下简单web服务器搭建

参考开源项目Tinyhttpd和同事/舍友代码，成功搭建web服务器

项目行数不多400行左右

采用VS2019通过SSH远程连接Ubuntu调试开发

ConsoleApplication1为VS项目 也有源码

Myweb下为linux下创建目录 	有本人编写的Makefile

------

#### 使用方法

修改web.conf下的路径和端口

make后执行即可

之后通过浏览器 访问/html内的页面

eg：

http://192.168.43.99:8080/alter.html  192.168.43.99: ip



​																												感谢wangzhaoguo1999						