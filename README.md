# auto_regulator

# 아두이노 겨울 프로젝트

---

1월8일~2월 5일

토요일: 1~2시, 동아리방

### 프로젝트 계획

---

**자동 수위 조절 장치** 

준비물: 수위센서, 아두이노, 점퍼선(암-수, 브레드보드용), 브레드보드, 우노용 USB 케이블, 저항

(브레드보드는 작은 것보다 큰 것이 편리한 것 같습니다.) 

- Arduino Raindrop sensor module(비, 눈 감지 센서)
    
    코드: [How to use the Raindrops sensor module with Arduino - Ardumotive Arduino Greek Playground](https://www.ardumotive.com/how-to-use-the-raindrops-sensor-moduleen.html)
    
    가격은 1800원 정도. 
    
    https://mechasolution.com/shop/goods/goods_view.php?goodsno=8935&category=
    
    코드
    
    https://m.blog.naver.com/roboholic84/220952348872
    
    [https://arduinosensors.tistory.com/entry/빗물-감지-MH-RD-아두이노-센서](https://arduinosensors.tistory.com/entry/%EB%B9%97%EB%AC%BC-%EA%B0%90%EC%A7%80-MH-RD-%EC%95%84%EB%91%90%EC%9D%B4%EB%85%B8-%EC%84%BC%EC%84%9C)
    
- 수위센서
    
    수위센서(비접촉): https://mechasolution.com/shop/goods/goods_view.php?goodsno=8801&category=002 
    
    수위센서(접촉):https://eduino.kr/product/detail.html?product_no=106&gclid=EAIaIQobChMI4I-ss8CP9QIVVj5gCh3SqADmEAYYAiABEgIdK_D_BwE
    
    *비접촉vs 접촉 
    
    접촉을 사용하면 센서에 남아있는 물때문에 오차 발생, 수시로 물기 제거를 해야함. 위생 문제 
    
    비접촉 사용을 권하지만 가격이 비쌈.
    
    비접촉 수위 센서 사용 방법
    
    https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=roboholic84&logNo=220556544245
    
    https://kocoafab.cc/tutorial/view/335
    
- 1602 LCD (I2C제어)
    
    시리얼 모니터에 나타나는 값(ex. Raining )을 나타내기 위해 LCD를 사용해도 좋을 듯 함. 
    
    또는 LED, 도트 매트릭스 등도 현재 상태 표시하는 데에 사용해도 좋을듯. 
    
    코드 예제: [[아두이노 강좌] LCD 1602(16x2) 4핀(I2C제어) 디스플레이 모듈 : 네이버 블로그 (naver.com)](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=eduino&logNo=220878435158)
    
    [아두이노 예제 12. LCD에 글자 표시하기 - 코딩런 (codingrun.com)](https://codingrun.com/112)
    
- 모터
    
    모터를 이용해 제설제 창고 open, 수로 open 등 기능 수행 가능할듯. 
    
    코드 예시: [아두이노 예제 11. 모터 제어하기 - 코딩런 (codingrun.com)](https://codingrun.com/111)
    
    코드 예시:
    
    [아두이노 강좌 #30 Servo 라이브러리 기본 사용법::Blacklog (tistory.com)](https://juahnpop.tistory.com/123)
    
    #include <Servo.h>
    
    Servo servo;
    
    void setup(){
    servo.attach(10);
    }
    
    void loop(){
    servo.write(0);
    delay(1000);
    servo.write(180);
    delay(1000);
    
    exit(0); //강제종료 
    }
    

물감지: 수위 조절 센서 바닥에 설치

물이 감지되면 4자리 7세그먼트에 수위 표시

접촉식 수위 센서 코딩: https://m.blog.naver.com/boilmint7/221979230749

눈감지: 온도센거 바닥에 설치

눈이 바닥에 쌓이면 눈이 센서에 접촉되어 온도를 낮춤-이때 서브모터작동

접촉식 온도 센서 코딩법: https://m.blog.naver.com/wlsepdb/222174751799

필요한것: 수위센서, 온도센서, 서브모터, 4자리 7 세그먼트, 아두이노 키트

https://blog.naver.com/roboholic84/220952348872 //lcd와 강우량 센서

[로직]

수위조절과정: 물 감지 (강우량 센서) -도트 세그먼트(or 4x세그먼트)에 수위 표시 - 기준 이상 -  수로 open - 기준 이하 - 수로 closed

제설 과정: 눈 감지 (온도 센서) -  눈 감지 반복 (특정 횟수 지정) - 제설제 창고 open or 온도 조절 센서   

[최종 준비물]

- 아두이노
- 점퍼선(암-수, 브레드보드용)
- 우노용 USB 케이블
- 브레드보드
- 저항
- **raindrops sensor(강우량 센서)**
- 도트 매트릭스(or  4x세그먼트)
- 서보모터 *2

- 구매 링크
    
    강우량 센서: https://mechasolution.com/shop/goods/goods_view.php?goodsno=8935&category=
    
    점퍼선: 동아리방
    
    브레드보드: 작은 브레드보드를 여러개 구매해서 사용 or 큰 브레드 보드 구매 
    
    저항: 동아리 방에 두 종류는 있음 ( 근데 몇 옴 인지는 기억 x)
    
    아두이노 키트 :https://mechasolution.com/shop/goods/goods_view.php?goodsno=582896&category=
    
    구매 시 저항, 점퍼선, 우노용 usb 케이블, 도트 매트릭스(or  4x세그먼트), 수위센서(눈/비 센서와 다름), 서보모터(동방에 더 있음) 모두 포함됨.
    

---

[프로젝트 과정 ](https://www.notion.so/63292920ad00414f8c07d5350777b3e6?pvs=21)
