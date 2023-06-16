from difflib import ndiff

def levenshtein_distance(str1,str2):
    counter = {"+": 0, "-": 0}
    distance = 0
    for edit_code, *_ in ndiff(str1, str2):
        if edit_code == " ":
            distance += max(counter.values())
            counter = {"+": 0, "-": 0}
        else: 
            counter[edit_code] += 1
    distance += max(counter.values())
    return distance

str1 = input()
str2 = input()
print(levenshtein_distance(str1,str2))