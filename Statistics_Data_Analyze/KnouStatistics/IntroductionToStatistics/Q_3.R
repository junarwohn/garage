player_A = c(198, 119, 174, 235, 134, 192, 124, 241, 158, 176)
player_B = c(196, 159, 162, 178, 188, 169, 173, 183, 177, 152)
summary(player_A)
summary(player_B)
var.test(player_A, player_B)
t.test(player_A, player_B)
# H_0 : u_1 - u_2 = 0, H_1 : u_1 - u_2 != 0
comparison_function = function(data_1_, data_2_) {
    D_0 = 0
    S_P_2 = ((length(data_1_) - 1)*var(data_1_) + (length(data_2_) - 1)*var(data_2_)) / (length(data_1_) + length(data_2_) - 2)
    tested_value = (mean(data_1_) - mean(data_2_) - D_0) / sqrt(S_P_2/length(data_1_) + S_P_2/length(data_2_))
    if (abs(tested_value) > qt(0.025, length(data_1_) + length(data_2_) - 2)) {
        print("H0 rejected")
    }
}
comparison_function(player_A, player_B)