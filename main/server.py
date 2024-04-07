import socket

KEY_MESSAGE = "avalanche"


def server_program():
    host = socket.gethostname()
    port = 5000 

    server_socket = socket.socket() 
    server_socket.bind((host, port))  

    server_socket.listen(2)
    conn, address = server_socket.accept()
    print("Connection from: " + str(address))

    while True:
        data = conn.recv(1024).decode()
        if not data:
            print('not recived')
            continue
        elif data == KEY_MESSAGE:
            print("Avalanche is in coming!")
            print("from connected user: " + str(data))
            ack_data = 'ack'
            conn.send(ack_data.encode())
            break
    conn.close()

if __name__ == '__main__':
    while (True):
        try:
            server_program()
        except:
            continue
        
        
