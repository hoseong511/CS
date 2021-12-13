# KDump-tools   
구동 중인 OS가 갑자기 kernel panic등으로 crash되었을 때, kdump를 이용하면 crash되었을 때, memory를 file로 dump할 수 있다. system log 등에 아무런 기록이 없을 때, kdump 파일은 문제 원인을 파악하는데 도움됨.

### kernel crash의 원인
- crash는 kernel이 스스로 제어/복구 할 수 없는 상황이 되었을 때, 발생함.
- kernel이 error를 감지했을 때, Linux의 경우 kernel panic이 되고, hang/reboot 되는것
- RAM 불량 : 메모리가 물리적으로 불량인 경우
- 그 밖의 장치 문제 : 하드웨어 관련된 문제. 물리적인 불량일 경우도 있지만, 하드웨어를 지어하는 firmware/driver의 문제일 수 도 있다.
- 소프트웨어 이슈 : kernel이나 그 Module, 혹은 특정 process의 버그(문제)일 수도 있다.

### To automate some of the necessary boot-time steps.
1. `sudo apt install kdump-tools`
1. 

### **Reference**
- [https://superuser.com/questions/280767/how-can-i-enable-kernel-crash-dumps-in-debian](https://superuser.com/questions/280767/how-can-i-enable-kernel-crash-dumps-in-debian)
