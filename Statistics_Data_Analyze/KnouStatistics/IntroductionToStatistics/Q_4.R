pre_accident_data <- c(8, 12, 5, 4, 6, 3, 4, 3, 2, 6, 6, 9)
post_accident_data <- c(5, 3, 2, 1, 4, 2, 2, 4, 3, 5, 4, 3)

# H0 : u_pre = u_post
# H1 : u_pre > u_post

delta_data = pre_accident_data - post_accident_data
mean_delta = mean(delta_data)
sd_delta = sd(delta_data)

st = (mean_delta - 0) / (sd_delta / sqrt(length(pre_accident_data)))

if (st > qt(0.05, 11)) {
    print("H0 rejected")
} else {
    print("Accepted")
}
