/*
 * @lc app=leetcode id=68 lang=golang
 *
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (22.37%)
 * Total Accepted:    90.1K
 * Total Submissions: 400.4K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of words and a width maxWidth, format the text such that each
 * line has exactly maxWidth characters and is fully (left and right)
 * justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 *
 * Note:
 *
 *
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be",
 * because the last line must be left-justified instead of fully-justified.
 * ⁠            Note that the second line is also left-justified becase it
 * contains only one word.
 *
 *
 * Example 3:
 *
 *
 * Input:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 *
 *
 */import "strings"

func fullJustify(words []string, maxWidth int) []string {
	var resLines, line []string
	wordLength := 0
	curLength := 0
	for _, word := range words {
		if curLength+len(word) <= maxWidth {
			line = append(line, word)
			wordLength = wordLength + len(word)
			curLength = curLength + len(word) + 1
		} else {
			lineRes := outputLine(line, maxWidth, wordLength)
			resLines = append(resLines, lineRes)
			line = []string{word}
			curLength = len(word) + 1
			wordLength = len(word)
		}
	}
	resLines = append(resLines, outputLastLine(line, maxWidth))
	return resLines
}

func outputLine(line []string, maxWidth, wordLength int) string {
	lineLength := len(line)
	var lineRes string
	if lineLength > 1 {
		res := (maxWidth - wordLength) / (lineLength - 1)
		mod := (maxWidth - wordLength) % (lineLength - 1)
		for i, w := range line {
			if i == len(line)-1 {
				lineRes += w
			} else if i < mod {
				lineRes += w + strings.Repeat(" ", res+1)
			} else {
				lineRes += w + strings.Repeat(" ", res)
			}
		}
	} else {
		lineRes = line[0] + strings.Repeat(" ", maxWidth-len(line[0]))
	}
	return lineRes
}

func outputLastLine(line []string, maxWidth int) string {
	lineRes := strings.Join(line, " ")
	lineRes += strings.Repeat(" ", maxWidth-len(lineRes))
	return lineRes
}
