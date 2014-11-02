#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
using namespace std;


void _generateParent(vector<string> &svec, int n, int nleft, int index, string &strtmp, int NumOfLeft)
{
    if (nleft == 0)
    {
        string Sv = string(strtmp);
        svec.push_back(Sv);
        return;
    }
    if (NumOfLeft == 0)
    {
        strtmp[index++] = '(';
        _generateParent(svec, n - 1, nleft - 1, index, strtmp, NumOfLeft + 1);
    }
    else
    {
        if (n != 0)
        {
            strtmp[index] = '(';
            _generateParent(svec, n - 1, nleft - 1, index + 1, strtmp, NumOfLeft + 1);
            strtmp[index] = ')';
            _generateParent(svec, n, nleft - 1, index + 1, strtmp, NumOfLeft - 1);
        }
        else{
            strtmp[index] = ')';
            _generateParent(svec, n, nleft - 1, index + 1, strtmp, NumOfLeft - 1);
        }
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    string strtmp = string(n * 2, '\0');
    _generateParent(res, n, n * 2, 0, strtmp, 0);
    return res;
}

void deleblank(string &s)
{
    int i = 0;
    while (i == 0 && s[i] == ' ')
    {
        s.erase(i, 1);
    }
    while (i < s.length())
    {
        if (s[i] == ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
        {
            s.erase(i, 1);
        }
        else
        {
            i++;
        }
    }
}
void reversOnly(string &s, int i, int j)
{
    char tmp;
    while (i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}
void reverseWords(string &s)
{
    deleblank(s);
    int len = s.length() - 1;
    reversOnly(s, 0, s.length() - 1);
    int j;
    for (int i = 0; i < len;)
    {
        j = i;
        while (s[j] != ' ' && s[j] != '\0')
        {
            j++;
        }
        reversOnly(s, i, j - 1);
        i = j + 1;
    }
}
int evalRPN(vector<string> &tokens) {
    vector<string>::iterator it = tokens.begin();
    stack<int> st;
    int res = 0;
    while (it != tokens.end())
    {
        if (((*it).at(0) >= '0' && (*it).at(0) <= '9') || (*it).length() > 1)
        {
            st.push(atoi((it->c_str())));
        }
        else
        {
            int rig = st.top();
            st.pop();
            int lef = st.top();
            st.pop();
            switch ((*it).at(0))
            {
            case '+':
                res = lef + rig;
                break;
            case '-':
                res = lef - rig;
                break;
            case '*':
                res = lef * rig;
                break;
            case '/':
                res = lef / rig;
                break;
            default:
                break;
            }
            st.push(res);
        }
        it++;
    }
    return res;
}


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int ListNum(ListNode *Li)
{
    ListNode* List_tmp = Li;
    int tmp = 0;
    while (Li != NULL)
    {
        tmp++;
        Li = Li->next;
    }
    return tmp;
}
ListNode *Merge(ListNode *A, ListNode *B)
{
    ListNode *tmp_a = A;
    ListNode *tmp_b = B;
    ListNode *list_now = NULL;
    ListNode *List_p = NULL;
    if (tmp_a != NULL && tmp_b != NULL)
    {
        if (tmp_a->val < tmp_b->val)
        {
            List_p = list_now = A;
            tmp_a = tmp_a->next;
        }
        else
        {
            List_p = list_now = B;
            tmp_b = tmp_b->next;
        }
        list_now->next = NULL;
    }
    while (tmp_a != NULL && tmp_b != NULL)
    {
        if (tmp_a->val < tmp_b->val)
        {
            list_now->next = tmp_a;
            tmp_a = tmp_a->next;
        }
        else
        {
            list_now->next = tmp_b;
            tmp_b = tmp_b->next;
        }
        list_now = list_now->next;
    }
    if (tmp_a == NULL)
    {
        list_now->next = tmp_b;
    }
    else
    {
        list_now->next = tmp_a;
    }
    return List_p;
}
ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    int len = ListNum(head);
    ListNode* B = head;
    ListNode* tmp = NULL;
    int i = 0;
    while (i < len / 2 - 1)
    {
        B = B->next;
        i++;
    }
    tmp = B;
    B = B->next;
    tmp->next = NULL;
    tmp = sortList(head);
    B = sortList(B);
    head = Merge(tmp, B);
    return head;
}
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode> st;
    vector<int> vc_trav;
    TreeNode *tmp = root;
    if (root != NULL)
    {
        st.push(*root);
    }
    while (!st.empty())
    {
        *tmp = st.top();
        vc_trav.push_back(tmp->val);
        st.pop();
        if (tmp->left != NULL)
        {
            st.push(*tmp->left);
        }
        if (tmp->right != NULL)
        {
            st.push(*tmp->right);
        }
    }
    reverse(vc_trav.begin(), vc_trav.end());
    return vc_trav;
}
void listReverse(ListNode *&head)
{
    if (head == NULL)
    {
        return;
    }
    ListNode *Header = new ListNode(0);
    ListNode *tmp;
    Header->next = NULL;
    while (head != NULL)
    {
        tmp = Header->next;
        Header->next = head;
        head = head->next;
        Header->next->next = tmp;
    }
    head = Header->next;
    delete Header;
}
void reorderList(ListNode *head) {
    if (head == NULL)
    {
        return;
    }
    int lenoflist = ListNum(head);
    if (lenoflist <= 2)
    {
        return;
    }
    ListNode *B = head;
    int i = 0;
    while (i < (((lenoflist + 1) / 2) - 1))
    {
        B = B->next;
        i++;
    }
    ListNode *tmp = B->next;
    B->next = NULL;
    B = tmp;
    listReverse(B);
    ListNode *tmpa, *tmpb;
    ListNode *InserPos;
    InserPos = head;
    tmpb = B;
    while (tmpb != NULL)
    {
        tmpa = InserPos->next;
        InserPos->next = tmpb;
        tmpb = tmpb->next;
        InserPos->next->next = tmpa;
        InserPos = tmpa;
    }
}
/*
vector<string> wordBreak(string s, set<string> &dict) {


}*/
struct dictree
{
    bool isEnd;
    string leftstr;
    dictree **next;
public:
    dictree(string str) :leftstr(str), isEnd(false)
    {
        next = (dictree **)malloc(sizeof(dictree *)*str.length());
        for (int i = 0; i < str.length(); i++)
        {
            next[i] = NULL;
        }
    }
};
bool create_tree(dictree &DCT, set<string> &dict)
{
    if (dict.find(DCT.leftstr) != dict.end())
    {
        DCT.isEnd = true;
        return true;
    }
    int flg = false;
    for (int i = 0; i < DCT.leftstr.length(); i++)
    {
        string tmp = DCT.leftstr.substr(0, i);
        if (dict.find(tmp) != dict.end())
        {
            dictree *LeftStr = new dictree(DCT.leftstr.substr(i, DCT.leftstr.length() - i));
            DCT.next[i] = LeftStr;
            bool ret = create_tree(*LeftStr, dict);
            if (!ret)
            {
                DCT.next[i] = NULL;
            }
            else
            {
                flg = true;
            }
        }
    }
    return flg;
}
bool get_parttion(dictree Dictree, int &index, vector<string> &res)
{
    if (Dictree.isEnd)
    {
        index++;
        res.push_back(Dictree.leftstr);
        return true;
    }
    int flg = false;
    for (int i = 0; i < Dictree.leftstr.length(); i++)
    {
        if (Dictree.next[i] != NULL)
        {
            flg = get_parttion(*Dictree.next[i], index, res);
            if (flg)
            {
                res[index - 1].insert(0, " ");
                res[index - 1].insert(0, Dictree.leftstr.substr(0, i));
            }
        }
    }
    return flg;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
int candy(vector<int> &ratings) {
    if (ratings.size() < 2)
    {
        return 1;
    }
    int res = 0;
    int *candies = (int *)malloc(sizeof(int)* ratings.size());
    candies[0] = 1;
    auto it = 1;
    for (it; it < ratings.size(); it++)
    {
        if (ratings[it] > ratings[it - 1])
        {
            candies[it] = candies[it - 1] + 1;
        }
        else
        {
            candies[it] = 1;
        }
    }
    it = it - 2;
    for (; it >= 0; it--)
    {
        if (ratings[it] > ratings[it + 1])
        {
            candies[it] = max(candies[it], candies[it + 1] + 1);
        }
    }
    it++;
    for (; it < ratings.size(); it++)
    {
        res = res + ratings[it];
    }
    free(candies);
    return res;
}
vector<vector<int>> PathTree(TreeNode *Tree)
{
    vector<vector<int>> vecres;
    if (Tree->left == NULL && Tree->right == NULL)
    {
        vecres.push_back({ Tree->val });
        return vecres;
    }
    vector<vector<int>> vecl, vecr;
    if (Tree->left != NULL)
    {
        vecl = PathTree(Tree->left);
    }
    if (Tree->right != NULL)
    {
        vecr = PathTree(Tree->right);
    }
    for (auto it = vecl.begin(); it != vecl.end(); it++)
    {
        it->push_back(Tree->val);
        vecres.push_back(*it);
    }
    for (auto it = vecr.begin(); it != vecr.end(); it++)
    {
        it->push_back(Tree->val);
        vecres.push_back(*it);
    }
    return vecres;
}
int sumNumbers(TreeNode *root) {
    vector<vector<int>> path = PathTree(root);
    int sum = 0;
    for (auto it = path.begin(); it < path.end(); it++)
    {
        int sumi = 0;
        for (auto iit = it->end() - 1; iit >= it->begin(); iit--)
        {
            sumi = sumi * 10 + *iit;
        }
        sum = sum + sumi;
    }
    return sum;
}
int minimumTotal(vector<vector<int> > &triangle) {
    //   vector<int> res;
    return 0;
}
void Inorder2(TreeNode *Tree)
{
    if (Tree == NULL)  return;
    stack<TreeNode> st;
    while (Tree != NULL)
    {
        st.push(*Tree);
        Tree = Tree->left;
    }
    do{
        Tree = &st.top();
        printf("%d\t", Tree->val);
        st.pop();
        if (Tree->right != NULL)
        {
            Tree = Tree->right;
            while (Tree != NULL)
            {
                st.push(*Tree);
                Tree = Tree->left;
            }
        }
    } while (!st.empty());

}
vector<string>par(string dststr)
{
    vector<string> res;
    if (dststr.length() == 0)
    {
        return res;
    }
    vector<string> tmpvec;
    tmpvec = par(dststr.substr(1, dststr.length() - 1));
    res.push_back(dststr.substr(0, 1));
    for (auto it = tmpvec.begin(); it != tmpvec.end(); it++)
    {
        res.push_back(*it);
        string tmpstr = (*it).insert(0, dststr, 0, 1);
        res.push_back(tmpstr);
    }
    return res;
}
struct randomnode
{
    int weight;
    int val;
};
int Weightrandom(struct randomnode *data, int len)
{
    int sum = 0;
    int i = 0;
    for (i = 0; i < len; i++)
    {
        sum = sum + data[i].weight;
    }
    int key = rand() % sum;
    int start = 0;
    int end = data[0].weight;
    for (i = 0; i < len; i++)
    {
        if (start <= key && key < end)
        {
            break;
        }
        start = end;
        end = start + data[i + 1].weight;
    }
    return data[i].val;
}
set<string> subsequence(string str)
{
    set<string> res;
    if (str.length() == 0)
    {
        return res;
    }
    if (str.length() == 1)
    {
        res.insert("");
        res.insert(str);
        return res;
    }
    else
    {
        set<string> res1 = subsequence(str.substr(1, str.length() - 1));
        int size = res.size();
        for (auto i = res1.begin(); i != res1.end(); i++)
        {
            string tempstr = *i;
            res.insert(tempstr);
            tempstr.insert(0, str.substr(0, 1));
            res.insert(tempstr);
        }
    }
    return res;
}
int numDistinct(string S, string T) {
    int count = 0;
    set<string> Sres = subsequence(S);
    set<string> Tres = subsequence(T);
    int Ssize = Sres.size();
    int Tsize = Tres.size();
    for (auto i = Sres.begin(); i != Sres.end(); i++)
    {
        auto it = Tres.find(*i);
        if (it == Tres.end())
        {
            count++;
        }
    }
    for (auto i = Tres.begin(); i != Tres.end(); i++)
    {
        auto it = Sres.find(*i);
        if (it == Sres.end())
        {
            count++;
        }
    }
    return count;
}



bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL)
    {
        return false;
    }
    if (root->left == NULL && root->right == NULL && root->val == sum)
    {
        return true;
    }
    bool   flgleft = false;
    bool    flgright = false;
    if (root->left != NULL)
    {
        //flgleft =  hasPathSum(root->left,sum - root->val);
        return hasPathSum(root->left, sum - root->val);
    }
    if (root->right != NULL)
    {
        //flgright = hasPathSum(root->right, sum - root->val);
        return hasPathSum(root->right, sum - root->val);
    }

    // return flgleft||flgright;
    return false;
}
int ListLen(ListNode *Li)
{
    int count = 0;
    while (Li != NULL)
    {
        count++;
        Li = Li->next;
    }
    return count;
}
TreeNode *_sortedListToBST(ListNode *head, int len)
{
    if (len == 0)
    {

        return NULL;
    }
    int leftlen = 1;
    ListNode *rightlist = head;
    while (leftlen < (len / 2 + 1))
    {
        rightlist = rightlist->next;
        leftlen++;
    }
    TreeNode *newTree;
    if (leftlen == 1)
    {
        newTree = new TreeNode(rightlist->val);
        newTree->left = NULL;
        newTree->right = NULL;
    }
    else
    {
        newTree = new TreeNode(rightlist->val);
        rightlist = rightlist->next;
        newTree->left = _sortedListToBST(head, leftlen - 1);
        newTree->right = _sortedListToBST(rightlist, len - leftlen);
    }
    return newTree;
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    queue<TreeNode *> qu;
    vector<vector<int>> res;
    vector<int> vectemp;
    TreeNode *temp;
    if (root == NULL)
    {
        return res;
    }
    qu.push(root);
    qu.push(NULL);
    while (!qu.empty())
    {
        temp = qu.front();
        qu.pop();
        if (temp == NULL)
        {
            res.insert(res.begin(), vectemp);
            if (!qu.empty())
            {
                qu.push(NULL);
                vectemp.clear();
            }
        }
        else
        {
            vectemp.push_back(temp->val);
            if (temp->left != NULL)
            {
                qu.push(temp->left);
            }
            if (temp->right != NULL)
            {
                qu.push(temp->left);
            }
        }
    }
    return res;
}

