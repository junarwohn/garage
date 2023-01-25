import requests
import re
import json
import datetime
import time
import copy
import telegram

class storeInfo:
    rotation_cycle = [1, 2, 3, 4, 0]
    unavailable_status = ['empty', 'break']
    def __init__(self, api_url, bot_token, chat_info, enable_5_rotation, enable_weekend):
        
        self.api_url = api_url 
        self.bot_token = bot_token 
        self.chat_info = chat_info 
        self.enable_5_rotation = enable_5_rotation
        self.enable_weekend = enable_weekend
        self.bot = telegram.Bot(token=self.bot_token)
        self.info = {}

        now_info = requests.get(self.api_url).json()['stores']
        for info in now_info:
            name = info['name']
            self.info[name] = {}    
            self.info[name]['created_at'] = ""
            self.info[name]['remain_stat'] = ""
            self.info[name]['stock_at'] = ""
        

    def update(self):
        now_info = requests.get(self.api_url).json()['stores']
        for info in now_info:
            print(info)
            name = info['name']

            if info['remain_stat'] != self.info[name]['remain_stat']:
            # if True:
                self.info[name]['remain_stat'] = info['remain_stat']
                self.info[name]['created_at'] = info['created_at']

                if self.info[name]['remain_stat'] in storeInfo.unavailable_status and False:
#                 if False:
                    pass
                else:
                    for chat in self.chat_info:
                        # mon 0 sun 6
                        today = datetime.datetime.today().weekday()
                        rotation5 = storeInfo.rotation_cycle.index(int(chat['birth'][-1]) % 5)
                        if today == rotation5 or (today < 5 and not self.enable_5_rotation) or (today >= 5 and self.enable_weekend):
                            msg = f"{info['name']} : {info['remain_stat']} {info['created_at']} {chat['birth']}"
                            self.bot.sendMessage(chat_id=chat['chat_id'], text=msg)

if __name__ == "__main__":
    with open("./api_url.txt", "r") as f:
        api_url = f.read()
    
    with open("./bot_token.txt", "r") as f:
        bot_token = f.read()
    
    with open("./chat_info.json", "r") as f:
        chat_info = json.load(f) 
       
    REFRESH_INTERVAL = 15 * 60
    
    print("Only alarm by alternative 5 day system? Y / N(all weekday)")
    while True:
        enable_5_rotation = input().lower()
        if enable_5_rotation == 'y':
            enable_5_rotation = True 
            break
        elif enable_5_rotation == 'n':
            enable_5_rotation = False 
            break
        else:
            print("Wrong input. Input between Y/N")
 
    print("Enable alarm in weekend? Y / N")
    while True:
        enable_weekend = input().lower()
        if enable_weekend == 'y':
            enable_weekend = True
            break
        elif enable_weekend == 'n':
            enable_weekend = False
            break
        else:
            print("Wrong input. Input between Y/N")
    
    store_info = storeInfo(api_url=api_url, bot_token=bot_token, chat_info=chat_info, enable_5_rotation=enable_5_rotation, enable_weekend=enable_weekend)

    while True:
        if (8 <= datetime.datetime.now().hour < 20):
#         if True:
            store_info.update()
            time.sleep(REFRESH_INTERVAL)
        else:
            now = datetime.datetime.today()
            future = datetime.datetime(now.year, now.month, now.day, 8, 0)
            future += datetime.timedelta(days=1)
            time.sleep((future - now).seconds)
