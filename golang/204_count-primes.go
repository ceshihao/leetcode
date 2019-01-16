func countPrimes(n int) int {
	if n < 3 {
		return 0
	}
	compositeMap := make([]bool, n)
	cnt := n
	for i := 2; i*i < n; i++ {
		if !compositeMap[i] {
			for j := i * i; j < n; j += i {
				if !compositeMap[j] {
					cnt--
					compositeMap[j] = true
				}
			}
		}
	}
	return cnt - 2
}
