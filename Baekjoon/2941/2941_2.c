#include <stdio.h>
char cro_list[8][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int cro_cmp(char * input_cmd_, int cmd_start_index_, char * cro_ele_) {
    // return -1 when end of cmd_, 0 to none, len_of_cor_ele to equal
    int len_of_cor_ele = 0;
    while (cro_ele_[len_of_cor_ele] != '\0')
        len_of_cor_ele++;
    for (int i = 0; i < len_of_cor_ele; i++) {
        if (input_cmd_[cmd_start_index_ + i] != cro_ele_[i])
            return 0;
        if (input_cmd_[cmd_start_index_ + i] == '\0')
            return -1;
    }
    return len_of_cor_ele;
}

int find_cro(char * input_cmd_, int cmd_start_index_) {
    int result = 0;
    for (int i = 0; i < 8; i++) {
        if ((result = cro_cmp(input_cmd_, cmd_start_index_, cro_list[i])) > 0) {
            return result;
        }
    }
    return 0;
}

int main(void) {
    char input_cmd[101];
    int num_of_words = 0;
    scanf("%s", input_cmd);
    for (int input_cmd_index = 0; input_cmd[input_cmd_index] != '\0';) {
        int result = find_cro(input_cmd, input_cmd_index);
        if (result > 0) {
            input_cmd_index += result;
        } else {
            input_cmd_index++;
        }
        num_of_words++;
    }
    printf("%d", num_of_words);
    return 0;
}