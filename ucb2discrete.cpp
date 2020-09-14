#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
void pickarms(int m,int T,vector<int> &deletedarms,double sum[],int times[]);
void updatedeletedarms(int m,int T,vector<int> &deletedarms,double sum[],int times[]);
int main() {
    int T=1000000;
    srand(time(NULL));
    vector<int> deletedarms;
    double sum[100];
    for (int i=0;i<100;i++) {
        sum[i]=0;
    }
    int times[100];
    for (int i=0;i<100;i++) {
        times[i]=0;
    }
    int allnum=0;
    double allsum;
    int m=1;
    while(allnum<T&&m<8) {
        allnum=0;
        allsum=0;
        pickarms(m,T,deletedarms,sum,times);
        updatedeletedarms(m,T,deletedarms,sum,times);
        cout<<100-int(deletedarms.size())<<endl;
        for(int i=0;i<100;i++) {
            allnum=allnum+times[i];
        }
        for(int i=0;i<100;i++) {
            allsum=allsum+sum[i];
        }
        cout<<allnum<<","<<allnum-allsum<<endl;
        m=m+1;
    }
    cout<<m-1<<endl;
    cout<<allnum<<endl;
    cout<<allnum-allsum<<endl;
    int a;
    for(int i=0;i<100;i++) {
        a=1;
        for(int j=0;j<int(deletedarms.size());j++) {
            if(i==deletedarms[j]) {
                a=0;
                break;
            }
        }
        if(a) {
            //cout<<i;
        }
    }
}
void pickarms(int m,int T,vector<int> &deletedarms,double sum[],int times[]) {
    int t=ceil(2*pow(2,2*m)*log(T*pow(2,-2*m)/3.));
    int judge;
    for (int i=0;i<100;i++) {
        judge=1;
        for(int j=0;j<int(deletedarms.size());j++) {
            if (i==deletedarms[j]) {
                judge=0;
                break;
            }
        }
        if(judge) {
            if(times[i]<t) {
                if(i==0) {
                    sum[i]=sum[i]+t-times[i];
                }
                else if(i>=1&&i<=11) {
                    for(int k=0;k<t-times[i];k++) {
                        if(rand()/32767.>=0.5) {
                            sum[i]=sum[i]+1;
                        } else {
                            sum[i]=sum[i]+0.8;
                        }
                    }
                }
                else if(i>=12&&i<=22) {
                    for(int k=0;k<t-times[i];k++) {
                        if(rand()/32767.>=0.5) {
                            sum[i]=sum[i]+1;
                        } else {
                            sum[i]=sum[i]+0.6;
                        }
                    }
                }
                else if(i>=23&&i<=33) {
                    for(int k=0;k<t-times[i];k++) {
                        if(rand()/32767.>=0.5) {
                            sum[i]=sum[i]+1;
                        } else {
                            sum[i]=sum[i]+0.4;
                        }
                    }
                }
                else if(i>=34&&i<=44) {
                    for(int k=0;k<t-times[i];k++) {
                        if(rand()/32767.>=0.5) {
                            sum[i]=sum[i]+1;
                        } else {
                            sum[i]=sum[i]+0.2;
                        }
                    }
                }
                else if(i>=45&&i<=55) {
                    for(int k=0;k<t-times[i];k++) {
                        if(rand()/32767.>=0.5) {
                            sum[i]=sum[i]+1;
                        } else {
                            sum[i]=sum[i];
                        }
                    }
                }
                else if(i>=56&&i<=66) {
                    for(int k=0;k<t-times[i];k++) {
                        if(rand()/32767.>=0.5) {
                            sum[i]=sum[i]+0.8;
                        } else {
                            sum[i]=sum[i];
                        }
                    }
                }
                else if(i>=67&&i<=77) {
                    for(int k=0;k<t-times[i];k++) {
                        if(rand()/32767.>=0.5) {
                            sum[i]=sum[i]+0.6;
                        } else {
                            sum[i]=sum[i];
                        }
                    }
                }
                else if(i>=78&&i<=88) {
                    for(int k=0;k<t-times[i];k++) {
                        if(rand()/32767.>=0.5) {
                            sum[i]=sum[i]+0.4;
                        } else {
                            sum[i]=sum[i];
                        }
                    }
                }
                else if(i>=89&&i<=99) {
                    for(int k=0;k<t-times[i];k++) {
                        if(rand()/32767.>=0.5) {
                            sum[i]=sum[i]+0.2;
                        } else {
                            sum[i]=sum[i];
                        }
                    }
                }
                times[i]=t;
            }
        }
    }
}
void updatedeletedarms(int m,int T,vector<int> &deletedarms,double sum[],int times[]) {
    int judge;
    double average[100];
    for(int i=0;i<100;i++) {
        average[i]=sum[i]/times[i];
    }
    for(int i=0;i<100;i++) {
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
