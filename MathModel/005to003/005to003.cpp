#include <bits/stdc++.h>
using namespace std;

array<tuple<int, int, int>, 13> abcd_need;
array<tuple<int, int, int>, 13> backup;
/*

________________________a_____________________________b________
|                                             |               |
|                                             |               |
|                                             |               |c
|                                             |               |
|_____________________________________________|_______________|
|                                             |               |
|                                             |               |
|                                             |               |
|                                             |               |
|                                             |               |
|                                             |               |
|                                             |               |
|                                             |               |
|  m * length                                 |               |
|                                             |               |d
|                                             |               |
|                                             |               |
|                                             |               |
|                                             |               |
|                                             |               |
|                                             |               |
|                                             |               |
|                  n * width                  |               |
|_____________________________________________|_______________|


 */
void put_in(int length, int width)
{

    for (int i = 0; i < 13; i++)
    {
        if (get<2>(abcd_need[i]) == 0)
        {
            continue;
        }
        if (get<0>(abcd_need[i]) >= length || get<1>(abcd_need[i]) >= width)
        {
            continue;
        }
        else
        {
            int length_box = get<0>(abcd_need[i]);
            int width_box = get<1>(abcd_need[i]);
            int m = length / length_box;
            int n = width / width_box;
            if (m * n == 0)
            {
                continue;
            }
            if (m * n <= get<2>(abcd_need[i]))
                get<2>(abcd_need[i]) -= m * n;
            else
            {
                if (get<2>(abcd_need[i]) % n == 0)
                {
                    m = get<2>(abcd_need[i]) / n;
                    get<2>(abcd_need[i]) = 0;
                }
                else
                {
                    m = get<2>(abcd_need[i]) / n + 1;
                    int k = n * width_box - get<2>(abcd_need[i]) % n;
                    get<2>(abcd_need[i]) = 0;
                    put_in(max(k, length_box), min(k, length_box));
                }
            }
            int d = m * length_box;
            int a = n * width_box;
            int b = width - a;
            int c = length - d;

            put_in(max(c, a), min(c, a));
            put_in(max(d, b), min(d, b));
            put_in(max(c, b), min(c, b));
            return;
        }
    }
    return;
}

int main()
{
    ofstream output("005to003.txt");

    abcd_need[0] = make_tuple(1710, 670, 40);
    abcd_need[1] = make_tuple(1590, 530, 67);
    abcd_need[2] = make_tuple(1330, 480, 86);
    abcd_need[3] = make_tuple(1130, 420, 89);
    abcd_need[4] = make_tuple(970, 360, 108);
    abcd_need[5] = make_tuple(850, 330, 111);
    abcd_need[6] = make_tuple(770, 290, 123);
    abcd_need[7] = make_tuple(690, 250, 129);
    abcd_need[8] = make_tuple(650, 240, 140);
    abcd_need[9] = make_tuple(590, 210, 110);
    abcd_need[10] = make_tuple(510, 190, 96);
    abcd_need[11] = make_tuple(470, 170, 84);
    abcd_need[12] = make_tuple(470, 125, 64);

    // abcd_need[0] = make_tuple(880, 670, 80);
    // abcd_need[1] = make_tuple(820, 530, 134);
    // abcd_need[2] = make_tuple(690, 480, 172);
    // abcd_need[3] = make_tuple(590, 420, 178);
    // abcd_need[4] = make_tuple(510, 360, 216);
    // abcd_need[5] = make_tuple(450, 330, 222);
    // abcd_need[6] = make_tuple(410, 290, 246);
    // abcd_need[7] = make_tuple(370, 250, 258);
    // abcd_need[8] = make_tuple(350, 240, 280);
    // abcd_need[9] = make_tuple(320, 210, 220);
    // abcd_need[10] = make_tuple(280, 190, 192);
    // abcd_need[11] = make_tuple(260, 170, 168);
    // abcd_need[12] = make_tuple(260, 125, 128);

    long sum_box_S = 0;
    for (auto &i : abcd_need)
    {
        sum_box_S += get<2>(i) * get<0>(i) * get<1>(i);
    }

    backup = abcd_need;

    array<tuple<long, long double>, 4> S_cost;
    S_cost[0] = make_tuple(9000000, 20.7);
    S_cost[1] = make_tuple(6250000, 13.8);
    S_cost[2] = make_tuple(4000000, 8.4);
    S_cost[3] = make_tuple(2250000, 4.5);

    double min_Money = 99999999999;
    int bestNumber = 0;
    array<int, 13> bestArray;

    // ifstream input("output.txt");
    ifstream input("output_without3.txt");
    for (int number = 0; number < 560; number++)
    {
        array<int, 13> chose_which_plate = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

        for (auto &i : chose_which_plate)
        {
            input >> i;
        }

        int index = -1;
        string ans = "";
        abcd_need = backup;
        long sum_S = 0;
        double sum_Money = 0;
        while (1)
        {
            int count = 0;
            for (int i = 0; i < 13; i++)
            {
                auto j = abcd_need[i];
                if (get<2>(j) == 0)
                {
                    count++;
                }

                ans += to_string(get<2>(j)) + " ";
            }
            for (int i = 0; i < 13; i++)
            {
                auto j = abcd_need[i];
                if (get<2>(j) != 0)
                {
                    index = i;
                    break;
                }
            }
            ans += '\n';
            if (count == 13)
                break;
            put_in(sqrt(get<0>(S_cost[chose_which_plate[index]])), sqrt(get<0>(S_cost[chose_which_plate[index]])));
            sum_S += get<0>(S_cost[chose_which_plate[index]]);
            sum_Money += get<1>(S_cost[chose_which_plate[index]]);
        }

        stringstream ss(ans);
        array<int, 13> last;
        for (int i = 0; i < 13; i++)
        {
            ss >> last[i];
        }
        int count = 0;
        if (number == 104)
        {
            while (count != 13)
            {
                count = 0;
                array<int, 13> now;
                for (int i = 0; i < 13; i++)
                {
                    ss >> now[i];
                    output << last[i] - now[i] << " ";
                    last[i] = now[i];
                    if (now[i] == 0)
                    {
                        count++;
                    }
                }
                output << endl;
            }
        }

        cout << sum_Money << " " << sum_Money - (sum_S - sum_box_S) * 0.0000006 << endl;
        if (number == 104)
        {
            output << sum_Money << " " << sum_Money - (sum_S - sum_box_S) * 0.0000006 << endl;
        }
        min_Money = min(min_Money, sum_Money - (sum_S - sum_box_S) * 0.0000006);
        if (min_Money >= sum_Money - (sum_S - sum_box_S) * 0.0000006)
        {
            bestNumber = number;
            bestArray = chose_which_plate;
        }
    }
    input.close();
    cout << min_Money << " " << bestNumber << endl;
    for (auto &i : bestArray)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}