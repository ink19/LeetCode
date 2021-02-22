#!/usr/bin/env  python3

test = ["1"]

def countAndSay(n):
    if (n == 1): return "1" 
    result = ""
    last_result = countAndSay(n - 1)
    temp_char = ''
    count = 0
    for mchar in last_result:
        if temp_char == mchar:
            count += 1
        elif temp_char != '':
            result += str(count) + temp_char
            count = 1
            temp_char = mchar
        else:
            count = 1
            temp_char = mchar
    result += str(count) + temp_char
    test.append(result)
    return result


countAndSay(32)

print(test)
