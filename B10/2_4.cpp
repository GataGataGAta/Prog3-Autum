#include <iostream>
#include <string>
#include <list>
#include <map>

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
    std::map<std::string, std::string> e;

    e["Kwansei Gakuin University (PR)"] = "0798-54-6017";
    e["Kwansei Gakuin University (KSC)"] = "079-565-7600";
    e["Kobe University"] = "078-881-1212";
    e["Sanda Woodytown SATY"] = "079-564-8800";
    e["Sanda Hotel"] = "079-564-1101";
    std::map<std::string, std::string>::iterator p;
    for (p = e.begin(); p != e.end(); p++)
    {
        if (p->second.substr(0, 4) == "079-" || p->second.substr(0, 4) == "078-")
        {
            p->second = p->second.substr(4);
        }
        else if (p->second.substr(0, 5) == "0798-")
        {
            p->second = p->second.substr(5);
        }
    }

    std::cout << "検索用文字列を入力して下さい: ";
    std::string s;
    std::cin >> s;
    // ------------------------------------------------
    // name に s を含むデータを全て表示せよ
    // -------------------------------------------

    for (p = e.begin(); p != e.end(); p++)
    {
        if (p->first.find(s) != std::string::npos)
        {
            std::cout << p->first << ": " << p->second << std::endl;
        }
    }
    return 0;
}