TreeNode *_buildTree(vector<int> &inorder, int ioStart, int ioEnd, vector<int> &postorder, int poStart, int poEnd)
{
    TreeNode *NewNode = NULL;
    if (ioStart == ioEnd)
    {
        NewNode = new TreeNode(postorder[poEnd]);
    }
    else if (ioStart < ioEnd)
    {
        int index = ioStart;
        while (index <= ioEnd && inorder[index] != postorder[poEnd]) index++;
        NewNode = new TreeNode(postorder[poEnd]);
        int poleftStart = index - ioStart + poStart;
        NewNode->left = _buildTree(inorder, ioStart, index - 1, postorder, poStart, poleftStart - 1);
        NewNode->right = _buildTree(inorder, index + 1, ioEnd, postorder, poleftStart, poEnd - 1);
    }
    return NewNode;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() == 0){ return NULL; }
    return _buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}
TreeNode *_buildTree2(vector<int> &inorder, int ioStart, int ioEnd, vector<int> &preorder, int prStart, int prEnd)
{
    TreeNode *NewNode = NULL;
    if (ioStart == ioEnd)
    {
        NewNode = new TreeNode(preorder[prStart]);
    }
    else if (ioStart < ioEnd)
    {
        int index = ioStart;
        while (index <= ioEnd && inorder[index] != preorder[prStart]) index++;
        NewNode = new TreeNode(preorder[prStart]);
        int prleftStart = index - ioStart + prStart + 1;
        NewNode->left = _buildTree(inorder, ioStart, index - 1, preorder, prStart + 1, prleftStart - 1);
        NewNode->right = _buildTree(inorder, index + 1, ioEnd, preorder, prleftStart, prEnd);
    }
    return NewNode;
}

