#include<iostream>
using namespace std;

int check_bin(int s[],int n){
    for(int i = 0; i < n; i++){
        if(s[i] != 0 && s[i] != 1){
            return 0;
        }
    }
    return 1;   
}

int main(){
    int s[] = {1,0,2,1};
    int n = sizeof(n)/sizeof(int);
    int ans = check_bin(s,n);
    cout<<ans;
    
    return 0;
}