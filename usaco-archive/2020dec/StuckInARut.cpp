#include <bits/stdc++.h>

using namespace std;

struct Cow
{
    int x, y, dist;
    bool east;
    Cow(int x, int y, char dir) : x(x), y(y)
    {
        dist = -1;
        east = dir == 'E';
    }

    void terminate(int px, int py)
    {
        dist = east ? px - x : py - y;
    }

    bool check(int px, int py)
    {
        return east ? (py == y && px >= x && (dist == -1 || px <= x + dist)) : (px == x && py >= y && (dist == -1 || py <= y + dist));
    }

    pair<int, int> cross(Cow b)
    {
        if (b.east != east)
        {
            int dx = east ? b.x : x;
            int dy = east ? y : b.y;

            if (check(dx, dy) && b.check(dx, dy))
            {
                return make_pair(dx, dy);
            }
        }
        return make_pair(-1, -1);
    }

    int getDis(int px, int py)
    {
        if (check(px, py))
        {
            return !east ? py - y : px - x;
        }

        return -1;
    }
};
struct Joint
{
    int x, y;
    Cow *a, *b;

    Joint(Cow *a, Cow *b, int x, int y) : a(a), b(b), x(x), y(y) {}

    bool valid()
    {
        int f = a->getDis(x, y);
        int s = b->getDis(x, y);
        return f >= 0 && s >= 0 && f != s;
    }

    int rearVal()
    {
        return min(a->getDis(x, y), b->getDis(x, y));
    }
};

int main()
{
    int n;
    cin >> n;

    vector<Cow> cows;

    for (int i = 0; i < n; i++)
    {
        char dir;
        int x, y;

        cin >> dir >> x >> y;
        cows.push_back(Cow(x, y, dir));
    }

    vector<Joint> cross;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair<int, int> curc = cows[i].cross(cows[j]);
            Joint x = Joint(&cows[i], &cows[j], curc.first, curc.second);

            if (curc.first > 0 && curc.second > 0 && x.valid())
            {
                cross.push_back(x);
            }
        }
    }

    sort(cross.begin(), cross.end(),
         [](Joint a, Joint b) {
             return a.rearVal() < b.rearVal();
         });

    // run through chronological order

    for (int i = 0; i < cross.size(); i++)
    {
        Joint curr = cross[i];
        if (curr.valid())
        {
            int cx = curr.x;
            int cy = curr.y;

            // whichever crosses second gets terminated
            if (curr.a->getDis(cx, cy) > curr.b->getDis(cx, cy))
            {
                curr.a->terminate(cx, cy);
            }
            else
            {
                curr.b->terminate(cx, cy);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cows[i].dist == -1)
        {
            cout << "Infinity" << endl;
        }
        else
        {
            cout << cows[i].dist << endl;
        }
    }
}