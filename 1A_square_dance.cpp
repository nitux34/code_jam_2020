#include <bits/stdc++.h>
using namespace std;


int findDancingNeighbour(int irow, int icol, int nrows, int ncols, int compassRow, int compassCol,vector<vector<int>> isDancing){
    int tmprow;
    int tmpcol;
    int tmpfactor=1;
    
    for(int ii=0; ii<nrows+ncols;ii++){
        tmprow = tmpfactor*compassRow + irow;
        tmpcol = tmpfactor*compassCol + icol;
        if (tmprow==nrows||tmpcol==ncols||tmpcol<0||tmprow<0){
            return tmpfactor;
        }
        if (isDancing[tmprow][tmpcol]>0 ){
            return tmpfactor;
        }
        tmpfactor++;
    }
    return tmpfactor;
}

vector<vector<int>> create_dance(int nrows, int ncols, vector<vector<int>> isDancing,int option) {
    for (int irow=0; irow<nrows; irow++){ 
        for (int icol=0; icol<ncols; icol++){  
                   
            if(option == 1){              
                isDancing[irow][icol] = 1;
            }else{
                if(isDancing[irow][icol] == 2){
                    isDancing[irow][icol] = 0;
                }
            }
        }
    }
    return isDancing;
}


int main(){


int ncols;
int nrows;


int tt;
long long interest,tmpinterest;
int compass[4] = {0,0,-1,1};
float tmpsum;
int tmprow, tmpcol,N,tmpfactor;
bool isEliminated = 0;

cin >> tt;
for (int it = 0; it < tt; it++){
    cout << "Case #" << it+1 << ": " << endl;
    cin >> nrows >> ncols;
    int danceSkills[nrows][ncols];
    for (int irow=0; irow<nrows; irow++){ 
            for (int icol=0; icol<ncols; icol++){
                cin >> danceSkills[irow][icol];
            }
    }



    vector<int> col(ncols,0);
    vector<vector<int>> isDancing(nrows,col);
    isDancing = create_dance(nrows, ncols, isDancing,1);
    tmpinterest = 0;

    for (int iround = 0; iround < ncols*nrows; iround++){
        isEliminated = 0;  
        isDancing = create_dance(nrows, ncols, isDancing,2);   
        for (int irow=0; irow<nrows; irow++){ 
            for (int icol=0; icol<ncols; icol++){
                if (isDancing[irow][icol]>0){
                    
                    tmpinterest = tmpinterest + danceSkills[irow][icol];

                    N = 0;
                    tmpsum = 0;
                    for (int ii = 0; ii < 4; ii++){
                        tmpfactor = findDancingNeighbour(irow, icol, nrows, ncols, compass[ii], compass[3-ii], isDancing);
                        tmprow = tmpfactor*compass[ii] + irow;
                        tmpcol = tmpfactor*compass[3-ii] + icol;

                        if (tmprow>=0 && tmpcol>=0 && tmprow<nrows && tmpcol<ncols && isDancing[tmprow][tmpcol] >0){                            
                            tmpsum = tmpsum + danceSkills[tmprow][tmpcol];
                            N++;                            
                        }                                                   
                    }

                    if (tmpsum/N>danceSkills[irow][icol]){
                        isDancing[irow][icol] = 2;
                        isEliminated = 1;
                    }
                }
            }
        }


        interest = tmpinterest;
        if(!isEliminated){
            break;
        }
        

    }

cout << interest << endl;
}
return 0;
}