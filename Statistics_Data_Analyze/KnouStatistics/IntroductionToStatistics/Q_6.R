mid_x <- c(92, 65, 75, 83, 95)
mid_y <- c(87, 71, 75, 84, 93)
# id <- rep(1:5, 1)

score <- data.frame(mid_x, mid_y)
# print(score)
# var.test(mid_x, mid_y)
out=lm(mid_y~mid_x,data=score)
summary(out)