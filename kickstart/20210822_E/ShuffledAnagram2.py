from functools import cmp_to_key

def cmp_items(a, b):
    if word[a] != word[b]:
        return 0
    else:
        return 1

if __name__=="__main__":
    global word

    tc = int(input())

    for tc_no in range(tc):
        word = input()

        possible = False
        word_char_index_list = [i for i in range(len(word))]
        # O(nlgn) attempt
        word_char_index_list.sort(key=cmp_to_key(cmp_items))

        word_char_list = []
        for idx in word_char_index_list:
            word_char_list.append(word[idx])
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
