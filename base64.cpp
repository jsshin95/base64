//C++ base64 encoding

//    base64 encoding 함수.
 
//  <parameter>
//    in : 평문 문자열.
 
//  <return>
//    out : base64 encoding 문자열.
/*
std::string base64_encode(const std::string &in) {
 
    typedef unsigned char uchar;
    std::string out;   
 
    int val = 0, valb = -6;
    for (uchar c : in) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val << 8) >> (valb + 8)) & 0x3F]);
    while (out.size() % 4) out.push_back('=');
    return out;
}
*/
//C++ base64 decoding
/*
  <Function Description>
    base64 decode 함수.
 
  <parameter>
    in : base64 encoding 문자열.
 
  <return>
    out : base64 decoding 문자열.
*/
/*
std::string base64_decode(const std::string &in) {
 
    typedef unsigned char uchar;
    static const std::string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 
    std::string out;
    std::vector<int> T(256, -1);
 
    for (int i = 0; i < 64; i++)
        T[b[i]] = i;
 
    int val = 0, valb = -8;
 
    for (uchar c : in) {
        if (T[c] == -1)
            break;
 
        val = (val << 6) + T[c];
        valb += 6;
 
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}
*/
//---------------------
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    char im;
    char asc[1001];
    char b64[1001];
    char ab[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int cnt=0;
    int q,r;
    int i,j;
    int ntemp;
    int n1,n2,n3,n4;
    char ctemp;
    while (true) {
        cout<<"> Input mode (E : Encode, D : Decode, Q : Quit"<<endl;
        cin>>im;
        if (im=='E'){
            cin>>asc; //Navis -> TmF2aXM=
            cnt=0;
            while(asc[cnt]!='\0'){
                cnt++;
            }
            q=cnt/3;
            r=cnt%3;
            cout<<"> Result : ";
            for(i=0;i<q;i++){
                ntemp=((asc[3*i]>>2) & 0x3F);
                cout<<ab[ntemp];
                ntemp=((asc[3*i] & 0x03)<<4)+((asc[3*i+1]>>4) & 0x0F);
                cout<<ab[ntemp];
                ntemp=((asc[3*i+1] & 0x0F)<<2)+((asc[3*i+2]>>6) & 0x03);
                cout<<ab[ntemp];
                ntemp=(asc[3*i+2] & 0x3F);
                cout<<ab[ntemp];
            }
            if (r==1){
                ntemp=((asc[cnt-1]>>2) & 0x3F);
                cout<<ab[ntemp];
                ntemp=((asc[cnt-1] & 0x03)<<4);
                cout<<ab[ntemp]<<'='<<'=';
            }
            else if (r==2){
                ntemp=((asc[cnt-2]>>2) & 0x3F);
                cout<<ab[ntemp];
                ntemp=((asc[cnt-2] & 0x03)<<4)+((asc[cnt-1]>>4) & 0x0F);
                cout<<ab[ntemp];
                ntemp=(asc[cnt-1] & 0x0F)<<2;
                cout<<ab[ntemp]<<'=';
            }
            cout<<endl<<endl;
            continue;
        }
        else if (im=='D'){
            cin>>b64; //TmF2a2luZ2RvbQ== -> Navkingdom
            cnt=0;
            while(b64[cnt]!='\0'){
                cnt++;
            }
            q=cnt/4;
            cout<<"> Result : ";
            for(i=0;i<q;i++){
                for (j=0;j<64;j++){
                    if (b64[4*i]==ab[j]) {
                        n1=j;
                        break;
                    }
                }
                for (j=0;j<64;j++){
                    if (b64[4*i+1]==ab[j]) {
                        n2=j;
                        break;
                    }
                }
                if (b64[4*i+2]=='=') n3=-1;
                else{
                    for (j=0;j<64;j++){
                        if (b64[4*i+2]==ab[j]) {
                            n3=j;
                            break;
                        }
                    }
                }
                if (b64[4*i+3]=='=') n4=-1;
                else{
                    for (j=0;j<64;j++){
                        if (b64[4*i+3]==ab[j]) {
                            n4=j;
                            break;
                        }
                    }
                }
                ctemp=((n1 & 0x3F)<<2) + ((n2>>4)&0x03);
                cout<<ctemp;
                if (n3==-1) break;
                ctemp=((n2 & 0x0F)<<4) + ((n3>>2)&0x0F);
                cout<<ctemp;
                if (n4==-1) break;
                ctemp=((n3 & 0x03)<<6) + (n4&0x3F);
                cout<<ctemp;
            }
            cout<<endl<<endl;
            continue;
        }
        else if (im=='Q'){
            break;
        }
        else {
            break;
        }
        
    }

    return 0;
}
