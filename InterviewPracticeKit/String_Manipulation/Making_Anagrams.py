"""
Given two strings,  and , that may or may not be of the same length,
determine the minimum number of character deletions required to make  and  anagrams. 
"""

def makeAnagram(a, b):
    A = set(a)
    B = set(b)
    C = A.intersection(B)
    
    total = 0
    for element in C:
        # remove from the string with lowest frequency
        total += min(a.count(element), b.count(element))
        
    return len(a)+len(b) - total*2

def main():
    tests = [['cde','abc'],
             ['fcrxzwscanmligyxyvym','jxwtrhvujlmrpdoqbisbwhmgpmeoke']]
    for test in tests:
        print(makeAnagram(test[0], test[1]))
    

if __name__ == '__main__':
    main()