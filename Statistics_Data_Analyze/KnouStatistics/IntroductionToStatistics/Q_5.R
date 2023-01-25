corp_A <- c(69, 67, 65, 59, 68, 61, 66)
corp_B <- c(56, 63, 55, 59, 52, 57, NA)
corp_C <- c(71, 72, 70, 68, 74, NA, NA)

# H0 : u_A = u_B = u_C
# H1: Not H0

y <- c(corp_A, corp_B, corp_C)
n <- rep(length(corp_A), 3)
group <- rep(1:3, n)
group_df <- data.frame(y, group)
group_df <- transform(group_df, group = factor(group))
sapply(group_df, class)
tapply(y, group, summary)
summary(aov(y ~ group, data = group_df))
a = aov(y ~ group, data = group_df)
F_value = summary(a)[[1]][["F value"]][[1]]
F_005 = 3.68232
if (F_value > F_005) {
    print("H0 rejected")
} else {
    print("No difference")
}