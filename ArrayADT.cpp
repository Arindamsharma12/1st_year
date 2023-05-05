#include<iostream>
using namespace std;

class myArray{
    int total_size;
    int used_size;
    int *ptr;

    public:
    myArray();
    myArray(int tsize, int usize){
        total_size = tsize;
        used_size = usize;
        ptr = new int(tsize * sizeof(int));
    }
    void setVal(){
        int n;
        for(int i = 0; i < used_size; i++){
            cout<<"Enter the element "<<(i+1)<<": "<<endl;
            cin>>n;
            ptr[i] = n;
        }
    }    
    void show(){
        for(int i = 0; i < used_size; i++){
            cout<<ptr[i]<<endl;
        }
    }    
};


int main(){
    myArray marks(20, 4);
    marks.setVal();
    marks.show();
    return 0;
}