#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<vector<int>> ways;
int a[10];
int cnt = 0;
int st[10];

void dfs(int u) {
    // �жϱ߽�
    if (u > n) {
        vector<int> way;
        for (int i = 1; i <= n; i++) {
            way.push_back(a[i]);
        }
        ways.push_back(way);
        cnt++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            st[i] = 1;
            a[u] = i;
            dfs(u + 1);
            // �ָ��ֳ�
            st[i] = 0;
            a[u] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    // �������ѭ��������Χ
    for (int i = 0; i < cnt; i++) {
        // �����ڲ�ѭ��������Χ
        for (int j = 0; j < ways[i].size(); j++) {
            printf("%d ", ways[i][j]);
        }
        puts("");
    }
    return 0;
}    
