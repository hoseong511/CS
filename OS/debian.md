## **CentOS과 Debian**

![centos vs debian](https://www.openlogic.com/sites/default/files/image/2021-02/image-blog-openlogic-centos-vs-debian%20%281%29.png)

- 센토스 : RHEL[^RHEL]의 소스를 가져와 그대로 배포한것이 센토스 (리눅스는 [GPL](https://hoseong511.github.io/CS/OS/license1)이고, 해당 라이선스 특성상 Redhat사 RHEL은 그대로 GPL 라이선스 적용) 

- 데비안 : 메이저 GNU/리눅스 배포한 중 거의 유일하게 비자유 소프트웨어를 적극적으로 배제하는 배포판이다. 의도적으로 비자유 소프트웨어를 포함하지 않았다.   

- 센토스는 2014년 1월[^official1]에 레드햇 사가 인수하고, 2020년 12월 [^official2] centOS stream 선언([참고](http://www.opennaru.com/linux/centos-%EC%A2%85%EB%A3%8C/)). 사실상 온전한 RHEL을 무료로 사용할 수 있다는 장점이 사라진 상태.   

- 데비안은 기존의 특성 그대로 꾸준히 안정성을 추구지만 자발적으로 참여하는 커뮤니티이기에 배포하는 업데이트 주기가 길다는 단점이 있다. 

- 센토스는 RPM 패키지 형식과 YUM/DNF를 패키지 관리자로 이용

- 데비안은 DEB 패키지 형식과 dpkg/APT를 패키지 관리자로 이용

- 둘 다 네트워크 기반 리포지토리 지원, 디펜더시 검사 및 해결 등을 포함한 패키지 관리 기능을 제공함. 둘 간에 약간의 차이는 있지만 크게 다르지는 않다. 기능이 유사함.

## **Debian**
- 데비안 프로젝트가 개발한 free software 컴퓨터 운영체제이다.

- 리눅스 커널 [^kernel]을 탑재한 데비안 GNU/리눅스, GNU허드[^GNUhud]커널을 탑재한 데비안 GNU/허드, FreeBSD[^FreeBSD] 커널을 탑재한 데비안 GNU/KFreeBSD, NetBSD 커널을 탑재한 데비안 GNU/NetBSD 등으로 나뉘며 현재 이 가운데 정식판이 존재하는 것은 리눅스 커널에 기반한 **데비안 GNU/리눅스 뿐**.

- 데비안의 특징은 패키지 설치와 업그레이드가 단순함.

- 데비안은 네트워크 결합 스토리지부터 전화기, 노트북, 데스크탑 및 서버까지 다양한 하드웨어에서 사용할 수 있음.

- 데비안은 안정성과 보안에 중점을 두며 사용자 편리성이 강한 우분투 등 다른 많은 리눅스 배포판의 기반으로 쓰이고 있음.
	
## **Reference**	
- [https://www.debian.org/CD/faq/](https://www.debian.org/CD/faq/)
- [centos vs debian 1](https://www.openlogic.com/blog/centos-vs-debian)
- [centos vs debian 2](https://1gbits.com/blog/debian-vs-centos/)
<br>

[^official1]: redhat 공식 원문 [링크](https://www.redhat.com/ko/about/press-releases/red-hat-and-centos-join-forces)

[^official2]: centos 공식 원문 [링크](https://blog.centos.org/2020/12/future-is-centos-stream/)

[^kernel]: CS에서 커널은 컴퓨터 운영 체제의 핵심이 되는 컴퓨터 프로그램으로, 시스템의 모든 것을 완전히 통제한다. 운영 체제의 다른 부분 및 응용 프로그램 수행에 필요한 여러 가지 서비스를 제공한다.

[^GNUhud]: GNU허드는 운영체제용 커널 중 하나이며, 맨 밑에 마이크로커널이 있고 그 위에서 몇 개의 서버 및 데몬이 돌아가는 형태를 가지며 기능, 보안 ,안정 면에서 원조 유닉스 커널보다 나으면서 원조 유닉스 커널과의 호환성까지 뛰어난 커널을 지향함.

[^FreeBSD]: BSD 계열의 오픈 소스 운영 체제로서, 버클리 대학교 CSRG의 4.4BSD 라이트를 바탕으로 개발, 

[^RHEL]: Red Hat Enterprise linux. 레드햇에서 기존 리눅스(배포판 페도라) + 오픈소스 소프트웨어를 잘 버무려 개발한 리눅스 배포판. 최신버전은 8. 참고로 RHEL은 리눅스 서버 시장 1인자. 기술지원 있고 레드햇 사는 기술지원비로 먹고 산다.
