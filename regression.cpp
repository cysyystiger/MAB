#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<fstream>
using namespace std;
int main() {
    ifstream myfile;
    myfile.open("data.txt");
    int x[50];
    for(int i=0;i<50;i++) {
        x[i]=100+9*i;
    }
    double y[50];
    for(int i=0;i<50;i++) {
        myfile>>y[i];
    }
    double b1=5000;
    double b2=5000;
    double c1,c2;
    for(int i=300;i<701;i++) {
        double err1=0;
        double err2=0;
        for(int j=0;j<36;j++) {
            err1=err1+pow(((i+500)*pow(x[j],0.5)-y[j]),2);
            err2=err2+pow((i*pow(x[j]*log(x[j]),0.5)-y[j]),2);
        }
        err1=err1/50;
        err2=err2/50;
        err1=pow(err1,0.5);
        err2=pow(err2,0.5);
        if(b1>err1) {
            b1=err1;
            c1=i+500;
        }
        if(b2>err2) {
            b2=err2;
            c2=i;
        }
    }/** 根號x做回歸 977pow(x,0.5) error=479.9
        根號xlnx做回歸 403pow(xlnx,0.5) error=822.836 **/
    cout<<c1<<" "<<b1<<endl<<c2<<" "<<b2;


}
