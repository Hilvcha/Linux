---
title: Lec2a-高阶过程
date: 2017-08-11 20:49:22
tags: 
- 函数式
- Sicp
- Lisp
- 递归
- 迭代
categories:
- Sicp
---
抽象概括出有价值的公共模式
```racket
(define (sum-int a b)
    (if (> a b)
        0
        (+ a
           (sum-int (1+ a) b))))
;
(define (sum-sq a b)
    (if (> a b)
        0
        (+ (square a)
           (sum-sq (1+ a) b))))
;
(define (pi-sum a b)
    (if (> a b)
        0
        (+ (/ 1 (* a (+ a 2)))
           (pi-sum (+ a 4) b))))
```

<!--more-->
对于一个求和过程可以抽出必有的求和作为骨架，将求出加的项和推出下一个迭代变量的过程作为参数提出来，进行递归的表示。

```racket
;term 根据下标a 求出当前的项 next 求出a的下一个迭代变量作为新的a值
(define (sum term a next b)
    (if (> a b)
         0
         (+ (term a)
            (sum term
                 (next a)
                 next
                 b))))
```

通过更高阶的过程传入要进行处理的过程，从而只改动隔离出的很小一部分就能产生新的求和过程。这样的程序易写易读。

```racket
(define (sum-int a b)
    (define (identity x) x)
    (sum identity a 1+ b))

(define (sum-sq a b)
    (sum square a 1+ b))
```