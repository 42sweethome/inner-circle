1. 파이프라인 오류처리
    1. 맨 앞에 파이프라인이 들어오는 경우
    2. 중간에 파이프 라인이 연속으로 들어오는 경우
    3. 맨 뒤에 파이프라인이 들어오는 경우
2. 파이프 구현
    1. while문을 (파이프 + 1) 만큼 돌리며, 포크
    2. 포크 된 값의 출력을 표준출력 파이프에 담아 새 포크의 표준입력으로 넣어줌