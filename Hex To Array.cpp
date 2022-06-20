#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define DBG(n) cout<<#n<<"->->->"<<n<<"\n"
#define vl vector<ll>
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0)
#define YESNO(n) cout<<((n) ? "YES\n":"NO\n")
#define pll pair<ll,ll>

string func(char c)
{
    if(c=='0'){return "0,0,0,0";}
    if(c=='1')return "0,0,0,1";
    if(c=='2')return "0,0,1,0";
    if(c=='3')return "0,0,1,1";
    if(c=='4')return "0,1,0,0";
    if(c=='5')return "0,1,0,1";
    if(c=='6')return "0,1,1,0";
    if(c=='7')return "0,1,1,1";
    if(c=='8')return "1,0,0,0";
    if(c=='9')return "1,0,0,1";
    if(c=='A')return "1,0,1,0";
    if(c=='B')return "1,0,1,1";
    if(c=='C')return "1,1,0,0";
    if(c=='D')return "1,1,0,1";
    if(c=='E')return "1,1,1,0";
    if(c=='F')return "1,1,1,1";
}

int main()
{
    string str[8]={"0x00","0x20","0x20","0x20","0x00","0x00","0x00","0x00"};
    for(int i=0;i<8;i++)
    {
        cout<<"{"<<func(str[i][2])+","+func(str[i][3])<<"},"<<endl;
    }
}
