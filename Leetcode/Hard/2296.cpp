#include "../../headers.h"

class TextEditor
{
public:
    string left, right;
    TextEditor()
    {
        left = "";
        right = "";
    }

    void addText(string t)
    {
        left.insert(left.end(), t.begin(), t.end());
    }

    int deleteText(int k)
    {
        k = min(k, (int)left.size());
        left.resize(left.size() - k);
        return k;
    }

    string cursorLeft(int k)
    {
        while(k-- && !left.empty())
        {
            right.push_back(left.back());
            left.pop_back();
        }
        return left.substr(left.size() - min(10, (int)left.length()));
    }

    string cursorRight(int k)
    {
        while(k-- && !right.empty())
        {
            left.push_back(right.back());
            right.pop_back();
        }
        return left.substr(left.size() - min(10, (int)left.length()));
    }
};