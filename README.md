## Lotto 6/45 시뮬레이터

### 소개

- Lotto 6/45 게임 (한국 로또에서 착안)

- 선택 과정

    - 1에서 45까지의 숫자 세트 중 6개의 고유한 숫자를 선택합니다.

- 규칙

  - 동일한 풀에서 6개의 당첨 번호가 추첨됩니다.

  - 일치하는 숫자 수에 따라 상금이 수여됩니다

    - 6개 일치: 1등 상

    - 5개 일치: 2등 상
    
    - 4개 일치: 3등 상
    
    - 3개 일치: 4등 상

- 비용 및 상금

  - 참가비: 게임당 1,000원

  - 1등 상: 10억 원
  
  - 2등 상: 100만 원
  
  - 3등 상: 5만 원
  
  - 4등 상: 5천 원

### 게임 모드

- 단일 게임 모드 (키보드 입력)

  - 1에서 45 사이의 고유한 숫자 6개를 한 줄에 입력, 공백으로 구분, 또는 'A'를 입력하여 6개의 무작위 숫자를 선택, 유효하지 않은 입력은 적절히 처리, 게임 종료 옵션 제공

  - 표시 내용: 사용자의 선택 번호, 당첨 번호, 수상 상금

- 단일 게임 모드 (파일 입력)

  - 텍스트 파일 이름으로 입력, 잘못된 파일 이름은 처리, 각 줄은 6개의 고유한 숫자 또는 무작위 선택을 위한 'A'를 포함, 잘못된 형식의 줄은 무시, 게임 종료 옵션 제공

  - 표시 내용: 사용자의 선택 번호, 당첨 번호, 게임당 수상 상금

- 다중 게임 시뮬레이션 모드

  - 출력 파일 이름과 플레이 횟수 입력 (범위: 1,000에서 1,000,000), 범위를 벗어난 값은 처리됨, 각 플레이마다 무작위 선택 생성

  - 각 플레이에 대한 표시 내용: 사용자의 선택 번호, 당첨 번호, 수상 상금

  - 요약: 각 상금의 획득 횟수, 총 지출 금액, 총 수익 금액