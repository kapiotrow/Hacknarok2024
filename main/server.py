import socket


import sqlite3


KEY_MESSAGE = "avalanche"

db_conn = sqlite3.connect('test.db')
idx = 1

def server_program():
    host = socket.gethostname()
    port = 5000 

    server_socket = socket.socket() 
    server_socket.bind((host, port))  

    server_socket.listen(2)
    conn, address = server_socket.accept()
    print("Connection from: " + str(address))
    ack_data = 'ack'

    temperature = 0
    snow_height = 0

    for i in range(2):
        data = conn.recv(1024).decode()
        conn.send(ack_data.encode())
        if not data:
            print('not recived')
            continue
        elif data == KEY_MESSAGE:
            print("Avalanche is in coming!")
            print("from connected user: " + str(data))
            conn.send(ack_data.encode())
            break
        else: 
            if i == 0:
                temperature = int(data)
                print(f"temp: {temperature}")
            else:
                snow_height = int(data)
                print(f"snow: {snow_height}")
        
    db_conn.execute(f"INSERT INTO FIELD_DATA (ID, TEMPERATURE, SNOW_HEIGHT) \
        VALUES ({idx}, {temperature}, {snow_height})")
    idx = idx + 1
    print(idx)
    db_conn.commit()
    conn.close()

if __name__ == '__main__':

    print("Opened database successfully");
    while (True):
        try:
            server_program()
        except:
            continue
        
        
