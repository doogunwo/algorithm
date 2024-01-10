	package main

	import "fmt"

	func ccw(x1, y1, x2, y2, x3, y3 int) int {
		result := (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)
		if result > 0 {
			return 1 // 반시계 방향
		} else if result < 0 {
			return -1 // 시계 방향
		} else {
			return 0 // 일직선에 놓여있음
		}
	}

	func main() {
		var x1, y1, x2, y2, x3, y3 int
		fmt.Scan(&x1, &y1, &x2, &y2, &x3, &y3)

		result := ccw(x1, y1, x2, y2, x3, y3)
		fmt.Println(result)
	}
