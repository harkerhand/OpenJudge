#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long double money(long x, long y, long S, long S_A, long S_B, long need, long double cost)
{

    long double whole;
    long last;
    long double result = 0;
    if (y % 2 == 0)
    {
        long A = x + y / 2;
        whole = need / A;
        result += whole * (cost - 0.0000006 * (S - S_A * x - S_B * y));
        last = need - whole * (x + y / 2);

        if (last != 0)
            result += cost;
        long lastS = S;
        while (last > 0)
        {
            if (x > 0)
            {
                lastS -= S_A;
                x--;
                last--;
            }
            else if (y >= 2)
            {
                lastS -= S_B * 2;
                y -= 2;
                last--;
            }
        }
        result -= lastS * 0.0000006;
    }
    else
    {
        whole = need / (x + x + y) * 2;
        result += whole * (cost - 0.0000006 * (S - S_A * x - S_B * y));
        last = need - whole / 2 * (x + x + y);
        if (last <= x + y / 2)
        {
            if (last != 0)
                result += cost;
            long lastS = S;
            while (last > 0)
            {
                if (x > 0)
                {
                    lastS -= S_A;
                    x--;
                    last--;
                }
                else if (y >= 2)
                {
                    lastS -= S_B * 2;
                    y -= 2;
                    last--;
                }
            }
            result -= lastS * 0.0000006;
        }
        else
        {
            long lastS = S;
            result += cost + cost - 0.0000006 * (S - S_A * x - S_B * y); // 两块板子 第一块全切
            last -= x + y / 2 + 1;
            y--;
            lastS -= S_B;
            // 现在又变成偶数个小
            while (last > 0)
            {
                if (x > 0)
                {
                    lastS -= S_A;
                    x--;
                    last--;
                }
                else if (y >= 2)
                {
                    lastS -= S_B * 2;
                    y -= 2;
                    last--;
                }
            }
            result -= lastS * 0.0000006;
        }
    }

    return result;
}

tuple<int, int, int> last(long x, long y, long S, long S_A, long S_B, long need, long double cost)
{
    long double whole;
    long last;
    long lastX = 0, lastY = 0;
    if (y % 2 == 0)
    {
        long A = x + y / 2;
        whole = need / A;
        last = need - whole * (x + y / 2);
        while (last > 0)
        {
            if (x > 0)
            {
                lastX++;
                x--;
                last--;
            }
            else if (y >= 2)
            {
                lastY += 2;
                y -= 2;
                last--;
            }
        }
    }
    else
    {
        whole = need / (x + x + y) * 2;
        last = need - whole / 2 * (x + x + y);
        if (last <= x + y / 2)
        {
            while (last > 0)
            {
                if (x > 0)
                {
                    lastX++;
                    x--;
                    last--;
                }
                else if (y >= 2)
                {
                    lastY += 2;
                    y -= 2;
                    last--;
                }
            }
        }
        else
        {
            last -= x + y / 2 + 1;
            y--;
            lastY += 1;
            // 现在又变成偶数个小
            while (last > 0)
            {
                if (x > 0)
                {
                    lastX++;
                    x--;
                    last--;
                }
                else if (y >= 2)
                {
                    lastY += 2;
                    y -= 2;
                    last--;
                }
            }
        }
    }
    return make_tuple(lastX, lastY, whole);
}

int main()
{
    array<tuple<long, long, long, long, long>, 13> abcd_need;
    abcd_need[0] = make_tuple(1710, 670, 880, 670, 40);
    abcd_need[1] = make_tuple(1590, 530, 820, 530, 67);
    abcd_need[2] = make_tuple(1330, 480, 690, 480, 86);
    abcd_need[3] = make_tuple(1130, 420, 590, 420, 89);
    abcd_need[4] = make_tuple(970, 360, 510, 360, 108);
    abcd_need[5] = make_tuple(850, 330, 450, 330, 111);
    abcd_need[6] = make_tuple(770, 290, 410, 290, 123);
    abcd_need[7] = make_tuple(690, 250, 370, 250, 129);
    abcd_need[8] = make_tuple(650, 240, 350, 240, 140);
    abcd_need[9] = make_tuple(590, 210, 320, 210, 110);
    abcd_need[10] = make_tuple(510, 190, 280, 190, 96);
    abcd_need[11] = make_tuple(470, 170, 260, 170, 84);
    abcd_need[12] = make_tuple(470, 125, 260, 125, 64);

    array<tuple<long, long double>, 4> S_cost;
    S_cost[0] = make_tuple(9000000, 20.7);
    S_cost[1] = make_tuple(6250000, 13.8);
    S_cost[2] = make_tuple(4000000, 8.4);
    S_cost[3] = make_tuple(2250000, 4.5);

    map<pair<int, int>, double> moneys;
    map<int, pair<int, int>> ids;

    map<pair<int, int>, pair<int, int>> box_plate_to_xy;
    ifstream id_to_id("id_to_id.txt");
    int box_id, plate_id;
    int id, x, y;

    while (id_to_id >> id >> box_id >> plate_id)
    {
        ids[id] = make_pair(box_id, plate_id);
        moneys[make_pair(box_id, plate_id)] = 99999999;
    }

    ifstream input("input.txt");
    while (input >> id >> x >> y)
    {

        if (y == -1)
        {
            continue;
        }
        box_id = ids[id].first;
        plate_id = ids[id].second;
        double money_temp = money(x, y, get<0>(S_cost[plate_id - 1]), get<0>(abcd_need[box_id - 1]) * get<1>(abcd_need[box_id - 1]), get<2>(abcd_need[box_id - 1]) * get<3>(abcd_need[box_id - 1]), get<4>(abcd_need[box_id - 1]), get<1>(S_cost[plate_id - 1]));
        moneys[make_pair(box_id, plate_id)] = min(moneys[make_pair(box_id, plate_id)], money_temp);
        if (money_temp <= moneys[make_pair(box_id, plate_id)])
        {
            box_plate_to_xy[make_pair(box_id, plate_id)] = make_pair(x, y);
        }
    }
    array<double, 4> costs = {0};
    ofstream output("moneys.txt", ios::app);

    for (auto &i : moneys)
    {
        costs[i.first.second - 1] += i.second;
        int box_id = i.first.first;
        int plate_id = i.first.second;
        auto temp = last(box_plate_to_xy[make_pair(box_id, plate_id)].first, box_plate_to_xy[make_pair(box_id, plate_id)].second, get<0>(S_cost[plate_id - 1]), get<0>(abcd_need[box_id - 1]) * get<1>(abcd_need[box_id - 1]), get<2>(abcd_need[box_id - 1]) * get<3>(abcd_need[box_id - 1]), get<4>(abcd_need[box_id - 1]), get<1>(S_cost[plate_id - 1]));

        output << "box:" << box_id << " plate:" << plate_id << " cost:" << i.second << " x:" << box_plate_to_xy[make_pair(box_id, plate_id)].first << " y:" << box_plate_to_xy[make_pair(box_id, plate_id)].second << " x" << get<2>(temp) << " last: x:" << get<0>(temp) << " y:" << get<1>(temp) << endl;
    }
    output << "costs: ";
    for (auto &i : costs)
    {
        output << i << " ";
    }
    output << endl;
    output.close();
}