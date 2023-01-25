# H_0 : u = 3, H_1 : u < 3
tar_data <- c(3, 3, 1, 1, 0.5, 2, 2, 4, 5, 4, 5, 3, 1, 3, 1, 4, 1, 1, 4, 2, 5, 3, 1, 1, 1, 0.75, 1.5, 3, 3, 2)
hypo_test_function <- function(data_set_, x_) {
    mean_of_data_ = mean(data_set_)
    sd_of_data_ = sd(data_set_)
    n_of_data = length(data_set_)
    t_ = ((mean_of_data_ - x_) / sd_of_data_) * sqrt(n_of_data)
    return (t_)
}

T = hypo_test_function(tar_data, 3)
rejection_region = qt(0.05, 29)
if (rejection_region > T) {
    print("We can say that population average is less than 3%")
} else {
    print("Hypothesis rejected")
}
