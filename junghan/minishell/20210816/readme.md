1. 환경변수 구현을 위해 일반 문자열, '' , "" 세가지 케이스로 구분
2. quo_while에서 $문자를 체크후 할당사이즈 파악
    1. check_env()함수에서 일련의 작업실행
    2. getenv로 갯수 파악 후 mini→env_len 넣어줌
3. scpy에서 구해진 환경변수 만큼 복사
    1. copy_env()함수에서 일련의 작업실행

 - 해결해야하는 부분
    $$$$ 여러번 오는 거
    할당오류