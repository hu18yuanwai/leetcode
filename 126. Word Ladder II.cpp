class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        wordList.push_back(beginWord);
        wordList.push_back(endWord);
        int len = wordList.size();
        vector< vector<int>> g(len,vector<int>(len,0));
        buildGrap(wordList,g);

    }
private:
    void buildGrap(vector<string>& wordList, vector<vector<int>>& g){
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(isChange(wordList[i],wordList[j])){
                    g[i][j]=g[j][i]=0;
                }
            }
        }
    }
};







class Solution
{
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        vector<vector<string>> ladders;
        if (start == end)
        {
            ladders.push_back(vector<string>{start});
            return ladders;
        }

        unordered_set<string> beginWords {start};
        unordered_set<string> endWords {end};
        dict.erase(start);
        dict.erase(end);

        unordered_map<string, unordered_set<string>> next;
        bool laddersFound = false;
        bool begin2end = true;

        while (!beginWords.empty() && !laddersFound)
        {
            unordered_set<string> nextWords;
            for (auto word : beginWords)
            {
                auto originWord = word;
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
                            laddersFound = true;
                            addNext(word, originWord, next, begin2end);
                        }
                        else if (dict.find(word) != dict.end())
                        {
                            addNext(word, originWord, next, begin2end);
                            nextWords.insert(word);
                        }
                    }
                    word[i] = originChar;
                }
            }

            for (auto w : nextWords)
            {
                dict.erase(w);
            }

            beginWords.clear();
            beginWords.swap(nextWords);
            if (beginWords.size() > endWords.size())
            {
                beginWords.swap(endWords);
                begin2end = !begin2end;
            }
        }

        vector<string> currLadder {start};
        getAllLadders(currLadder, next, ladders, end);
        return ladders;
    }

private:
    inline void addNext(const string &word, const string &originWord, unordered_map<string, unordered_set<string>> &next, bool begin2end)
    {
        if (begin2end)
        {
            next[originWord].insert(word);
        }
        else
        {
            next[word].insert(originWord);
        }
    }

    void getAllLadders(vector<string> &currLadder, unordered_map<string, unordered_set<string>> &next, vector<vector<string>> &ladders, const string &endWord)
    {
        auto word = currLadder.back();
        if (word == endWord)
        {
            ladders.push_back(currLadder);
            return;
        }

        auto nextWords = next[word];
        for (auto w : nextWords)
        {
            currLadder.push_back(w);
            getAllLadders(currLadder, next, ladders, endWord);
            currLadder.pop_back();
        }
    }
};
