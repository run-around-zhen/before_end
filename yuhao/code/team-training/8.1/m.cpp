#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define lol long long

int N, R;

struct point
{
    int x;
    int y;

    point(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};

bool inner(point A)
{
    return (A.x*A.x + A.y*A.y <= R*R);
}

vector <point> convex_hull; 

int area(point A, point B, point C)
{
    int p = B.x - A.x;
    int q = B.y - A.y;

    int r = C.x - A.x;
    int l = C.y - A.y;

    return (q*r - p*l);
}

void Init()
{
    cin >> N >> R;
}

void Make_Convex_Hull()
{
    convex_hull.push_back(point(0, R));
    
    while(true)
    {
        point cur = convex_hull[convex_hull.size() - 1];
        --cur.y;
        
        while(!inner(point(cur.x + 1, cur.y)))
            --cur.y;

        while(inner(point(cur.x + 1, cur.y)))
            ++cur.x;

        if (cur.y == 0)
            break;

        //cout << cur.x << " | " << cur.y << "\n";
            
        if (area(convex_hull[convex_hull.size() - 1], cur, point(R, 0)) >= 0)
            convex_hull.push_back(cur);
        while(convex_hull.size() >= 3 && area(convex_hull[convex_hull.size() - 3], convex_hull[convex_hull.size() - 2], convex_hull[convex_hull.size() - 1]) <= 0)
        {
            convex_hull[convex_hull.size() - 2] = convex_hull[convex_hull.size() - 1];
            convex_hull.pop_back();
        }
            
    }

    int s = convex_hull.size();

    for(int i = 0; i<s; ++i)
        convex_hull.push_back(point(convex_hull[i].y, -convex_hull[i].x));

    for(int i = 0; i<s; ++i)
        convex_hull.push_back(point(-convex_hull[i].x, -convex_hull[i].y));

    for(int i = 0; i<s; ++i)
        convex_hull.push_back(point(-convex_hull[i].y, convex_hull[i].x));

    //for(int i = 0; i<convex_hull.size(); ++i)
    //  cout << convex_hull[i].x << " " << convex_hull[i].y << "\n";
}

int maxx = 0;
int cur = 0;

vector<point> ans;
vector<point> best;

 void Case(int px, int sx, int py, int sy, int iteration, int last)
{
    if (iteration < N)
    {
        for(int i = last; i<convex_hull.size(); ++i)
        {
            int curx = iteration*convex_hull[i].x*convex_hull[i].x - 2*px*convex_hull[i].x + sx;
            int cury = iteration*convex_hull[i].y*convex_hull[i].y - 2*py*convex_hull[i].y + sy;

                        cur += curx;
                        cur += cury;

            int dpx = convex_hull[i].x;
            int dpy = convex_hull[i].y;

            int dsx = convex_hull[i].x*convex_hull[i].x;
            int dsy = convex_hull[i].y*convex_hull[i].y;

            ans.push_back(convex_hull[i]);

            Case(px + dpx, sx + dsx, py + dpy, sy + dsy, iteration + 1, i);

            cur -= curx;
            cur -= cury;

            ans.pop_back();
        }
    }
    else
    {
        if (maxx < cur)
        {
            maxx = cur;
            best = ans;
        }
    }
}

int main(){

    for(int i = 1; i <= 8; i ++){
    	for(int j = 1; j <= 30; j ++){
    		N = i;
    		R = j;
    		convex_hull.clear();
    		maxx = 0;
			 cur = 0;
			 best.clear();
			 ans.clear();
    		Make_Convex_Hull();
    		
   			Case(0, 0, 0, 0, 0, 0);
   			 cout << maxx << ",";
    	}
    }
    

   
    
  /*  for(int i = 0; i<best.size(); ++i)
        cout << best[i].x << " " << best[i].y << "\n";*/

    return 0;

}