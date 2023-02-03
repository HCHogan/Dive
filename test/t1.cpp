#include <iostream>
using namespace std;
const int N = 100010;

int nums[N];
int n;
bool flag;                      //flag = 1 表示能走到最后一位

void dfs(int po, int ra) {      //po是当前位置, ra是当前位置能够跳的格数
    if(po >= n) {
        flag = 1;               //如果当前位置大于n, 说明能到终点, 标记, 返回
        return;
    }
    for(int i = po + 1; i <= po+ra; i++) {      //枚举下一步所有可能走的地方
        dfs(i, nums[i]);
        if(flag) return;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    dfs(0,nums[0]);             //从下标为0的地方开始搜
    if(flag) cout << "true" << endl;
    else cout << "false" <<endl;
    return 0;
}
