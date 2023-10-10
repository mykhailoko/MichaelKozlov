package main

import (
	"bufio"
	"fmt"
	"os"
)

func isPalindrome(s string) bool {
	s = toLowerCase(s)

	var cleaned string
	for _, char := range s {
		if isAlphaNumeric(char) {
			cleaned += string(char)
		}
	}

	return isPalindromeHelper(cleaned)
}

func toLowerCase(s string) string {
	var result string
	for _, char := range s {
		if char >= 'A' && char <= 'Z' {
			result += string(char + 32)
		} else {
			result += string(char)
		}
	}
	return result
}

func isAlphaNumeric(char rune) bool {
	return (char >= 'a' && char <= 'z') || (char >= '0' && char <= '9')
}

func isPalindromeHelper(s string) bool {
	length := len(s)
	for i := 0; i < length/2; i++ {
		if s[i] != s[length-1-i] {
			return false
		}
	}
	return true
}

func main() {
	line, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isPalindrome(line[:len(line)-1]) { // Обрезаем \n в конце строки
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

