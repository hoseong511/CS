## [How to install debian on virtual box](https://www.debian.org/releases/stable/amd64/index.en.html)
### **Requirements**
- VirtualBox installed
- At least 8GB of RAM installed
- At least 10GB of free disk space
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

4. 메모리 설정   
	<img src="https://user-images.githubusercontent.com/62678380/145516623-c4188a96-8e43-4fc8-81c7-6b02d37a56a6.png" width=50% />

5. 해당 부분을 선택하고 만들기 (나중에 하드디스크를 추가해서 [LVM](https://github.com/hoseong511/CS/blob/main/OS/lvm.md) 테스트)   
	<img src="https://user-images.githubusercontent.com/62678380/145516834-e2e380ba-0914-4e55-a746-db452b91f4f4.png" width=50% />

6. virtual box에서만 사용하는 디스크 파일 형식 선택   
	<img src="https://user-images.githubusercontent.com/62678380/145517110-6fd0cd0e-eea3-4f33-ad9b-6b0346c80bf8.png" width=50% />

7. 동적할당 선택 (정적할당은 해당되는 용량을 물리적으로 확보한 채로 디스크 생성, 동적할당은 실제 사용량에 맞춰 크기가 늘어남)   
	<img src="https://user-images.githubusercontent.com/62678380/145517717-a1a8afdf-028f-42a9-8e79-cd3ae0dca41a.png" width=50% />

8. 디스크 용량 선택 후, 만들기    
	<img src="https://user-images.githubusercontent.com/62678380/145518112-82b84a8e-f40a-4583-af2c-a0ba7387352e.png" width=50% />

9. 생성된 버추얼박스 실행   
	<img src="https://user-images.githubusercontent.com/62678380/145518275-82811263-9e10-4313-b7c9-c11ee0ac46e0.png" width=50% />

10. 다운받은 이미지 선택 후, 시작    
	<img src="https://user-images.githubusercontent.com/62678380/145518453-12954825-46fb-4cb3-a574-1c00d1973959.png" width=50% />   

11. install 선택 후, 다음(GUI에서는 마우스를 사용할 수 있음.)   
	<img src="https://user-images.githubusercontent.com/62678380/145519059-bfbac082-cc11-4a59-a716-24dc932d1ff1.png" width=50% />   

12. 언어 설정   
	<img src="https://user-images.githubusercontent.com/62678380/145526338-4f4bd528-0c81-451e-97ed-9c7ef863e747.png" width=50% />   

13. 위치 설정   
	<img src="https://user-images.githubusercontent.com/62678380/145526406-d0fbdc8e-7c71-4a0c-bf2b-e103a27650fa.png" width=50% />   

14. 키맵 설정   
	<img src="https://user-images.githubusercontent.com/62678380/145526465-ac88d0d5-7f27-4402-a52d-0174c734a0f8.png" width=50% />   

15. 네트워크 설정 : 호스트 이름   
	<img src="https://user-images.githubusercontent.com/62678380/145526844-c4bc8b1d-607c-4ff5-a654-6384e62ec583.png" width=50% />   

16. 네트워크 설정 : 도메인 이름, 빈칸인 상태로 엔터를 누르자  
	<img src="https://user-images.githubusercontent.com/62678380/145526978-30cbb433-ef04-41a9-be2a-32f424dbbe3b.png" width=50% />   

17. 사용자 및 암호 설정 : root 비밀번호 설정   
	<img src="https://user-images.githubusercontent.com/62678380/145527260-eab9fccf-3fc2-4108-891c-266f11703e02.png" width=50% />   

18. 사용자 및 암호 설정 : 사용자 이름 설정1   
	<img src="https://user-images.githubusercontent.com/62678380/145527633-2c1481cf-0144-4f2b-951f-a52bad5d27df.png" width=50% />   

19. 사용자 및 암호 설정 : 사용자 이름 설정2   
	<img src="https://user-images.githubusercontent.com/62678380/145527857-906c3538-35a4-4460-afa6-4a4a7ce2417b.png" width=50% />   
	
20. 사용자 및 암호 설정 : 사용자 암호 설정  
	<img src="https://user-images.githubusercontent.com/62678380/145527902-647e4cf4-edca-4129-ac6d-3ed8cb84e639.png" width=50% />   

21. 디스크 설정 : 파티션 - 암호화된 LVM 선택  
	<img src="https://user-images.githubusercontent.com/62678380/145528278-5e3cceda-9f8e-4e74-bff9-c4b0dabda8a6.png" width=50% />   

22. 디스크 설정 : 파티션 - 디스크 선택   
	<img src="https://user-images.githubusercontent.com/62678380/145528763-ba1bad63-ba9e-43ab-8fb0-4ea1e68a0fe2.png" width=50% />   

23. 디스크 설정 : 파티션 - /home 디렉토리 분리 여부, root와 사용자 공간이 분리된다.   
	<img src="https://user-images.githubusercontent.com/62678380/145528867-1e143ed5-d793-4a85-9437-17a3d4456ef9.png" width=50% />   

24. 디스크 설정 : 파티션 - 디스크를 구성하고 LVM을 설정하는 과정   
	<img src="https://user-images.githubusercontent.com/62678380/145529049-bf092960-72f5-414a-97e3-1efe3cb9f5b7.png" width=50% />   

25. 디스크 설정 : 파티션 - 디스크 암호 설정, 앞 부분 암호화된 LVM 선택해서 나온 설정   
	<img src="https://user-images.githubusercontent.com/62678380/145529049-bf092960-72f5-414a-97e3-1efe3cb9f5b7.png" width=50% />   

26. 디스크 설정 : 파티션 - 최대 크기 설정  
	<img src="https://user-images.githubusercontent.com/62678380/145525232-8961bb9e-fadc-4a41-b209-4f89c7bcfb4c.png" width=50% />   


27. 디스크 설정 : 파티션   
	<img src="https://user-images.githubusercontent.com/62678380/145523668-a33a448f-28bd-4487-8be9-affc6b3c315a.png" width=50% />   


27. 패키지 관리자 설정   
	<img src="https://user-images.githubusercontent.com/62678380/145530090-b434826d-e394-41c0-b9ba-7c311cd3ecf2.png" width=50% />   

28. 패키지 관리자 설정1   
	<img src="https://user-images.githubusercontent.com/62678380/145523416-12080f54-d7ae-4a4a-83fa-bf7b2036fc8f.png" width=50% />   

29. 패키지 관리자 설정2   
	<img src="https://user-images.githubusercontent.com/62678380/145523434-6063bd30-7299-4229-9b65-4c823a38a2d2.png" width=50% />   

30. 패키지 관리자 설정3    
	<img src="https://user-images.githubusercontent.com/62678380/145525465-38db8354-675e-4a4a-8ca6-30198bc06e97.png" width=50% />   

30. 패키지 인기 투표   
	<img src="https://user-images.githubusercontent.com/62678380/145523562-34b108a3-128c-4f00-950f-6eb003ed72bf.png" width=50% /> 

31. 추가 설치할 패키지 선택   
	<img src="https://user-images.githubusercontent.com/62678380/145525960-874b449d-39dd-4795-91e5-192d397e4035.png" width=50% /> 

32. 부트로더 설정 : GRUB 부트로더  
	<img src="https://user-images.githubusercontent.com/62678380/145525743-6264ca06-7160-47aa-b406-e382c6f7cef4.png" width=50% />  

33. 부트로더 설정 : 부트로더 설치할 장소 선택  
	<img src="https://user-images.githubusercontent.com/62678380/145524821-e88a816c-f312-4cb1-91c2-23ea6709ae73.png" width=50% />   

34. 부트로더 설정 : 위치를 지정해 줄 수 있다. (/dev/sda1)  
	<img src="https://user-images.githubusercontent.com/62678380/145524787-aa0a54c5-cf2b-4ff3-9d18-b71c04e9a8b6.png" width=50% />   

35. 설치완료   
	<img src="https://user-images.githubusercontent.com/62678380/145524230-62584fc7-0ee0-49d4-9b05-074d6fe1fc3d.png" width=50% />  
	

### **Reference**
- https://parkseunghan.notion.site/born2beroot-afdb78d74995456d9c91a4ae1be9874f
- https://www.brianlinkletter.com/2012/10/installing-debian-linux-in-a-virtualbox-virtual-machine/
- https://linuxhint.com/install_debian10_virtualbox/