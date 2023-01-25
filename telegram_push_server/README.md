# mask_telegram_push

마스크 재고 알림 푸시

아직 실사용을 안해봐서 오류가 있을 수 있으니 참고용으로만 사용권장.

- 기능

마스크 재고 확인과 사용자의 생년 확인 후 재고 변경시 telegram 알림

5부제로 알림 or 주중 알림 설정가능

주말알림 설정가능

아침 8시부터 저녁 8시까지만 알림

텔레그램으로 상호작용 X

DB X



- 구성 및 사용방법

의존 패키지 설치

    pip3 install requests python-telegram-bot

https://app.swaggerhub.com/apis-docs/Promptech/public-mask-info/20200307-oas3#/

제공되는 api 자체가 너무 훌륭함. 

위도, 경도, 반경을 넘겨주면 알아서 마스크 판매처를 찾아서 전송해준다.

    GET ​/storesByGeo​/json

참고해서 본인 위치와 반경 입력후 나온 주소를 api_url.txt 에 저장.

텔레그램 봇 생성 후 토큰을 bot_token 에 저장

본인의 chat id 와 생년을 {"chat_id" : "CHAT_ID", "birth" : "XXXX"} 형식으로 chat_info.json에 저장 (여러명 가능, 그러나 같은 판매처의 재고 알림)

main.py로 python script 실행 후 

1. 5부제 알림 / 주중 알림
2. 주말 알림

여부 체크 후 초기설정값 15분 sleep후 반복 실행.