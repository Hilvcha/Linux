---
title: http请求概览
date: 2017-07-29 22:39:06
type: tags
tags: 
- 网站
- http
categories: 
- 计算机网络
---
http 是一套计算机通过网络进行通信的规则。它是无状态的协议，浏览器与服务器之间不需要建立持久链接。只要遵循request/response模型，之后就可以关闭连接。
<!--more-->

## http 通信机制

一次完整的通信要经过下列7步骤

1. **建立TCP连接**  
http作为应用层协议，必须先通过低层协议TCP进行连接，通常端口80

2. **浏览器向服务器发送请求命令**  
形如:GET/sample/hello.jsp HTTP/1.1

3. **浏览器请求头信息**  
类型格式说明，空行结束

4. **服务器应答**  
形如:HTTP/1.1 200 OK
协议版本号和应答状态码

5. **服务器发送应答头信息**  
说明它自己的数据以及被请求的文档

6. **服务器发送数据**  
以content_type描述的格式发送数据

7. **服务器关闭TCP**  
通常关闭TCP，如果头信息加入connection:keep-alive,保持连接，节约了带宽。

## http 请求格式

请求信息有三部分：

- **请求方法 URI 协议/版本**  
对于GET/sample.jsp HTTP/1.1，GET为方法，/sample.jsp为URI，之后为协议和协议的版本  
请求方法有7种：GET、POST、HEAD、OPTIONS、PUT、DELETE、TARCE  
**GET** 通过请求URI得到资源  
默认的请求方法，日常用来提交表单数据，但表单数据只经过简单编码，存在QUERY_STRING环境变量中，作为URL的一部分发送过去。例如`http://127.0.0.1/login.jsp?Name=zhangshi&Age=30&Submit=%cc%E+%BD%BB`,所以数据量也不能太大。  
**POST** 添加新的内容  
GET的替代方法，主要是大批量的数据，表单不作为请求的一部分而是标准数据，从标准输入流中获取。  
**PUT** 修改内容  
**DELETE** 删除内容  
**CONNECT** 代理传输（SSL）  
**OPTIONS** 询问可执行的方法  
**PATCH** 更改部分文档  
**PROPFIND** 查看属性  
**MKCOL** 创建集合  
**COPY** 拷贝  
**MOVE** 移动  
**LOCK**  加锁
**UNLOCK**  解锁
**TRACE**  远程诊断服务器
**HEAD** 类似于GET，但无body信息，检查对象的存在。  

URI 是一个字符串格式规范，可表示一个域，也可以标识一个资源（主码）。  
URL 前者子集，是资源用地址定位的规范，只能表示一个资源。  

- **request header**  
关于环境与正文的信息。

- **request content**  
可以包含客户提交的查询字符串信息

## http 响应

- **协议状态版本代码描述**  
协议版本+数字。
- 1XX-信息类（information），表示收到，进行相应的处理。  
- 2XX-成功类（successful），正确接受，理解和处理。  
- 3XX-重定向类（redirection），未成功，进一步的动作。
- 4XX-客户端错误（client error），请求的错误。
- 5XX-服务端错误（server error），不能处理请求。

- **响应头**  
服务器类型、日期时间、内容类型和长度等。

- **响应正文**  
返回HTML页面。