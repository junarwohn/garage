class cq:
    def __init__(self, N):
        self.cq_ = []
        for i in range(1, N + 1):
            self.cq_.append(i)
        self.iter_ = 0
    
    def show_cq(self):
        print(self.cq_)
    
    def find_value(self, val_):
#        self.show_cq()
        val_index = self.cq_.index(val_)
        result = 0 
#        print("val_index self.iter_", val_index, self.iter_)
        cw_delta = abs(val_index - self.iter_)
        ccw_delta = len(self.cq_) - cw_delta
        self.iter_ = val_index
        self.pop()
        if cw_delta < ccw_delta:
            return cw_delta
        else:
            return ccw_delta

    def pop(self):
        self.cq_.remove(self.cq_[self.iter_])
        if len(self.cq_) == self.iter_:
            self.iter_ -= 1

nm = list(map(int, input().split()))
num = list(map(int, input().split()))
R = 0
circular_queue = cq(int(nm[0]))
for i in range(nm[1]):
    R += circular_queue.find_value(num[i])
print(R)
