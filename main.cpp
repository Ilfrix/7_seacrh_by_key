#include <string>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class specialization{
    public:
    string code;
    string name;
};
int value = 0;
specialization brute_force(vector <specialization> &arr, string key){
    for (size_t i = 0; i < arr.size(); ++i){
        ++value;
        if (arr[i].code == key){
            return arr[i];
        }
    }
    return {"None", "None"};
}
specialization linear_with_barrier(vector <specialization> &arr, string key){
    arr.push_back({key, ""});
    int i = 0;
    
    while (arr[i].code != key){
        ++value;
        ++i;
    }
    specialization res;
    if (i < arr.size() - 1){
        res = arr[i];
        ++value;
    } else{
        res = specialization{"Node", "None"};
    }
    return res;
}
specialization binary_search(vector <specialization> &arr, string key){
    int l = 0, r = arr.size(), mid = 0;
    while (l != r){
        mid = (l + r) / 2;
        value += 2;
        if (arr[mid].code < key){
            l = mid + 1;
            --value;        
        }
        else if (arr[mid].code == key){
            l = mid;
            break;
        }
        else    r = mid;
    }
    return arr[l];
}

int main(){
    srand( time(0) );
    int n = 10;
    for (int j = 0; j < 4; ++j){
    vector <specialization> array;
    n *= 10;
    int k = 0;
    for (int i = 0; i < n; ++i){
        specialization tmp{"01."+ to_string(k), "1234" + to_string(k)};
        array.push_back(tmp);
        ++k;
    }
    //cout <<"byte : "<< sizeof(specialization{"01.100","1234567"});
    auto start = std::chrono::steady_clock::now();

    //specialization c = brute_force(array, "01.59");
    //specialization c = linear_with_barrier(array, "01.60");
    specialization c = binary_search(array, "01." + to_string(0));
    auto end = std::chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    cout << value << '\n';
    value = 0;
    }
    //cout << c.name << ' ' << c.code<<'\n';
}