class Solution
{
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
    {
        if (beginWord == endWord)
        {
            return 1;
        }

        unordered_set<string> beginWords {beginWord};
        unordered_set<string> endWords {endWord};
        wordDict.erase(beginWord);
        wordDict.erase(endWord);
        int len = 2;

        while (!beginWords.empty())
        {
            unordered_set<string> nextWords;
            for (auto word : beginWords)
            {
                for (int i = 0; i < word.size(); i++)
                {
                    auto originChar = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        if (ch == originChar)
                        {
                            continue;
                        }

                        word[i] = ch;
                        if (endWords.find(word) != endWords.end())
                        {
                            return len;
                        }
                        else if (wordDict.find(word) != wordDict.end())
                        {
                            nextWords.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[i] = originChar;
                }
            }

            beginWords.clear();
            beginWords.swap(nextWords);
            if (beginWords.size() > endWords.size())
            {
                beginWords.swap(endWords);
            }
            len++;
        }
        return 0;
    }
};


class Solution
{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        if (start.size() != end.size())
            return 0;
        if (start.empty() || end.empty())
            return 1;
        if (dict.size() == 0)
            return 0;
        int distance = 1; //!!!
        queue<string> queToPush, queToPop;
        queToPop.push(start);
        while (dict.size() > 0 && !queToPop.empty())
        {
            while (!queToPop.empty())
            {
                string str(queToPop.front()); //!!!how to initialize the str
                queToPop.pop(); //!!! should pop after it is used up
                for (int i = 0; i < str.size(); i++)
                {
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        if (j == str[i])
                            continue;
                        char temp = str[i];
                        str[i] = j;
                        if (str == end)
                            return distance + 1; //found it
                        if (dict.count(str) > 0) //exists in dict
                        {
                            queToPush.push(str); //find all the element that is one edit away
                            dict.erase(str); //delete corresponding element in dict in case of loop
                        }
                        str[i] = temp; //
                    }
                }
            }
            swap(queToPush, queToPop); //!!! how to use swap
            distance++;
        } //end while
        return 0; //all the dict words are used up and we do not find dest word
    } //end function
};  
