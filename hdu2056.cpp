#include <stdio.h>
void swp(double& a,double& b){
    double temp=a;
    a=b;
    b=temp;
}
int main(){
    double x1=0.0,x2=0.0,x3=0.0,x4=0.0,y1=0.0,y2=0.0,y3=0.0,y4=0.0;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF){
        //printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f",x1,y1,x2,y2,x3,y3,x4,y4);
        double r=0.00;
        if(x1>x2) swp(x1,x2);
        if(y1>y2) swp(y1,y2);
        if(x3>x4) swp(x3,x4);
        if(y3>y4) swp(y3,y4);
        //printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f",x1,y1,x2,y2,x3,y3,x4,y4);
        if(x3>x2 || y3>y2) printf("%.2f\n",r);
        else printf("%.2f\n",(x2-x3)*(y2-y3));
    }
    return 0;
}