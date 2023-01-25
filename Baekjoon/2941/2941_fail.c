#include <stdio.h>
int main(void) {
    char kro_list[8][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="}; 
    char kro_input[101];
    int num_result = 0;
    scanf("%s", kro_input);
    int find_index = 0;
    int find_list[8] = {1,1,1,1,1,1,1,1};
    for (int k_index = 0; kro_input[k_index] != '\0';) {
        if (find_index == 0) {
            for (int i = 0; i < 8; i++) {
                find_list[i] = 1;
            }
        }
        for (int i = 0; i < 8; i++) {
            if (kro_input[k_index + find_index] != kro_list[i][find_index]){
                find_list[i] = 0;
            }
        }
        int det = 1;
        for (int i = 0; i < 8; i++){
            printf("%d", find_list[i]);
            det *= !find_list[i];
        }
        printf("\n");
        if (det) {
            switch(find_index){
                case 0:
                case 1:
                    k_index++;
                    num_result++;
                    find_index = 0;
                    break;
                case 2:
                    if (kro_input[k_index + find_index - 1] == 'z'){
                        k_index++;
                    } else {
                        k_index += 2;
                    }
                    num_result++;
                    find_index = 0;
                    break;
            }
        } else {
            find_index++;
        }
    }
    printf("%d", num_result);
    return 0;
}