#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Entry
{
public:
    std::string name;
    std::string phone;
    Entry(const std::string &nm = "", const std::string &ph = "")
    {
        name = nm;
        phone = ph;
    }
};

std::ostream &operator<<(std::ostream &os, const Entry &e)
{
    os << e.name << ": " << e.phone;
    return os;
}

int main(void)
{
    vector<Entry> e;

    e.push_back(Entry("Kwansei Gakuin University (PR)", "0798-54-6017"));
    e.push_back(Entry("Kwansei Gakuin University (KSC)", "079-565-7600"));
    e.push_back(Entry("Kobe University", "078-881-1212"));
    e.push_back(Entry("Sanda Woodytown SATY", "079-564-8800"));
    e.push_back(Entry("Sanda Hotel", "079-564-1101"));

    for (int i = 0; i < e.size(); i++)
    {
        if (e[i].phone.substr(0, 4) == "079-" || e[i].phone.substr(0, 4) == "078-")
        {
            e[i].phone = e[i].phone.substr(4);
        }
        else if (e[i].phone.substr(0, 5) == "0798-")
        {
            e[i].phone = e[i].phone.substr(5);
        }
    }
    
    std::cout << "検索用文字列を入力して下さい: ";
    std::string s;
    std::cin >> s;
    // ------------------------------------------------
    // name に s を含むデータを全て表示せよ
    // -------------------------------------------
    for (int i = 0; i < e.size(); i++)
    {
        if (e[i].name.find(s) != std::string::npos)
        {
            std::cout << e[i] << std::endl;
        }
    }
    return 0;
}