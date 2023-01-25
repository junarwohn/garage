# Chap.02 자료의 요약과 중요한 기술통계량들

## 2.1 도수분포와 히스토그램

- 도수(frequency)
- 도수분포(frequency distribution): 자료를 몇 개의 계급구간으로 나눈 다음 각 구간에 속하는 항목의 수를 표로 만든 것.
- 상대도수(relative frequency): 도수를 항목의 총수로 나눈 값. 이것으로 표를 만든게 도수 분포표.
- 히스토그램(histogram): 위를 그래프로 그린 것.
- 누적도수분포(cumulative frequency distribution), 누적상대도수분포(cumulative relative frequency distribution)

## 2.2 자료의 위치를 나타내는 통계량

- 평균(average, mean): 자료의 중심위치를 파악. 
- 중위수(median): 자료를 크기 순으로 정리 할 때 중간에 위치하는 값. 홀수=(n+1/2)번, 짝수=n/2번과 n+1/2번의 평균.
- 최빈값(mode): 관측된 도구가 가장 많은 값.
- 그외 백분위수(percentile), 십분위수(decile), 사분위수(quartile)

## 2.3 자료의 변동성을 나타내는 통계량

- 분산(variance): 자료의 변동성을 측정하기 위해 사용되는 것.
- 자유도(degree of freedom): 관측치의 수에서 1을 뺀 n-1, 1뺀 이유는 8장에서 공부
  - Ex) a는 넓은범위 흩어져 있고 b는 평균주변에 밀집 -> 변동성 a > b, 분산 a > b
- 표준편차(standard deviation): 분산의 제곱근, 변동성에 비례
- 평균, 분산, 표준편차 모두 평균에 먼 값, 즉 이상치(outlier)에 의해 영향을 받음
- 사분위 범위(IQR, interquartile range): IQR = Q_{3} - Q1

## 2.4 도수분포형태의 자료

## 2.5 산포도와 상관계수

- 산포도(scatter diagram): 하나의 변수를 횡축에, 그리고 다른 하나의 변수를 종축에 측정 후 각 표본점을 좌표평면 상의 점으로 나타낸 것
- 공분산(covariance):
  - s_xy=1/(n-1) ∑_(i=1)^n▒〖(X_i-X ̅)(Y_i-Y ̅)〗
  - 공분산은 부호만 의미가 있을 뿐 크기는 아무런 의미를 가지지 못함
- 상관계수(correlation coefficient): 
  - 측정단위에 따라 크기가 변하는 공분산의 단점을 보완.
  - r=s_xy/(s_x s_y )=(∑(X_i-X ̅ )(Y_i-Y ̅ ))/(√(∑(X_i-X ̅ )^2 )  √(∑(Y_i-Y ̅)^2 )) 
  - -1과 1사이의 값을 가짐. -1/1에 가까울수록 밀접한 음/양의 상관관계, 
 
