## [How to install debian on virtual box](https://www.debian.org/releases/stable/amd64/index.en.html)
### **Requirements**
- VirtualBox installed
- At least 8GB of RAM installed
- At least 20GB of free disk space
- Internet connectivity
- Hardware virtualization VT-x/VT-d or AMD-v enabled from the BIOS of your motherboard

### **Versions**
- debian CD image : [debian-10.11.0-amd64-netinst.iso](https://www.debian.org/CD/netinst/index.ko.html)
- Virtual Box : ver 6.0.14 r133895 (Qt5.6.3)
- macOS : ver 10.15.7(19H1519)
- CPU : 3.1 GHz 6core Intel Core i5

### **Install**
1. [CPU](https://github.com/hoseong511/CS/blob/main/OS/cpu.md)확인 후, 데비안 [이미지 선택](https://cdimage.debian.org/cdimage/archive/). ([해당 버전을 사용한 이유](https://ko.wikipedia.org/wiki/%EB%8D%B0%EB%B9%84%EC%95%88#%EB%B0%B0%ED%8F%AC_%EC%97%AD%EC%82%AC))   
	<img src="https://user-images.githubusercontent.com/62678380/145513483-a82d4334-2da9-4d74-99da-c79cb9d68318.png" width=50% />
2. 이미지를 다운 받았으면 간단히 확인해보자. (`shasum`)   
	<img src="https://user-images.githubusercontent.com/62678380/145515099-3e28e2ba-621e-49c8-8e24-5f9a37228c39.png" width=50% />
	   
	`shasum -a 512 debian-10.11.0-amd64-netinst.iso
	`
3. virtual box에서 새로 만들기 후, 이름과 이미지의 종류/버전을 선택 다음.   
	<img src="https://user-images.githubusercontent.com/62678380/145515981-da1dcb54-4cc8-4cb6-b71a-6cfca30a51af.png" width=50% />


### **Reference**
- https://parkseunghan.notion.site/born2beroot-afdb78d74995456d9c91a4ae1be9874f
- https://www.brianlinkletter.com/2012/10/installing-debian-linux-in-a-virtualbox-virtual-machine/
- https://linuxhint.com/install_debian10_virtualbox/