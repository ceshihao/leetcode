func validUtf8(data []int) bool {
	cnt := 0
	for i := 0; i < len(data); i++ {
		if cnt == 0 {
			if data[i]>>5 == 6 {
				cnt = 1
			} else if data[i]>>4 == 14 {
				cnt = 2
			} else if data[i]>>3 == 30 {
				cnt = 3
			} else if data[i]>>7 == 1 {
				return false
			}
		} else {
			if data[i]>>6 != 2 {
				return false
			}
			cnt--
		}
	}
	return cnt == 0
}
