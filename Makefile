echoclient:
	gcc -c echoclient.c csapp.c ipaddress.c
	gcc echoclient.o csapp.o ipaddress.o -o echoclient

echoservers:
	gcc -c echoservers.c csapp.c echo.c ipaddress.c
	gcc echoservers.o csapp.o echo.o ipaddress.o -o echoservers
