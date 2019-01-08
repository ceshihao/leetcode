func fourSumCount(A []int, B []int, C []int, D []int) int {
	aBMap := make(map[int]int)
	for _, a := range A {
		for _, b := range B {
			aBMap[a+b]++
		}
	}
	cnt := 0
	for _, c := range C {
		for _, d := range D {
			cnt += aBMap[-1*(c+d)]
		}
	}
	return cnt
}
