func minAddToMakeValid(S string) int {
	var sum, add int
	for _, s := range S {
		if s == '(' {
			if add <= 0 {
				sum += -add
				add = 1
			} else {
				add++
			}
		} else {
			add--
		}
	}
	if add < 0 {
		add = -add
	}
	return sum + add
}
