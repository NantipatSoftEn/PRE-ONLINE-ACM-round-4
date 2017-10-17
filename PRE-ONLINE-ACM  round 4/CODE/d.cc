#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
        double x1,y1,z1;
        cin >> x1 >> y1 >> z1;
        int t;
        cin >> t;

        double a,b,c,d,e,f;
        if(t==1) {
                cin >> a >> b >> c;
                printf("%lf %lf %lf",x1+2*(a-x1),y1+2*(b-y1),z1+2*(c-z1));
        }
        if(t==2) {
                cin >> a >> b >> c >> d >> e >> f;
                // project point P to line AB
                // result = A + dot(AP,AB)/dot(AB,AB) * AB
                // A = (a,b,c)
                // B = (d,e,f)
                // P = (x,y,z)

                double APx = x1-a, APy = y1-b, APz = z1-c;
                double ABx = d-a, ABy = e-b, ABz = f-c;
                double ratio = ((APx*ABx)+(APy*ABy)+(APz*ABz))/((ABx*ABx)+(ABy*ABy)+(ABz*ABz));
                double Rx = a + ratio * ABx;
                double Ry = b + ratio * ABy;
                double Rz = c + ratio * ABz;

                printf("%lf %lf %lf",x1+2*(Rx-x1),y1+2*(Ry-y1),z1+2*(Rz-z1));

        }
        if(t==3) {
                cin >> a >> b >> c >> d;
                // normal ax+by+cz
                // t = (x-x1)/a = (y-y1)/b = (z-z1)/c
                // x = at+x1, y = bt+y1, z = ct+z1
                // a(at+x1) + b(bt+y1) + c(ct+z1) = d
                // aat+ax1 + bbt+by1 + cct+cz1 = d
                // t = (d-ax1-by1-cz1)/(aa+bb+cc)

                double t = (d-a*x1-b*y1-c*z1)/(a*a+b*b+c*c);
                double Rx = a*t+x1, Ry = b*t+y1, Rz = c*t+z1;

                printf("%lf %lf %lf",x1+2*(Rx-x1),y1+2*(Ry-y1),z1+2*(Rz-z1));
        }
}
