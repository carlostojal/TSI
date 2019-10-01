import socket

#
# Copyright (c) Carlos Tojal (carlostojal)
# MyService.py
# MyService
# APIs
# github.com/carlostojal/TSI
#

print("\n** MyService **\n")

s = socket.socket()

host = "10.1.25.91" # endereço da placa de rede a utilizar
port = 555

s.bind((host, port))
s.listen()

print("Serviço iniciado em "+host+":"+str(port))

client, client_addr = s.accept()
print("Cliente conectado ("+str(client_addr)+")\n")

message = ""

while message != "exit":
        message = input("Mensagem: ")
        client.send((message+"\n").encode())
