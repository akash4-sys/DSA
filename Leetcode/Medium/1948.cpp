#include "../../headers.h"

#define vvs vector<vector<string>>
#define vs vector<string>
#define f first
#define sc second

struct Node
{
    string name;
    bool deleted = false;
    map<string, Node *> dir;
    Node(string s) : name(s) {}

    void insert(vs &path, int i)
    {
        if (i >= path.size())
            return;
        auto it = dir.find(path[i]);
        if (it == end(dir))
            it = dir.insert({path[i], new Node(path[i])}).f;
        it->sc->insert(path, i + 1);
    }

    string trim(unordered_map<string, Node *> &m)
    {
        string path;
        for (auto [s, node] : dir)
            path += node->trim(m);
        if (!path.empty())
        {
            auto it = m.find(path);
            if (it != m.end())
                it->sc->deleted = deleted = true;
            else
                m[path] = this;
        }
        return "(" + name + path + ")";
    }

    void build(vvs &paths, vs &path)
    {
        if (deleted)
            return;
        if (!path.empty())
            paths.push_back(path);
        for (auto [s, node] : dir)
        {
            path.push_back(s);
            node->build(paths, path);
            path.pop_back();
        }
    }
};

class Solution
{
public:
    vvs deleteDuplicateFolder(vvs &paths)
    {
        Node node("");
        for (auto &path : paths)
            node.insert(path, 0);
        vvs ans;
        node.trim(unordered_map<string, Node *>() = {});
        node.build(ans, vs() = {});
        return ans;
    }
};