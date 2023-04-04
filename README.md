## 1. 프로그램 제작 동기 <br>
### 	가. 내 입맛에 맞는 뽑기 프로그램 만들기 <br>
### 	나. MLX 그래픽 라이브러리 연습 <br>

## 2. 작동 방식 <br>
### 	가. txt_to_array : 뽑아야 하는 명단이 들어간 텍스트 파일에서 명단을 추출하여 char 배열로 구성 <br>
### 	나. draw_title : 추출된 명단을 이용하여 뽑기 프로그램 대문을 그린다 <br>
### 	다. keyboard_hook : 화면에서 지정된 위치에서 키보드 입력을 감지하면 그에 맞는 행동을 취한다 <br>
### 	라. random_select : 선형합동법을 이용하여 명단에서 무작위로 대상을 뽑는다 <br>
### 	마. draw_selected_user : 뽑힌 대상을 알 수 있게 화면에 대상의 명칭을 표시한다 <br>
### 	바. draw_char : 명단의 각 문자를 분석하여 문자의 형태에 맞게 정형화하여 이미지 버퍼에 넣어준다 <br>

## 3. 개념 설명 <br>
### 	가. 선형합동법 : 무작위로 대상을 뽑을 시 사용할 난수 추출법 <br>
#### 		ㄱ. 점화식 : Xn+1 = (a * Xn + c) % m <br>
#### 		ㄴ. 조건 : c와 m은 서로소이어야 한다, a - 1이 m의 모든 소인수로 나뉘어져야 한다, m이 4의 배수일 경우, a - 1도 4의 배수여야 한다 <br>
### 	나. 문자 정형화 <br>
#### 		ㄱ. 모든 문자는 화면에 할당된 범위 내에서 사전에 정의된 비율을 통해 문자 크기를 잡는다 <br>
#### 		ㄴ. 각 문자는 변환된 이미지 파일을 읽어서 변환 <br>
#### 		ㄷ. 변환된 내용물을 이미지 버퍼에 삽입 <br>