vector<string> _func(string s, int n)
{
    vector<string> res;
    if ((s.length() > ((n + 1) * 3)) || (s.length() < (n + 1)))
    {
        return res;
    }
    if (n == 0)
    {
        if ((s[0] == '0') && s.length() > 1)
        {
            return res;
        }
        int num = atoi(s.c_str());
        if (num >= 0 && num <= 255)
        {
            res.push_back(s);
        }
    }
    else
    {
        if (s[0] == '0')
        {
            vector<string> restmp = _func(s.substr(1, s.length() - 1), n - 1);
            if (restmp.size() != 0)
            {
                for (int i = 0; i < restmp.size(); i++)
                {
                    string strtmp = restmp[i];
                    strtmp.insert(0, 1, '.');
                    strtmp.insert(0, 1, s[0]);
                    res.push_back(strtmp);
                }
            }
        }
        else{
            for (int i = 1; i <= 3; i++)
            {
                if (s.length() >= i)
                {
                    int num = atoi(s.substr(0, i).c_str());
                    if (num >= 0 && num <= 255)
                    {
                        vector<string> restmp = _func(s.substr(i, s.length() - i), n - 1);
                        if (restmp.size() != 0)
                        {
                            for (int j = 0; j < restmp.size(); j++)
                            {
                                string strtmp = restmp[j];
                                strtmp.insert(0, 1, '.');
                                strtmp.insert(0, s.substr(0, i).c_str());
                                res.push_back(strtmp);
                            }
                        }
                    }
                }
            }
        }
    }
    return res;
}
vector<vector<int>> _func(vector<int> &s, int start, set<int> &path)
{
    vector<vector<int>> res;
    vector<vector<int>> resleft;
    if (path.find(s[start]) == path.end())
    {
        path.insert(s[start]);
        if (s.size() > start)
        {
            vector<int> tmp;
            resleft = _func(s, start + 1, path);
            if (resleft.size() == 0)
            {
                res.push_back(tmp);
                tmp.insert(tmp.begin(), s[start]);
                res.push_back(tmp);
            }
            else
            {
                for (int i = 0; i < resleft.size(); i++)
                {
                    tmp = resleft[i];
                    res.push_back(tmp);
                    tmp.insert(tmp.begin(), s[start]);
                    res.push_back(tmp);
                }
            }
        }
    }
    return res;
}
void _changeToN(vector<int> &res, int &num, int n)
{
    for (int i = 1; i <= n; i++)
    {
        num = num ^ (1 << (i - 1));
        res.push_back(num);
        if (i > 1)
        {
            _changeToN(res, num, i - 1);
        }
    }
}
vector<int> grayCode(int n) {

    int num = 0;
    vector<int> res;
    if (n < 0)
    {
        return res;
    }
    res.push_back(num);
    _changeToN(res, num, n);
    return res;
}

