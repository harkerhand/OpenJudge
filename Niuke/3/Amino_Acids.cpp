#include <bits/stdc++.h>
using namespace std;

vector<string> chain = {
    " H H O ",
    " | | ||",
    "-N-C-C-",
    "   |   "};
vector<string> lleft = {
    " ",
    " ",
    "H"};
vector<string> rright = {
    "   ",
    "   ",
    "O-H"};

vector<string> Ala = {
    " H-C-H  ",
    "   |    ",
    "   H    ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "};

vector<string> Asp = {
    " H-C-H  ",
    "   |    ",
    " O=C-O-H",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "};

vector<string> Asn = {
    " H-C-H  ",
    "   |    ",
    " O=C-N-H",
    "     |  ",
    "     H  ",
    "        ",
    "        ",
    "        ",
    "        "};

vector<string> Cys = {
    " H-C-S-H",
    "   |    ",
    "   H    ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "};

vector<string> Gly = {
    "   H    ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "};

vector<string> Ser = {
    " H-C-O-H",
    "   |    ",
    "   H    ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "};

vector<string> Met = {
    " H-C-H  ",
    "   |    ",
    " H-C-H  ",
    "   |    ",
    "   S    ",
    "   |    ",
    " H-C-H  ",
    "   |    ",
    "   H    "};

vector<string> Thr = {
    " H-C-O-H",
    "   |    ",
    " H-C-H  ",
    "   |    ",
    "   H    ",
    "        ",
    "        ",
    "        ",
    "        "};

vector<string> Gln = {
    " H-C-H  ",
    "   |    ",
    " H-C-H  ",
    "   |    ",
    " O=C-N-H",
    "     |  ",
    "     H  ",
    "        ",
    "        "};

vector<string> Glu = {
    " H-C-H  ",
    "   |    ",
    " O=C-O-H",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "};

vector<string> PeptideBond = {
    " ",
    " ",
    "-"};

map<string, int>
    mp = {{"Ala", 89}, {"Asn", 132}, {"Asp", 133}, {"Cys", 121}, {"Gln", 146}, {"Glu", 147}, {"Gly", 75}, {"Met", 149}, {"Ser", 105}, {"Thr", 119}};
map<int, vector<string>> reMp = {
    {89, Ala}, {132, Asn}, {133, Asp}, {121, Cys}, {146, Gln}, {147, Glu}, {75, Gly}, {149, Met}, {105, Ser}, {119, Thr}};
bool isAllSpaces(const string &str)
{
    // 遍历字符串的每个字符
    for (char c : str)
    {
        // 如果有一个字符不是空格，则返回 false
        if (c != ' ')
        {
            return false;
        }
    }
    // 如果所有字符都是空格，返回 true
    return true;
}
vector<vector<int>> ans;

// 回溯函数，找出和不超过N的组合
void findCombinations(vector<int> &vec, int N, int index, int currentSum, vector<int> &currentCombination)
{
    // 如果当前和大于N，直接返回
    if (currentSum > N)
    {
        return;
    }

    // 如果当前选定的数字数量已经达到n，且和小于等于N，输出组合
    if (index == vec.size())
    {
        if (currentSum <= N)
        {
            /* // 输出当前组合
            for (int num : currentCombination)
            {
                cout << num << " ";
            }
            cout << endl; */
            ans.push_back(currentCombination);
        }
        return;
    }

    // 遍历每个数字，选择加入或不加入
    for (int i = 0; i < vec.size(); ++i)
    {
        currentCombination.push_back(vec[i]);                                         // 选择当前数字
        findCombinations(vec, N, index + 1, currentSum + vec[i], currentCombination); // 递归选择下一个数字
        currentCombination.pop_back();                                                // 回溯，撤销选择当前数字
    }
}
map<int, string> numToStr = {{89, "Ala"}, {132, "Asn"}, {133, "Asp"}, {121, "Cys"}, {146, "Gln"}, {147, "Glu"}, {75, "Gly"}, {149, "Met"}, {105, "Ser"}, {119, "Thr"}};

string rowToString(const vector<int> &row)
{
    stringstream ss;
    for (int num : row)
    {
        ss << numToStr.at(num);
    }
    return ss.str();
}

void print()
{
    cout << ans.size() << endl;
    vector<string> ansss;
    sort(ans.begin(), ans.end(), [&](const vector<int> &a, const vector<int> &b)
         { return rowToString(a) < rowToString(b); });
    for (auto &v : ans)
    {
        ansss.clear();
        ansss.resize(13);
        ansss[0] = lleft[0];
        ansss[1] = lleft[1];
        ansss[2] = lleft[2];
        ansss[3] = " ";
        ansss[4] = " ";
        ansss[5] = " ";
        ansss[6] = " ";
        ansss[7] = " ";
        ansss[8] = " ";
        ansss[9] = " ";
        ansss[10] = " ";
        ansss[11] = " ";
        ansss[12] = " ";
        for (auto &i : v)
        {
            ansss[0] += chain[0];
            ansss[1] += chain[1];
            ansss[2] += chain[2];
            ansss[3] += chain[3];
            ansss[4] += reMp[i][0];
            ansss[5] += reMp[i][1];
            ansss[6] += reMp[i][2];
            ansss[7] += reMp[i][3];
            ansss[8] += reMp[i][4];
            ansss[9] += reMp[i][5];
            ansss[10] += reMp[i][6];
            ansss[11] += reMp[i][7];
            ansss[12] += reMp[i][8];
            ansss[0] += PeptideBond[0];
            ansss[1] += PeptideBond[1];
            ansss[2] += PeptideBond[2];
            ansss[3] += " ";
        }
        ansss[2].pop_back();
        ansss[2] += rright[2];
        for (auto &i : ansss)
        {
            if (isAllSpaces(i))
                break;
            cout << i << endl;
        }
        cout << endl;
    }
}

void solve()
{
    int a, N;
    cin >> a >> N;
    N += (a - 1) * 18;
    vector<int> v;
    for (int i = 0; i < a; i++)
    {
        string s;
        cin >> s;
        v.push_back(mp[s]);
    }
    vector<int> currentCombination;
    findCombinations(v, N, 0, 0, currentCombination);
    print();
}

int main()
{
    solve();
}