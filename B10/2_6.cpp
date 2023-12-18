#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

class by_name
{ // 名前の比較関数オブジェクト
public:
    bool operator()(const Entry &e1, const Entry &e2) const
    {
        return e1.name < e2.name;
    }
};

class by_phone
{ // 番号の比較関数オブジェクト
public:
    bool operator()(const Entry &e1, const Entry &e2) const
    {
        return e1.phone < e2.phone;
    }
};

int main(void)
{
    vector<Entry> e;

    e.push_back(Entry("Kwansei Gakuin University (PR)", "0798-54-6017"));
    e.push_back(Entry("Kwansei Gakuin University (KSC)", "079-565-7600"));
    e.push_back(Entry("Kobe University", "078-881-1212"));
    e.push_back(Entry("Sanda Woodytown SATY", "079-564-8800"));
    e.push_back(Entry("Sanda Hotel", "079-564-1101"));

    // for (int i = 0; i < e.size(); i++)
    // {
    //     if (e[i].phone.substr(0, 4) == "079-" || e[i].phone.substr(0, 4) == "078-")
    //     {
    //         e[i].phone = e[i].phone.substr(4);
    //     }
    //     else if (e[i].phone.substr(0, 5) == "0798-")
    //     {
    //         e[i].phone = e[i].phone.substr(5);
    //     }
    // }

    std::cout<< "名前順に並べ替え" << std::endl;
    sort(e.begin(), e.end(), by_name());
    for(int j = 0; j < e.size(); j++)
    {
        std::cout << e[j] << std::endl;
    }// 名前でソート
    std::cout<< "番号順に並べ替え" << std::endl;
    sort(e.begin(), e.end(), by_phone()); 
    for(int j = 0; j < e.size(); j++)
    {
        std::cout << e[j] << std::endl;
    }// 番号でソート

    return 0;                             
}
