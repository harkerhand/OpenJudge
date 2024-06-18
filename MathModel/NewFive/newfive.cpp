#include <iostream>
#include <map>
#include <cmath>
#include <array>
#include <tuple>
#include <fstream>

using namespace std;

long id = 0;
int plate_id = 0;
int box_id = 0;

void findMaxXY(long a, long b, long c, long d, long S, long need, long double cost)
{
    long m = sqrt(S) / b;

    map<long, long> maxValues;

    for (long x = 0; x <= long(sqrt(S) / a); x++)
    {
        if (x * m > need)
            break;
        long y = (sqrt(S) - a * x) / c;
        if (a * x + c * y <= sqrt(S))
        {
            maxValues[x * m] = min((need - m * x) * 2, max(maxValues[x * m], y * m));
        }
    }

    ofstream output("hardCut.txt", ios::app);
    ofstream output1("output1.txt", ios::app);
    for (const auto &pair : maxValues)
    {
        output1 << id + 1 << "(" << pair.first << ", " << pair.second << ")" << endl;
        output << ++id << endl;
        output << plate_id << " " << box_id << endl;
        output << sqrt(S) << endl;
        output << a << " " << b << " " << c << " " << d << endl;
        output << pair.first << " " << pair.second << endl;
    }
    output.close();
    output1.close();
}

int main()
{
    ofstream output("hardCut.txt");
    output << "id\nplate_id box_id\nmax\nsize\nnum\n";
    output.close();
    ofstream output1("output1.txt");
    output1 << "";
    output1.close();
    ofstream output2("output2.txt");
    output2 << "";
    output2.close();

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

    for (auto &i : abcd_need)
    {

        box_id++;
        plate_id = 0;
        for (auto &j : S_cost)
        {
            plate_id++;
            long a, b, c, d, S, need;
            long double cost;
            a = get<0>(i);
            b = get<1>(i);
            c = get<2>(i);
            d = get<3>(i);
            S = get<0>(j);
            need = get<4>(i);
            cost = get<1>(j);
            ofstream output1("output1.txt", ios::app);

            output1 << a << "x" << b << "," << c << "x" << d << "," << "S = " << S << ", cost = " << cost << endl;
            ofstream output("output.txt", ios::app);
            output.close();
            findMaxXY(a, b, c, d, S, need, cost);
            output1 << "\n\n";
            output1.close();
        }
    }
    return 0;
}
