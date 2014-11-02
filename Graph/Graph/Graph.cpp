#include <iostream>
#include <vector>
#include <map>
#define GRAPH  vector<vector<int>>
using namespace std;

map<char, int> key;
vector<vector<int>> G;
vector<int> P;

void Graph_init()
{
    vector<int> tmp;
    //vector<vector<char>> path = { { 'w', 'z' }
    //                            , { 'u', 'v' }
    //                            , { 't', 'v' }
    //                            , { 's', 'w' }
    //                            , { 'x' }
    //                            , { 'z' }
    //                            , { 'x' }
    //                            , { 'w', 'y' } };
    vector<vector<char>> path = { 
      { 'w', 'z' }  //s
    , { 'u', 'v' }  //t
    , { 'v' }  //u
    , { 's', 'w' }  //v
    , { 'x' }       //w
    , { 'z'}       //x
    , { 'x' }       //y
    , { 'w', 'y' }  //z
    };
    key['s'] = 0;
    key['t'] = 1;
    key['u'] = 2;
    key['v'] = 3;
    key['w'] = 4;
    key['x'] = 5;
    key['y'] = 6;
    key['z'] = 7;
    for (int i = 0; i < key.size(); i++)
    {
        vector<int> tmp;
        for (int j = 0; j < path[i].size(); j++)
        {
            tmp.push_back(key[path[i][j]]);
        }
        G.push_back(tmp);
        tmp.erase(tmp.begin(), tmp.end());
    }

}
void _DFSVisit(GRAPH &G, int start, vector<bool> &isvisit)
{
    if (isvisit[start] == true)
    {
        return;
    }
    else
    {
        isvisit[start] = true;
        cout << start << "\t";
        for (int i = 0; i < G[start].size(); i++)
        {
            _DFSVisit(G, G[start][i], isvisit);
        }
    }
}
void DFSVisit(GRAPH &G)
{
    int len = G.size();
    vector<bool> flg(len,false);
    for (int i = 0; i < len; i++)
    {
        _DFSVisit(G, i, flg);
    }
}
bool DFSHasCircle(GRAPH &G, int start, vector<bool> &visit, vector<bool> &visitover)
{
    if (visit[start] == false)
    {
        visit[start] = true;
        for (int i = 0; i < G[start].size(); i++)
        {
            if (DFSHasCircle(G, G[start][i], visit, visitover))
            {
                return true;
            }
        }
        visitover[start] = true;
    }
    else if (visitover[start] == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool HasCircle(GRAPH &G)
{
    int len = G.size();
    vector<bool> flg(len, false);
    vector<bool> flgover(len, false);
    for (int i = 0; i < len; i++)
    {
        if (DFSHasCircle(G, i, flg, flgover))
        {
            return true;
        }
    }
    return false;
}
int main(void)
{
    Graph_init();
    bool flg = HasCircle(G);
    cout << flg << endl;
    return 0;
}