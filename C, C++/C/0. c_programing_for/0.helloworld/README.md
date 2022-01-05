# C Programing for beginners
## TOC

## **C 개발 환경 on mac OS**

- xcode가 설치 됐다면 c compiler가 설치 되어 있음.

	- xcode 설치 하기

	- Appstore에서 xcode 검색

	- 설치

	- `gcc --version` 확인

- VScode 이용하기

	- extensions에서 C/C++ 검색 후 설치

	- `cmd + shift + p `

	- task 입력 후, `Task : Configure Default Build Task` 선택

	- tasks.json 만들기 선택

	- Others 선택, 아래와 같이 json파일 생성   
		```json
		{
			// See https://go.microsoft.com/fwlink/?LinkId=733558
			// for the documentation about the tasks.json format
			"version": "2.0.0",
			"tasks": [
				{
					"label": "echo",
					"type": "shell",
					"command": "echo Hello"
				}
			]
		}
		```
	- 아래와 같이 작성   
		```json

		{
			// See https://go.microsoft.com/fwlink/?LinkId=733558
			// for the documentation about the tasks.json format
			"version": "2.0.0",
			"tasks": [
				{
					"label": "build hello world",
					"type": "shell",
					"command": "gcc",
					"args": [
						"-Wall",
						"-Wextra",
						"-Werror",
						"-g",
						"-o",
						"helloworld",
						"helloworld.c"
					],
					"group": {
						"kind": "build",
						"isDefault": true
					}
				}
			]
		}
		```
	- `cmd + shift + b`로 빌드

- 디버깅 하기

	- `cmd + shift + p `

	- launch 검색

	- C++(LLDB/GDB) 선택 후, 아래와 같이 생성   

	```json

	{
		// IntelliSense를 사용하여 가능한 특성에 대해 알아보세요.
		// 기존 특성에 대한 설명을 보려면 가리킵니다.
		// 자세한 내용을 보려면 https://go.microsoft.com/fwlink/?linkid=830387을(를) 방문하세요.
		"version": "0.2.0",
		"configurations": [
			{
				"name": "(lldb) 시작",
				"type": "cppdbg",
				"request": "launch",
				"program": "프로그램 이름 입력(예: ${workspaceFolder}/a.out)",
				"args": [],
				"stopAtEntry": false,
				"cwd": "${workspaceFolder}",
				"environment": [],
				"externalConsole": false,
				"MIMode": "lldb"
			}
		]
	}
	```

	- 프로그램 이름 입력 부분 수정, stopAtEntry 디버깅 시작 시 break 여부   

	```json

	{
		// IntelliSense를 사용하여 가능한 특성에 대해 알아보세요.
		// 기존 특성에 대한 설명을 보려면 가리킵니다.
		// 자세한 내용을 보려면 https://go.microsoft.com/fwlink/?linkid=830387을(를) 방문하세요.
		"version": "0.2.0",
		"configurations": [
			{
				"name": "(lldb) 시작",
				"type": "cppdbg",
				"request": "launch",
				"program": "${workspaceFolder}/helloworld",
				"args": [],
				"stopAtEntry": true,
				"cwd": "${workspaceFolder}",
				"environment": [],
				"externalConsole": false,
				"MIMode": "lldb"
			}
		]
	}
	```

- 메모리 누수 검사

	- 터미널 열기

	- 프로세스 번호 : `ps -ef | grep -i [프로그램이름]`

	- 메모리 누수 검사 : `while true; do leaks [프로세스번호]; sleep 0.5; done`