#include <iostream>

using namespace std;

void find_(char * _list, int _N, int _I, int * _result) {
    for (int i = 0; i < 2 * _N; i++) {
        if (_list[i] != _I) continue;
        else {
            int c[3], min_index; // 0 to left, 1 to right, 2 to vertical
            c[0] = _list[(i - 1 + _N) % _N];
            c[1] = _list[(i + 1 + _N) % _N];
            c[2] = _list[(i + _N) % (2 * _N)];
            min_index = 0;
            for (int m = 1; m < 3; m++)
                if (c[min_index] > c[m])
                    min_index = m;
            if (c[min_index] > 3 || c[min_index] == 0) {
                continue;
            } else {
                (*_result)++;
                _list[i] = 4;
                switch(min_index){
                    case 0:
                        _list[(i - 1 + _N) % _N] = 4;
                        break;
                    case 1:
                        _list[(i + 1 + _N) % _N] = 4;
                        break;
                    case 2:
                        _list[(i + _N) % (2 * _N)] = 4;
                        break;
                }
            }
        }
    }
}

int main(void) {
    int T,N,W;
    scanf("%d", &T);
    for (int _t = 0; _t < T; _t++) {
        scanf("%d %d", &N, &W);
        int * onetagon_enemy_list = new int[2 * N];
        for (int i = 0; i < (2 * N); i++) {
            scanf("%d", onetagon_enemy_list + i);
        }
        char * near_point_list = new char[2 * N]();
        for (int i = 0; i < N; i++) {
            int rest = W - onetagon_enemy_list[i];
            if (onetagon_enemy_list[(i + 1) % N] <= rest) near_point_list[i]++;
            if (onetagon_enemy_list[(i - 1 + N) % N] <= rest) near_point_list[i]++;
            if (onetagon_enemy_list[i + N] <= rest) near_point_list[i]++;
        }
        for (int i = N; i < 2 * N; i++) {
            int rest = W - onetagon_enemy_list[i];
            if (onetagon_enemy_list[(i + 1) % (2 * N)] <= rest) near_point_list[i]++;
            if (onetagon_enemy_list[(i - 1 + N) % (2 * N)] <= rest) near_point_list[i]++;
        }
        int result = 0;
        for (int _f = 0; _f < 4; _f++) {
            find_(near_point_list, N, _f, &result);
        }
        for (int i = 0; i < 2 * N; i++){ 
            if (near_point_list[i] != 4)
                result++;
        }
        delete []onetagon_enemy_list;
        printf("%d\n", result);
    }
    return 0;
}