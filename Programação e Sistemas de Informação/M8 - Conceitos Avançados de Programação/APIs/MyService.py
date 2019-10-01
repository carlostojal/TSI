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

<<<<<<< HEAD
host = "10.1.25.91" # endereço da placa de rede a utilizar
=======
host = "10.1.25.74" # endereço da placa de rede a utilizar
>>>>>>> e23fd683f864fe5274e1f73a48ecb3987caabcab
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
