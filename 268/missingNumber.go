package main

import "fmt"

func main() {

	nums := []int{3, 0, 1}
	fmt.Println(missingNumber(nums))

}

func missingNumber(nums []int) int {

	var result int = len(nums)

	for i := 0; i < len(nums); i++ {
		result = result ^ i
		result = result ^ nums[i]
	}
	return result

}
