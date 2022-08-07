#include<iostream>
#include<string>
#include<vector>
using namespace std;
/**
 *
 * @param xx
 * @param gj
 * @param flag 元素伤害
 */
void gongji(vector<int> &xx,int gj,int flag){
    if(flag){
        xx[0] -=gj;
    }else{
        xx[0] -= gj>xx[2]?gj-xx[2]:0;
    }
}

void v2vbeidong(vector<int> &v2v,vector<int> &qj){
    v2v[0] +=20;
    qj[0] +=20;
    v2v[1] +=15;
}
void qjbeidong(vector<int> &qj,int begin){
    qj[1] += (begin-qj[0])/2;
}

int main(){
    int x;
    vector <vector<int>> matrix{};
    cin >> x;
    auto t_x = 2*x;
    while (t_x--) {
        vector<int> matrix_t{};
        auto t_y = 4;
        while (t_y--) {
            int t{};
            cin >> t;
            matrix_t.push_back(t);
        }
        matrix.push_back(matrix_t);
    }
    for (int i = 0; i < matrix.size(); i+=2) {
        vector<int> V2V(matrix[i]);
        vector<int> QJ(matrix[i+1]);
        int qianjieBlood = QJ[0];
        int huihe = 0;
        bool v2vflag = false;
        /*1主动，2被动*/
        bool v2vskillflag1 = false;
        bool v2vskillflag2 = false;

        bool qjskillflag1 = false;

        if(V2V[3] > QJ[3]){
            v2vflag = true;
        }
        while (V2V[0] >0 and QJ[0] >0){
            /*开战*/
            /*生命 攻击 ，防御,速度*/
            huihe++;
            if(v2vflag){
                /*v2v先发动技能*/
                if(huihe%3 == 0 ){
                    /*技能*/
                    v2vskillflag1 = true;
                    gongji(QJ,V2V[1],false);
                    if (QJ[0] < 0) break;
                    /*qj被动*/
                    qjbeidong(QJ,qianjieBlood);
                    if (QJ[0] < 11) {
                        /*QJPutong ji 自己打自己*/
                        gongji(QJ,QJ[1], false);
                    } else{
                        /*技能释放*/
                        gongji(QJ,45, false);
                        gongji(QJ,20, true);
                        gongji(QJ,10, true);
                        if(QJ[0] <=0)break;
                    }
                    qjskillflag1 = true;
                } else{
                    /*普通攻击*/
                    gongji(QJ,V2V[1], false);
                    if(QJ[0] <=0)break;
                    /*qj被动*/
                    qjbeidong(QJ,qianjieBlood);
                    if (!qjskillflag1) {
                        if (v2vskillflag1) {
                            gongji(QJ, QJ[1], false);
                        } else {
                            gongji(V2V, QJ[1], false);
                        }
                    }
                    qjskillflag1 = false;

                    if(V2V[0] <= 0) break;
                    if(!v2vskillflag2 and V2V[0]<31){
                        v2vbeidong(V2V,QJ);
                        v2vskillflag2 = true;
                    }
                }
            } else{
                /*QJ 先*/
                if(huihe%3 ==0){
                    qjskillflag1 = true;
                    gongji(V2V,45, false);
                    gongji(V2V,20, true);
                    gongji(QJ,10, true);
                    /*v2v被动*/
                    if(V2V[0] <= 0) break;
                    if(!v2vskillflag2 and V2V[0]<31){
                        v2vbeidong(V2V,QJ);
                        v2vskillflag2 = true;
                    }
                    v2vskillflag1 = true;
                    gongji(QJ,V2V[1],false);
                    if(QJ[0] <=0)break;
                } else{
                    if (!qjskillflag1) {
                        if (v2vskillflag1) {
                            gongji(QJ, QJ[1], false);
                        } else {
                            gongji(V2V, QJ[1], false);
                        }
                    }
                    qjskillflag1 = false;
                    /*v2v被动*/
                    if(V2V[0] <= 0) break;
                    if(!v2vskillflag2 and V2V[0]<31){
                        v2vbeidong(V2V,QJ);
                        v2vskillflag2 = true;
                    }
                    gongji(QJ,V2V[1], false);
                    /*qj被动*/
                    qjbeidong(QJ,qianjieBlood);
                }
            }
        }
        if(V2V[0] > 0) cout<<"I love V2V forever!"<<endl;
        else cout<<"Kalpas yame te!"<<endl;
    }
    return 0;
}