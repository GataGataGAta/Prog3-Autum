#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

typedef std::list<int> int_list;
typedef int_list::iterator int_list_iter;

int main(void)
{
    // 謨ｴ謨ｰ繝ｪ繧ｹ繝� li = (3 5 2 3 2 3) 繧剃ｽ懊ｋ
    std::vector<int> li;
    li.push_back(3);
    li.push_back(5);
    li.push_back(2);
    li.push_back(3);
    li.push_back(2);
    li.push_back(3);

    std::cout << ">";
    int i;
    std::cin >> i;

    // 繝ｪ繧ｹ繝井ｸｭ縺ｮ i 繧呈､懃ｴ｢
    std::vector<int>::iterator p = find(li.begin(), li.end(), i);
    if (p == li.end())
    {
        // 隕九▽縺九ｉ縺ｪ縺��ｴ蜷�
        std::cout << "not found\n";
    }
    else
    {
        // 隕九▽縺九▲縺溷�ｴ蜷�
        std::cout << *p << " found\n";

        // 隕九▽縺九▲縺溘→縺薙ｍ縺ｮ逶ｴ蠕後°繧画峩縺ｫ讀懃ｴ｢繧堤ｶ咏ｶ�
        p = find(++p, li.end(), i);
        if (p == li.end())
        {
            std::cout << "not found\n";
        }
        else
        {
            std::cout << *p << " found again\n";
        }
    }

    return 0;
}