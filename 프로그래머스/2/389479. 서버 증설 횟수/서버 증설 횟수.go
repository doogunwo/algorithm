package main

import (
	"container/heap"
)

// 최소 힙 정의
type IntHeap []int

func (h IntHeap) Len() int            { return len(h) }
func (h IntHeap) Less(i, j int) bool  { return h[i] < h[j] } // 최소 힙
func (h IntHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	val := old[n-1]
	*h = old[0 : n-1]
	return val
}

func solution(players []int, m int, k int) int {
	answer := 0
	server := 1
	active := &IntHeap{}
	heap.Init(active)

	for time := 0; time < 24; time++ {
		// 만료된 서버 제거
		for active.Len() > 0 && (*active)[0] <= time {
			heap.Pop(active)
			server--
		}

		player := players[time]
		remain := player - server*m

		if remain < 0 {
			continue
		}

		for remain >= 0 {
			answer++
			server++
			heap.Push(active, time+k)
			remain -= m
		}
	}
	return answer
}