bool strEqu(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
bool resEqu(string s1, string s2)
{
    reverse(s1.begin(), s1.end());
    return s1 == s2;
}
bool isScramble(string s1, string s2) {
    if ((s1.length() == 0) || (s1.length() != s2.length()))
    {
        return false;
    }
    bool flg = false;
    int len = s1.length();
    for (int i = 1; i <= s1.length(); i++)
    {
        string s1tmp1 = s1.substr(0, i);
        string s1tmp2 = s1.substr(i, len - i);
        string s2tmp1 = s2.substr(0, i);
        string s2tmp2 = s2.substr(i, len - i);
        if (strEqu(s1tmp1, s2tmp1) && strEqu(s1tmp2, s2tmp2))
        {
            bool isRevers = resEqu(s1tmp1, s2tmp1) && resEqu(s1tmp2, s2tmp2);
            flg = flg ||
                (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.length() - i), s1.substr(i, s1.length() - i)));
        }
        if (flg)
        {
            return true;
        }
    }
    return false;
}
ListNode *Lpartition(ListNode *head, int x) {
    if (head == NULL || head->next == NULL)return head;
    ListNode *Headtmp = new ListNode(0);
    Headtmp->next = head;
    ListNode *insertPer = Headtmp;
    ListNode *deltmp = head;
    ListNode *delper = Headtmp;
    while (insertPer->next != NULL && insertPer->next->val < x){ insertPer = insertPer->next; }
    if (insertPer->next == NULL)
    {
        delete Headtmp;
        return head;
    }
    delper = insertPer->next;
    deltmp = delper->next;
    while (deltmp != NULL)
    {
        if (deltmp->val < x)
        {
            delper->next = deltmp->next;
            deltmp->next = insertPer->next;
            insertPer->next = deltmp;
            insertPer = insertPer->next;
            deltmp = delper->next;
        }
        else
        {
            delper = deltmp;
            deltmp = deltmp->next;
        }
    }
    head = Headtmp->next;
    delete Headtmp;
    return head;
}

