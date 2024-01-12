package main

import (
	"fmt"
	"strings"
)

func swapCase(input string) string {
	result := ""

	for _, char := range input {
		if 'a' <= char && char <= 'z' {
			// 소문자인 경우 대문자로 변경
			result += strings.ToUpper(string(char))
		} else if 'A' <= char && char <= 'Z' {
			// 대문자인 경우 소문자로 변경
			result += strings.ToLower(string(char))
		} else {
			// 알파벳이 아닌 경우 그대로 유지
			result += string(char)
		}
	}

	return result
}

func main() {
	var input string
	_, err := fmt.Scan(&input)

	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	swapped := swapCase(input)
	fmt.Println(swapped)
}
