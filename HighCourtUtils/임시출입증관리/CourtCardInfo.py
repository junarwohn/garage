from datetime import datetime

class CourtCardInfo:
    total_cards_cnt = 0
    total_left_cnt = 0
    def __init__(self):
        self.department = ""
        self.number = 0
        self.name = ""
        self.birthday = datetime.strptime("2017-06-13", "%Y-%m-%d")
        self.due_date = datetime.strptime("2017-06-13", "%Y-%m-%d")
        self.issued_date = datetime.strptime("2017-06-13", "%Y-%m-%d")
        self.tel = "010-0000-0000"
        self.is_issued = False
        CourtCardInfo.total_cards_cnt = CourtCardInfo.total_cards_cnt + 1
        CourtCardInfo.total_left_cnt = CourtCardInfo.total_left_cnt + 1
    
    def isOutDate(self):
        if datatime.now() > self.due_date:
            return False
        else :
            return True
    
    def getDueDate(self):
        return self.due_date.strftime("%Y-%m-%d")