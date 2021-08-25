1. ctrl+D 들어가면 터짐
2. execve는 실패시 자식프로세스가 살아있음 성공시 자동으로 kill
    1. 고로 실패시 kill로 죽여줘야함
3. 명령을 실행 시킬때 PATH를 붙여줌.
4. Minishell안에서 minishell을 실행 시킬때 재귀적으로 실행가능하게 해줌
5. main의 envp를 execve로 상속시켜줌
6. ./minishell을 실행 시킬 때, 파라미터가 들어오는 경우 에러처리 해줌
7. "echo"함수와 옵션 "-n" 구현
8. pwd함수와 env함수 exit함수 구현
