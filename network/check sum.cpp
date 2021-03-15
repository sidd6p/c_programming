#include<bits/stdc++.h>
#define MAXLENTH 16
using namespace std;

string dataword;
string receiver_codeword;
string codeword;
string carry = "0";
string comp = "0000";

string sender(string &s);
string receiver(string &r);
string addition(string &d1, string &d2);
bool check_for_error(string &c);

int main(){
  string codeword_to_send;
  string status;
  cout<<"Enter the 16 bits data"<<endl;
  cin>>dataword;
  codeword_to_send = sender(dataword);
  cout<<"\n\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";
  cout<<"Enter the codeword for receiver"<<endl;
  cin>>receiver_codeword;
  status = receiver(receiver_codeword);
  if(check_for_error(status)){
    cout<<"No error found"<<endl;
  }
  else{
    cout<<"Error found"<<endl;
  }
  return 0;
}

string sender(string &s){
    string s1, s2, s3, s4, sf;
    s1 = s.substr(0, 4);
    s2 = s.substr(4, 4);
    s3 = s.substr(8, 4);
    s4 = s.substr(12, 4);
    cout<<"Divide "<<s<<" into"<<endl;
    cout<<"s1 = "<<s1<<"\ns2 = "<<s2 <<"\ns3 = "<<s3 <<"\ns4 = "<<s4<<endl;
    sf = addition(s1, s2);
    sf = addition(sf, s3);
    sf = addition(sf, s4);
   cout<<"1's addition of s1 + s2 + s3 + s4 = "<<sf<<endl;
    for(int i = 0; i <sf.length(); i++){
        if(sf[i] == '0'){
            comp[i] = '1';
        }
        else{
            comp[i] = '0';
        }
    }
    cout<<"complement of 1's addition of s1 + s2 + s3 + s4 = "<<comp<<endl;
    cout<<"Code word to send is " << s+comp;
    return s+comp;

}

string receiver(string &r){
    string r1, r2, r3, r4, r5, rf;
    r1 = r.substr(0, 4);
    r2 = r.substr(4, 4);
    r3 = r.substr(8, 4);
    r4 = r.substr(12, 4);
    r5 = r.substr(16, 4);
    cout<<"Divide "<<r<<" into"<<endl;
    cout<<"r1 = "<<r1<<"\nr2 = "<<r2 <<"\nr3 = "<<r3 <<"\nr4 = "<<r4 <<"\nr5 = "<<r5<<endl;
    rf = addition(r1, r2);
    rf = addition(rf, r3);
    rf = addition(rf, r4);
    rf = addition(rf, r5);
   cout<<"1's addition of r1 + r2 + r3 + r4 + r5 = "<<rf<<endl;
    for(int i = 0; i <rf.length(); i++){
        if(rf[i] == '0'){
            comp[i] = '1';
        }
        else{
            comp[i] = '0';
        }
    }
    cout<<"complement of 1's addition of r1 + r2 + r3 + r4 + r5= "<<comp<<endl;
    return comp;
}

string addition(string &d1, string &d2){
     string sum = "0000";
     int length=d1.length();
     int i;

		for(i=length-1;i>=0;i--)
        {
            if((d1[i]=='0') && (d2[i]=='0') && (carry[0]=='0'))
            {
                sum[i]='0';
                carry[0]='0';
            }
            else if(d1[i]=='0' && d2[i]=='0' && carry[0]=='1')
            {
                sum[i]='1';
                carry[0]='0';

            }
            else if(d1[i]=='0' && d2[i]=='1' && carry[0]=='0')
            {
                sum[i]='1';
                carry[0]='0';

            }
            else if(d1[i]=='0' && d2[i]=='1' && carry[0]=='1')
            {
                sum[i]='0';
                carry[0]='1';

            }
            else if(d1[i]=='1' && d2[i]=='0' && carry[0]=='0')
            {
                sum[i]='1';
                carry[0]='0';

            }
            else if(d1[i]=='1' && d2[i]=='0' && carry[0]=='1')
            {
                sum[i]='0';
                carry[0]='1';

            }
            else if(d1[i]=='1' && d2[i]=='1' && carry[0]=='0')
            {
                sum[i]='0';
                carry[0]='1';

            }
            else if(d1[i]=='1' && d2[i]=='1' && carry[0]=='1')
            {
                sum[i]='1';
                carry[0]='1';

            }
            else
                break;
        }
        if(carry[0] == '1'){
                carry = "0001";
                sum = addition(sum, carry);
        }
        return sum;
}

bool check_for_error(string &c){
    if(c == "0000"){
        return true;
    }
    else{
        return false;
    }
}
