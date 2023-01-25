#include <stdio.h>
typedef struct cro {
    char alpha[4];
    int len;
    int check;
} Cro;

int det_check(Cro * list_) {
    int result = 0;
    for (int i = 0; i < 8; i++) {
        if (list_[i].check != 0) {
            result++;
        }
    }
    return result;
}

int det_index(Cro * list_) {
    for (int i = 0; i < 8; i++) {
        if (list_[i].check != 0) {
            return i;
        }
    }
}
int main(void) {
    Cro cor_list[8] = {"c=", 2, 0, "c-", 2, 0, "dz=", 3, 0, "d-", 2, 0, "lj", 2, 0, "nj", 2, 0, "s=", 2, 0, "z=", 2, 0};
    char cmd[101];
    int num_of_words = 0;
    scanf("%s", cmd);
    for (int start_index = 0; cmd[start_index] != '\0'; ){
        for (int i = 0; i < 8; i++) {
            cor_list[i].check = 0;
            if (cmd[start_index] == cor_list[i].alpha[0]) {
                cor_list[i].check++;
            }
        }
        for (int cmd_index = 1; cmd_index < 3 && cmd[start_index + cmd_index] != '\0'; cmd_index++) {
            for (int cor_list_index = 0; cor_list_index < 8; cor_list_index++) {
                if (cor_list[cor_list_index].check == 0) {
                    continue;
                } else {
                    if (cor_list[cor_list_index].alpha[cmd_index] == cmd[start_index + cmd_index]) {
                        cor_list[cor_list_index].check++;
                    } else {
                        cor_list[cor_list_index].check = 0;
                    }
                }
            }
            int det = det_check(cor_list);
            if (det == 1) {
                int find_index = det_index(cor_list);
                if (cor_list[find_index].len == cor_list[find_index].check) {
                    num_of_words++;
                    start_index += find_index;
                    printf("found %d : %c to %d : %c\n", start_index, cmd[start_index], start_index + find_index, cmd[start_index + find_index]);
                    break;
                } else {
                    num_of_words++;
                    start_index++;
                    break;
                }
            } else if (det == 0) {
                num_of_words++;
                start_index++;
                break;
            }
        }
    }
    // for (int i = 0; i < 8; i++) {
    //     printf("%s %d\n", cor_list[i].alpha, cor_list[i].len);
    // }
    printf("%d", num_of_words);
    return 0;
}