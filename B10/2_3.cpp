#include <iostream>
#include <string>
#include <list>

// 学生 1 人分の記録
class Record
{
public:
    int id;           // 学籍番号
    std::string name; // 名前
    int score;        // 点数
    Record() {}
    Record(int i, const std::string &nm, int s)
    {
        id = i;
        name = nm;
        score = s;
    }
};

std::ostream &operator<<(std::ostream &os, const Record &r)
{
    os << "[" << r.id << "] " << r.name << " : " << r.score;
    return os;
}

// 成績簿 (全学生の記録)
class Seiseki
{
public:
    std::list<Record> data;
    void insert(int, const std::string &, int);
    void lookup(int) const;
    void erase_worst();
};

std::ostream &operator<<(std::ostream &os, const Seiseki &s)
{
    os << "*** 成績簿 ***\n";
    for (std::list<Record>::const_iterator p = s.data.begin();
         p != s.data.end(); p++)
    {
        os << *p << "\n";
    }
    return os;
}

void Seiseki::insert(int id, const std::string &nm, int s)
{
    // -----------------------------
    //   この部分を完成させよ
    // -----------------------------
    data.push_back(Record(id, nm, s));
}

void Seiseki::lookup(int id) const
{
    // -----------------------------
    //   この部分を完成させよ
    // -----------------------------
    std::list<Record>::const_iterator it = data.begin();
    while (it != data.end())
    {
        if (it->id == id)
        {
            std::cout << *it << std::endl;
            return;
        }
        ++it;
    }
    std::cout << "not found" << std::endl;
}

void Seiseki::erase_worst()
{
    // -----------------------------
    //   この部分を完成させよ
    // -----------------------------
    std::list<Record>::iterator worst = data.begin();
    std::list<Record>::iterator it;
    for (it = data.begin(); it != data.end(); ++it)
    {
        if (it->score < worst->score)
        {
            worst = it;
        }
    }
    data.erase(worst);
}

int main(void)
{
    Seiseki s;

    // 成績の登録
    s.insert(7001, "aaaa", 89);
    s.insert(7123, "bbbb", 70);
    s.insert(7013, "cccc", 55);
    s.insert(7200, "dddd", 99);
    s.insert(7087, "eeee", 83);

    // 全学生の成績の表示
    std::cout << s;

    // 入力した id の記録の表示 (0 を入力するまで繰り返し)
    int id;
    std::cout << "> ";
    std::cin >> id;
    while (id != 0)
    {
        s.lookup(id);
        std::cout << "> ";
        std::cin >> id;
    }

    // 点数が最も悪い学生を消去
    s.erase_worst();

    // 全学生の成績の表示
    std::cout << s;

    return 0;
}