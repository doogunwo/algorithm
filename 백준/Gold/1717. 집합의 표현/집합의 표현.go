package main

import (
    "bufio"
    "fmt"
    "os"
)

var parent []int

// find 함수: 특정 원소의 루트 노드를 찾습니다.
func find(x int) int {
    if parent[x] == x {
        return x
    }
    parent[x] = find(parent[x]) // 경로 압축(Path Compression)
    return parent[x]
}

// union 함수: 두 원소가 속한 집합을 합칩니다.
func union(x, y int) {
    xRoot := find(x)
    yRoot := find(y)
    if xRoot != yRoot {
        parent[yRoot] = xRoot
    }
}

// isSameSet 함수: 두 원소가 같은 집합에 속하는지 확인합니다.
func isSameSet(x, y int) bool {
    return find(x) == find(y)
}

func main() {
    var n, m int
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Split(bufio.ScanWords)
    scanner.Scan()
    fmt.Sscan(scanner.Text(), &n)
    scanner.Scan()
    fmt.Sscan(scanner.Text(), &m)

    parent = make([]int, n+1)
    for i := range parent {
        parent[i] = i
    }

    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    for i := 0; i < m; i++ {
        var command, a, b int
        scanner.Scan()
        fmt.Sscan(scanner.Text(), &command)
        scanner.Scan()
        fmt.Sscan(scanner.Text(), &a)
        scanner.Scan()
        fmt.Sscan(scanner.Text(), &b)

        if command == 0 {
            union(a, b)
        } else if command == 1 {
            if isSameSet(a, b) {
                writer.WriteString("YES\n")
            } else {
                writer.WriteString("NO\n")
            }
        }
    }
}
