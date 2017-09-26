---
title: Lec1a-Lisp概览
date: 2017-07-30 09:56:22
tags: 
- 函数式
- Sicp
- Lisp
categories:
- Sicp
---

程序很像一个黑箱，应用一些规则处理数据得到输出。这在数学上来讲就是一个函数。可是耦合的关系使它们不能像数学函数那样灵活组合，而函数式的特性使得它放宽现实中程序的限制，输入的可以是另一个程序（函数），而它本身也可以作为数据传入其他函数，从而像数学中应用的形式化方法一样，更好的抽象滴描述这个世界。
<!--more-->
# **计算机科学研究的是一种大系统中控制复杂度的技术.**  
这种复杂度不像其他现实工程中为了拟合现实带来的误差或者噪声。计算机工程通过大量数值计算等方面的研究可以看做设计的都是隔离于底层的理想化组件，可随意组合，无现实的约束。函数式可以比较显式地表达这种关系，而这种抽象的系统设计却是复杂所在。

## 黑盒抽象 black-box abstraction

- primitive objects  
    基本过程和基本数据

- means of combination  
    基本过程的组合和基本数据的组合

- means of abstraction  
    如何将过程抽象出来

- capturing common patterns  
    找到它的通用模式

## 约定接口 conventional interfaces

- generic operations  
    通用化来应对此类各种扩展

- large-scale structure and modularity
    - object-opiented programming  
    抽象出个体互相传递消息联系起来
    - operations on aggregates  
    聚集的操作，称为流

## 元语言抽象 metalinguistic abstraction

虽然编程语言通常是图灵完备的，但是设计意图都是为了强调系统的某个方面，它隐藏了一部分细节，却强调了另一部分，所以要设计新的语言。此时要设计出解释别的语言的程序，这也是一个输入输出的过程，但是因为输入的是需要理解的语言片段，他可能表达的不仅是一类数据，而是现实中无限的可能。为了能在简单的机器上应用并理解这些输入，需要通过有限的通用规则来处理输入的语言中的符号组合关系。
对于lisp，它可以神奇的只是循环的通过“应用”(apply)与“求值”(eval)完成解释自己的过程（自举）。

# Lisp

## 用于抽象的语法设施

lisp应用前缀表示法，将操作符与操作数（基本对象）依次放入括号，称为组合式（基本过程）。组合式作为基本过程可以成为新的操作数进行组合。这个线性字符串最终可看成一个树状结构。

 box-abstraction    | procedures | data     
----                 |---------   |------
 primitive elements  | + * < =    | 23 1.735 
 means of combination| ( ) combination</br> cond</br> if |  
 means of abstraction| define     |                  

```scheme
; 无参数
(define A (* 5 5))
(* A A)
; 传入参数
(define (rectangle a b)
    (* a b))
(rectangle 3 4)
;lambda 为一个带有参数的过程
(define square (lambda (x) (* 1 x)))
```
## 一个关于sqrt的例子

### 结构图

可将sqrt分解为以下按层级抽象的过程,其中try对自身递归定义

<img src="./Lisp概览/sqrt.jpg" width="300"  height="300" />

### lisp抽象定义的sqrt盒子

```scheme
(define (sqrt x)
    (define (improve guess)
        (average guess (/ x guess)))
    (define (good-enough? guess)
        (< (abs (- (square guess) x))
            001))
    (define (try guess)
        (if (good-enough? guess)
            guess
            (try (improve guess))))
    (try 1))
```