int largestRectangleArea(vector<int> &height)
{
    if (height.size() == 0)
    {
        return 0;
    }
    stack<int> Stpos;
    int len = height.size();
    int max = 0;
    int pos = 0;
    while (pos < len)
    {
        if (Stpos.empty() || height[pos] > height[Stpos.top()])
        {
            Stpos.push(pos);
            pos++;
        }
        else
        {
            int min = height[Stpos.top()];
            int left = -1;
            int maxtmp = 0;
            Stpos.pop();
            if (Stpos.empty())
            {
                left = -1;
            }
            else
            {
                left = Stpos.top();
            }
            maxtmp = (pos - left - 1) * min;
            if (max < maxtmp)
            {
                max = maxtmp;
            }
        }
    }
    while (!Stpos.empty())
    {
        int min = height[Stpos.top()];
        int right = Stpos.top();
        Stpos.pop();
        int maxtmp = 0;
        int left = -1;
        if (!Stpos.empty())
        {
            left = Stpos.top();
        }
        maxtmp = (pos - left - 1) * min;
        if (max < maxtmp)
        {
            max = maxtmp;
        }
    }
    return max;
}
vector<vector<int> > _combine(int start, int end, int k)
{
    vector<vector<int>> res;
    if (k == 1)
    {
        for (int i = start; i <= end; i++)
        {
            vector<int> tmp;
            tmp.push_back(i);
            res.push_back(tmp);
        }
        return res;
    }
    while (start <= (end - k))
    {
        vector<vector<int>> restmp;
        restmp = _combine(start + 1, end, k - 1);
        for (int i = 0; i < restmp.size(); i++)
        {
            vector<int> tmp;
            tmp = restmp[i];
            tmp.insert(tmp.begin(), start);
            res.push_back(tmp);
        }
        start++;
    }
    return res;
}
vector<vector<int> > combine(int n, int k) {
    vector<vector<int>> res;
    if (k > n || n < 1)
    {
        return res;
    }
    return _combine(1, n, k);
}
int extrBlank(string s)
{
    int blankcount = 0;
    int wordcount = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            blankcount++;
        }
        else
        {
            if (s[i - 1] == ' ')
            {
                wordcount++;
            }
        }
    }
    return blankcount - wordcount;
}

