#include<iostream>
#include<random>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v){
        if(!v.empty()){
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
        }
        return out;
}


int main(){
        cout << "RAND_MAX" << RAND_MAX << endl;
        srand((unsigned)time(NULL));

        int min_rand_num, max_rand_num, rand_num_cnt;
        cout << "随机数下限：" <<endl;
        cin >> min_rand_num;
        cout << "随机数上限：" <<endl;
        cin >> max_rand_num;
        cout << "随机数数量：" << endl;
        cin >> rand_num_cnt;
        //获取随机数
        vector<int> rand_nums;
        for(int i=0; i<rand_num_cnt; i++){
                rand_nums.push_back(rand()%(max_rand_num-min_rand_num)+min_rand_num);
        }

        cout << "随机数为:"<< rand_nums << endl;

        return 0;
}
