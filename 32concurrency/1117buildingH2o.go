/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-08
 * @tag   concurrency,
 * @similar
 */

/*
现在有两种线程，氧 oxygen 和氢 hydrogen，你的目标是组织这两种线程来产生水分子。

存在一个屏障（barrier）使得每个线程必须等候直到一个完整水分子能够被产生出来。

氢和氧线程会被分别给予 releaseHydrogen 和 releaseOxygen 方法来允许它们突破屏障。

这些线程应该三三成组突破屏障并能立即组合产生一个水分子。

你必须保证产生一个水分子所需线程的结合必须发生在下一个水分子产生之前。

换句话说:

如果一个氧线程到达屏障时没有氢线程到达，它必须等候直到两个氢线程到达。
如果一个氢线程到达屏障时没有其它线程到达，它必须等候直到一个氧线程和另一个氢线程到达。
书写满足这些限制条件的氢、氧线程同步代码。



示例 1:

输入: water = "HOH"
输出: "HHO"
解释: "HOH" 和 "OHH" 依然都是有效解。
示例 2:

输入: water = "OOHHHH"
输出: "HHOHHO"
解释: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" 和 "OHHOHH" 依然都是有效解。


提示：

3 * n == water.length
1 <= n <= 20
water[i] == 'O' or 'H'
输入字符串 water 中的 'H' 总数将会是 2 * n 。
输入字符串 water 中的 'O' 总数将会是 n 。

*/

package main

import (
	"fmt"
	"sync"
	"time"
)

type H2O struct {
	Mu    sync.Mutex
	MCond *sync.Cond
	HCnt  int
	OCnt  int
}

func NewH2O() *H2O {
	h := &H2O{
		HCnt: 0,
		OCnt: 0,
	}
	h.MCond = sync.NewCond(&h.Mu)
	return h
}
func (h *H2O) Reset() {
	//h.Mu.Lock()
	if h.HCnt == 2 && h.OCnt == 1 {
		h.HCnt = 0
		h.OCnt = 0
	}
	//h.Mu.Unlock()
}

func (h *H2O) Hydrogen(releaseHydrogen func()) {
	// releaseHydrogen() outputs "H". Do not change or remove this line.
	h.Mu.Lock()
	for h.HCnt >= 2 {
		h.MCond.Wait()
	}

	releaseHydrogen()
	h.HCnt++
	h.Reset()
	h.MCond.Signal()
	h.Mu.Unlock()
}

func (h *H2O) Oxygen(releaseOxygen func()) {
	// releaseOxygen() outputs "H". Do not change or remove this line.
	h.Mu.Lock()
	for h.OCnt >= 1 {
		h.MCond.Wait()
	}
	releaseOxygen()
	h.OCnt++
	h.Reset()
	h.MCond.Signal()
	//h.MCond.Signal()
	h.Mu.Unlock()
}

func main1117() {
	h2o := NewH2O()
	water := "OOHHHH"
	for _, ch := range water {
		if ch == 'O' {
			go h2o.Oxygen(func() {
				fmt.Printf("O ")
			})
		} else {
			go h2o.Hydrogen(func() {
				fmt.Printf("H ")
			})
		}
	}

	time.Sleep(time.Second * 3)
}

/*
Tips
M1

M2


OHOHOOHHOHHOOHHHHOOHOOHHOHHOOHHHOOHOHHOHHOHHHHHOHHHHHHHHHHHH

*/