string formString(vector<string> &words, int &start, int end, int L)
{
    string res;
    if (end == start)
    {
        res.insert(0, words[start]);
        string blank = string(L - words[start].length(), ' ');
        res.insert(res.length(), blank);
        start++;
        return res;
    }
    int i = start + 1;
    int lentmp = words[start].length();
    while (i <= end && (lentmp + 1 + words[i].length()) <= L)
    {
        lentmp = lentmp + 1 + words[i].length();
        i++;
    }
    i--;
    int wordcount = i - start + 1;
    int extrblank = L - lentmp;
    int blanklen;

    int other;
    if (wordcount == 1)
    {
        blanklen = extrblank;
        other = 0;
    }
    else
    {
        blanklen = 1 + extrblank / (wordcount - 1);
        other = extrblank % (wordcount - 1);
    }
    while (start < i)
    {
        string blank;
        if (other != 0)
        {
            other--;
            blank = string(blanklen + 1, ' ');
        }
        else
        {
            blank = string(blanklen, ' ');
        }
        res.insert(res.length(), words[start]);
        res.insert(res.length(), blank);
        start++;
    }
    res.insert(res.length(), words[start]);
    start++;
    return res;
}
vector<string> _fullJustfy(vector<string> &words, int start, int end, int L)
{
    vector<string> res;
    if (start > end)
    {
        return res;
    }
    int newstart = 0;
    while (newstart <= end)
    {
        string str = formString(words, newstart, end, L);
        res.push_back(str);
    }
    return res;
}
vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> res;
    if (words.size() == 0)
    {
        return res;
    }
    if (L == 0)
    {
        res.push_back("");
        return res;
    }
    int start = 0;
    res = _fullJustfy(words, start, words.size() - 1, L);
    return res;
}
string addBinary(string a, string b) {
    int lena = a.length();
    int lenb = b.length();
    int maxlen = max(lena, lenb);
    int carry = 0;
    string res = string(maxlen, '0');
    for (int i = 0; i < maxlen; i++)
    {
        int ai = 0, bi = 0, key = 0;
        if (i < lena) ai = a[a.length() - 1 - i] - '0';
        if (i < lenb) bi = b[b.length() - 1 - i] - '0';
        key = ai + bi + carry;
        switch (key)
        {
        case 0:
            carry = 0; break;
        case 1:
            carry = 0;
            res[maxlen - 1 - i] = '1';
            break;
        case 2:
            carry = 1; break;
        case 3:
            carry = 1; res[maxlen - 1 - i] = 1;
        }
    }
    return carry == 1 ? '1' + res : res;
}
/*
int min(int a, int b)
{
return a > b ? b : a;
}
int _minPathSum(vector<vector<int>> &grid, int posi, int posj)
{
if (posi == grid.size())
{
return INT_MAX;
}
if (posj == grid[0].size())
{
return INT_MAX;
}
if ((posi == (grid.size() - 1)) && (posj == (grid[0].size() - 1))) return grid[posi][posj];
int right = _minPathSum(grid, posi, posj + 1);
int down = _minPathSum(grid, posi + 1, posj);
return grid[posi][posj] + min(right, down);
}
int minPathSum(vector<vector<int> > &grid) {
if (grid.size() == 0)
{
return 0;
}
return _minPathSum(grid, 0, 0);
} */
int min(int a, int b)
{
    return a > b ? b : a;
}
int _minPathSum(vector<vector<int>> &grid, int posi, int posj, int **path)
{
    if (posi == grid.size())
    {
        return INT_MAX;
    }
    if (posj == grid[0].size())
    {
        return INT_MAX;
    }
    if ((posi == (grid.size() - 1)) && (posj == (grid[0].size() - 1))) return grid[posi][posj];
    int right;
    if ((posi < grid.size()) && (posj + 1 < grid[0].size()) && path[posi][posj + 1] != 0)
    {
        right = path[posi][posj + 1];
    }
    else
    {
        right = _minPathSum(grid, posi, posj + 1, path);
        //path[posi][posj + 1] = right;
    }
    int down = _minPathSum(grid, posi + 1, posj, path);
    if ((posi + 1 < grid.size()) && (posj < grid[0].size()) && path[posi + 1][posj] != 0)
    {
        down = path[posi + 1][posj];
    }
    else
    {
        right = _minPathSum(grid, posi + 1, posj, path);
        //path[posi + 1][posj] = right;
    }
    path[posi][posj] = grid[posi][posj] + min(right, down);
    return grid[posi][posj] + min(right, down);
}

