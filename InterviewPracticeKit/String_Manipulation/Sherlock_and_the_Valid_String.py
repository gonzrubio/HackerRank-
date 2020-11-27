"""
Sherlock considers a string to be valid if all characters of the string
appear the same number of times. It is also valid if he can remove just 1 character
at 1 index in the string, and the remaining characters will occur the same number of times.
Given a string , determine if it is valid. If so, return YES, otherwise return NO.
"""

def isValid(s):
    dictionary = dict()
    for letter in s:
        dictionary[letter] = dictionary.get(letter,0) + 1        
    dict(sorted(dictionary.items(), key=lambda item: item[1]))

    if len(dictionary) == 1 or sum(dictionary.values()) % len(dictionary) == 0 \
                            or (sum(dictionary.values())-1)%(len(dictionary)-1)== 0 \
                            or (sum(dictionary.values())-1)%(len(dictionary))== 0:    
        print("YES")
    else:
        print("NO")    
    

def main():
    tests = ['abc','abcc','aabbcd','aabbccddeefghi','abcdefghhgfedecba']
    for test in tests:
         isValid(test)
    #isValid('abcdefghhgfedecba')

    
if __name__ == '__main__':
    main()