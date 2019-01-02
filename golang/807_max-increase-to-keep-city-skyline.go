func maxIncreaseKeepingSkyline(grid [][]int) int {
    rowMax := make([]int, len(grid))
    colMax := make([]int, len(grid[0]))
    for r, row := range grid {
        for c, ele := range row {
            if ele > rowMax[r] {
                rowMax[r] = ele
            }
            if ele > colMax[c] {
                colMax[c] = ele
            }
        }
    }
    
    increaseSum := 0
    for r, row := range grid {
        for c, ele := range row {
            increaseSum = increaseSum + min(rowMax[r], colMax[c]) - ele
        }
    }
    return increaseSum
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