int minPathSum(vector<vector<int> > &grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int m = grid.size(), n = grid[0].size();

    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;

    for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
        dp[j + 1] = min(dp[j + 1], dp[j]) + grid[i][j];

    return dp.back();
}
int _maxProWithoutZ(int A[], int start, int end)
{
    if (start == end)
    {
        return A[start];
    }
    int before = 1;
    int tail = 1;
    int res = 1;
    for (int i = start; i <= end; i++)
    {
        res = res * A[i];
    }
    if (res > 0)
    {
        return res;
    }
    else
    {
        int i = start;
        while (A[i] > 0) { before = before * A[i]; i++; };
        before = before * A[i];
        int j = end;
        while (A[j] > 0) { tail = tail * A[j]; i--; };
        tail = tail * A[j];
        return max(res / before, res / tail);
    }
}
int maxProduct(int A[], int n) {
    if (n == 1){ return A[0]; }
    int start = 0;
    int max = INT_MIN;
    int maxtmp;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            if (i != start)
            {
                maxtmp = _maxProWithoutZ(A, start, i - 1);
                if (max < maxtmp)
                {
                    max = maxtmp;
                }
            }
            start = i + 1;
        }
    }
    if (i != start)
    {
        maxtmp = _maxProWithoutZ(A, start, i - 1);
        if (max < maxtmp)
        {
            max = maxtmp;
        }
    }
    return max;
}
void swap(string &data, int i, int j)
{
    char tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}
