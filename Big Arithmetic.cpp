#include<bits/stdc++.h>
using namespace std;

int main() {
int t;
    cin>>t;
    while(t--){
        string a,b,c,d,e;
        cin>>a;
        c=a;
        cin>>b;
       // cout<<c;
        int n=a.length(),m=b.length(),i=n-1,j=m-1;
       // cout<<i<<" "<<j<<endl;
        while(j>=0){
            if(c[i] >= b[j]){    c[i]=c[i]-b[j]+48; }
            else {
                if(c[i-1]=='0'){
                   
                    int k=i-1;
                    while(c[k]=='0'){  c[k--]='9'; }
                    c[k]-=1;
                    //cout<<a[i]<<" "<<b[j]<<endl;
                    c[i]=(c[i]-b[j])+58;
                }else{
                   
                    c[i-1]-=1;
                      c[i]=(c[i]-b[j])+58;}
            }
            i--;
            j--;
        }
        
        
         j=c.length(),i=0;
        int carry=0;
        while(c[i]=='0') i++;
        while(i<j){
            if(carry+c[i]-48==0){ d+='0'; carry=0; }
            else if(carry+c[i]-48==1){
                int t=10;
                if(i+1 <j ) t+=c[i+1]-48;
                else t=0;
                //cout<<t<<endl;
                if(d.length()>0) d+='0';
                d+=(t/2)+48;
                if(t&1) carry=10;
                else carry=0;
                i++;
            }else{
                int t=carry+c[i]-48;
                d+=(t/2)+48;
                if(t&1) carry=10;
                else carry=0;
            }
            i++;
        }
        if(d.length()==0) d+='0';
        i=d.length()-1;
        j=m-1;
        carry=0;
        while(i>=0&&j>=0){
            int t=(b[j]-48)+carry+(d[i]-48);
             carry=t/10;
            e+=(t%10)+48;
            i--;
            j--;
        } while(i>=0){
            int t=carry+d[i]-48;
            carry=t/10;
            e+=(t%10)+48;
            i--;
        }
        while(j>=0){
            int t=carry+b[j]-48;
            carry=t/10;
            e+=(t%10)+48;
            j--;
        }
        if(carry>0) e+=carry+48;
        i=e.length();
       // cout<<a<<" "<<b<<" "<<c<< " "<<d<<" ";
        for(i-=1;i>=0;i--) cout<<e[i];
        cout<<endl<<d<<endl;
    }
    
  return 0;
}
