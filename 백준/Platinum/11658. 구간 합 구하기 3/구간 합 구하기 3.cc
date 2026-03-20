#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
int vec[1030][1030];
ll seg[5000][5000]; 

ll init_x(int yloc, int ys, int ye, int xloc, int xs, int xe) {
    if (xs == xe) {
        if (ys == ye) return seg[yloc][xloc] = vec[ys][xs];
        return seg[yloc][xloc] = seg[yloc * 2][xloc] + seg[yloc * 2 + 1][xloc];
    }
    int mid = (xs + xe) / 2;
    return seg[yloc][xloc] = init_x(yloc, ys, ye, xloc * 2, xs, mid) + init_x(yloc, ys, ye, xloc * 2 + 1, mid + 1, xe);
}

void init_y(int yloc, int ys, int ye) {
    if (ys != ye) {
        int mid = (ys + ye) / 2;
        init_y(yloc * 2, ys, mid);
        init_y(yloc * 2 + 1, mid + 1, ye);
    }
    init_x(yloc, ys, ye, 1, 1, n);
}

void update_x(int yloc, int ys, int ye, int xloc, int xs, int xe, int x_idx, int val) {
    if (xs == xe) {
        if (ys == ye) seg[yloc][xloc] = val;
        else seg[yloc][xloc] = seg[yloc * 2][xloc] + seg[yloc * 2 + 1][xloc];
        return;
    }
    int mid = (xs + xe) / 2;
    if (x_idx <= mid) update_x(yloc, ys, ye, xloc * 2, xs, mid, x_idx, val);
    else update_x(yloc, ys, ye, xloc * 2 + 1, mid + 1, xe, x_idx, val);
    
    seg[yloc][xloc] = seg[yloc][xloc * 2] + seg[yloc][xloc * 2 + 1];
}

void update_y(int yloc, int ys, int ye, int y_idx, int x_idx, int val) {
    if (ys != ye) {
        int mid = (ys + ye) / 2;
        if (y_idx <= mid) update_y(yloc * 2, ys, mid, y_idx, x_idx, val);
        else update_y(yloc * 2 + 1, mid + 1, ye, y_idx, x_idx, val);
    }
    update_x(yloc, ys, ye, 1, 1, n, x_idx, val);
}

ll find_x(int yloc, int xloc, int xs, int xe, int x1, int x2) {
    if (x1 > xe || x2 < xs) return 0;
    if (x1 <= xs && xe <= x2) return seg[yloc][xloc];
    int mid = (xs + xe) / 2;
    return find_x(yloc, xloc * 2, xs, mid, x1, x2) +
           find_x(yloc, xloc * 2 + 1, mid + 1, xe, x1, x2);
}

ll find_y(int yloc, int ys, int ye, int y1, int y2, int x1, int x2) {
    if (y1 > ye || y2 < ys) return 0;
    if (y1 <= ys && ye <= y2) return find_x(yloc, 1, 1, n, x1, x2);
    int mid = (ys + ye) / 2;
    return find_y(yloc * 2, ys, mid, y1, y2, x1, x2) +
           find_y(yloc * 2 + 1, mid + 1, ye, y1, y2, x1, x2);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> vec[i][j];

    init_y(1, 1, n);
    int a, b, c, d, e;
    for(int i=0; i< m ; i++){
        cin >> a;
        if(a==1){
            cin >> b >> c>>d>>e;
            ll res = find_y(1,1,n,b,d,c,e);
            cout << res<<'\n';
        }else{
            cin >> b >> c>>d;
            update_y(1, 1, n, b, c, d);
        }
    }

    return 0;
}