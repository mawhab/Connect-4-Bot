#include <iostream>

#define n 6
#define m 7
using namespace std;

class tst{
    public:
        int *x;
        int s;
        tst& operator=(tst cpy)noexcept{
            if(this==&cpy) printf("same\n");
            printf("here\n");
            delete this->x;
            this->x = nullptr;
            this->x = new int[4];
            this->s = 4;
            std::copy(cpy.x, cpy.x + cpy.s, this->x);
            return *this;
        }
};

int board[n][m] = { {0,0,0,0,0,0,0},
                    {0,2,2,2,2,0,0},
                    {1,0,1,0,0,1,0},
                    {0,1,1,0,1,0,0},
                    {0,0,1,1,0,0,0},
                    {1,1,1,1,0,0,0}};

int row[2][n] = {{0,0,0,0,0,0}, {0,0,0,0,0,0}};
int col[2][m] = {{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}};
int diag_p[2][n] = {{0,0,0,0,0,0}, {0,0,0,0,0,0}};
int diag_n[2][n] = {{0,0,0,0,0,0}, {0,0,0,0,0,0}};
int count[] = {0,0};


void find(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char dp_i = j - i + 2;
            char dn_i = j + i - 3;
            char p = board[i][j]-1;
            if(p==0 || p==1){
                if(++row[p][i]==4) {
                    count[p]++;
                    row[p][i] = 0;
                }
                if(++col[p][j]==4){
                    count[p]++;
                    col[p][j] = 0;
                }
                if(dp_i>=0 && dp_i<6 && ++diag_p[p][dp_i]==4){
                    count[p]++;
                    diag_p[p][dp_i] = 0;
                }
                if(dn_i>=0 && dn_i<6 && ++diag_n[p][dn_i]==4){
                    count[p]++;
                    diag_n[p][dn_i] = 0;
                }
            }else{
                row[0][i] = 0;
                row[1][i] = 0;
                col[1][j] = 0;
                col[0][j] = 0;
                if(dp_i>=0 && dp_i<6){
                    diag_p[0][dp_i] = 0;
                    diag_p[1][dp_i] = 0;
                }
                if(dn_i>=0 && dn_i<6){
                    diag_n[0][dn_i] = 0;
                    diag_n[1][dn_i] = 0;
                }
            }
        }
    }
}

int main(){
    // for(int x=0;x<2000;x++){
    //     count[0] = 0;
    //     count[1] = 0;
    //     find();
    // }
    tst y;
    y.s = 4;
    y.x = new int[4];
    y.x[0] = 4;
    tst z;
    z.operator=(y);    
    z.x[0] = 6;
    printf("%x -- %x\n", y.x[0], z.x[0]);
    cout << count[0] << endl;
    cout << count[1] << endl;
}