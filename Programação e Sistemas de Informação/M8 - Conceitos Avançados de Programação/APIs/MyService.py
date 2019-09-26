import socket

#
# Copyright (c) Carlos Tojal (carlostojal)
# MyService.py
# APIs
# github.com/carlostojal/TSI
#

print("\n** MyService **\n")

s = socket.socket()

host = socket.gethostbyname(socket.gethostname())
port = 555

s.bind((host, port))
s.listen()

print("Serviço iniciado em "+host+":"+str(port))

client, client_addr = s.accept()
print("Cliente conectado\n")

message = ""

while message != "exit":
	message = input("Mensagem: ")
	client.send((message+"\n").encode())
