/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-30
 * @tag   concurrency
 * @similar
 */

/*
给你一个类：

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
三个不同的线程 A、B、C 将会共用一个 Foo 实例。

线程 A 将会调用 first() 方法
线程 B 将会调用 second() 方法
线程 C 将会调用 third() 方法
请设计修改程序，以确保 second() 方法在 first() 方法之后被执行，third() 方法在 second() 方法之后被执行。

提示：

尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。
你看到的输入格式主要是为了确保测试的全面性。


示例 1：

输入：nums = [1,2,3]
输出："firstsecondthird"
解释：
有三个线程会被异步启动。输入 [1,2,3] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 second() 方法，线程 C 将会调用 third() 方法。正确的输出是 "firstsecondthird"。
示例 2：

输入：nums = [1,3,2]
输出："firstsecondthird"
解释：
输入 [1,3,2] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 third() 方法，线程 C 将会调用 second() 方法。正确的输出是 "firstsecondthird"。


提示：
nums 是 [1, 2, 3] 的一组排列
*/

package main

import (
	"fmt"
	"time"
)

/*
Tips
M1

M2

*/

type Foo struct {
	//Ch1 chan struct{}
	Ch2 chan struct{}
	Ch3 chan struct{}
}

func NewFoo() *Foo {
	return &Foo{
		//Ch1: make(chan struct{}),
		Ch2: make(chan struct{}),
		Ch3: make(chan struct{}),
	}
}

func (f *Foo) First(printFirst func()) {
	// Do not change this line
	//<-f.Ch1
	printFirst()
	f.Ch2 <- struct{}{}
}

func (f *Foo) Second(printSecond func()) {
	/// Do not change this line
	<-f.Ch2
	printSecond()
	f.Ch3 <- struct{}{}
}

func (f *Foo) Third(printThird func()) {
	// Do not change this line
	<-f.Ch3
	printThird()
	//f.Ch1 <- struct{}{}
}

func main1114() {
	foo := NewFoo()
	go foo.Third(func() {
		fmt.Printf("third\n")
	})
	go foo.First(func() {
		fmt.Printf("first\n")
	})
	go foo.Second(func() {
		fmt.Printf("second\n")
	})
	time.Sleep(time.Second * 3)
}
