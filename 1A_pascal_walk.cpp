#include <bits/stdc++.h>
using namespace std;

#define BIT_CHECK(val,n) ((val)& (1<<(n-1)))

int get_col(int irow, int direction){
    int icol;
    if (direction==1){
        icol = 1;
    }else{
        icol = irow;
    }
    return icol;
}

void print_row(int irow,int direction){
    int icol = get_col(irow,direction);
    for (int ii=0;ii<irow;ii++){        
        cout << irow << " " << icol + direction*ii <<"\n";
    }
}


int main()
{
int nn;
int tt;
cin >> tt;

int maxRow = 30;
int firstIndex;
int nOnce;
int direction;
int icol;
for (int it = 1; it <=tt; it++){
    nOnce = 0;
    firstIndex = 0;
    direction = 1;
    cout << "Case #"<<  it << ":\n";
    cin >> nn;
    
    for (int ii = maxRow; ii>0; ii--){ 
        if (firstIndex == 0 && BIT_CHECK(nn,ii)){
            firstIndex = ii;
        }
    }

    for (int ii = firstIndex-1; ii>0; ii--){
        if (!BIT_CHECK(nn,ii)){
            nOnce++;
            nn--;
        }
    }

    for (int ii = 1; ii <= firstIndex; ii++){
        if(BIT_CHECK(nn,ii)){       
            print_row(ii,direction);
            direction = -direction;
        }else if(ii != firstIndex){
            icol = get_col(ii,direction);
            cout << ii << " " << icol << "\n";
            nOnce--;
        }
    }

    firstIndex = BIT_CHECK(nn,firstIndex) ? firstIndex : firstIndex-1;
    for (int ii = 0; ii<nOnce; ii++){
        icol = get_col(ii+firstIndex + 1,direction);
        cout << firstIndex + ii  + 1<< " " << icol << "\n";
    }
}
}