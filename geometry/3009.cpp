#include <iostream>

using namespace std;

int main(int argc, char **argv){
    
    int a,b;
    int c,d;
    int e,f;
    int g,h;
    cin >> a >> b >> c >> d >> e >> f;
    if(a != c && a != e)
        g = a;
    else if(a == c)
        g = e;
    else
        g = c;

    if(b != d && b!= f)
        h = b;
    else if(b==d)
        h= f;
    else   
        h= d;

    cout << g << " " << h;
    return 0;

}