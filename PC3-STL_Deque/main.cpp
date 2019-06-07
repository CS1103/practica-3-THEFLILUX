#include <iostream>
#include <deque>
using namespace std;

template <typename T>
void function(deque<T> deq, int n){
    int a=0,k=0,menor=0;
    T array[n];
    for (int i = 0; i <= n; i++) {
        for (int j = 0+a; j < n+a; j++) {
            //cout << deq[j] << " ";
            array[k]=deq[j];
            k++;
        }
        menor=array[0];
        for (int l = 0; l < n; l++) {
            if (array[l]< menor){
                menor=array[l];
            }
        }
        cout << menor << " ";
        a++;
        k=0;
        array[n]={0};
    }
}

int main() {
    deque<int> deq;
    deq.assign({5,1,4,8,2,4});
    function(deq,3);

    return 0;
}