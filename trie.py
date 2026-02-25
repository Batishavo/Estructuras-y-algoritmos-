from collections import deque 

class WordDictionary:

    def __init__(self):
        self.dictionary = {}

    def addWord(self, word: str) -> None:
        
        tmp = self

        for char in word:

            if not char in tmp.dictionary:
                tmp.dictionary[char] = WordDictionary()
            
            tmp = tmp.dictionary[char]
        
        tmp.dictionary["*"] = WordDictionary()



    def search(self, word: str) -> bool:

        tmp = self
        bfs = deque([[tmp,0]])

        while len(bfs)>0:

            node,pos = bfs.popleft()

            if pos == len(word):
               
                if "*" in node.dictionary:
                    return  True
                else:
                    continue

            char = word[pos]
          
            if char in node.dictionary:
                bfs.append([node.dictionary[char],pos+1])

        return False

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
