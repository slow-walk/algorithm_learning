#include<iostream>
#include<random>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<iterator>
#include<algorithm>
#include<ctime>
#include<map>
using namespace std;

#define PRINT_SORTED_NUMS 0

//重载打印运算符，打印vector容器变量
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v){
        if(!v.empty()){
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
        }
        return out;
}

vector<int> get_randm_nums(){
        cout << "RAND_MAX" << RAND_MAX << endl;
        srand((unsigned)time(NULL));
        char need_input_randm_config;
        cout << "是否需要输入随机数参数[Y/N]" << endl;
        cin >> need_input_randm_config;

        int min_rand_num, max_rand_num, rand_num_cnt;
        if (need_input_randm_config=='Y'){
                cout << "随机数下限：" <<endl;
                cin >> min_rand_num;
                cout << "随机数上限：" <<endl;
                cin >> max_rand_num;
                cout << "随机数数量：" << endl;
                cin >> rand_num_cnt;
        }
        else if (need_input_randm_config=='N'){
                min_rand_num = 0;
                max_rand_num = 100;
                rand_num_cnt = 100;
        }
        else{
                cout << "输入参数非法" << endl;
                exit(1);
        }

        //获取随机数
        vector<int> rand_nums;
        for(int i=0; i<rand_num_cnt; i++){
                rand_nums.push_back(rand()%(max_rand_num-min_rand_num)+min_rand_num);
        }

        if(PRINT_SORTED_NUMS!=0){
                cout << "随机数为:"<< rand_nums << endl;
        }
        return rand_nums;
}

void swap(vector<int> &nums, int i_1, int i_2){
        int temp = nums[i_1];
        nums[i_1] = nums[i_2];
        nums[i_2] = temp;
}

void test_swap(){
        vector<int> input;
        input.push_back(1);
        input.push_back(2);
        cout << "交换前：" << input << endl;
        swap(input, 0, 1);
        cout << "交换后：" << input << endl;
}

void bubble_sort(vector<int> nums){
        int length = nums.size();
        for(int i =0; i<length-1; i++){
                for(int j=0; j<length-1-i; j++){
                        if(nums[j]>nums[j+1]){
                                swap(nums, j, j+1);
                        }
                }
        }
        if(PRINT_SORTED_NUMS!=0){
                cout << "冒泡排序结果：" << nums << endl;
        }
}

void choice_sort(vector<int> nums){
        int length = nums.size();
        for(int i=0; i<length; i++){
                for(int j=i+1; j<length; j++){
                        if(nums[i]>nums[j]){
                                swap(nums, i, j);
                        }
                }
        }
        if(PRINT_SORTED_NUMS!=0){
                cout << "选择排序结果：" << nums << endl;
        }
}    

void insert_sort(vector<int> nums){
        int length = nums.size();
        int j;
        for(int i=1; i<length; i++){
                j = 0;
                while(j<i){
                        if(nums[j] >= nums[i]){
                                break;
                        }
                        j++;
                }
                if(j!=i){
                        nums.insert(nums.begin()+j,nums[i]);
                        nums.erase(nums.begin()+i+1);
                }
        }
        if(PRINT_SORTED_NUMS!=0){
                cout << "插入排序结果：" << nums << endl;
        }
}        

vector<int> merge_two_sorted(vector<int> &nums1, vector<int> &nums2){
        vector<int>::iterator point_nums1 = nums1.begin();
        vector<int>::iterator point_nums2 = nums2.begin();
        vector<int> result;
        while(point_nums1<nums1.end()&&point_nums2<nums2.end()){
                if (*point_nums1<*point_nums2){
                        result.push_back(*point_nums1);
                        point_nums1++;
                }
                else{
                        result.push_back(*point_nums2);
                        point_nums2++;
                }
        }
        if (point_nums1<nums1.end()){
                result.insert(result.end(), point_nums1, nums1.end());
        }
        else{
                result.insert(result.end(), point_nums2, nums2.end());
        }
        return result;
}

void merge_sort(vector<int> &nums){
        int length = nums.size();
        if (length<=1){
                return ;
        }
        vector<int> nums1(nums.begin(), nums.begin()+int(length/2));
        vector<int> nums2(nums.begin()+int(length/2), nums.end());
        merge_sort(nums1);
        merge_sort(nums2);
        nums = merge_two_sorted(nums1, nums2);
}

void get_cost_time(void (*func)(vector<int>), vector<int> rand_nums){
        map<void (*)(vector<int>), const char *> func_array;
        func_array[bubble_sort] = "bubble";
        func_array[choice_sort] = "choice";
        func_array[insert_sort] = "insert";

        clock_t start_time = clock();
        func(rand_nums);
        clock_t end_time = clock();
        cout << func_array[func] << "的耗时为" << (end_time-start_time) << "ms" << endl;
}

void get_cost_time(void (*func)(vector<int> &), vector<int> rand_nums){
        map<void (*)(vector<int> &), const char *> func_array;
        func_array[merge_sort] = "merge";

        clock_t start_time = clock();
        func(rand_nums);
        clock_t end_time = clock();
        if(PRINT_SORTED_NUMS!=0){
                cout << func_array[func] << "排序结果：" << rand_nums << endl;
        }
        cout << func_array[func] << "的耗时为" << (end_time-start_time) << "ms" << endl;
}

int main(){
        vector<int> rand_nums = get_randm_nums();
        get_cost_time(bubble_sort, rand_nums);
        get_cost_time(choice_sort, rand_nums);
        get_cost_time(insert_sort, rand_nums);
        get_cost_time(merge_sort, rand_nums);
        return 0;
}
