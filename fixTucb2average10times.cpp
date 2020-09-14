#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<fstream>
using namespace std;
void pickarms(int m,int T,vector<int> &deletedarms,double sum[],int times[],int n);
void updatedeletedarms(int m,int T,vector<int> &deletedarms,double sum[],int times[],int n);
int main() {
    srand(time(NULL));
    ofstream myfile;
    myfile.open("data.txt");
    for(int k=0;k<50;k++) {
        double avregret=0;
        for(int e=0;e<100;e++) {
            int T=50000;
            int n=100+9*k;//n=1+9k form, k is natural number.
            vector<int> deletedarms;
            double sum[n];
            for (int i=0;i<n;i++) {
                sum[i]=0;
            }
            int times[n];
            for (int i=0;i<n;i++) {
                times[i]=0;
            }
            int allnum=0;
            double allsum;
            int m=1;
            while(allnum<T&&T*pow(2,-2*m)>3) {
                allnum=0;
                allsum=0;
                pickarms(m,T,deletedarms,sum,times,n);
                updatedeletedarms(m,T,deletedarms,sum,times,n);
                //cout<<n-int(deletedarms.size())<<endl;
                for(int i=0;i<n;i++) {
                    allnum=allnum+times[i];
                }
                for(int i=0;i<n;i++) {
                    allsum=allsum+sum[i];
                }
                //cout<<allnum<<","<<allnum-allsum<<endl;
                m=m+1;
            }
            //cout<<m-1<<endl;
            //cout<<allnum<<endl;
            //cout<<allnum-allsum<<endl;
            avregret=avregret+allnum-allsum;
        }
        cout<<100+9*k<<", ave="<<avregret/100<<endl;
        myfile<<avregret/100<<" ";
    }
}
void pickarms(int m,int T,vector<int> &deletedarms,double sum[],int times[],int n) {
    int c=(n-1)/9;
    int alltimes=0;
    for(int i=0;i<n;i++) {
        alltimes=alltimes+times[i];
    }
    int t=ceil(2*pow(2,2*m)*log(T*pow(2,-2*m)/3.));
    int judge;
    for (int i=0;i<n;i++) {
        judge=1;
        for(int j=0;j<int(deletedarms.size());j++) {
            if (i==deletedarms[j]) {
                judge=0;
                break;
            }
        }
        if(judge) {
            if(times[i]<t) {
                if((t-times[i])*(n-int(deletedarms.size()))+alltimes<=T) {
                    if(i==0) {
                        sum[i]=sum[i]+t-times[i];
                    }
                    else if(i>=1&&i<=c) {
                        for(int k=0;k<t-times[i];k++) {
                            sum[i]=sum[i]+(0.8+0.2*rand()/32767.);
                        }
                    }
                    else if(i>=1+c&&i<=2*c) {
                        for(int k=0;k<t-times[i];k++) {
                            sum[i]=sum[i]+(0.6+0.4*rand()/32767.);
                        }
                    }
                    else if(i>=2*c+1&&i<=3*c) {
                        for(int k=0;k<t-times[i];k++) {
                            sum[i]=sum[i]+(0.4+0.6*rand()/32767.);
                        }
                    }
                    else if(i>=3*c+1&&i<=4*c) {
                        for(int k=0;k<t-times[i];k++) {
                            sum[i]=sum[i]+(0.2+0.8*rand()/32767.);
                        }
                    }
                    else if(i>=4*c+1&&i<=5*c) {
                        for(int k=0;k<t-times[i];k++) {
                            sum[i]=sum[i]+rand()/32767.;
                        }
                    }
                    else if(i>=5*c+1&&i<=6*c) {
                        for(int k=0;k<t-times[i];k++) {
                            sum[i]=sum[i]+0.8*rand()/32767.;
                        }
                    }
                    else if(i>=6*c+1&&i<=7*c) {
                        for(int k=0;k<t-times[i];k++) {
                            sum[i]=sum[i]+0.6*rand()/32767.;
                        }
                    }
                    else if(i>=7*c+1&&i<=8*c) {
                        for(int k=0;k<t-times[i];k++) {
                            sum[i]=sum[i]+0.4*rand()/32767.;
                        }
                    }
                    else if(i>=8*c+1&&i<=9*c) {
                        for(int k=0;k<t-times[i];k++) {
                            sum[i]=sum[i]+0.2*rand()/32767.;
                        }
                    }
                    times[i]=t;
                }
                else {
                    int p=floor((T-alltimes)/(n-int(deletedarms.size())));
                    int r=(T-alltimes)%(n-int(deletedarms.size()));
                    if(i==0) {
                        sum[i]=sum[i]+p+r;
                        times[i]=times[i]+p+r;
                    }
                    else if(i>=1&&i<=c) {
                        for(int k=0;k<p;k++) {
                            sum[i]=sum[i]+(0.8+0.2*rand()/32767.);
                        }
                        times[i]=times[i]+p;
                    }
                    else if(i>=c+1&&i<=2*c) {
                        for(int k=0;k<p;k++) {
                            sum[i]=sum[i]+(0.6+0.4*rand()/32767.);
                        }
                        times[i]=times[i]+p;
                    }
                    else if(i>=2*c+1&&i<=3*c) {
                        for(int k=0;k<p;k++) {
                            sum[i]=sum[i]+(0.4+0.6*rand()/32767.);
                        }
                        times[i]=times[i]+p;
                    }
                    else if(i>=3*c+1&&i<=4*c) {
                        for(int k=0;k<p;k++) {
                            sum[i]=sum[i]+(0.2+0.8*rand()/32767.);
                        }
                        times[i]=times[i]+p;
                    }
                    else if(i>=4*c+1&&i<=5*c) {
                        for(int k=0;k<p;k++) {
                            sum[i]=sum[i]+rand()/32767.;
                        }
                        times[i]=times[i]+p;
                    }
                    else if(i>=5*c+1&&i<=6*c) {
                        for(int k=0;k<p;k++) {
                            sum[i]=sum[i]+0.8*rand()/32767.;
                        }
                        times[i]=times[i]+p;
                    }
                    else if(i>=6*c+1&&i<=7*c) {
                        for(int k=0;k<p;k++) {
                            sum[i]=sum[i]+0.6*rand()/32767.;
                        }
                        times[i]=times[i]+p;
                    }
                    else if(i>=7*c+1&&i<=8*c) {
                        for(int k=0;k<p;k++) {
                            sum[i]=sum[i]+0.4*rand()/32767.;
                        }
                        times[i]=times[i]+p;
                    }
                    else if(i>=8*c+1&&i<=9*c) {
                        for(int k=0;k<p;k++) {
                            sum[i]=sum[i]+0.2*rand()/32767.;
                        }
                        times[i]=times[i]+p;
                    }
                }
            }
        }
    }
}
void updatedeletedarms(int m,int T,vector<int> &deletedarms,double sum[],int times[],int n) {
    int judge;
    double average[n];
    for(int i=0;i<n;i++) {
        average[i]=sum[i]/times[i];
    }
    for(int i=0;i<n;i++) {
        judge=1;
        for(int j=0;j<int(deletedarms.size());j++) {
            if (i==deletedarms[j]) {
                judge=0;
                break;
            }
        }
        if(judge) {
            if(average[i]<average[0]-pow(2,-m)) {
                deletedarms.push_back(i);
            }
        }
    }
}
