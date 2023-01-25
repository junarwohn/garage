import re

class DailySituationReport:
    # day_of_week = -1
    # time = ""
    # room = ""
    # content = ""
    # trial_info = ""
    # department = ""
    # special_event = ""
    # parsing_check_list = []
    # content_check_list = {'day_of_week':False, 'time':False, 'room':False, 'content':False, 'trial_info':False, 'department':False, 'etc':False}

    def __init__(self, day_of_week_, day_total_info):
        self.day_of_week = -1
        self.time = ""
        self.room = ""
        self.content = ""
        self.trial_info = ""
        self.department = ""
        self.special_event = ""
        self.parsing_check_list = []
        self.content_check_list = {'day_of_week':False, 'time':False, 'room':False, 'content':False, 'trial_info':False, 'department':False, 'etc':False}

        # self.day_of_week = day_of_week_
        # # print(day_total_info)
        day_infos = day_total_info.split('\n')
        # self.content_check_list['day_of_week'] = False
        # self.content_check_list['time'] = False
        # self.content_check_list['room'] = False
        # self.content_check_list['content'] = False
        # self.content_check_list['trial_info'] = False
        # self.content_check_list['department'] = False
        # self.content_check_list['etc'] = False
        # print("========================")
        # print(day_infos)
        # print("************************")
        for n in range(len(day_infos)):
            self.parsing_check_list.append(False)
        
        # print(self.content_check_list)
        for line_index in range(len(day_infos)):
            # find time
            # print("++++++")
            # print(day_infos[line_index])
            if self.content_check_list['time'] == False:
                regex = re.compile(r'\d\d:\d\d')
                time_candi = regex.search(day_infos[line_index])
                if time_candi != None:
                    self.time = time_candi.group()
                    self.content_check_list['time'] = True
                    self.parsing_check_list[line_index] = True
                else:
                    regex = re.compile(r'\d:\d\d')
                    time_candi = regex.search(day_infos[line_index])
                    if time_candi != None:
                        self.time = time_candi.group()
                        self.content_check_list['item'] = True
                        self.parsing_check_list[line_index] = True
            # find room
            if self.content_check_list['room'] == False:
                regex = re.compile(r'\d\d\d호')
                room_candi = regex.search(day_infos[line_index])
                if room_candi != None:
                    self.room = room_candi.group()
                    self.content_check_list['room'] = True
                    self.parsing_check_list[line_index] = True
                else:
                    regex = re.compile(r'\d\d호')
                    room_candi = regex.search(day_infos[line_index])
                    if room_candi != None:
                        self.room = room_candi.group()
                        self.content_check_list['room'] = True
                        self.parsing_check_list[line_index] = True
            # find trial_info
            if self.content_check_list['trial_info'] == False:
                # print("--------")
                # print(day_infos[line_index])
                trial_info_regex_list = []
                trial_info_regex_list.append(re.compile(r'\d\d\d\d\w\w\d\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\d\d\w\w\s\d\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\d\d\w\w\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\d\d\w\w\s\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\d\d\w\w\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\d\d\w\w\s\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\d\d\w\d\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\d\d\w\s\d\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\d\d\w\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\d\d\w\s\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\w\w\d\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\w\w\s\d\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\w\w\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\w\w\s\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\w\d\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\w\s\d\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\w\d\d\d'))
                trial_info_regex_list.append(re.compile(r'\d\d\w\s\d\d\d'))
                for regex_ in trial_info_regex_list:
                    trial_info_candi = regex_.search(day_infos[line_index])
                    # print("=========================================")
                    # print(day_infos[line_index])
                    # print("*****************************************")
                    if trial_info_candi != None:
                        # print("=========================================")
                        # print(day_infos[line_index])
                        # print("*****************************************")
                        self.trial_info = trial_info_candi.group()
                        self.content_check_list['trial_info'] = True
                        self.parsing_check_list[line_index] = True
                        break
            if self.content_check_list['department'] == False:
                department_regex_list = []
                department_regex_list.append(re.compile(r'(\d\d단독)'))
                department_regex_list.append(re.compile(r'(\d단독)'))
                department_regex_list.append(re.compile(r'(\d\d부)'))
                department_regex_list.append(re.compile(r'(\d부)'))
                for regex_ in department_regex_list:
                    department_candi = regex_.search(day_infos[line_index])
                    if department_candi != None:
                        self.department = department_candi.group()
                        self.content_check_list['department'] = True
                        self.parsing_check_list[line_index] = True
                        break
            if self.content_check_list['etc'] == False:
                regex_ = re.compile(r'\s접수')
                etc_candi = regex_.search(day_infos[line_index])
                if etc_candi != None:
                    # print(etc_candi.group() + "etc....")
                    self.content_check_list['etc'] = True
                    self.parsing_check_list[line_index] = True

            if day_infos[line_index].find('*') != -1 or day_infos[line_index].find('※') != -1:
                self.special_event = self.special_event + day_infos[line_index]
                self.parsing_check_list[line_index] = True


        for line_index in range(len(day_infos)):
            if self.parsing_check_list[line_index] == False:
                self.content = self.content + day_infos[line_index]
                
    
    def print(self):
        str_ = ""
        try:
            self.parsing_check_list.index(True)
            str_ = self.time + " " + self.room + " " + self.content + " " + self.trial_info + " " + self.department + " " + self.special_event
            return str_
        except:
            return str_
    def compare(self, dsr_cmp):
        if self.time < dsr_cmp.time:
            return -1
        else:
            return 1