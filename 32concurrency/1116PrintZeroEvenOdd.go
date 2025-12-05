/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-05
 * @tag   concurrency
 * @similar
 */

/*
现有函数 printNumber 可以用一个整数参数调用，并输出该整数到控制台。

例如，调用 printNumber(7) 将会输出 7 到控制台。
给你类 ZeroEvenOdd 的一个实例，该类中有三个函数：zero、even 和 odd 。ZeroEvenOdd 的相同实例将会传递给三个不同线程：

线程 A：调用 zero() ，只输出 0
线程 B：调用 even() ，只输出偶数
线程 C：调用 odd() ，只输出奇数
修改给出的类，以输出序列 "010203040506..." ，其中序列的长度必须为 2n 。

实现 ZeroEvenOdd 类：

ZeroEvenOdd(int n) 用数字 n 初始化对象，表示需要输出的数。
void zero(printNumber) 调用 printNumber 以输出一个 0 。
void even(printNumber) 调用printNumber 以输出偶数。
void odd(printNumber) 调用 printNumber 以输出奇数。


示例 1：

输入：n = 2
输出："0102"
解释：三条线程异步执行，其中一个调用 zero()，另一个线程调用 even()，最后一个线程调用odd()。正确的输出为 "0102"。
示例 2：

输入：n = 5
输出："0102030405"


提示：

1 <= n <= 1000

*/

package main

import (
	"fmt"
	"time"
)

type ZeroEvenOdd struct {
	n       int
	zeroCh1 chan int
	zeroCh2 chan int
	numCh   chan struct{}
}

func NewZeroEvenOdd(n int) *ZeroEvenOdd {
	zeo := &ZeroEvenOdd{
		n:       n,
		zeroCh1: make(chan int),
		zeroCh2: make(chan int),
		numCh:   make(chan struct{}, 1),
	}
	// first trigger
	zeo.numCh <- struct{}{}
	return zeo
}

func (z *ZeroEvenOdd) Zero(printNumber func(int)) {
	for i := 1; i <= z.n; i++ {
		<-z.numCh
		printNumber(0)
		if i%2 == 0 {
			z.zeroCh1 <- i
		} else {
			z.zeroCh2 <- i
		}
	}
}

func (z *ZeroEvenOdd) Even(printNumber func(int)) {
	for k := 1; k <= z.n/2; k++ {
		cur := <-z.zeroCh1
		printNumber(cur)
		z.numCh <- struct{}{}
	}
}

func (z *ZeroEvenOdd) Odd(printNumber func(int)) {
	for k := 1; k <= (z.n+1)/2; k++ {
		cur := <-z.zeroCh2
		printNumber(cur)
		z.numCh <- struct{}{}
	}
}

func pn(i int) {
	fmt.Printf("%d", i)
}

func main1116() {
	ze := NewZeroEvenOdd(3)
	go ze.Zero(pn)
	go ze.Even(pn)
	go ze.Odd(pn)
	time.Sleep(time.Second * 3)
}

/*
Tips
M1

M2

*/
