class Solution {
public:
    void proc(vector<int>& ver, const string& version){
        int i=0;
        while(i<version.size()){
            int count= 0;
            while(i+count<version.size() && version[i+count] != '.') count++;
            string str = version.substr(i,count);
            ver.push_back(stoi(str));
            i = i+count+1;
        }
    }

    int compareVersion(string version1, string version2) {
        vector<int>ver1,ver2;
        proc(ver1,version1);
        proc(ver2,version2);
        int len = ver1.size() > ver2.size() ? ver1.size() : ver2.size();
        if(ver1.size() < len){
            for(int i=0;i<len - ver1.size();i++) ver1.push_back(0);
        }
        if(ver2.size() < len){
            for(int i=0; i<len -ver2.size();i++) ver2.push_back(0);
        }
        for(int i=0;i<len;i++){
            if(ver1[i]<ver2[i]) return -1;
            else if(ver1[i]>ver2[i]) return 1;
            else continue;
        }
        return 0;
    }
};


class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        while (!version1.empty() || !version2.empty())
        {
            auto ver1 = version1.empty() ? 0 : stoi(version1);
            auto ver2 = version2.empty() ? 0 : stoi(version2);
            if (ver1 < ver2)
            {
                return -1;
            }
            else if (ver1 > ver2)
            {
                return 1;
            }
            else
            {
                auto pos1 = version1.find('.');
                version1 = (pos1 == string::npos) ? "" : version1.substr(pos1 + 1);
                auto pos2 = version2.find('.');
                version2 = (pos2 == string::npos) ? "" : version2.substr(pos2 + 1);
            }
        }
        return 0;
    }
};
