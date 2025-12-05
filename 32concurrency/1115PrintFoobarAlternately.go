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
给你一个类：

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
两个不同的线程将会共用一个 FooBar 实例：

线程 A 将会调用 foo() 方法，而
线程 B 将会调用 bar() 方法
请设计修改程序，以确保 "foobar" 被输出 n 次。



示例 1：

输入：n = 1
输出："foobar"
解释：这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
示例 2：

输入：n = 2
输出："foobarfoobar"
解释："foobar" 将被输出两次。


提示：

1 <= n <= 1000
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

type FooBar struct {
	n     int
	fooCh chan struct{}
	barCh chan struct{}
}

func NewFooBar(n int) *FooBar {
	return &FooBar{
		n:     n,
		fooCh: make(chan struct{}, 1),
		barCh: make(chan struct{}, 1),
	}
}

func (fb *FooBar) Foo(printFoo func()) {
	// first trigger
	fb.barCh <- struct{}{}
	for i := 0; i < fb.n; i++ {
		// printFoo() outputs "foo". Do not change or remove this line.
		<-fb.barCh
		printFoo()
		fb.fooCh <- struct{}{}
	}
}

func (fb *FooBar) Bar(printBar func()) {
	for i := 0; i < fb.n; i++ {
		// printBar() outputs "bar". Do not change or remove this line.
		<-fb.fooCh
		printBar()
		fb.barCh <- struct{}{}
	}
}

func main1115() {
	foo := NewFooBar(3)
	go foo.Foo(func() {
		fmt.Printf("foo")
	})
	go foo.Bar(func() {
		fmt.Printf("bar")
	})
	time.Sleep(time.Second * 3)
}
