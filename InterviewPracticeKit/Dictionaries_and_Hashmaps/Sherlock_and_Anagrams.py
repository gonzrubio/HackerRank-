"""
Given a string s, find the number of pairs of substrings of s that are anagrams of each other.
1<=q<=10 - Number of queries to analyze.
2<=|s|<=100 - Length of string.
s in ascii[a-z] 
"""


def sherlockAndAnagrams(s):
    """Return the number (int) of anagramatic pairs.
    
    s (list) - input string
    """
    n = len(s)        
    anagrams = dict() 
    for start in range(n):
        for end in range(start,n):
            substring = ''.join(sorted(s[start:end+1]))
            anagrams[substring] = anagrams.get(substring,0) + 1
    
    count = 0
    for substring in anagrams:
        freq = anagrams[substring]
        count += freq*(freq-1) // 2
            
    return count
 
    
def main():
    tests = ['abba','abcd','ifailuhkqq','kkkk']
    #for _ in range(int(input())):           # 1<=q<=10
    for test in tests:           # 1<=q<=10
        print(sherlockAndAnagrams(test)) # 2<=|s|<=100
              
    #return 0
    
if __name__ == '__main__':
    main()
    
    
    
    
    