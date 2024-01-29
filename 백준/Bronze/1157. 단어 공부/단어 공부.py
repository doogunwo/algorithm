from collections import Counter


def find_most_letter(s):
    s = s.upper()
    counter = Counter(s)
    most_common = counter.most_common(2)
    
    if len(most_common) > 1 and most_common[0][1] == most_common[1][1]:
        return "?"
    else:
        return most_common[0][0]

s = input()
print(find_most_letter(s))