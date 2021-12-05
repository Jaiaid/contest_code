if __name__=="__main__":
    tc = int(input())

    for tc_no in range(tc):
        word = input()

        word_char_list = [c for c in word]
        # O(n^2) attempt
        # take each character in list and replace it with other so that original char position don't match
        for i in range(0, len(word)):
            for j in range(0, len(word)):
                if i != j and word_char_list[i] != word[j] and word_char_list[j] != word[i]:
                    # exchange
                    tmp = word_char_list[j]
                    word_char_list[j] = word_char_list [i]
                    word_char_list[i] = tmp
                    break
            # print(word_char_list)

        # check if that creates a valid string
        possible = True
        for idx, c in enumerate(word):
            if c == word_char_list[idx]:
                possible = False
                break

        if possible:
            print("Case #{0}: ".format(tc_no+1) + "".join(word_char_list))
        else:
            print("Case #{0}: IMPOSSIBLE".format(tc_no+1))