string getPerOrder(string &data, int start, int len)
{
    if (len <= 1)
    {
        return data;
    }
    int per = 1;
    int now = 1;
    int i = 0;
    while (now < len)
    {
        i++;
        now = now * i;
    }
    per = now / i;
    len--;
    int posStart = data.length() - i;
    int swapindex = posStart + len / per;
    if (now == len)
    {
        swapindex = posStart + 1;
    }
    int nextlen = len % per;
    swap(data, swapindex, posStart);
    getPerOrder(data, posStart + 1, nextlen);
    return data;
}
string getPermutation(int n, int k) {
    string res = string(n, '0');
    for (int i = 0; i < n; i++)
    {
        res[i] = '1' + i;
    }
    res = getPerOrder(res, 0, k);
    return res;
}
bool equ(double x, double y)
{
    if ((((x - y) >0) && ((x - y) < 0.000000001)) || (((x - y) < 0) && ((x - y) > -0.000000001)))
    {
        return true;
    }
    return false;
}
double mypow(double x, int n) {
    if (n == 0 || equ(x, 0.0)){ return 1.0; }
    if (n == 1){ return x; }
    bool negtive = false;
    double res = 1.0;
    if (n < 0)
    {
        negtive = true;
        n = 0 - n;
    }

    int left = n % 2;
    double tmp = pow(x, n / 2);
    left == 1 ? res = tmp *tmp *x : res = tmp*tmp;
    if (negtive == true)
    {
        res = 1 / res;
    }
    return res;
}
void _rotate(vector<vector<int>> &matrix, int start, int n)
{
    if (n <= 1){ return; }
    int posi1 = start, posj1 = start;
    int posi2 = start, posj2 = start + n - 1;
    int posi3 = start + n - 1, posj3 = start + n - 1;
    int posi4 = start + n - 1, posj4 = start;
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        tmp = matrix[posi1 + i][posj1];
        matrix[posi1][posj1 + i] = matrix[posi4 - i][posj4];
        matrix[posi4 - i][posj4] = matrix[posi3][posj3 - i];
        matrix[posi3][posj3 - i] = matrix[posi2 + i][posj2];
        matrix[posi2 + i][posj2] = tmp;
    }
    _rotate(matrix, start + 1, n - 2);
}
void rotate(vector<vector<int> > &matrix) {
    _rotate(matrix, 0, matrix.size());
}
void swap(vector<int> &num, int i, int j)
{
    int tmp = num[j];
    num[j] = num[i];
    num[i] = tmp;
}
void _permute(vector<int> &num, int start, int end, vector<vector<int>> &res)
{
    if (start == end)
    {
        res.push_back(num);
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(num, start, i);
            _permute(num, start + 1, end, res);
            swap(num, start, i);
        }
    }
}
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int>> res;
    _permute(num, 0, num.size() - 1, res);
    return res;
}
int func(int n)
{
    int max;
    if (n <= 9)
    {
        return n;
    }
    for (int i = 9; i >= 2; i--)
    {
        if (n%i == 0)
        {
            max = func(n / i) * 10 + i;
            if (max < 0)
            {
                return -1;
            }
            return max;
        }
    }
    return -1;
}
string add(string num1, string num2)
{
    int len1 = num1.length() - 1;
    int len2 = num2.length() - 1;
    string res;
    char per = '0';
    while (len1 >= 0 && len2 >= 0)
    {
        int restmp = (num1[len1--] - '0') + (num2[len2--] - '0') + (per - '0');
        per = restmp / 10 + '0';
        char left = restmp % 10 + '0';
        res = left + res;
    }
    while (len1 >= 0)
    {
        int restmp = (num1[len1--] - '0') + (per - '0');
        per = restmp / 10 + '0';
        char left = restmp % 10 + '0';
        res = left + res;
    }
    while (len2 >= 0)
    {
        int restmp = (num2[len2--] - '0') + (per - '0');
        per = restmp / 10 + '0';
        char left = restmp % 10 + '0';
        res = left + res;
    }
    if (per != '0')
    {
        return per + res;
    }
    return res;
}
string _multiply(string num1, char num2)
{
    if (num2 == '0') return "0";
    char per = '0';
    int len = num1.length() - 1;
    string res;
    while (len >= 0)
    {
        int tmp = (num1[len--] - '0') * (num2 - '0') + per - '0';
        per = tmp / 10 + '0';
        char left = tmp % 10 + '0';
        res = left + res;
    }
    if (per == '0')
    {
        return res;
    }
    return per + res;
}
string multiply(string num1, string num2) {
    int len2 = num2.length();
    char per = '0';
    string res, restmp, resper;
    for (int i = 0; i < len2; i++)
    {
        restmp = _multiply(num1, num2[i]);
        res = add(res + '0', restmp);
    }
    return res;
}
int min(int x, int y, int z)
{
    int min;
    min = x>y ? y : x;
    min = min > z ? z : min;
    return min;
}
int Urglist(int n)
{
    int *pro2;
    int *pro3;
    int *pro5;
    int res;
    if (n == 1){ return 2; }
    int index = 0;
    int *path = new int[n + 1];
    path[0] = 1;
    path[1] = 2;
    index = 1;
    while (index < n)
    {
        pro2 = path;
        pro3 = path;
        pro5 = path;
        while ((*pro2) * 2 <= path[index]) pro2++;
        while ((*pro3) * 3 <= path[index]) pro3++;
        while ((*pro5) * 5 <= path[index]) pro5++;
        index++;
        path[index] = min((*pro2) * 2, (*pro5) * 5, (*pro3) * 3);
    }
    res = path[n];
    delete[] path;
    return res;
}
int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    if (len2 == 0) return len1;
    if (len1 == 0) return len2;
    vector<int> path(len2 + 1, 0);
    for (int j = 0; j <= len2; j++)
    {
        path[j] = j;
    }
    for (int i = 1; i <= len1; i++)
    {
        int perclu = i;
        int perper = i - 1;
        for (int j = 1; j <= len2; j++)
        {
            int perrow = path[j];
            if (word1[i - 1] == word2[j - 1])
            {
                path[j] = min(perper, perrow + 1, perclu + 1);
            }
            else
            {
                path[j] = min(perper + 1, perrow + 1, perclu + 1);
            }
            perper = perrow;
            perclu = path[j];
        }
    }
    return path.back();
}
int main()
{
    string str1 = "a";
    string str2 = "ab";
    int res = minDistance(str1, str2);
    return 0;
}
TreeNode *_sortedArrayToBST(vector<int> &num, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end + 1) / 2;
    int **a = new int*[];
    TreeNode *newNode = new TreeNode(num[mid]);
    newNode->left = _sortedArrayToBST(num, start, mid - 1);
    newNode->right = _sortedArrayToBST(num, mid + 1, end);
    return newNode;
}
TreeNode *sortedArrayToBST(vector<int> &num) {
    int len = num.size();
    return _sortedArrayToBST(num, 0, len - 1);
}
/*
bool isSameTree(TreeNode *p, TreeNode *q) {
bool flg = false;
if (p != NULL && q != NULL)
{
if (p->val == q->val)
{
flg = (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
//(isSameTree(p->right,q->left) && isSameTree(p->left,q->right));
}
else
{
flg = false;
}
}
else
{
if (p == NULL && q == NULL)
{
flg = true;
}
}
return flg;
}
*/
