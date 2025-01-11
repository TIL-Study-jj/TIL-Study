# TIL-Study
TIL 기록을 위한 레포입니다.


# Notice
스터디 참여 방식, 깃허브 사용법에 대한 가이드입니다.


# RULE
1. 자료는 상세하게 작성하기 ( 글만 읽어도 이해할 수 있게 )
2. 소스코드 역시 주석 달아두기 ( 나중에 보기 편하도록 )

# PR 가이드
1. 이 레포를 본인 깃허브 계정으로 fork 한다.
2. fork 한 레포를 클론한다. `git clone [레포 클론 주소]` 사용
3. `git remote -v`를 통해 먼저 연결된 원격 저장소를 확인한다.

  - 보통 다음과 같이 되어있을 것
  ```
  origin  https://github.com/nx006/algorithm-study.git (fetch)
  origin  https://github.com/nx006/algorithm-study.git (push)
  ```
  - `git remote add upstream https://github.com/TIL-Study-jj/TIL-Study.git`를 입력하여 원격 저장소에 원본 저장소를 추가한다.
  
  - 그러면 다음과 같이 된다.
  ```
  origin  https://github.com/nx006/algorithm-study.git (fetch)
  origin  https://github.com/nx006/algorithm-study.git (push)
  upstream https://github.com/TIL-Study-jj/TIL-Study.git (fetch)
  upstream https://github.com/TIL-Study-jj/TIL-Study.git (push)
  ```
  - 참고로 origin과 upstream은 변수명.
  - 여기에 원격 레포지토리 주소를 변수로써 저장한다는 뜻

4. 매번 새로 들어올 때마다, `git fetch upstream`을 통해 원본 저장소와 내 포크한 레포를 동기화시켜주는 것이 좋다.

  - `fetch` 는 이후에 `merge` 과정을 거쳐야 하는데, fetch+merge를 합친 명령어로 `pull`이 있다.
  - `git pull upstream main`해서 원본 저장소의 main 레포지토리를 pull 한다.
  - 참고로 이 pull 과정을 안 했을시 이후에 merge conflict 등 다양한 문제가 발생할 수 있어서, 꼭 pull을 해주는 것이 좋다.
  - `git pull upstream submit`도 해서 submit도 동기화시켜주자.
5. 본인 github 아이디 폴더를 새로 생성한 후 해당 폴더에서 작업을 열심히 마무리하고서, `git add [파일명]`을 통해 변경사항이 들어있는 파일을 스테이징 아리아로 옮긴다.

  - `git add .`를 하면 모든 변경된 파일이 스테이징 아리아에 올라간다.
6. `git commit -m [커밋메시지]`로 스테이징된 파일들을 로컬 레포지토리로 옮긴다.
7. `git push origin`으로 원격 레포지토리에 푸시한다.
  - 참고로 이때 origin 뒤에 브렌치 이름을 붙인다면 해당 브랜치로 푸시된다.
  - 예를 들어 `git push origin wltjd0620`라 하면 wltjd0620라는 브랜치로 푸시됨
  - upstream으로 푸시 금지

8. 이후에 github.com으로 가서 변경사항을 확인 후 `Create Pull Request`를 눌러 `pull request`를 생성해준다.
9. merge conflict가 나는지 확인한 후에, submit 브랜치에 PR을 생성한다.
10. 방장한테 PR 올렸다고 말하기



 # 참고자료
 B612 Algorithm Study : https://github.com/HongikB612/algorithm-study
