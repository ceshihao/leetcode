func search(nums []int, target int) bool {
	if len(nums) == 0 {
		return false
	}
	if nums[0] < target {
		for _, num := range nums {
			if num == target {
				return true
			} else if num > target {
				return false
			}
		}
	} else {
		for _, num := range nums {
			if num == target {
				return true
			}
		}
	}
	return false
}
