1. 첫번째 인자에 $환경변수 출력시 출력오류
    1. 애초에 받아줄 때, 인자가 null인경우 넘겨서 할당
    2. 전부 다 받은 뒤, 받은 인자를 검사해서 명령어의 위치를 변경
2. odd_quo가 1 일때 buf가 해제되는 부분이 구현되어 있지않음.
3. parsing함수에서 cmd_ret의 값이 -1일 경우 에러처리가 되어있지 않음
4. check_path함수에서 execve를 사용하는 경우 해제해야하나? (통일성)
5. get_path함수에서 중복할당되는 현상해결
6. cd명령어만들기
    1. 00
7. export, unset명령어 만들기
    1. export명령어를 만들던 도중, 오류
        1. 값이 없는 변수를 export로 등록한 경우, export명령어로 인덱싱할 수 없음.
        2. envp를 수정 혹은 export "=" 기능 구현 시 삽입해줘야함.
